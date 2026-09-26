#!/usr/bin/env python3
"""
vm_asm.py - Clean-Room Bytecode Assembler & Disassembler for DoogEngine1

Assembles human-readable assembly instructions into:
  1. Standalone raw bytecode stream (.bin)
  2. Full payload file patched at offset 0x200 (ready for run_payload.exe)

Features:
  - Supports all 7 Opcode Families (Kernel Gateways, Register Ops, Stream XOR,
    ALU/Bitwise, Frame Shifts, Bounds Guards, and Stack/Hash Ops)
  - Supports labels and relative branches (BRANCH_REL, BRANCH_IF_ZERO, BRANCH_IF_NZ)
  - Assembler CLI + Disassembler CLI (`assemble` and `disasm` subcommands)
  - Can patch existing testfile payloads directly with `--payload <path>`
"""

import sys
import os
import re
import struct
import argparse
from typing import List, Dict, Tuple, Optional, Any

# ============================================================================
# INSTRUCTION ENCODING SCHEMA TABLE
# ============================================================================
# Format specification:
#   mnemonic: (opcode_byte, operand_types)
#   operand_types:
#     - 'none': no operands
#     - 'reg': 1 byte register index (0..15 or R0..R15)
#     - 'reg_imm8': reg index (u8), imm8 (u8)
#     - 'reg_imm16': reg index (u8), imm16 (u16 little-endian)
#     - 'reg_imm32': reg index (u8), imm32 (i32 little-endian)
#     - 'reg_reg': dst reg (u8), src reg (u8)
#     - 'reg_shift': dst reg (u8), shift amount (u8)
#     - 'imm32': 32-bit immediate (u32/i32 little-endian)
#     - 'label_or_rel8': 8-bit signed branch offset or label name
#     - 'reg_label_or_rel8': reg index (u8), 8-bit signed offset or label
# ============================================================================

INSTRUCTIONS: Dict[str, Tuple[int, str]] = {
    # Family 1: Kernel Gateways & Context Setup
    "NOP":              (0x00, "none"),
    "INIT":             (0x00, "none"),
    "HALT":             (0x01, "none"),
    "FETCH_TAG":        (0x02, "reg"),
    "FETCH_WORD":       (0x03, "reg"),
    "FETCH_DWORD":      (0x04, "reg"),
    "SET_BASE":         (0x05, "imm32"),
    "SYNC_CONTEXT":     (0x06, "none"),
    "BRANCH_REL":       (0x07, "label_or_rel8"),
    "BRANCH_IF_ZERO":   (0x08, "reg_label_or_rel8"),
    "BRANCH_IF_NZ":     (0x09, "reg_label_or_rel8"),

    # Family 2: Register Load, Store & Move
    "LOAD_IMM8":        (0x0A, "reg_imm8"),
    "LOAD_IMM16":       (0x0B, "reg_imm16"),
    "LOAD_IMM32":       (0x0C, "reg_imm32"),
    "MOV_REG":          (0x0D, "reg_reg"),
    "LOAD_MEM8":        (0x0E, "reg_reg"),
    "LOAD_MEM32":       (0x0F, "reg_reg"),
    "STORE_MEM8":       (0x10, "reg_reg"),
    "STORE_MEM32":      (0x11, "reg_reg"),

    # Family 3: Stream XOR Operations
    "XOR_BYTE_STREAM":  (0x19, "reg_imm8"),
    "XOR_WORD_STREAM":  (0x1A, "reg_imm8"),
    "XOR_DWORD_STREAM": (0x1B, "reg_imm8"),

    # Family 4: Arithmetic & Bitwise Logic
    "ADD_REG":          (0x28, "reg_reg"),
    "SUB_REG":          (0x29, "reg_reg"),
    "AND_REG":          (0x2A, "reg_reg"),
    "OR_REG":           (0x2B, "reg_reg"),
    "XOR_REG":          (0x2C, "reg_reg"),

    # Family 5: Register Window Sliding Shifts
    "SHL_REG":          (0x37, "reg_shift"),
    "SHR_REG":          (0x38, "reg_shift"),
    "ROL_REG":          (0x39, "reg_shift"),
    "ROR_REG":          (0x3A, "reg_shift"),

    # Family 6: Bounds & Alignment Guards
    "CHK_BOUNDS8":      (0x46, "reg_reg"),
    "CHK_BOUNDS32":     (0x47, "reg_reg"),
    "ALIGN_WORD":       (0x48, "reg"),
    "ALIGN_DWORD":      (0x49, "reg"),

    # Family 7: Stack Operations & Checksum Hash Guards
    "PUSH_REG":         (0x50, "reg"),
    "POP_REG":          (0x51, "reg"),
    "PUSH_IMM32":       (0x52, "imm32"),
    "CHK_STACK":        (0x53, "none"),
    "HASH_ACC":         (0x54, "reg"),
    "VERIFY_HASH":      (0x55, "imm32"),
    "EXIT_KERNEL":      (0x56, "none"),
}

OPCODE_TO_MNEMONIC: Dict[int, Tuple[str, str]] = {
    op: (mnem, op_type) for mnem, (op, op_type) in INSTRUCTIONS.items()
}

def parse_reg(token: str) -> int:
    """Parses register names like R0..R15, raw integers 0..15, or bracketed memory pointers [R0]."""
    clean = token.strip().upper().strip("[]")
    if clean.startswith("R") and clean[1:].isdigit():
        idx = int(clean[1:])
    else:
        idx = int(clean, 0)
    if not (0 <= idx <= 15):
        raise ValueError(f"Invalid register index: {token} (expected 0..15 / R0..R15)")
    return idx

def parse_int(token: str, bits: int = 32, signed: bool = True) -> int:
    """Parses immediate integers (dec or hex) with bit-width bounds checking."""
    clean = token.strip()
    val = int(clean, 0)
    if signed:
        # If passed as unsigned hex/dec up to (1 << bits) - 1, map to two's-complement signed
        if 0 <= val <= (1 << bits) - 1:
            if val >= (1 << (bits - 1)):
                val -= (1 << bits)
        min_val = -(1 << (bits - 1))
        max_val = (1 << (bits - 1)) - 1
    else:
        min_val = 0
        max_val = (1 << bits) - 1

    if not (min_val <= val <= max_val):
        raise ValueError(f"Value '{token}' out of range for {bits}-bit integer [{min_val}..{max_val}]")
    return val

# ============================================================================
# TWO-PASS ASSEMBLER
# ============================================================================

class Assembler:
    def __init__(self):
        self.labels: Dict[str, int] = {}
        self.unresolved_branches: List[Tuple[int, str, int]] = [] # (pc_offset, label_name, instr_end_offset)

    def assemble(self, source_code: str) -> bytes:
        lines = source_code.splitlines()
        self.labels.clear()
        self.unresolved_branches.clear()

        # Pass 1: Parse structure, record label positions, build raw stream with placeholders
        bytecode = bytearray()

        for line_num, raw_line in enumerate(lines, 1):
            line = raw_line.split(";")[0].split("//")[0].strip()
            if not line:
                continue

            # Check for label definition: "label_name:"
            if line.endswith(":"):
                label_name = line[:-1].strip()
                if label_name in self.labels:
                    raise SyntaxError(f"Line {line_num}: Duplicate label '{label_name}'")
                self.labels[label_name] = len(bytecode)
                continue

            # Check for inline label: "label_name: INSTR ..."
            if ":" in line:
                label_part, rest = line.split(":", 1)
                label_name = label_part.strip()
                if label_name in self.labels:
                    raise SyntaxError(f"Line {line_num}: Duplicate label '{label_name}'")
                self.labels[label_name] = len(bytecode)
                line = rest.strip()
                if not line:
                    continue

            tokens = [t.strip().rstrip(",") for t in re.split(r'[\s,]+', line) if t.strip()]
            if not tokens:
                continue

            mnemonic = tokens[0].upper()
            if mnemonic not in INSTRUCTIONS:
                raise SyntaxError(f"Line {line_num}: Unknown mnemonic '{mnemonic}'")

            opcode, op_type = INSTRUCTIONS[mnemonic]
            args = tokens[1:]

            bytecode.append(opcode)

            try:
                if op_type == "none":
                    if len(args) != 0:
                        raise ValueError(f"Expected 0 operands for {mnemonic}, got {len(args)}")

                elif op_type == "reg":
                    if len(args) != 1:
                        raise ValueError(f"Expected 1 register operand for {mnemonic}")
                    bytecode.append(parse_reg(args[0]))

                elif op_type == "reg_imm8":
                    if len(args) != 2:
                        raise ValueError(f"Expected 2 operands (reg, imm8) for {mnemonic}")
                    bytecode.append(parse_reg(args[0]))
                    bytecode.append(parse_int(args[1], bits=8, signed=False))

                elif op_type == "reg_imm16":
                    if len(args) != 2:
                        raise ValueError(f"Expected 2 operands (reg, imm16) for {mnemonic}")
                    bytecode.append(parse_reg(args[0]))
                    val16 = parse_int(args[1], bits=16, signed=False)
                    bytecode.extend(struct.pack("<H", val16))

                elif op_type == "reg_imm32":
                    if len(args) != 2:
                        raise ValueError(f"Expected 2 operands (reg, imm32) for {mnemonic}")
                    bytecode.append(parse_reg(args[0]))
                    val32 = parse_int(args[1], bits=32, signed=True)
                    bytecode.extend(struct.pack("<i", val32))

                elif op_type == "reg_reg":
                    if len(args) != 2:
                        raise ValueError(f"Expected 2 register operands for {mnemonic}")
                    bytecode.append(parse_reg(args[0]))
                    bytecode.append(parse_reg(args[1]))

                elif op_type == "reg_shift":
                    if len(args) != 2:
                        raise ValueError(f"Expected 2 operands (reg, shift) for {mnemonic}")
                    bytecode.append(parse_reg(args[0]))
                    bytecode.append(parse_int(args[1], bits=8, signed=False) % 32)

                elif op_type == "imm32":
                    if len(args) != 1:
                        raise ValueError(f"Expected 1 32-bit immediate for {mnemonic}")
                    val32 = parse_int(args[0], bits=32, signed=True)
                    bytecode.extend(struct.pack("<i", val32))

                elif op_type == "label_or_rel8":
                    if len(args) != 1:
                        raise ValueError(f"Expected 1 relative target for {mnemonic}")
                    target = args[0]
                    placeholder_pos = len(bytecode)
                    bytecode.append(0x00) # Placeholder for relative offset
                    self.unresolved_branches.append((placeholder_pos, target, len(bytecode)))

                elif op_type == "reg_label_or_rel8":
                    if len(args) != 2:
                        raise ValueError(f"Expected 2 operands (reg, target) for {mnemonic}")
                    bytecode.append(parse_reg(args[0]))
                    target = args[1]
                    placeholder_pos = len(bytecode)
                    bytecode.append(0x00)
                    self.unresolved_branches.append((placeholder_pos, target, len(bytecode)))

            except Exception as e:
                raise SyntaxError(f"Line {line_num} ('{raw_line}'): {e}") from e

        # Pass 2: Resolve branch target labels to relative 8-bit signed offsets
        for patch_pos, target, instr_end in self.unresolved_branches:
            if target in self.labels:
                target_offset = self.labels[target]
                rel_offset = target_offset - instr_end
                if not (-128 <= rel_offset <= 127):
                    raise OverflowError(f"Branch target '{target}' offset {rel_offset} exceeds 8-bit signed range (-128..127)")
                bytecode[patch_pos] = struct.pack("<b", rel_offset)[0]
            else:
                try:
                    rel_val = parse_int(target, bits=8, signed=True)
                    bytecode[patch_pos] = struct.pack("<b", rel_val)[0]
                except ValueError:
                    raise KeyError(f"Undefined branch label: '{target}'")

        return bytes(bytecode)

# ============================================================================
# DISASSEMBLER
# ============================================================================

def disassemble(bytecode: bytes, base_pc: int = 0x200) -> str:
    """Disassembles binary bytecode stream into human-readable instructions."""
    pc = 0
    total = len(bytecode)
    lines: List[str] = []

    while pc < total:
        cur_pc = base_pc + pc
        opcode = bytecode[pc]
        pc += 1

        if opcode not in OPCODE_TO_MNEMONIC:
            lines.append(f"{cur_pc:04X}: DB 0x{opcode:02X} ; Unknown opcode")
            continue

        mnem, op_type = OPCODE_TO_MNEMONIC[opcode]

        if op_type == "none":
            lines.append(f"{cur_pc:04X}: {mnem}")

        elif op_type == "reg":
            if pc < total:
                reg = bytecode[pc]
                pc += 1
                lines.append(f"{cur_pc:04X}: {mnem:<14} R{reg}")
            else:
                lines.append(f"{cur_pc:04X}: {mnem} <TRUNCATED>")

        elif op_type == "reg_imm8":
            if pc + 1 < total:
                reg = bytecode[pc]
                imm8 = bytecode[pc + 1]
                pc += 2
                lines.append(f"{cur_pc:04X}: {mnem:<14} R{reg}, 0x{imm8:02X}")
            else:
                lines.append(f"{cur_pc:04X}: {mnem} <TRUNCATED>")

        elif op_type == "reg_imm16":
            if pc + 2 <= total:
                reg = bytecode[pc]
                val16 = struct.unpack("<H", bytecode[pc + 1:pc + 3])[0]
                pc += 3
                lines.append(f"{cur_pc:04X}: {mnem:<14} R{reg}, 0x{val16:04X}")
            else:
                lines.append(f"{cur_pc:04X}: {mnem} <TRUNCATED>")

        elif op_type == "reg_imm32":
            if pc + 4 <= total:
                reg = bytecode[pc]
                val32 = struct.unpack("<I", bytecode[pc + 1:pc + 5])[0]
                pc += 5
                lines.append(f"{cur_pc:04X}: {mnem:<14} R{reg}, 0x{val32:08X}")
            else:
                lines.append(f"{cur_pc:04X}: {mnem} <TRUNCATED>")

        elif op_type in ("reg_reg", "reg_shift"):
            if pc + 1 < total:
                r1 = bytecode[pc]
                r2 = bytecode[pc + 1]
                pc += 2
                if mnem in ("LOAD_MEM8", "LOAD_MEM32"):
                    lines.append(f"{cur_pc:04X}: {mnem:<14} R{r1}, [R{r2}]")
                elif mnem in ("STORE_MEM8", "STORE_MEM32"):
                    lines.append(f"{cur_pc:04X}: {mnem:<14} [R{r1}], R{r2}")
                elif op_type == "reg_shift":
                    lines.append(f"{cur_pc:04X}: {mnem:<14} R{r1}, {r2}")
                else:
                    lines.append(f"{cur_pc:04X}: {mnem:<14} R{r1}, R{r2}")
            else:
                lines.append(f"{cur_pc:04X}: {mnem} <TRUNCATED>")

        elif op_type == "imm32":
            if pc + 4 <= total:
                val32 = struct.unpack("<I", bytecode[pc:pc + 4])[0]
                pc += 4
                lines.append(f"{cur_pc:04X}: {mnem:<14} 0x{val32:08X}")
            else:
                lines.append(f"{cur_pc:04X}: {mnem} <TRUNCATED>")

        elif op_type == "label_or_rel8":
            if pc < total:
                rel = struct.unpack("<b", bytes([bytecode[pc]]))[0]
                pc += 1
                target = base_pc + pc + rel
                lines.append(f"{cur_pc:04X}: {mnem:<14} {rel:+d}  ; -> 0x{target:04X}")
            else:
                lines.append(f"{cur_pc:04X}: {mnem} <TRUNCATED>")

        elif op_type == "reg_label_or_rel8":
            if pc + 1 < total:
                reg = bytecode[pc]
                rel = struct.unpack("<b", bytes([bytecode[pc + 1]]))[0]
                pc += 2
                target = base_pc + pc + rel
                lines.append(f"{cur_pc:04X}: {mnem:<14} R{reg}, {rel:+d}  ; -> 0x{target:04X}")
            else:
                lines.append(f"{cur_pc:04X}: {mnem} <TRUNCATED>")

    return "\n".join(lines)

# ============================================================================
# PAYLOAD PATCHING HELPER
# ============================================================================

def patch_payload_file(payload_path: str, bytecode: bytes, offset: int = 0x200):
    """Patches bytecode into an existing 1.85MB payload file at offset (default: 0x200)."""
    if not os.path.exists(payload_path):
        print(f"[+] Creating fresh baseline payload '{payload_path}' (1854136 bytes)...")
        with open(payload_path, "wb") as f:
            f.write(b"\x00" * 1854136)

    with open(payload_path, "r+b") as f:
        f.seek(offset)
        f.write(bytecode)

    print(f"[+] Successfully wrote {len(bytecode)} bytes of assembled bytecode to '{payload_path}' at 0x{offset:X}")

# ============================================================================
# CLI ENTRYPOINT
# ============================================================================

def main():
    parser = argparse.ArgumentParser(
        description="DoogEngine1 Bytecode Assembler & Disassembler (vm_asm.py)",
        formatter_class=argparse.RawDescriptionHelpFormatter
    )
    subparsers = parser.add_subparsers(dest="subcommand", required=True, help="Subcommand")

    # assemble
    p_asm = subparsers.add_parser("assemble", help="Assemble assembly source into bytecode")
    p_asm.add_argument("input_file", help="Input assembly file (.asm / .s)")
    p_asm.add_argument("-o", "--output", help="Output raw binary bytecode file (.bin)")
    p_asm.add_argument("-p", "--payload", help="Patch assembled bytecode directly into payload file at offset")
    p_asm.add_argument("--offset", default="0x200", help="Payload injection offset (default: 0x200)")
    p_asm.add_argument("--print-hex", action="store_true", help="Print assembled bytecode as hex bytes")

    # disasm
    p_dis = subparsers.add_parser("disasm", help="Disassemble binary bytecode into human-readable instructions")
    p_dis.add_argument("binary_file", help="Input binary bytecode or payload file")
    p_dis.add_argument("--offset", default="0x0", help="Read start offset in input file (default: 0x0; use 0x200 for payload)")
    p_dis.add_argument("--length", type=int, default=128, help="Number of bytes to disassemble (default: 128)")
    p_dis.add_argument("--base-pc", default="0x200", help="Base Program Counter address for display (default: 0x200)")

    args = parser.parse_args()

    if args.subcommand == "assemble":
        with open(args.input_file, "r") as f:
            source = f.read()

        asm = Assembler()
        bytecode = asm.assemble(source)

        print(f"[*] Assembled {len(bytecode)} bytes from '{args.input_file}'")
        if args.print_hex:
            hex_str = " ".join([f"{b:02X}" for b in bytecode])
            print(f"[*] Hex output: {hex_str}")

        if args.output:
            with open(args.output, "wb") as f:
                f.write(bytecode)
            print(f"[+] Saved raw bytecode to '{args.output}'")

        if args.payload:
            offset = int(args.offset, 16) if args.offset.startswith("0x") else int(args.offset)
            patch_payload_file(args.payload, bytecode, offset)

    elif args.subcommand == "disasm":
        start_off = int(args.offset, 16) if args.offset.startswith("0x") else int(args.offset)
        base_pc = int(args.base_pc, 16) if args.base_pc.startswith("0x") else int(args.base_pc)

        with open(args.binary_file, "rb") as f:
            f.seek(start_off)
            blob = f.read(args.length)

        listing = disassemble(blob, base_pc=base_pc)
        print(f"[*] Disassembly of '{args.binary_file}' (offset 0x{start_off:X}, {len(blob)} bytes):")
        print("-" * 50)
        print(listing)

if __name__ == "__main__":
    main()
