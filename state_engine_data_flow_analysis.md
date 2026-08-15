# DoogEngine1 State Engine Data Flow & Shared Structure Analysis (Steps 1 – 55)

## Executive Summary

This document provides a technical analysis of the **data flow, state mutations, function arguments, memory offsets, and shared data structures** across the **55 compiled steps** of the DoogEngine1 State Engine.

Through empirical control-flow analysis and clean-room C++ compilation, we have established that a specific group of core functions all read, mutate, and evaluate offsets within a single shared memory context: the **`MasterEngineStateStruct`**.

---

## 1. Data Ingress, Mutation, and Egress Lifecycle

```mermaid
graph LR
    IN["INPUT DATA<br/>• Bytecode Header ('0x1QRH')<br/>• Raw Section Buffer Pointer<br/>• Callback Function Pointers"] 
    
    subgraph Shared MasterEngineStateStruct Mutations
        MUT1["Precondition Flags (FUN_10343870)"]
        MUT2["Memory Arena Allocation (FUN_1034f83e)"]
        MUT3["Execution State Switch Register (FUN_1032a1f0)"]
        MUT4["Recursion Depth Counter (FUN_1034145b)"]
        MUT5["Checksum / Hash (FUN_1034798f)"]
    end
    
    OUT["OUTPUT DATA<br/>• Execution Status Code (0/1 Success)<br/>• Mutated Data Memory Buffer<br/>• Response Result Handle"]
    
    IN --> MUT1
    MUT1 --> MUT2
    MUT2 --> MUT3
    MUT3 --> MUT4
    MUT4 --> MUT5
    MUT5 --> OUT
```

---

## 2. Empirical Data Matrix Table

The table below maps each data element in the state engine kernel to its type, input site, mutating functions, and output destination:

| Data Element | Data Type | Entrance Site | Mutating / Evaluating Functions | Exit / Destination Site |
| :--- | :--- | :--- | :--- | :--- |
| **Magic Signature String** | `const char*` / `char[6]` | `FUN_1033f53a` (Step 1), `FUN_1033cd98` (Step 55) | Evaluated in `FUN_1033f53a` against `"0x1QRH"` | Immediately returns `false` if header mismatch |
| **Section Table Flags** | `uint32_t` bitfield | Header Payload Buffer | Evaluated across 25 basic blocks in `FUN_10343870` (Step 23) | Error exit block if invalid flag set |
| **Buffer Layout Footprint** | `size_t` (bytes) | Pass 1 in `FUN_1033c5bf` | Calculated by `FUN_10331850` (Pass 1 in `FUN_1033c5bf`) | Passed to `FUN_1034a0b2` allocation wrapper |
| **Dynamic Memory Arena** | `uint8_t*` pointer | `FUN_1034a0b2` (Step 48) | Allocated in `FUN_1034f83e` (Step 47); populated in `FUN_1032a1f0` (Step 42) | Bound to `FUN_10342ebe` for active execution |
| **State Switch Register** | `enum class State` | Top of every state function | Mutated on every block transition in `FUN_1032a1f0`, `FUN_1033c5bf`, `FUN_1034f83e` | Reaches `State::Exit` on completion |
| **Indirect Callback Pointers** | `void(*)()` function ptr | Path B (`FUN_1034150c`) | Evaluated by `guard_check_icall` (Step 7) | Invoked if CFG check passes; aborted if bad ptr |
| **Recursion Guard Counter** | `int` counter | `FUN_1034145b` (Step 12) | Incremented in `FUN_1034145b`; checked against `callDepth >= 1` | Early exit if stack recursion detected |
| **Checksum / Hash Value** | `uint32_t` hash | `FUN_10347a27` (Step 44) | Evaluated across 27 basic blocks in `FUN_1034798f` (Step 43) | Rejects payload if hash mismatch |
| **Application Result Code** | `bool` / `int` status | `FUN_1034a030` (Step 40) | Formatted in `FUN_1034a030` | Returned by API Gateway (`FUN_1033c9ee`) |

---

## 3. Shared Structure Reconstruction (`MasterEngineStateStruct`)

A specific cluster of core functions all manipulate offsets within the same master memory structure:

```cpp
struct MasterEngineStateStruct {
    // Offset +0x00: Header Magic Signature ("0x1QRH")
    const char* magicHeader;        // Read by FUN_1033f53a
    
    // Offset +0x08: Precondition & Section Header Flags
    uint32_t headerFlags;           // Validated by FUN_10343870 (25-State Tree)
    
    // Offset +0x10: Memory Arena Allocation Parameters
    size_t memorySize;              // Pre-calculated by FUN_10331850 (Pass 1)
    uint8_t* memoryBuffer;          // Allocated by FUN_1034a0b2 / FUN_1034f83e
    
    // Offset +0x20: Active State Switch Register & Data Registers
    uint32_t currentState;          // Mutated by FUN_1032a1f0 (87-State Machine)
    int callDepth;                  // Checked by FUN_1034145b (Recursion Guard)
    
    // Offset +0x2C: Function Pointer Dispatch Table
    void** indirectCallbackTable;   // Validated by guard_check_icall in FUN_1034150c
    
    // Offset +0x38: Checksum & Integrity Fields
    uint32_t payloadChecksum;       // Validated by FUN_10347a27 / FUN_1034798f (27-State Tree)
};
```

### Shared Access Architecture

```mermaid
graph TD
    STRUCT["MasterEngineStateStruct"]
    
    F1["FUN_1033f53a (Step 1)<br/>Reads magicHeader (+0x00)"] --> STRUCT
    F2["FUN_10343870 (Step 23)<br/>Validates headerFlags (+0x08)"] --> STRUCT
    F3["FUN_1033c5bf + FUN_10331850 (Step 52)<br/>Calculates memorySize (+0x10)"] --> STRUCT
    F4["FUN_1034a0b2 + FUN_1034f83e (Steps 47-48)<br/>Allocates memoryBuffer (+0x18)"] --> STRUCT
    F5["FUN_1032a1f0 (Step 42)<br/>Mutates currentState & memoryBuffer (+0x20)"] --> STRUCT
    F6["FUN_1034150c + guard_check_icall (Step 25)<br/>Verifies indirectCallbackTable (+0x2C)"] --> STRUCT
    F7["FUN_10347a27 + FUN_1034798f (Steps 43-44)<br/>Verifies payloadChecksum (+0x38)"] --> STRUCT
```

---

## 4. Authoritative C++ Pseudo-Code

The code below uses `FUN_xxxxxx` symbols as the sole authoritative function identifiers, with human-readable descriptors explicitly designated as hypotheses:

```cpp
namespace DoogEngine1::AuthoritativeFacts {

constexpr char MAGIC_HEADER_STRING[] = "0x1QRH";

// Forward declarations of authoritative compiled symbols
void guard_check_icall();                                                     // FACT: Symbol in clean_symbols.h (Step 7)
void FUN_1034169e();                                                           // FACT: Step 14 (Central Convergence Hub)
void FUN_1034145b();                                                           // FACT: Step 12 (Path A Entry)
void FUN_1034150c();                                                           // FACT: Step 25 (Path B Entry)
void FUN_1034130a();                                                           // FACT: Step 30 (Path C Entry)
void FUN_10343870();                                                           // FACT: Step 23 (25-State Decision Machine)
void FUN_10343900();                                                           // FACT: Step 24 (Validation Function)
void FUN_103482c7();                                                           // FACT: Step 36 (Execution Payload Engine)
void FUN_10342017();                                                           // FACT: Step 33 (Phase 1 Lifecycle Controller)
void FUN_10342075();                                                           // FACT: Step 38 (Phase 2 Lifecycle Controller)
void FUN_10331850();                                                           // FACT: Step 39 (Two-Phase Master Orchestrator)
void FUN_1032a1f0();                                                           // FACT: Step 42 (87-State Machine)
void FUN_1034798f();                                                           // FACT: Step 43 (27-State Verification Machine)
void FUN_10347a27();                                                           // FACT: Step 44 (Verification Wrapper)
void FUN_1034f83e();                                                           // FACT: Step 47 (42-State Allocator Routine)
void FUN_1034a0b2();                                                           // FACT: Step 48 (Allocation Wrapper)
void FUN_10342ebe();                                                           // FACT: Step 49 (3-Phase Context Controller)
void FUN_1034a0f5();                                                           // FACT: Step 51 (Memory Manager)
void FUN_1033c5bf();                                                           // FACT: Step 52 (System Integration Engine)
void FUN_1033cea9();                                                           // FACT: Step 53 (Subsystem Orchestrator)
void FUN_1033cea1();                                                           // FACT: Step 54 (Terminal Exit Leaf)
void FUN_1033cd98();                                                           // FACT: Step 55 (Apex Root Kernel Node)

// --- STEP 55: FUN_1033cd98 ---
// FACT: Top-level root entry of the 55-step call graph
// HYPOTHESIS: Virtual Machine / Integrity Kernel Main Entry
void FUN_1033cd98(const char* inputHeader) {
    if (std::string(inputHeader) != MAGIC_HEADER_STRING) return;

    FUN_1033cea9(); 
    FUN_1033cea1(); 
}

// --- STEP 53: FUN_1033cea9 ---
// FACT: Intermediate dispatcher function
// HYPOTHESIS: Subsystem Orchestrator & API Dispatcher
void FUN_1033cea9() {
    FUN_1033c5bf(); 
}

// --- STEP 52: FUN_1033c5bf ---
// FACT: Contains 147 basic block states; unifies FUN_10331850, FUN_1032a1f0, FUN_1034a0f5, FUN_10342ebe, FUN_10343900
// HYPOTHESIS: System Integration & Inter-Module Bus Controller
void FUN_1033c5bf() {
    // FACT: Invocation #1 of FUN_10331850 (Occurs BEFORE FUN_1034a0b2 memory allocation)
    // HYPOTHESIS: Pre-computes static register footprint / layout table
    FUN_10331850(); 
    
    // FACT: Calls FUN_1032a1f0 (Step 42 - 87-State Machine)
    // HYPOTHESIS: Core Opcode Fetch-Decode-Execute Processor Loop
    FUN_1032a1f0(); 
    
    // FACT: Calls FUN_1034a0f5 (Step 51)
    // HYPOTHESIS: Memory Manager Routine
    FUN_1034a0f5(); 
    
    // FACT: Calls FUN_10342ebe (Step 49)
    // HYPOTHESIS: Outer Context Controller Routine
    FUN_10342ebe(); 
    
    // FACT: Calls FUN_10343900 (Step 24)
    // HYPOTHESIS: Precondition Validation Pass
    FUN_10343900(); 
}

// --- STEP 49: FUN_10342ebe ---
// FACT: 3-phase execution function invoking Allocation, Orchestrator, and Verification
// HYPOTHESIS: 3-Phase Outer Context Execution Controller
void FUN_10342ebe() {
    // FACT Phase 1: Calls FUN_1034a0b2 (Step 48 -> FUN_1034f83e 42-State Allocator)
    // HYPOTHESIS: Memory Arena Allocation Pass
    FUN_1034a0b2(); 
    
    // FACT Phase 2: Invocation #2 of FUN_10331850 (Occurs AFTER FUN_1034a0b2 memory allocation)
    // HYPOTHESIS: Active Payload Execution Pass on instantiated memory context
    FUN_10331850(); 
    
    // FACT Phase 3: Calls FUN_10347a27 (Step 44 -> FUN_1034798f 27-State Verifier)
    // HYPOTHESIS: Post-Execution Payload Checksum & Anti-Tamper Verification
    FUN_10347a27(); 
}

// --- STEP 39: FUN_10331850 ---
// FACT: Master orchestrator invoking Two-Phase Lifecycle functions
// HYPOTHESIS: Master Engine State Orchestrator
void FUN_10331850() {
    FUN_10342017(); // Phase A Init
    FUN_10342075(); // Phase B Exec
}

// --- TRIPLE-ROUTE MULTIPLEXER & CENTRAL HUB ---
void FUN_1034145b() {
    FUN_1034169e(); // Step 12 -> Calls Central Hub
}

void FUN_1034150c() {
    guard_check_icall(); // Step 7 -> Guard check before call
    FUN_1034169e();      // Step 25 -> Calls Central Hub
}

void FUN_1034130a() {
    FUN_1034169e(); // Step 30 -> Fallback route to Central Hub
}

void FUN_1034169e() {
    // FACT: Central convergence hub for FUN_1034145b, FUN_1034150c, and FUN_1034130a
}

} // namespace DoogEngine1::AuthoritativeFacts
```
