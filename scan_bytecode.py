#!/usr/bin/env python3
"""
scan_bytecode.py - DoogEngine1 Bytecode Pattern Scanner

Scans binary files (payloads, memory dumps, game assets) for valid DoogEngine1 bytecode sequences.
Identifies candidate instruction streams, validates register ranges and branch bounds,
and disassembles discovered blocks.
"""

import sys
import os
import struct
import argparse
import json
from typing import Dict, List, Tuple, Optional, Any

# Import disassembly and opcode tables from vm_asm
try:
    from vm_asm import INSTRUCTIONS, OPCODE_TO_MNEMONIC, disassemble
except ImportError:
    print("[-] Error: 'vm_asm.py' not found in path. Ensure it is in the same directory.")
    sys.exit(1)

TERMINAL_OPCODES = {0x01: "HALT", 0x56: "EXIT_KERNEL"}

class DiscoveredBlock:
    def __init__(self, offset: int, length: int, instruction_count: int, terminal_mnemonic: str, preview: str):
        self.offset = offset
        self.length = length
        self.instruction_count = instruction_count
        self.terminal_mnemonic = terminal_mnemonic
        self.preview = preview

    def to_dict(self) -> Dict[str, Any]:
        return {
            "offset_hex": f"0x{self.offset:X}",
            "offset_dec": self.offset,
            "length_bytes": self.length,
            "instruction_count": self.instruction_count,
            "terminal": self.terminal_mnemonic,
            "preview": self.preview
        }

def try_parse_instruction(data: bytes, pos: int, total_len: int) -> Optional[Tuple[int, str, Optional[int]]]:
    """
    Attempts to decode a single valid instruction at data[pos].
    Returns (instruction_length, mnemonic, branch_target_offset) or None if invalid.
    """
    if pos >= total_len:
        return None

    opcode = data[pos]
    if opcode not in OPCODE_TO_MNEMONIC:
        return None

    mnem, op_type = OPCODE_TO_MNEMONIC[opcode]
    branch_target = None

    if op_type == "none":
        return 1, mnem, None

    elif op_type == "reg":
        if pos + 1 >= total_len:
            return None
        reg = data[pos + 1]
        if reg > 15:
            return None
        return 2, mnem, None

    elif op_type == "reg_imm8":
        if pos + 2 >= total_len:
            return None
        reg = data[pos + 1]
        if reg > 15:
            return None
        return 3, mnem, None

    elif op_type == "reg_imm16":
        if pos + 3 >= total_len:
            return None
        reg = data[pos + 1]
        if reg > 15:
            return None
        return 4, mnem, None

    elif op_type == "reg_imm32":
        if pos + 5 >= total_len:
            return None
        reg = data[pos + 1]
        if reg > 15:
            return None
        return 6, mnem, None

    elif op_type == "reg_reg":
        if pos + 2 >= total_len:
            return None
        r1 = data[pos + 1]
        r2 = data[pos + 2]
        if r1 > 15 or r2 > 15:
            return None
        return 3, mnem, None

    elif op_type == "reg_shift":
        if pos + 2 >= total_len:
            return None
        reg = data[pos + 1]
        shift = data[pos + 2]
        if reg > 15 or shift >= 32:
            return None
        return 3, mnem, None

    elif op_type == "imm32":
        if pos + 4 >= total_len:
            return None
        return 5, mnem, None

    elif op_type == "label_or_rel8":
        if pos + 1 >= total_len:
            return None
        rel = struct.unpack("<b", bytes([data[pos + 1]]))[0]
        branch_target = (pos + 2) + rel
        return 2, mnem, branch_target

    elif op_type == "reg_label_or_rel8":
        if pos + 2 >= total_len:
            return None
        reg = data[pos + 1]
        if reg > 15:
            return None
        rel = struct.unpack("<b", bytes([data[pos + 2]]))[0]
        branch_target = (pos + 3) + rel
        return 3, mnem, branch_target

    return None

def scan_file(filepath: str, min_instructions: int = 4, max_scan_len: Optional[int] = None) -> List[DiscoveredBlock]:
    """Scans binary file for valid DoogEngine1 bytecode blocks."""
    if not os.path.exists(filepath):
        print(f"[-] Error: File not found: {filepath}")
        return []

    with open(filepath, "rb") as f:
        data = f.read(max_scan_len) if max_scan_len else f.read()

    total_len = len(data)
    blocks: List[DiscoveredBlock] = []
    pos = 0

    while pos < total_len:
        # Candidate block starts if opcode is not 0x00 (avoid pure zero streams) and is valid
        if data[pos] == 0x00 or data[pos] not in OPCODE_TO_MNEMONIC:
            pos += 1
            continue

        curr_pos = pos
        instructions = []
        branch_targets = []
        is_terminated = False
        terminal_mnemonic = ""

        while curr_pos < total_len:
            res = try_parse_instruction(data, curr_pos, total_len)
            if res is None:
                break

            instr_len, mnem, branch_target = res
            instructions.append((curr_pos, mnem, instr_len))
            if branch_target is not None:
                branch_targets.append(branch_target)

            curr_pos += instr_len

            if mnem in ("HALT", "EXIT_KERNEL"):
                # If there are unresolved forward branches that target beyond curr_pos, keep parsing
                if not any(target >= curr_pos for target in branch_targets):
                    is_terminated = True
                    terminal_mnemonic = mnem
                    break

        # Validate candidates
        if is_terminated and len(instructions) >= min_instructions:
            block_start = pos
            block_end = curr_pos

            # Verify branch targets fall within block bounds and land on instruction boundaries
            instr_offsets = {p for p, _, _ in instructions}
            branches_valid = all(target in instr_offsets for target in branch_targets)

            # Filter out sequences that are mostly NOPs
            non_nops = sum(1 for _, mnem, _ in instructions if mnem not in ("NOP", "INIT"))
            if branches_valid and (non_nops >= min_instructions // 2):
                preview_mnems = [mnem for _, mnem, _ in instructions[:4]]
                preview = " -> ".join(preview_mnems)
                if len(instructions) > 4:
                    preview += " ..."

                block = DiscoveredBlock(
                    offset=block_start,
                    length=block_end - block_start,
                    instruction_count=len(instructions),
                    terminal_mnemonic=terminal_mnemonic,
                    preview=preview
                )
                blocks.append(block)
                # Advance pos past the discovered block
                pos = block_end
                continue

        pos += 1

    return blocks

def print_blocks_table(blocks: List[DiscoveredBlock], filename: str):
    """Prints a formatted ASCII table of discovered bytecode blocks."""
    print(f"\n[*] Bytecode Scan Results for: {filename}")
    if not blocks:
        print("  [!] No valid bytecode blocks found matching criteria.")
        return

    header = f"{'Offset (Hex)':<14} | {'Offset (Dec)':<12} | {'Length':<8} | {'Instructions':<12} | {'Terminal':<11} | {'Preview'}"
    separator = "-" * 90
    print(separator)
    print(header)
    print(separator)

    for b in blocks:
        print(f"0x{b.offset:08X}     | {b.offset:<12} | {b.length:<8} | {b.instruction_count:<12} | {b.terminal_mnemonic:<11} | {b.preview}")
    print(separator)
    print(f"[+] Total Candidate Blocks Detected: {len(blocks)}\n")

def main():
    parser = argparse.ArgumentParser(description="Scan binary files for DoogEngine1 bytecode sequences.")
    parser.add_argument("binary", help="Target binary file to scan (e.g. payload, asset, executable)")
    parser.add_argument("--min-inst", type=int, default=4, help="Minimum instruction count to consider a valid block (default: 4)")
    parser.add_argument("--disasm", type=str, default=None, help="Disassemble discovered block at specified hex or dec offset (e.g. 0x200)")
    parser.add_argument("--length", type=int, default=None, help="Disassembly length in bytes (optional, defaults to detected block length)")
    parser.add_argument("--json", type=str, default=None, help="Export scan results to JSON file")

    args = parser.parse_args()

    if not os.path.exists(args.binary):
        print(f"[-] Error: File not found: {args.binary}")
        sys.exit(1)

    # If disasm flag is supplied directly, disassemble that offset
    if args.disasm is not None:
        target_offset = int(args.disasm, 16) if args.disasm.startswith("0x") else int(args.disasm)
        disasm_len = args.length

        if disasm_len is None:
            blocks = scan_file(args.binary, min_instructions=args.min_inst)
            matched = next((b for b in blocks if b.offset == target_offset), None)
            disasm_len = matched.length if matched else 128

        with open(args.binary, "rb") as f:
            f.seek(target_offset)
            code_bytes = f.read(disasm_len)

        print(f"\n[*] Disassembling '{args.binary}' at 0x{target_offset:X} ({len(code_bytes)} bytes):")
        print("-" * 60)
        output = disassemble(code_bytes, base_pc=target_offset)
        print(output)
        return

    # Run scan
    blocks = scan_file(args.binary, min_instructions=args.min_inst)
    print_blocks_table(blocks, args.binary)

    if args.json:
        with open(args.json, "w") as f:
            json.dump([b.to_dict() for b in blocks], f, indent=2)
        print(f"[+] Exported results to JSON: {args.json}")

if __name__ == "__main__":
    main()
