#!/usr/bin/env python3
import os
import re
import json
from pathlib import Path

DOT_DIR = "./specs_output"  # Path to your .dot files folder
OUTPUT_FILE = "top_10_priority.json"

# Heuristic Weighting Multipliers
WEIGHT_LOOP = 25       # Strongly prioritize loops/cycles
WEIGHT_INDIRECT = 20   # Dynamic calls/jumps (dispatchers)
WEIGHT_STATE = 15      # VM context/register writes
WEIGHT_MEMORY = 5      # Raw memory loads/stores

def score_dot_file(filepath):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    # 1. Detect Loops (Back-edges / self-references in graph syntax)
    # Counts reverse edge patterns like "NodeA -> NodeB" where NodeB was declared earlier
    edges = re.findall(r'(\w+)\s*->\s*(\w+)', content)
    nodes_seen = set()
    loop_count = 0
    for src, dst in edges:
        if dst in nodes_seen or src == dst:
            loop_count += 1
        nodes_seen.add(src)

    # 2. Detect Indirect Calls / Jumps (e.g., call rax, jmp [r32 + offset])
    indirect_calls = len(re.findall(r'(call|jmp)\s*\[|\*(eax|ebx|ecx|edx|rax|rbx|rcx|rdx|r\d+)', content, re.IGNORECASE))

    # 3. Detect VM State Writes (References to vm, registers, stack, pc, or struct offsets)
    state_writes = len(re.findall(r'(registers|stack|sp|pc|ctx|vm_context|r\d+)\b', content, re.IGNORECASE))

    # 4. Detect General Memory Accesses (Pointer derefs, mov [ptr])
    memory_accesses = len(re.findall(r'(\[|\*|PTR|load|store)', content, re.IGNORECASE))

    # Compute Final Weighted Score
    total_score = (
        (loop_count * WEIGHT_LOOP) +
        (indirect_calls * WEIGHT_INDIRECT) +
        (state_writes * WEIGHT_STATE) +
        (memory_accesses * WEIGHT_MEMORY)
    )

    return {
        "file": filepath.name,
        "func_name": filepath.stem,
        "score": total_score,
        "metrics": {
            "loops": loop_count,
            "indirect_calls": indirect_calls,
            "state_writes": state_writes,
            "memory_accesses": memory_accesses
        }
    }

def main():
    dot_path = Path(DOT_DIR)
    if not dot_path.exists():
        print(f"[!] Directory {DOT_DIR} not found.")
        return

    results = []
    for dot_file in dot_path.glob("*.dot"):
        results.append(score_dot_file(dot_file))

    # Sort descending by score
    results.sort(key=lambda x: x["score"], reverse=True)
    top_10 = results[:10]

    print("==================================================")
    print("       TOP 10 HIGH-VALUE KERNEL FUNCTIONS         ")
    print("==================================================")
    for idx, item in enumerate(top_10, 1):
        m = item["metrics"]
        print(f"{idx:2d}. {item['func_name']:<20} | Score: {item['score']:<5} | "
              f"Loops: {m['loops']} | IndCalls: {m['indirect_calls']} | StateWrites: {m['state_writes']}")
    print("==================================================")

    with open(OUTPUT_FILE, "w") as f:
        json.dump(top_10, f, indent=2)
    print(f"[+] Saved top 10 specs to {OUTPUT_FILE}")

if __name__ == "__main__":
    main()