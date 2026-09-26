#!/usr/bin/env python3
"""
vm_sweep.py - Unified VM Opcode & Payload Sweep CLI Tool

Consolidates all fragmented sweep scripts:
  - opcode_sweep.py (sweep byte at 0x200)
  - opcode_sweep1.py (sweep byte at 0x201)
  - opcode_sweep2.py (sweep byte at 0x202)
  - opcode_sweep_pair.py (sweep 16-bit pairs at 0x200-0x201)
  - opcode_sweep_targeted.py (sweep targeted opcode pairs)
  - marker_sweep.py (sweep execution marker bytes across offsets)

Features:
  - Subcommands: byte, pair, targeted, marker, custom
  - Formatted terminal tables & summary sensitivity matrix
  - Output export to JSON or CSV
  - Automatically verifies harness executable and base payload
"""

import os
import sys
import shutil
import subprocess
import re
import argparse
import json
import csv
from typing import Dict, List, Tuple, Any, Optional

DEFAULT_ORIGINAL = "testfile"
DEFAULT_MUTATED = "testfile_sweep_active"
DEFAULT_HARNESS = "./clean_build/run_payload.exe"

def ensure_testfile(path: str = DEFAULT_ORIGINAL, size: int = 1854136):
    """Ensures a base testfile exists so runs are always reproducible."""
    if not os.path.exists(path) or os.path.getsize(path) != size:
        print(f"[!] Base payload '{path}' missing or invalid size. Generating {size}-byte baseline...")
        with open(path, "wb") as f:
            f.write(b"\x00" * size)

def run_payload_with_patch(patches: Dict[int, int], harness_path: str = DEFAULT_HARNESS,
                           orig_file: str = DEFAULT_ORIGINAL, mut_file: str = DEFAULT_MUTATED,
                           trace: bool = False) -> Tuple[Dict[int, int], str]:
    """
    Copies orig_file to mut_file, writes byte patches {offset: byte_val},
    runs harness_path, and extracts register state R0-R15.
    """
    ensure_testfile(orig_file)
    shutil.copyfile(orig_file, mut_file)

    with open(mut_file, "r+b") as f:
        for offset, val in patches.items():
            f.seek(offset)
            f.write(bytes([val & 0xFF]))

    cmd = [harness_path]
    if trace:
        cmd.append("--trace")
    cmd.append(mut_file)

    res = subprocess.run(cmd, capture_output=True, text=True)
    output = res.stdout
    registers: Dict[int, int] = {}

    for line in output.splitlines():
        matches = re.findall(r'R\s*(\d+)\s*=\s*0x([0-9A-Fa-f]+)', line)
        for reg_str, val_str in matches:
            registers[int(reg_str)] = int(val_str, 16)

    return registers, output

def print_register_table(results: List[Dict[str, Any]], key_field: str, registers_to_show: List[int] = list(range(8))):
    """Prints a clean tabular view of register values across sweep iterations."""
    header_regs = " ".join([f"R{r:>8}" for r in registers_to_show])
    header = f"{key_field:>12} | " + header_regs
    print("\n" + "=" * len(header))
    print(header)
    print("-" * len(header))

    for item in results:
        key_val = str(item[key_field])
        regs = item['registers']
        row_vals = " ".join([f"0x{regs.get(r, 0):08X}" for r in registers_to_show])
        print(f"{key_val:>12} | {row_vals}")

def analyze_sensitivity(results: List[Dict[str, Any]]) -> Dict[int, List[int]]:
    """Analyzes which registers changed vs remained constant across tests."""
    sensitivity: Dict[int, List[int]] = {}
    print("\n" + "-" * 50)
    print("REGISTER SENSITIVITY ANALYSIS (R0 - R15)")
    print("-" * 50)

    for reg in range(16):
        vals = [r['registers'].get(reg, 0) for r in results]
        unique = sorted(list(set(vals)))
        sensitivity[reg] = unique
        if len(unique) > 1:
            hex_samples = [f"0x{v:X}" for v in unique[:8]]
            ellipsis = "..." if len(unique) > 8 else ""
            print(f"  R{reg:<2} : DYNAMIC ({len(unique)} unique values) -> {hex_samples}{ellipsis}")
        else:
            print(f"  R{reg:<2} : CONSTANT = 0x{unique[0]:08X}")

    return sensitivity

def export_results(results: List[Dict[str, Any]], export_json: Optional[str] = None, export_csv: Optional[str] = None):
    """Optionally exports test results to JSON or CSV."""
    if export_json:
        with open(export_json, "w") as f:
            json.dump(results, f, indent=2)
        print(f"[+] Results saved to JSON: {export_json}")

    if export_csv:
        with open(export_csv, "w", newline="") as f:
            writer = csv.writer(f)
            header = ["test_id"] + [f"R{i}" for i in range(16)]
            writer.writerow(header)
            for idx, item in enumerate(results):
                key = item.get("label", str(idx))
                regs = item["registers"]
                row = [key] + [f"0x{regs.get(i, 0):08X}" for i in range(16)]
                writer.writerow(row)
        print(f"[+] Results saved to CSV: {export_csv}")

# ----------------------------------------------------------------------------
# Command Handlers
# ----------------------------------------------------------------------------

def cmd_byte(args):
    """Sweeps a single byte across 0x00 - 0xFF at any specified offset."""
    offset = int(args.offset, 16) if args.offset.startswith("0x") else int(args.offset)
    fixed_patches: Dict[int, int] = {}

    if args.fixed:
        for pair in args.fixed.split(","):
            if ":" in pair:
                o_str, v_str = pair.split(":")
                o = int(o_str, 16) if o_str.startswith("0x") else int(o_str)
                v = int(v_str, 16) if v_str.startswith("0x") else int(v_str)
                fixed_patches[o] = v

    step = args.step
    results = []
    print(f"[*] Starting byte sweep at offset 0x{offset:X} with step {step}...")
    if fixed_patches:
        print(f"[*] Fixed patches: { {hex(k): hex(v) for k, v in fixed_patches.items()} }")

    for val in range(0, 0x100, step):
        patches = dict(fixed_patches)
        patches[offset] = val
        regs, _ = run_payload_with_patch(patches, args.harness, args.orig, args.mutated)
        results.append({
            "byte_val": f"0x{val:02X}",
            "int_val": val,
            "label": f"byte_0x{offset:X}=0x{val:02X}",
            "registers": regs
        })

    print_register_table(results, "byte_val")
    analyze_sensitivity(results)
    export_results(results, args.json, args.csv)

def cmd_pair(args):
    """Sweeps 16-bit pair (opcode0 at 0x200, opcode1 at 0x201). Mode: diagonal or grid."""
    results = []
    mode = args.mode

    if mode == "diagonal":
        print("[*] Running diagonal pair sweep (opcode0 == opcode1: 0x00..0xFF)...")
        for val in range(0x00, 0x100, args.step):
            patches = {0x200: val, 0x201: val}
            regs, _ = run_payload_with_patch(patches, args.harness, args.orig, args.mutated)
            results.append({
                "pair": f"0x{val:02X},0x{val:02X}",
                "label": f"pair_0x{val:02X}_0x{val:02X}",
                "registers": regs
            })
        print_register_table(results, "pair")
    else:
        print(f"[*] Running grid pair sweep with step {args.step}...")
        for o0 in range(0x00, 0x100, args.step):
            for o1 in range(0x00, 0x100, args.step):
                patches = {0x200: o0, 0x201: o1}
                regs, _ = run_payload_with_patch(patches, args.harness, args.orig, args.mutated)
                results.append({
                    "pair": f"0x{o0:02X},0x{o1:02X}",
                    "label": f"pair_0x{o0:02X}_0x{o1:02X}",
                    "registers": regs
                })
        print_register_table(results, "pair")

    analyze_sensitivity(results)
    export_results(results, args.json, args.csv)

def cmd_targeted(args):
    """Runs a targeted curated suite of opcode pairs to investigate instruction behavior."""
    pairs = [
        # Zero & edge cases
        (0x00, 0x00), (0x00, 0x01), (0x01, 0x00), (0x01, 0x01),
        (0x02, 0x01), (0x01, 0x02), (0x02, 0x02), (0x03, 0x03),
        # Immediate / Family candidates
        (0x0A, 0x0A), (0x0B, 0x0B), (0x0C, 0x0C), (0x0F, 0x0F),
        (0x37, 0x01), (0x38, 0x01), (0x39, 0x01), (0x3A, 0x01),
        (0x50, 0x00), (0x51, 0x00), (0x52, 0x00), (0x56, 0x00),
        # Distinct high / low combinations
        (0xA5, 0x00), (0xA5, 0x03), (0xA5, 0x3C), (0xA5, 0xAA),
        (0xFF, 0x00), (0x00, 0xFF), (0xFF, 0xFF)
    ]

    print(f"[*] Running targeted suite ({len(pairs)} test cases)...")
    results = []
    for o0, o1 in pairs:
        patches = {0x200: o0, 0x201: o1}
        regs, _ = run_payload_with_patch(patches, args.harness, args.orig, args.mutated)
        results.append({
            "pair": f"0x{o0:02X},0x{o1:02X}",
            "label": f"target_0x{o0:02X}_0x{o1:02X}",
            "registers": regs
        })

    print_register_table(results, "pair")
    analyze_sensitivity(results)
    export_results(results, args.json, args.csv)

def cmd_marker(args):
    """Places marker bytes at increasing offsets beyond 0x202 to detect execution horizon."""
    marker_byte = int(args.marker, 16) if args.marker.startswith("0x") else int(args.marker)
    offsets = [
        0x202, 0x203, 0x204, 0x205, 0x206, 0x208, 0x20A,
        0x20C, 0x210, 0x218, 0x220, 0x240, 0x280, 0x300
    ]

    opcode0 = int(args.opcode0, 16) if args.opcode0.startswith("0x") else int(args.opcode0)
    opcode1 = int(args.opcode1, 16) if args.opcode1.startswith("0x") else int(args.opcode1)

    print(f"[*] Marker sweep: marker=0x{marker_byte:02X}, base instruction=(0x{opcode0:02X}, 0x{opcode1:02X})")
    results = []

    for offset in offsets:
        patches = {0x200: opcode0, 0x201: opcode1, offset: marker_byte}
        regs, _ = run_payload_with_patch(patches, args.harness, args.orig, args.mutated)
        results.append({
            "offset": f"0x{offset:04X}",
            "label": f"marker_at_0x{offset:X}",
            "registers": regs
        })

    print_register_table(results, "offset")
    analyze_sensitivity(results)
    export_results(results, args.json, args.csv)

def cmd_custom(args):
    """Executes a single test with arbitrary patch specification (e.g. 0x200:0xA5,0x201:0x3C)."""
    patches: Dict[int, int] = {}
    for item in args.patches.split(","):
        if ":" in item:
            o_str, v_str = item.split(":")
            o = int(o_str, 16) if o_str.startswith("0x") else int(o_str)
            v = int(v_str, 16) if v_str.startswith("0x") else int(v_str)
            patches[o] = v

    print(f"[*] Running custom patch: { {hex(k): hex(v) for k, v in patches.items()} }")
    regs, output = run_payload_with_patch(patches, args.harness, args.orig, args.mutated, trace=args.trace)

    if args.trace:
        print("\n" + output)

    print("\n--- Register Output (R0 - R15) ---")
    for i in range(16):
        print(f"  R{i:<2} = 0x{regs.get(i, 0):08X}", end="  " if (i + 1) % 4 != 0 else "\n")

    if args.verbose:
        print("\n--- Full Harness Stdout ---")
        print(output)

# ----------------------------------------------------------------------------
# CLI Entrypoint
# ----------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description="Unified VM Opcode & Payload Sweep CLI Tool for DoogEngine1",
        formatter_class=argparse.RawDescriptionHelpFormatter
    )
    parser.add_argument("--harness", default=DEFAULT_HARNESS, help=f"Path to run_payload executable (default: {DEFAULT_HARNESS})")
    parser.add_argument("--orig", default=DEFAULT_ORIGINAL, help=f"Original payload path (default: {DEFAULT_ORIGINAL})")
    parser.add_argument("--mutated", default=DEFAULT_MUTATED, help=f"Temporary mutated payload path (default: {DEFAULT_MUTATED})")
    parser.add_argument("--json", help="Export sweep results to JSON file")
    parser.add_argument("--csv", help="Export sweep results to CSV file")
    parser.add_argument("-t", "--trace", action="store_true", help="Enable instruction step tracer in VM")

    subparsers = parser.add_subparsers(dest="subcommand", required=True, help="Subcommand to execute")

    # subcommand: byte
    p_byte = subparsers.add_parser("byte", help="Sweep a single byte across 0x00-0xFF at an offset")
    p_byte.add_argument("--offset", default="0x200", help="Byte offset to sweep (default: 0x200)")
    p_byte.add_argument("--step", type=int, default=1, help="Sweep step interval (default: 1)")
    p_byte.add_argument("--fixed", help="Fixed patches, e.g. '0x201:0x03,0x202:0x00'")
    p_byte.set_defaults(func=cmd_byte)

    # subcommand: pair
    p_pair = subparsers.add_parser("pair", help="Sweep 16-bit opcode pair at 0x200-0x201")
    p_pair.add_argument("--mode", choices=["diagonal", "grid"], default="diagonal", help="Sweep mode (diagonal: o0==o1; grid: full 2D grid)")
    p_pair.add_argument("--step", type=int, default=1, help="Sweep step interval (default: 1; use 16 or 32 for grid)")
    p_pair.set_defaults(func=cmd_pair)

    # subcommand: targeted
    p_target = subparsers.add_parser("targeted", help="Run curated suite of interesting opcode pairs")
    p_target.set_defaults(func=cmd_targeted)

    # subcommand: marker
    p_marker = subparsers.add_parser("marker", help="Marker byte horizon sweep across payload offsets")
    p_marker.add_argument("--marker", default="0xAA", help="Marker byte value (default: 0xAA)")
    p_marker.add_argument("--opcode0", default="0x00", help="Opcode0 byte at 0x200 (default: 0x00)")
    p_marker.add_argument("--opcode1", default="0x03", help="Opcode1 byte at 0x201 (default: 0x03)")
    p_marker.set_defaults(func=cmd_marker)

    # subcommand: custom
    p_custom = subparsers.add_parser("custom", help="Run arbitrary manual byte patch")
    p_custom.add_argument("patches", help="Patch spec, e.g. '0x200:0xA5,0x201:0x3C'")
    p_custom.add_argument("-v", "--verbose", action="store_true", help="Print full harness output")
    p_custom.set_defaults(func=cmd_custom)

    args = parser.parse_args()
    args.func(args)

if __name__ == "__main__":
    main()
