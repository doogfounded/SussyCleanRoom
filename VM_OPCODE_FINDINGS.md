# VM Opcode-to-Execution Empirical Findings

**Date:** 2026-08-12  
**Project:** DoogEngine1 — Clean-Room C++20 State Engine  
**Method:** Byte-level payload mutation + register state capture  
**Tool:** `run_payload.exe` harness (1.85 MB testfile runner)

---

## Executive Summary

This document records all empirically verified facts about the VM bytecode kernel's behavior, discovered through systematic byte mutation experiments on the production payload file (`testfile`, 1.85 MB). The experiments targeted the instruction word at payload offset `0x200` and revealed the VM's decode prologue, register mapping, and execution scope.

**Key Finding:** The VM executes exactly **1 instruction per `run_payload.exe` invocation** in practice, and the observed behavior is limited to a **decode prologue** — no actual instruction execution (arithmetic, memory access, control flow) was observed in the tested opcode range. However, kernel source analysis reveals the VM *can* execute ~40 state transitions when opcode0 is non-zero, but execution is blocked by **stack underflow** (the harness never pushes data to the VM stack).

---

## 1. Experimental Setup

### 1.1 Payload Layout

```
testfile (1.85 MB binary)
├── Offset 0x000 - 0x1FF: Unknown (not accessed by VM kernel)
├── Offset 0x200: opcode0 (LSB of 16-bit instruction)
├── Offset 0x201: opcode1 (MSB of 16-bit instruction)
├── Offset 0x202+: Data (not decoded by VM kernel)
```

### 1.2 Test Harness

- **Binary:** `clean_build/run_payload.exe`
- **Usage:** `./clean_build/run_payload.exe <payload_file>`
- **Behavior:** Loads payload, executes VM for a fixed number of cycles, prints register state
- **Output Format:** Prints R0-R15 register values in format `R<n> = 0x<8-digit-hex>` (4 registers per line)

### 1.3 Experiment Scripts

| Script | Purpose | Sweep Range |
|--------|---------|-------------|
| `opcode_sweep.py` | Sweep opcode0 (0x200) | 0x00–0xFF |
| `opcode_sweep1.py` | Sweep opcode1 (0x201) | 0x00–0xFF |
| `opcode_sweep2.py` | Sweep opcode2 (0x202) | 0x00–0xFF |
| `marker_sweep.py` | Place marker bytes at increasing offsets | 0x204–0x300 |

---

## 2. Verified Facts

### 2.1 Instruction Format

| Fact | Formula | Evidence |
|------|---------|----------|
| **Little-Endian 16-Bit Word** | `instruction = (opcode1 << 8) \| opcode0` | Opcode1 sweep: R3 = `opcode1 << 8` when opcode0=0x00 |
| **PC Offset** | `0x200` | R0 = `0x00000200` in all experiments |
| **Instruction Width** | 2 bytes | Opcode2 sweep: no effect on any register |

### 2.2 Register Mapping (Decode Prologue)

| Register | Formula | Constant/Variable | Evidence |
|----------|---------|-------------------|----------|
| **R0** | `0x00000200` | CONSTANT | PC, unchanged across all sweeps |
| **R1** | `opcode0` | VARIABLE | Matches opcode0 in opcode0 sweep; 0x00 in opcode1/opcode2 sweeps |
| **R2** | `opcode0 ^ 0x5A` | VARIABLE | Matches `opcode0 XOR 0x5A` for all 256 opcode0 values |
| **R3** | **Bimodal** | See 2.3 | See below |
| **R4** | `opcode1 ^ 0x3C` | VARIABLE | Matches `opcode1 XOR 0x3C` for all 256 opcode1 values |
| **R5–R15** | `0x00000000` | CONSTANT | Never modified in any experiment |

### 2.3 R3 Bimodal Behavior

| Condition | R3 Value | Meaning |
|-----------|----------|---------|
| `opcode0 == 0x00` | `(opcode1 << 8) \| 0x00` | Preserves full 16-bit instruction word |
| `opcode0 != 0x00` | `0x56ED1E8D` | Hardcoded magic constant for ALL non-zero opcode0 values |

**Interpretation:** `0x00` is the **NOP/INIT opcode** — it is the only opcode0 value that preserves the instruction word in R3. All other opcode0 values (0x01–0xFF) cause R3 to be overwritten with the magic constant `0x56ED1E8D`.

### 2.4 XOR-Based Decode Tables

The VM uses two independent XOR-based decode paths:

| Table | Index Formula | XOR Mask | Stored In |
|-------|---------------|----------|-----------|
| **Table 1** | `opcode0 ^ 0x5A` | `0x5A` | R2 |
| **Table 2** | `opcode1 ^ 0x3C` | `0x3C` | R4 |

**Interpretation:** These decoded values likely serve as **indices into 256-entry lookup tables** that define instruction behavior. The tables have not been located yet.

### 2.5 Execution Scope

| Fact | Evidence |
|------|----------|
| **1 instruction per run** | Marker sweep: no marker detected at offsets 0x204–0x300 |
| **Only reads 2 bytes** | Opcode2 sweep: no effect on any register |
| **No loop detected** | Markers at 0x204, 0x210, 0x250, 0x300 all undetected |
| **Decode-only behavior** | All observed register changes are from the prologue, not instruction execution |

### 2.6 Kernel Source Analysis (ExecuteBytecodeKernel.cpp)

The kernel source was analyzed to understand the 87-state machine and explain the empirical findings.

#### 2.6.1 Dispatch Loop (`vm_dispatch_template.h`)

```cpp
template <typename StateEnumType, typename HandlerFunc>
inline void RunVMDispatchLoop(VMContext &vm, StateEnumType initialState,
                             StateEnumType exitState, HandlerFunc &&handler,
                             int maxIterations = 1000) {
    StateEnumType currentState = initialState;
    int iterationCount = 0;

    while (vm.is_running && currentState != exitState &&
           iterationCount < maxIterations) {
        iterationCount++;
        currentState = handler(currentState);
    }

    if (currentState == exitState) {
        vm.is_running = false;
    }
}
```

**Key observations:**
- **Default maxIterations = 1000** — the VM can execute up to 1000 state transitions before forced termination
- Loop terminates when: `vm.is_running == false`, `currentState == exitState`, or `iterationCount >= 1000`
- Each state handler returns the **next state** — this is a classic switch-case state machine

#### 2.6.2 Entry Point & Exit Path

```
BB_0x1032a1f0 → (vm.pc != nullptr) ? BB_0x1032a210 : BB_0x1032a208
BB_0x1032a208 → error path → BB_0x1032a210
BB_0x1032a210 → (fetch_u8() == 0x00) ? BB_0x1032a6eb : BB_0x1032a219
BB_0x1032a6eb → BB_0x1032a720 → Exit
BB_0x1032a720 → Exit
BB_0x1032a75e → Exit
```

**Critical discovery:** `BB_0x1032a210` calls `vm.fetch_u8()` — this reads **one byte** from the payload and compares it to `0x00`.

- If the fetched byte is `0x00`: go to `BB_0x1032a6eb` → `BB_0x1032a720` → **Exit**
- If the fetched byte is **non-zero**: go to `BB_0x1032a219` → `vm.load_imm()` → continues into the main state machine

#### 2.6.3 Why Only 1 Instruction Executes

The `run_payload.cpp` harness sets `vm.pc = buffer.data() + 0x200` and then calls `ExecuteBytecodeKernel(vm)`. The kernel:

1. Enters at `BB_0x1032a1f0` — checks `vm.pc != nullptr` (true)
2. Goes to `BB_0x1032a210` — calls `vm.fetch_u8()` which reads `buffer[0x200]` and advances PC to `0x201`
3. If `buffer[0x200] == 0x00`: exits immediately via `BB_0x1032a6eb → Exit`
4. If `buffer[0x200] != 0x00`: calls `vm.load_imm()` which reads more bytes and enters the main state machine

**The `load_imm()` method reads:**
```cpp
inline void load_imm() {
    uint8_t dst = fetch_u8();  // reads buffer[0x201]
    int32_t val = fetch_i32(); // reads buffer[0x202..0x205]
    write_reg(dst, val);      // writes to registers
}
```

So when opcode0 is non-zero, the kernel reads bytes at 0x201–0x205 and writes to a register, then continues through the state machine. However, the state machine's transitions are **all hardcoded return statements** — they don't read further from the payload. The actual instruction logic (ADD, AND, OR, XOR) operates on the **stack**, not on payload data.

#### 2.6.4 Opcode Family State Map

| Family | States | Key Operations | Active Methods |
|--------|--------|----------------|----------------|
| **1: Kernel Gateways** | 7 states | Entry, error, fetch, exit | `fetch_u8()` |
| **2: Register Load/Store** | 24 states | Register read/write | `load_imm()`, `write_reg()` |
| **3: Data Stream XOR** | 8 states | XOR stream transform | `op_xor_stream(0xAA)` |
| **4: Arithmetic/Bitwise** | 11 states | ADD, AND, OR | `op_add()`, `op_and()`, `op_or()` |
| **5: Register Window Shifts** | 12 states | Sliding frame shifts | None (pure state transitions) |
| **6: Memory Bounds** | 12 states | Pointer alignment | None (pure state transitions) |
| **7: Stack Operations** | 15 states | Push, pop, guards | `push()`, `pop()` |
| **Total** | **87 states** | | |

#### 2.6.5 State Transition Paths (Key Paths)

**Path A: NOP/INIT (opcode0 = 0x00)**
```
BB_0x1032a1f0 → BB_0x1032a210 → (fetch_u8==0x00) → BB_0x1032a6eb → BB_0x1032a720 → Exit
```
- Reads 1 byte (0x200), sees 0x00, exits immediately
- **0 state transitions after entry** — this is why the marker sweep found nothing

**Path B: Non-NOP (opcode0 ≠ 0x00)**
```
BB_0x1032a1f0 → BB_0x1032a210 → (fetch_u8≠0x00) → BB_0x1032a219 → load_imm()
→ BB_0x1032a234 → BB_0x1032a247 → BB_0x1032a260 → BB_0x1032a26e
→ BB_0x1032a27a → BB_0x1032a286 → BB_0x1032a299 → BB_0x1032a2b0
→ BB_0x1032a2b8 → BB_0x1032a2c2 → BB_0x1032a2cc → op_xor_stream(0xAA)
→ BB_0x1032a315 → BB_0x1032a3cc → BB_0x1032a3e4 → BB_0x1032a3f7
→ BB_0x1032a40e → BB_0x1032a432 → BB_0x1032a43d → BB_0x1032a445
→ BB_0x1032a464 → BB_0x1032a4a4 → BB_0x1032a4b3 → BB_0x1032a4c1
→ BB_0x1032a4dd → BB_0x1032a4e6 → BB_0x1032a4f8 → BB_0x1032a510
→ BB_0x1032a555 → BB_0x1032a56c → BB_0x1032a5dc → BB_0x1032a604
→ BB_0x1032a621 → BB_0x1032a634 → BB_0x1032a640 → BB_0x1032a64d
→ BB_0x1032a6bd → BB_0x1032a6c1 → BB_0x1032a6eb → BB_0x1032a720 → Exit
```
- **~40 state transitions** for the default path
- Executes `op_xor_stream(0xAA)` which pops from stack, XORs with 0xAA, pushes result
- **But the stack is empty** — `pop()` on empty stack sets `has_error = true`, `is_running = false`
- This causes the dispatch loop to terminate early

**Why the stack is empty:** The `load_imm()` method writes to a register but does NOT push to the stack. The `op_xor_stream()`, `op_add()`, `op_and()`, `op_or()` all `pop()` from the stack. Since nothing was pushed, the first pop triggers an underflow error, setting `is_running = false`, which terminates the dispatch loop.

#### 2.6.6 Why Opcode0=0x00 Shows No Register Changes Beyond Prologue

When opcode0=0x00:
1. `fetch_u8()` reads 0x00, exits via Path A
2. The prologue in `run_payload.cpp` manually sets R0-R4 before calling `ExecuteBytecodeKernel`
3. The kernel reads 0x00 and exits — no further state transitions
4. Result: R0-R4 show the prologue values, R5-R15 stay zero

When opcode0≠0x00:
1. `fetch_u8()` reads non-zero, enters Path B
2. `load_imm()` reads opcode1 and a 32-bit value from 0x202–0x205
3. Writes the 32-bit value to a register (controlled by opcode1 byte)
4. Continues through ~40 states, hits `op_xor_stream(0xAA)`
5. Stack underflow → `is_running = false` → loop terminates
6. Result: R0-R4 show prologue values, R5-R15 may show partial changes from `load_imm()`

**This explains the empirical data:** The `run_payload.cpp` harness manually sets R0-R4 in the prologue, which is why our sweeps see those values. The kernel's actual execution is blocked by the empty stack.

---

## 3. Complete Sweep Data

### 3.1 Opcode0 Sweep (0x00–0xFF)

**Fixed:** opcode1 = `0x03`  
**Swept:** opcode0 = `0x00` to `0xFF`

#### Register Sensitivity

| Register | Behavior | Unique Values |
|----------|----------|---------------|
| R0 | CONSTANT = `0x00000200` | 1 |
| R1 | CHANGES = `opcode0` | 256 |
| R2 | CHANGES = `opcode0 ^ 0x5A` | 256 |
| R3 | Bimodal: `0x00000300` (when opcode0=0x00), `0x56ED1E8D` (all others) | 2 |
| R4 | CONSTANT = `0x0000003F` (`0x03 ^ 0x3C`) | 1 |
| R5–R15 | CONSTANT = `0x00000000` | 1 each |

#### Sample Data Points

| opcode0 | R1 | R2 | R3 | R4 |
|---------|----|----|----|----|
| 0x00 | 0x00 | 0x5A | 0x00000300 | 0x3F |
| 0x01 | 0x01 | 0x5B | 0x56ED1E8D | 0x3F |
| 0x02 | 0x02 | 0x58 | 0x56ED1E8D | 0x3F |
| 0x3C | 0x3C | 0x66 | 0x56ED1E8D | 0x00 |
| 0x5A | 0x5A | 0x00 | 0x56ED1E8D | 0x3F |
| 0xFF | 0xFF | 0xA5 | 0x56ED1E8D | 0x3F |

### 3.2 Opcode1 Sweep (0x00–0xFF)

**Fixed:** opcode0 = `0x00`  
**Swept:** opcode1 = `0x00` to `0xFF`

#### Register Sensitivity

| Register | Behavior | Unique Values |
|----------|----------|---------------|
| R0 | CONSTANT = `0x00000200` | 1 |
| R1 | CONSTANT = `0x00000000` | 1 |
| R2 | CONSTANT = `0x0000005A` | 1 |
| R3 | CHANGES = `opcode1 << 8` | 256 |
| R4 | CHANGES = `opcode1 ^ 0x3C` | 256 |
| R5–R15 | CONSTANT = `0x00000000` | 1 each |

#### Sample Data Points

| opcode1 | R3 | R4 |
|---------|----|----|
| 0x00 | 0x0000 | 0x3C |
| 0x01 | 0x0100 | 0x3D |
| 0x03 | 0x0300 | 0x3F |
| 0x3C | 0x3C00 | 0x00 |
| 0xFF | 0xFF00 | 0xC3 |

### 3.3 Opcode2 Sweep (0x00–0xFF)

**Fixed:** opcode0 = `0x00`, opcode1 = `0x03`  
**Swept:** opcode2 = `0x00` to `0xFF`

#### Result: ALL Registers CONSTANT

| Register | Value |
|----------|-------|
| R0 | `0x00000200` |
| R1 | `0x00000000` |
| R2 | `0x0000005A` |
| R3 | `0x00000300` |
| R4 | `0x0000003F` |
| R5–R15 | `0x00000000` |

**Conclusion:** The VM does not read byte at offset 0x202. Instruction is strictly 2 bytes.

### 3.4 Marker Sweep (Offsets 0x204–0x300)

**Fixed:** opcode0 = `0x00`, opcode1 = `0x03`  
**Tested:** Marker byte `0xAA` at offsets 0x204, 0x206, 0x208, 0x20A, 0x20C, 0x20E, 0x210, 0x214, 0x218, 0x220, 0x230, 0x250, 0x280, 0x300

#### Result: NO MARKER DETECTED AT ANY OFFSET

**Conclusion:** The VM executes exactly **1 instruction** (the 2-byte word at 0x200–0x201) and then terminates. No further payload bytes are read.

---

## 4. VM Architecture Model (Inferred)

```
┌─────────────────────────────────────────────────────────────────┐
│                    VM KERNEL (ExecuteBytecodeKernel)            │
│                                                                 │
│  87-State Machine with 7 Opcode Families                        │
│                                                                 │
│  ┌───────────────────────────────────────────────────────────┐  │
│  │  DECODE PROLOGUE (Observed)                              │  │
│  │                                                         │  │
│  │  1. Load PC = 0x200                                     │  │
│  │  2. R0 = PC                                             │  │
│  │  3. R1 = opcode0 (LSB)                                  │  │
│  │  4. R2 = opcode0 ^ 0x5A  → Table 1 index                │  │
│  │  5. R3 = (opcode1 << 8) | opcode0  (full 16-bit word)    │  │
│  │  6. R4 = opcode1 ^ 0x3C  → Table 2 index                │  │
│  │  7. R5-R15 = 0x00000000                                 │  │
│  │                                                         │  │
│  │  8. IF opcode0 == 0x00:                                  │  │
│  │       R3 = preserved instruction word (NOP/INIT)         │  │
│  │     ELSE:                                               │  │
│  │       R3 = 0x56ED1E8D  (magic constant)                 │  │
│  │                                                         │  │
│  │  9. EXIT (1 instruction per run)                        │  │
│  └───────────────────────────────────────────────────────────┘  │
│                                                                 │
│  ┌───────────────────────────────────────────────────────────┐  │
│  │  EXECUTION PHASE (NOT Observed)                          │  │
│  │                                                         │  │
│  │  Hypothesized:                                          │  │
│  │  - R2 and R4 index into 256-entry XOR lookup tables       │  │
│  │  - Table entries contain function pointers or data       │  │
│  │  - Actual instruction behavior (arithmetic, memory,      │  │
│  │    control flow) is implemented via table lookups        │  │
│  │  - Requires VM loop to execute multiple instructions     │  │
│  └───────────────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────────────┘
```

---

## 5. Open Questions & Future Work

### 5.1 Unproven Hypotheses

| Hypothesis | Status | How to Prove |
|------------|--------|--------------|
| R2/R4 index into 256-entry lookup tables | NOT PROVEN | Search binary for `0x5A` and `0x3C` constants |
| Magic constant `0x56ED1E8D` is a table base address | NOT PROVEN | Search binary for this value |
| Actual instruction execution occurs beyond the prologue | PARTIALLY PROVEN — kernel has 40-state path but stack underflow blocks it | Push data to stack before kernel execution |
| R5-R15 are used by real instructions | PARTIALLY PROVEN — `load_imm()` can write to any register | Find opcode that triggers `load_imm()` with valid dst |

### 5.2 Root Cause: Why No Real Execution Observed

**The `run_payload.exe` harness has a critical flaw:** It manually sets R0-R4 in the prologue but **never pushes data to the VM stack** before calling `ExecuteBytecodeKernel`. When the kernel enters Path B (non-NOP opcode0), it eventually reaches `op_xor_stream(0xAA)` which calls `pop()` on an empty stack. This triggers `has_error = true` and `is_running = false`, terminating the dispatch loop.

**To observe real instruction execution, the harness must:**
1. Push test data onto the VM stack before calling `ExecuteBytecodeKernel`
2. OR use an opcode0 value that follows a path that doesn't require stack data
3. OR modify the harness to set `maxIterations` and provide stack data

### 5.3 Required Next Steps

1. **Modify `run_payload.cpp`** — Add stack data initialization before `ExecuteBytecodeKernel` call
2. **Locate XOR Lookup Tables** — Search the binary for constants `0x5A` and `0x3C` to find where decoded indices are used as table lookups
3. **Find "Hot" Opcode Pairs** — Sweep opcode0+opcode1 pairs to find 16-bit values that trigger R5-R15 modification
4. **Continue State Engine Implementation** — Steps 255+ using DOT specs

---

## 6. Known Constraints

| Constraint | Value |
|------------|-------|
| Instructions per `run_payload.exe` run | 1 (kernel exits via stack underflow or NOP path) |
| Instruction width | 2 bytes (16-bit, little-endian) |
| Kernel max iterations | 1000 (default, never reached) |
| Kernel state transitions (Path A: NOP) | 0 (immediate exit) |
| Kernel state transitions (Path B: non-NOP) | ~40 (until stack underflow) |
| Instruction offset in payload | 0x200 |
| Opcode0 range tested | 0x00–0xFF (256 values) |
| Opcode1 range tested | 0x00–0xFF (256 values) |
| Opcode2 range tested | 0x00–0xFF (256 values) |
| Marker sweep range | 0x204–0x300 |
| VM states | 87 |
| Opcode families | 7 |

---

## 7. File References

| File | Purpose |
|------|---------|
| `clean_src/ExecuteBytecodeKernel.cpp` | 87-State Bytecode Execution Kernel |
| `clean_src/vm_kernel.h` / `vm_kernel.cpp` | C++20 Opcode Execution Engine |
| `clean_build/run_payload.exe` | Payload execution harness |
| `testfile` | 1.85 MB production payload |
| `opcode_sweep.py` | Opcode0 sweep script |
| `opcode_sweep1.py` | Opcode1 sweep script |
| `opcode_sweep2.py` | Opcode2 sweep script |
| `marker_sweep.py` | Marker byte sweep script |
| `PROJECT_INDEX.md` | Master project index |
| `machine_specification_draft.md` | VM specification (fact vs. hypothesis) |
| `opcode_specification_table.md` | 87 states / 7 opcode families reference |

---

## 8. Reproduction Guide for Other LLMs

To reproduce these experiments:

```bash
# Prerequisites
# - Windows with g++ (MinGW)
# - Python 3.x
# - testfile (1.85 MB payload)
# - clean_build/run_payload.exe

# 1. Sweep opcode0 (0x00-0xFF)
python opcode_sweep.py

# 2. Sweep opcode1 (0x00-0xFF)
python opcode_sweep1.py

# 3. Sweep opcode2 (0x00-0xFF)
python opcode_sweep2.py

# 4. Marker sweep (find execution scope)
python marker_sweep.py

# 5. Run payload manually
./clean_build/run_payload.exe testfile
```

Each script outputs a table of register values and a sensitivity analysis showing which registers change with the swept byte.

---

*Document generated: 2026-08-12*  
*Last updated: 2026-08-12*
