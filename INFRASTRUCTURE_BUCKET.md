# Infrastructure / Low Confidence Classification Bucket

## Purpose
When analyzing `.dot` function specifications, use this taxonomy to quickly classify functions that do **NOT** contain custom domain logic, file format parsing, game state rules, or custom execution math.

## Classification Tree

```
[Infrastructure / Low Confidence]
├── CRT wrapper ....................... Standard C/C++ runtime functions (malloc, free, memset, memcpy, fprintf, etc.)
├── allocator ......................... Memory allocation helpers (operator_new, calloc, alloca probes)
├── synchronization ................... Mutex/lock/thread primitives
├── trivial thunk ..................... Single-call pass-through wrappers
├── compiler-generated helper ......... EH prologue/epilogue, guard checks, stack probes
└── unknown plumbing ................ Complex but semantically opaque state machines
```

## Decision Criteria

| Category | Key Signals | Examples Seen |
|----------|-------------|---------------|
| **CRT wrapper** | Name matches standard CRT (`_memset`, `_fprintf`, `___std_exception_copy`) | `_memset`, `_fprintf`, `___std_exception_copy` |
| **allocator** | Calls `operator_new`, `calloc`, `alloca`, or manages heap pointers | `operator_new`, `__alloca_probe_16`, `FUN_10337a28` (aliased to `calloc`) |
| **synchronization** | Mutex/lock primitives, thread sync | `FUN_102d1580`, `FUN_102db5a0`, `FUN_102e18a0` |
| **trivial thunk** | DOT has ≤3 nodes, single outgoing edge to another function | `FUN_102a2390`, `FUN_102a2270`, `FUN_102a23a0`, `jinfo_get_method` |
| **compiler-generated helper** | Stack probes, guard checks, EH frames, security cookies | `__alloca_probe_16` |
| **unknown plumbing** | Complex state machine (5+ nodes) but no clear semantic purpose | `FUN_102d3080`, `FUN_102edd10`, `FUN_102b9f00`, `FUN_102d1890` |

## Recommended Actions by Category

| Category | Action |
|----------|--------|
| CRT wrapper | **ALIAS_STDLIB** — map to standard C/C++ function |
| allocator | **ALIAS_STDLIB** or **STUB_DECLARATION** |
| synchronization | **STUB_DECLARATION** with debug print |
| trivial thunk | **GENERATE_FULL_CPP** (minimal, often no-op) |
| compiler-generated helper | **STUB_DECLARATION** (no-op) |
| unknown plumbing | **GENERATE_FULL_CPP** — translate DOT faithfully, may reveal purpose later |

## Functions Already Classified

### CRT wrapper
- `_memset` (Step ~125)
- `_fprintf` (stub in utilities.cpp)
- `___std_exception_copy` (Step 195)

### allocator
- `operator_new` (stub in utilities.cpp)
- `FUN_10337a28` → aliased to `std::calloc`
- `__alloca_probe_16` (stub in utilities.cpp)

### synchronization
- `FUN_102d1580` (Step 125)
- `FUN_102db5a0` / `FUN_102b8ec0` (Steps 134-135)
- `FUN_102e18a0` (Step 149)

### trivial thunk
- `FUN_100027a0` (Step 172)
- `FUN_103581e0` (Step 173)
- `FUN_102e70d0` (Step 174)
- `FUN_102a2260` (Step 218)
- `FUN_102a2390` (Step 228)
- `FUN_102a23a0` (Step 230)
- `FUN_102a2270` (Step 231)
- `FUN_10284800` (Step 246)
- `jinfo_get_method` (Step 238)
- `is_wide_character_specifier<char>` (Step 250)
- `is_integral_specifier<>` (Step 251)

### compiler-generated helper
- `__alloca_probe_16` (Step 234 dependency)

### unknown plumbing
- `FUN_102edd10` (Step 185, 24 states)
- `FUN_102f0180` (Step 187, 15 states)
- `FUN_102d3080` (Step 209, 17 states)
- `FUN_102d1890` (Step 217, 18 states)
- `FUN_102b9f00` (Step 226, 17 states)
- `FUN_102ba540` (Step 227, 15 states)
- `FUN_102d1f30` (Step 233, 14 states)
- `FUN_102d3190` (Step 216, 16 states)
- `FUN_102d3360` (Step 215, 17 states)
- `FUN_102d1250` (Step 213, 15 states)
- `FUN_102b3460` (Step 232, wrapper)
- `FUN_102b8aa0` (Step 231, wrapper)
- `FUN_102b1e00` (Step 229, wrapper)
- `FUN_102d1c20` (Step 234, wrapper)
- `FUN_102d3270` (Step 214, 10 states)
- `FUN_102b8d50` (Step 232, 10 states)
- `FUN_102ef3b0` (Step 236, 4 states)
- `FUN_102b3ad0` (Step 237, thunk)
- `FUN_1031e500` (Step 219, 10 states)
- `FUN_1031e430` (Step 220, thunk)
- `FUN_102bb350` (Step 221, thunk)
- `FUN_1031e450` (Step 222, thunk)
- `FUN_102954d0` (Step 235, thunk)
- `FUN_10285930` (Step 245, 5 states)
- `FUN_102846a0` (Step 248, 9 states)
- `FUN_102859a0` (Step 247, thunk)
- `FUN_1029cbe0` (Step 249, wrapper)
- `to_integer_size` (Step 252, 9 states)
- `is_positional_parameter_reappearance_consistent` (Step 253, 20 states)
- `FUN_103360ca` (Step 254, 6 states)

## Stub Inventory (Far-Future Dependencies)

| Function | Step | Status |
|----------|------|--------|
| `FUN_102b23f0` | 847 | Stub in utilities.cpp |
| `FUN_10337a28` | 14220 | Aliased to `std::calloc` |
| `FUN_102b0b30` | 2180 | Stub in utilities.cpp |
| `FUN_102d1e90` | 2353 | Stub in utilities.cpp |
| `FUN_10329247` | N/A | Stub in utilities.cpp |
