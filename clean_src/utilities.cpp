#include <cstdio>
#include "clean_symbols.h"

namespace DoogEngine1 {

// Stub for FUN_102b23f0 (Step 847) — called by 100+ downstream steps.
// TODO: Replace with real implementation once Step 847 DOT is reached.
void FUN_102b23f0() {
    std::printf("[STUB] FUN_102b23f0 called from step 847 (not yet implemented)\n");
}

// Stub for operator_new — CRT dependency bypass
void operator_new() {
    std::printf("[STUB] operator_new called (CRT bypass)\n");
}

// Stub for _fprintf — CRT dependency bypass
void _fprintf() {
    std::printf("[STUB] _fprintf called (CRT bypass)\n");
}

// Stub for FUN_102b0b30 — Step 2180, called by FUN_102ba540
void FUN_102b0b30() {
    std::printf("[STUB] FUN_102b0b30 called from step 2180 (not yet implemented)\n");
}

// Stub for FUN_102d1e90 — Step 2353, called by FUN_102d1f30
void FUN_102d1e90() {
    std::printf("[STUB] FUN_102d1e90 called from step 2353 (not yet implemented)\n");
}

// Stub for __alloca_probe_16 — CRT stack probe
void __alloca_probe_16() {
    // No-op: stack probe is CRT noise
}

// Stub for __invoke_watson — CRT error handler
void __invoke_watson() {
    std::printf("[STUB] __invoke_watson called (CRT bypass)\n");
}

// Stub for FUN_10329247 — referenced in DOT files but not in execution plan
void FUN_10329247() {
    std::printf("[STUB] FUN_10329247 called (not yet implemented)\n");
}

} // namespace DoogEngine1
