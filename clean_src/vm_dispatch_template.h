#pragma once

#include "vm_context.h"

namespace DoogEngine1 {

// ============================================================================
// REUSABLE DISPATCH LOOP TEMPLATE
// Generic outer execution loop template for state-machine bytecode engines
// ============================================================================
template <typename StateEnumType, typename HandlerFunc>
inline void RunVMDispatchLoop(VMContext &vm, StateEnumType initialState, StateEnumType exitState, HandlerFunc &&handler, int maxIterations = 1000) {
    StateEnumType currentState = initialState;
    int iterationCount = 0;

    while (vm.is_running && currentState != exitState && iterationCount < maxIterations) {
        iterationCount++;
        currentState = handler(currentState);
    }

    if (currentState == exitState) {
        vm.is_running = false;
    }
}

} // namespace DoogEngine1
