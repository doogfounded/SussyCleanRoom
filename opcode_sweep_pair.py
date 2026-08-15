#!/usr/bin/env python3
"""
16-Bit Opcode Pair Sweep Experiment
Sweeps opcode0 (0x200) and opcode1 (0x201) as a 16-bit pair.
Tests 256 pairs: (0x00,0x00), (0x01,0x01), ..., (0xFF,0xFF) — diagonal sweep.
Also tests a few targeted pairs known to be "interesting".
Captures full 16-register matrix from run_payload.exe output.
"""

import subprocess
import shutil
import re

ORIGINAL = "testfile"
MUTATED = "testfile_sweep_pair"

def sweep_pairs():
    results = []
    
    # Diagonal sweep: opcode0 == opcode1
    for val in range(0x00, 0x100):
        shutil.copyfile(ORIGINAL, MUTATED)
        
        with open(MUTATED, "r+b") as f:
            f.seek(0x200)
            f.write(bytes([val, val]))  # opcode0=val, opcode1=val
        
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
        
        results.append({
            'opcode0': val,
            'opcode1': val,
            'registers': registers,
            'raw_output': output
        })
        
        print(f"[+] Tested (0x{val:02X},0x{val:02X}), captured {len(registers)} registers")
    
    # Targeted pairs: small non-zero values for both bytes
    targets = [
        (0x01, 0x00), (0x00, 0x01), (0x01, 0x01), (0x01, 0x02),
        (0x02, 0x01), (0x02, 0x02), (0x03, 0x03), (0x04, 0x04),
        (0x05, 0x05), (0x0A, 0x0A), (0x0F, 0x0F),
        (0x10, 0x10), (0x20, 0x20), (0x30, 0x30),
        (0x40, 0x40), (0x50, 0x50), (0x60, 0x60),
        (0x80, 0x80), (0xFF, 0xFF),
    ]
    
    for o0, o1 in targets:
        # Skip if already done in diagonal sweep
        if o0 == o1:
            continue
        
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
        
        results.append({
            'opcode0': o0,
            'opcode1': o1,
            'registers': registers,
            'raw_output': output
        })
        
        print(f"[+] Tested (0x{o0:02X},0x{o1:02X}), captured {len(registers)} registers")
    
    return results

def analyze_results(results):
    print("\n" + "="*70)
    print("16-BIT OPCODE PAIR SWEEP ANALYSIS")
    print("="*70)
    
    # Show R0-R7 for each pair
    print("\n--- Final Register Values by Opcode Pair ---")
    header = "opcode0 | opcode1 | " + " ".join([f"R{i:>8}" for i in range(8)])
    print(header)
    print("-" * len(header))
    
    for r in results:
        o0, o1 = r['opcode0'], r['opcode1']
        regs = r['registers']
        row = f"  0x{o0:02X}    |  0x{o1:02X}    | " + " ".join([f"0x{regs.get(i, 0):06X}" for i in range(8)])
        print(row)
    
    # Detect which registers change across pairs
    print("\n--- Register Sensitivity to Opcode Pairs ---")
    for reg in range(16):
        values = [r['registers'].get(reg, 0) for r in results]
        unique = sorted(set(values))
        if len(unique) > 1:
            print(f"  R{reg}: CHANGES ({len(unique)} unique values, first 30: {[hex(v) for v in unique[:30]]})")
        else:
            print(f"  R{reg}: CONSTANT = 0x{values[0]:08X}")
    
    # Check for R5-R15 activation
    print("\n--- R5-R15 Activation Check ---")
    for r in results:
        o0, o1 = r['opcode0'], r['opcode1']
        regs = r['registers']
        non_zero = [i for i in range(5, 16) if regs.get(i, 0) != 0]
        if non_zero:
            details = ", ".join([f"R{i}={hex(regs[i])}" for i in non_zero])
            print(f"  (0x{o0:02X},0x{o1:02X}): {details}")
    
    # Pattern detection
    print("\n--- Pattern Detection ---")
    for r in results:
        o0, o1 = r['opcode0'], r['opcode1']
        regs = r['registers']
        for reg in range(16):
            val = regs.get(reg, 0)
            if val == o0:
                print(f"  R{reg} = opcode0 (0x{o0:02X})")
            if val == o1:
                print(f"  R{reg} = opcode1 (0x{o1:02X})")
            if val == (o0 ^ 0x5A) & 0xFF:
                print(f"  R{reg} = opcode0 ^ 0x5A")
            if val == (o1 ^ 0x3C) & 0xFF:
                print(f"  R{reg} = opcode1 ^ 0x3C")
            if val == (o1 << 8) | o0:
                print(f"  R{reg} = (opcode1<<8)|opcode0 = 0x{(o1<<8)|o0:04X}")

if __name__ == "__main__":
    print("Starting 16-bit opcode pair sweep (diagonal + targeted pairs)...")
    results = sweep_pairs()
    analyze_results(results)
    print("\n[+] Sweep complete. Results above.")
