#!/usr/bin/env python3
"""
Targeted Opcode Pair Sweep — Focus on R5-R15 activation.
Tests specific pairs that might trigger actual instruction execution.
"""

import subprocess
import shutil
import re

ORIGINAL = "testfile"
MUTATED = "testfile_sweep_t"

def run_test(o0, o1):
    shutil.copyfile(ORIGINAL, MUTATED)
    with open(MUTATED, "r+b") as f:
        f.seek(0x200)
        f.write(bytes([o0, o1]))
    
    result = subprocess.run(
        ["./clean_build/run_payload.exe", MUTATED],
        capture_output=True, text=True
    )
    
    output = result.stdout
    registers = {}
    
    first_exec = output.split("2. MUTATED")[0] if "2. MUTATED" in output else output
    
    for line in first_exec.split('\n'):
        matches = re.findall(r'R\s*(\d+)\s*=\s*0x([0-9A-Fa-f]+)', line)
        for match in matches:
            reg_num = int(match[0])
            reg_val = int(match[1], 16)
            registers[reg_num] = reg_val
    
    return registers

def main():
    # Test pairs: (opcode0, opcode1)
    # Focus on pairs where both bytes are non-zero and different
    pairs = [
        # Small non-zero pairs
        (0x01, 0x00), (0x00, 0x01), (0x01, 0x01), (0x01, 0x02), (0x02, 0x01),
        (0x02, 0x02), (0x03, 0x03), (0x04, 0x04), (0x05, 0x05),
        (0x0A, 0x0A), (0x0F, 0x0F), (0x10, 0x10), (0x20, 0x20),
        (0x30, 0x30), (0x40, 0x40), (0x50, 0x50), (0x60, 0x60),
        (0x80, 0x80), (0xFF, 0xFF),
        # Cross pairs
        (0x01, 0x03), (0x03, 0x01), (0x02, 0x03), (0x03, 0x02),
        (0x04, 0x03), (0x03, 0x04), (0x05, 0x03), (0x03, 0x05),
        (0x10, 0x03), (0x03, 0x10), (0x20, 0x03), (0x03, 0x20),
        (0x40, 0x03), (0x03, 0x40), (0x80, 0x03), (0x03, 0x80),
        # High byte varied, low byte fixed
        (0x00, 0x01), (0x00, 0x02), (0x00, 0x04), (0x00, 0x08),
        (0x00, 0x10), (0x00, 0x20), (0x00, 0x40), (0x00, 0x80),
        (0x01, 0x02), (0x01, 0x04), (0x01, 0x08), (0x01, 0x10),
        (0x01, 0x20), (0x01, 0x40), (0x01, 0x80),
        (0x02, 0x04), (0x02, 0x08), (0x02, 0x10), (0x02, 0x20),
        (0x02, 0x40), (0x02, 0x80),
    ]
    
    print(f"Testing {len(pairs)} targeted opcode pairs...")
    
    results = []
    for o0, o1 in pairs:
        regs = run_test(o0, o1)
        results.append({'o0': o0, 'o1': o1, 'regs': regs})
        print(f"  (0x{o0:02X},0x{o1:02X}): R0=0x{regs.get(0,0):08X} R1=0x{regs.get(1,0):08X} R2=0x{regs.get(2,0):08X} R3=0x{regs.get(3,0):08X} R4=0x{regs.get(4,0):08X} R5=0x{regs.get(5,0):08X}")
    
    # Summary
    print("\n" + "="*70)
    print("TARGETED PAIR SWEEP SUMMARY")
    print("="*70)
    
    # Show all registers for each pair
    print("\n--- Full Register Matrix ---")
    header = "Pair     | " + " ".join([f"R{i:>8}" for i in range(16)])
    print(header)
    print("-" * len(header))
    
    for r in results:
        o0, o1 = r['o0'], r['o1']
        regs = r['regs']
        row = f"(0x{o0:02X},0x{o1:02X}) | " + " ".join([f"0x{regs.get(i, 0):06X}" for i in range(16)])
        print(row)
    
    # R5-R15 activation
    print("\n--- R5-R15 Activation ---")
    activated = []
    for r in results:
        o0, o1 = r['o0'], r['o1']
        regs = r['regs']
        non_zero = [i for i in range(5, 16) if regs.get(i, 0) != 0]
        if non_zero:
            details = ", ".join([f"R{i}={hex(regs[i])}" for i in non_zero])
            activated.append((o0, o1, details))
            print(f"  (0x{o0:02X},0x{o1:02X}): {details}")
    
    if not activated:
        print("  No R5-R15 activation found in any pair.")
    
    # Register sensitivity
    print("\n--- Register Sensitivity ---")
    for reg in range(16):
        values = [r['regs'].get(reg, 0) for r in results]
        unique = sorted(set(values))
        if len(unique) > 1:
            print(f"  R{reg}: CHANGES ({len(unique)} unique: {[hex(v) for v in unique[:20]]})")
        else:
            print(f"  R{reg}: CONSTANT = 0x{values[0]:08X}")

if __name__ == "__main__":
    main()
