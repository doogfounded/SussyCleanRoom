# DoogEngine1 Master Project Index & Reference Guide for LLMs

Welcome to the **DoogEngine1 Clean-Room C++ State Engine Builder** repository. This document serves as an authoritative reference index for AI subagents, LLMs, and human pair-programmers working on this codebase.

---

## 1. Project Mission & Identity

* **Objective:** Translate abstract Control Flow Graphs (`.dot`) and execution plan manifests (`.json`) into production-ready, standard **C++20** code in `namespace DoogEngine1`.
* **Current Status:** **150 Steps Fully Compiled, Linked, and Empirically Verified**.
* **Compilation Warning Count:** **0 Warnings, 0 Errors**.
* **Master Test Harness Status:** **PASSED (100%)**.

---

## 2. Absolute Legal & Operational Rules

1. **Abstract Spec Only:** Rely ENTIRELY on text-based `.dot` state graphs and `.json` schema manifests located in `./specs_output/`.
2. **Zero Feature Invention:** Do not invent unlisted state branches or external APIs. Implement only what is topologically defined in the graphs.
3. **No Direct Binary Inspection:** Strictly forbidden from running disassemblers (Ghidra, IDA, objdump, gdb) or reading raw binary executables for reverse engineering.
4. **Self-Healing Loop (Max 3 Attempts):** Compile and test each function (`g++ -std=c++20 -I./clean_src -c ./clean_src/<func>.cpp -o ./clean_build/<func>.o`). Retry up to 3 times before HARD STOP.
5. **CRT Noise Purge Rule:** Bypass CRT wrappers (`_nolock`, `guard_check`, `ptd`, `_alloca`, `__calloc`, `__fileno`, `operator_new`) as MSVC compiler noise.

---

## 3. Directory Layout & File Map

```txt
d:/Desktop/cool/doog1/
├── clean_src/                       # Production C++20 Clean-Room Source Files
│   ├── clean_symbols.h              # Master header containing all 150 compiled function signatures
│   ├── vm_context.h                 # VMContext lightweight state container struct
│   ├── vm_dispatch_template.h       # Generic state-machine outer dispatch loop template
│   ├── vm_kernel.h / vm_kernel.cpp  # C++20 Opcode Execution Engine (Python refophan.py translated)
│   ├── ExecuteBytecodeKernel.cpp    # 87-State Bytecode Execution Kernel (7 Opcode Families)
│   ├── test_harness.cpp             # Master test harness verifying steps 1-150 + VM kernel
│   ├── test_vm_kernel.cpp           # Standalone VM kernel unit test suite
│   ├── test_refophan.cpp            # Python reference verification test runner (Matches hash 10)
│   ├── run_payload.cpp              # Real payload execution harness (1.85 MB testfile runner)
│   ├── progress.json                # Structured JSON progress state tracker
│   └── FUN_*.h / FUN_*.cpp          # 150 Compiled step headers and implementations
├── clean_build/                     # Compiled C++20 object files (.o) and test executables (.exe)
│   ├── test_harness.exe             # Master verification binary
│   ├── test_vm_kernel.exe           # VM Kernel test binary
│   ├── test_refophan.exe            # Python reference comparison binary
│   └── run_payload.exe              # Payload file test execution binary
├── specs_output/                    # Text-based specs and sorted execution plan
│   ├── sorted_execution_plan.json   # 1000+ step topological execution plan
│   └── FUN_*.dot                    # Directed Graphviz Control Flow Graphs
├── progress.json                    # Root workspace JSON progress tracker
├── mutate_and_run.py                # Automated byte mutation test tool
├── testfile                         # 1.85 MB production payload file
├── machine_specification_draft.md   # Machine specification draft (Fact vs. Hypothesis)
└── opcode_specification_table.md   # Reference table for all 87 states / 7 Opcode Families
```

---

## 4. Key Architectural Discoveries & Confirmed Facts

| Architecture Element | Confirmed Fact / Status | Reference Implementation |
| :--- | :--- | :--- |
| **Magic Signature Tag** | Evaluates `"0x1QRH"` magic tag | [`FUN_1033f53a.cpp`](file:///d:/Desktop/cool/doog1/clean_src/FUN_1033f53a.cpp) |
| **Apex Root Node** | Step 55 entry point for entire state engine | [`FUN_1033cd98.cpp`](file:///d:/Desktop/cool/doog1/clean_src/FUN_1033cd98.cpp) |
| **3-Phase Context Pipeline** | Phase 1 (Layout Calc) $\to$ Phase 2 (Alloc) $\to$ Phase 3 (Exec) | [`FUN_10342ebe.cpp`](file:///d:/Desktop/cool/doog1/clean_src/FUN_10342ebe.cpp) |
| **Two-Pass Execution Cycle** | `FUN_10331850` executes Pass 1 layout & Pass 2 execution | [`FUN_10331850.cpp`](file:///d:/Desktop/cool/doog1/clean_src/FUN_10331850.cpp) |
| **87-State Bytecode Kernel** | 87 basic blocks refactored into 7 Opcode Families | [`ExecuteBytecodeKernel.cpp`](file:///d:/Desktop/cool/doog1/clean_src/ExecuteBytecodeKernel.cpp) |
| **Host Export Shim Range** | 18 `0x10001xxx` shims refactored under **Option A** | `FUN_100016a0` .. `FUN_10001bc0` |
| **Thread Sync Locks** | 3 Mutex Lock primitives (`FUN_102d1580`, `FUN_102db5a0`, `FUN_102e18a0`) | Step 125, Steps 134-135, Step 149 |
| **Instruction Decoding** | **Little-Endian 16-Bit Word Decoding** (`(Byte[1]<<8)\|Byte[0]`) | Verified in `run_payload.exe` trace |

---

## 5. Core Documentation Artifacts for LLMs

* 📄 **[machine_specification_draft.md](file:///d:/Desktop/cool/doog1/clean_src/machine_specification_draft.md)**: Formal C++ VM Specification separating confirmed facts from working hypotheses.
* 📄 **[opcode_specification_table.md](file:///d:/Desktop/cool/doog1/clean_src/opcode_specification_table.md)**: Master reference table mapping all 87 VM states across 7 Opcode Families.
* 📄 **[state_engine_architecture_summary.md](file:///C:/Users/Doug/.gemini/antigravity-ide/brain/1b566184-b2d9-405e-ac58-d1b4a2943df4/state_engine_architecture_summary.md)**: Control flow diagram & subsystem node classification.
* 📄 **[state_engine_data_flow_analysis.md](file:///C:/Users/Doug/.gemini/antigravity-ide/brain/1b566184-b2d9-405e-ac58-d1b4a2943df4/state_engine_data_flow_analysis.md)**: Data matrix table and memory arena offset reconstructions.
* 📄 **[progress.json](file:///d:/Desktop/cool/doog1/progress.json)**: Machine-readable progress file tracking current completed steps.

---

## 6. Build & Execution Commands

### Compile a New Function Step:
```bash
g++ -std=c++20 -I./clean_src -c ./clean_src/<func>.cpp -o ./clean_build/<func>.o
```

### Re-Link and Run Master Test Harness:
```bash
g++ -std=c++20 -I./clean_src ./clean_build/*.o ./clean_src/test_harness.cpp -o ./clean_build/test_harness.exe
./clean_build/test_harness.exe
```

### Run Python Reference Verification Test:
```bash
g++ -std=c++20 -I./clean_src ./clean_build/vm_kernel.o ./clean_src/test_refophan.cpp -o ./clean_build/test_refophan.exe
./clean_build/test_refophan.exe
```

### Run Payload File Execution Harness:
```bash
./clean_build/run_payload.exe testfile
```

### Mutate Payload Bytes & Test:
```bash
python mutate_and_run.py <offset> <hex_bytes>
```
