#!/usr/bin/env python3
"""
Systematic Opcode2 Sweep Experiment
Keeps opcode0=0x00, opcode1=0x03 fixed. Sweeps opcode2 across 0x00-0xFF.
Tests whether R5-R15 become sensitive to higher payload bytes.
Captures final register matrix from run_payload.exe output.
"""

import subprocess
import shutil
import re

ORIGINAL = "testfile"
MUTATED = "testfile_sweep2"

def sweep_opcode2():
    results = []
    
    for opcode2 in range(0x00, 0x100):
        # Copy original
        shutil.copyfile(ORIGINAL, MUTATED)
        
        # Patch byte at 0x202 (keep 0x200=0x00, 0x201=0x03)
        with open(MUTATED, "r+b") as f:
            f.seek(0x202)
            f.write(bytes([opcode2]))
        
        # Run payload harness
        result = subprocess.run(
            ["./clean_build/run_payload.exe", MUTATED],
            capture_output=True, text=True
        )
        
        # Extract register matrix from output
        output = result.stdout
        registers = {}
        
        # Only parse the FIRST execution
        first_exec = output.split("2. MUTATED")[0] if "2. MUTATED" in output else output
        
        # Parse R0-R15 lines (4 registers per line)
        for line in first_exec.split('\n'):
            matches = re.findall(r'R\s*(\d+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            for match in matches:
                reg_num = int(match[0])
                reg_val = int(match[1], 16)
                registers[reg_num] = reg_val
        
        results.append({
            'opcode2': opcode2,
            'registers': registers,
            'raw_output': output
        })
        
        print(f"[+] Tested opcode2=0x{opcode2:02X}, captured {len(registers)} registers")
    
    return results

def analyze_results(results):
    print("\n" + "="*70)
    print("OPCODE2 SWEEP ANALYSIS (opcode0=0x00, opcode1=0x03 fixed)")
    print("="*70)
    
    # Show R0-R7 final values for each opcode2
    print("\n--- Final Register Values by Opcode2 ---")
    header = "opcode2 | " + " ".join([f"R{i:>8}" for i in range(8)])
    print(header)
    print("-" * len(header))
    
    for r in results:
        opcode2 = r['opcode2']
        regs = r['registers']
        row = f"  0x{opcode2:02X}  | " + " ".join([f"0x{regs.get(i, 0):06X}" for i in range(8)])
        print(row)
    
    # Detect which registers change with opcode2
    print("\n--- Register Sensitivity to Opcode2 ---")
    for reg in range(16):
        values = [r['registers'].get(reg, 0) for r in results]
        if len(set(values)) > 1:
            unique = sorted(set(values))[:30]  # Show first 30 unique values
            print(f"  R{reg}: CHANGES across sweep ({len(unique)} unique values, first 30: {[hex(v) for v in unique]})")
        else:
            print(f"  R{reg}: CONSTANT = 0x{values[0]:08X}")
    
    # Look for patterns
    print("\n--- Pattern Detection ---")
    for r in results:
        opcode2 = r['opcode2']
        regs = r['registers']
        for reg in range(16):
            val = regs.get(reg, 0)
            if val == opcode2:
                print(f"  R{reg} = opcode2 (0x{opcode2:02X}) when opcode2=0x{opcode2:02X}")
            if val == (opcode2 ^ 0x5A) & 0xFF:
                print(f"  R{reg} = opcode2 ^ 0x5A when opcode2=0x{opcode2:02X}")
            if val == (opcode2 ^ 0x3C) & 0xFF:
                print(f"  R{reg} = opcode2 ^ 0x3C when opcode2=0x{opcode2:02X}")

if __name__ == "__main__":
    print("Starting systematic opcode2 sweep (0x00-0xFF at offset 0x202, opcode0=0x00, opcode1=0x03)...")
    results = sweep_opcode2()
    analyze_results(results)
    print("\n[+] Sweep complete. Results above.")
