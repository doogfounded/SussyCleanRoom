---
name: fun_10285dc0_engine
description: Reference guide and instructions for understanding, extending, and compiling the modular state machine for FUN_10285dc0.
---

# Design & Maintenance Manual: FUN_10285dc0 Modular State Engine

This document defines the architecture, directory structure, coding standards, and safety invariants of the `FUN_10285dc0` C++20 state machine. Any LLM or developer maintaining this codebase must adhere strictly to these patterns.

## 1. Architectural Strategy: Split Region Handlers
Because the original control flow graph (`FUN_10285dc0.dot`) contains **6,400+ basic blocks**, representing it as a single flat `switch(state)` inside a single function causes massive compiler slowdowns, memory exhaustion, and stack frame optimization issues. 

Instead, the machine is partitioned into **13 distinct regions** based on basic block address ranges.

### Files & Layout
- **[clean_symbols.h](file:///d:/Desktop/cool/doog1/clean_src/clean_symbols.h)**: Standard interface exposing `void FUN_10285dc0(BufferContext& ctx)`.
- **[FUN_10285dc0.h](file:///d:/Desktop/cool/doog1/clean_src/FUN_10285dc0.h)**: Defines:
  - `BufferContext`: Bounds-tracked buffer and cursor.
  - `FUN_10285dc0_State`: `enum class : uint32_t` using raw basic block addresses directly as underlying values.
  - `RegionResult`: `{ FUN_10285dc0_State next_state, bool exit_loop, bool has_error }` returned by region handlers.
- **[FUN_10285dc0_regions.h](file:///d:/Desktop/cool/doog1/clean_src/FUN_10285dc0_regions.h)**: Implements `classify_region()` and the `safe_copy_loop` template.
- **[FUN_10285dc0.cpp](file:///d:/Desktop/cool/doog1/clean_src/FUN_10285dc0.cpp)**: Contains the main loop routing to correct case handler functions.
- **[FUN_10285dc0_region_entry.cpp](file:///d:/Desktop/cool/doog1/clean_src/FUN_10285dc0_region_entry.cpp)**: Entry check and dispatch router.
- **[FUN_10285dc0_region_core0.cpp](file:///d:/Desktop/cool/doog1/clean_src/FUN_10285dc0_region_core0.cpp)** through **[_core11.cpp](file:///d:/Desktop/cool/doog1/clean_src/FUN_10285dc0_region_core11.cpp)**: State machine case handlers.

---

## 2. Invariants & Patterns

### 1. State Mapping & Casting
All states are represented by `FUN_10285dc0_State` which casts raw block addresses directly (e.g. `static_cast<FUN_10285dc0_State>(0x1028bb10L)`). This prevents defining 6,400 enum names.

### 2. Region Classification
`classify_region(state)` returns an integer index from `0` to `12` corresponding to the address range:
- `0`  -> `0x10285dc0` - `0x10285e4b` (Entry check)
- `1`  -> `0x10285ed0` - `0x10286a19` (Case 0)
- `2`  -> `0x10286a40` - `0x10287372` (Case 1)
- `3`  -> `0x10287390` - `0x10287f9e` (Case 2)
- `4`  -> `0x10287fc0` - `0x10288d00` (Case 3)
- `5`  -> `0x10288d10` - `0x10289c99` (Case 4)
- `6`  -> `0x10289cc0` - `0x1028ac96` (Case 5)
- `7`  -> `0x1028acc0` - `0x1028bdc2` (Case 6)
- `8`  -> `0x1028bdf0` - `0x1028ccf8` (Case 7)
- `9`  -> `0x1028cd20` - `0x1028d720` (Case 8)
- `10` -> `0x1028d720` - `0x1028e3e0` (Case 9)
- `11` -> `0x1028e3e0` - `0x1028f3d7` (Case 10)
- `12` -> `0x1028f400` - `0x10290664` (Case 11)

### 3. Exit & Error Sentinels
- `BB_0x103282d0L` maps to `State::EXIT`.
- `BB_0x103281d0L` maps to `State::ERROR`.
The main dispatcher loop terminates immediately on reaching either state. If it terminates on `State::ERROR`, it sets `ctx.has_overflow = true`.

### 4. Safety Iteration Guards
- **`safe_copy_loop`**: Performs byte copying loops safely. Wraps the loop body, tracks maximum iterations, and guarantees execution returns to a predefined exit state without hanging.
- **Self-loops**: Any basic block transitioning to itself or simple multi-state cycles uses a local decrementing loop counter (`max_iters = 256`) to guarantee loop termination.

---

## 3. Compilation & Verification
To test changes across the state machine, compile the translation units:
```cmd
cmd /c "for %f in (clean_src\FUN_10285dc0*.cpp) do g++ -std=c++20 -I./clean_src -c %f -o clean_build\%~nf.o"
```
Ensure compilation completes with exit code 0.
