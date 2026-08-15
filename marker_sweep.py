#!/usr/bin/env python3
"""
Marker Sweep Experiment
Places a unique marker byte at various offsets in the payload.
Tests if the VM ever reads beyond offset 0x202 (the 2-byte instruction).
If a marker byte affects any register, the VM executed enough instructions to reach that offset.

Strategy:
  - Keep opcode0=0x00, opcode1=0x03 (NOP/INIT) at 0x200-0x201
  - Place marker 0xAA at offset 0x200 + 2*N for N=1..20
  - If marker is read, it will appear in some register (likely R5-R15)
  - Binary search to find the furthest offset the VM reads
"""

import subprocess
import shutil
import re

ORIGINAL = "testfile"
MUTATED = "testfile_marker"
MARKER = 0xAA

# Test offsets: 0x204, 0x206, 0x208, 0x20A, 0x20C, 0x20E, 0x210, 0x214, 0x218, 0x220
TEST_OFFSETS = [0x204, 0x206, 0x208, 0x20A, 0x20C, 0x20E, 0x210, 0x214, 0x218, 0x220, 0x230, 0x250, 0x280, 0x300]

def run_with_marker(offset, marker_byte):
    """Place marker at offset and run payload. Returns register dict."""
    shutil.copyfile(ORIGINAL, MUTATED)
    
    with open(MUTATED, "r+b") as f:
        f.seek(offset)
        f.write(bytes([marker_byte]))
    
    result = subprocess.run(
        ["./clean_build/run_payload.exe", MUTATED],
        capture_output=True, text=True
    )
    
    output = result.stdout
    registers = {}
    
    # Parse FIRST execution only
    first_exec = output.split("2. MUTATED")[0] if "2. MUTATED" in output else output
    
    for line in first_exec.split('\n'):
        matches = re.findall(r'R\s*(\d+)\s*=\s*0x([0-9A-Fa-f]+)', line)
        for match in matches:
            reg_num = int(match[0])
            reg_val = int(match[1], 16)
            registers[reg_num] = reg_val
    
    return registers, output

def main():
    print("="*70)
    print("MARKER SWEEP EXPERIMENT")
    print("="*70)
    print("\nBase instruction: opcode0=0x00, opcode1=0x03 at offset 0x200")
    print(f"Marker byte: 0x{MARKER:02X}")
    print(f"Testing offsets: {[hex(o) for o in TEST_OFFSETS]}")
    print()
    
    results = []
    
    for offset in TEST_OFFSETS:
        registers, output = run_with_marker(offset, MARKER)
        
        # Check if marker appears in any register
        marker_found = False
        for reg in range(16):
            val = registers.get(reg, 0)
            # Check if marker byte is part of the register value
            if (val & 0xFF) == MARKER or ((val >> 8) & 0xFF) == MARKER or \
               ((val >> 16) & 0xFF) == MARKER or ((val >> 24) & 0xFF) == MARKER:
                marker_found = True
                print(f"[!] OFFSET {hex(offset)}: MARKER 0x{MARKER:02X} DETECTED in R{reg}=0x{val:08X}")
        
        if not marker_found:
            print(f"[.] OFFSET {hex(offset)}: No marker detected (VM didn't reach this offset)")
        
        results.append({
            'offset': offset,
            'registers': registers,
            'marker_found': marker_found
        })
    
    # Summary
    print("\n" + "="*70)
    print("SUMMARY")
    print("="*70)
    
    reached_offsets = [r['offset'] for r in results if r['marker_found']]
    not_reached = [r['offset'] for r in results if not r['marker_found']]
    
    if reached_offsets:
        max_reached = max(reached_offsets)
        min_reached = min(reached_offsets)
        print(f"VM reached offsets: {[hex(o) for o in reached_offsets]}")
        print(f"Max offset reached: {hex(max_reached)}")
        print(f"Min offset reached: {hex(min_reached)}")
        
        # Estimate instruction count (2 bytes per instruction)
        # Instruction at 0x200 = instruction 0
        # Instruction at 0x202 = instruction 1
        # Instruction at 0x204 = instruction 2
        estimated_instructions = (max_reached - 0x200) // 2 + 1
        print(f"Estimated minimum instructions executed: {estimated_instructions}")
    else:
        print("VM did NOT reach any test offset beyond the base instruction.")
        print("The VM executes exactly 1 instruction (the NOP at 0x200).")
    
    if not_reached:
        print(f"VM did NOT reach offsets: {[hex(o) for o in not_reached]}")

if __name__ == "__main__":
    main()
