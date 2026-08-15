#include "vm_context.h"
#include "vm_dispatch_template.h"
#include <iostream>

namespace DoogEngine1 {

// ============================================================================
// REFACTORED 87-STATE BYTECODE EXECUTION KERNEL
// Driven by generic RunVMDispatchLoop template & VMContext inline helpers
// ============================================================================
void ExecuteBytecodeKernel(VMContext &vm) {
    enum class State {
        // Family 1: Kernel Control & Dispatch Gateways
        BB_0x1032a1f0L, BB_0x1032a208L, BB_0x1032a210L, BB_0x1032a219L,
        BB_0x1032a6ebL, BB_0x1032a720L, BB_0x1032a75eL,

        // Family 2: Register Load, Store & Transfer
        BB_0x1032a221L, BB_0x1032a22fL, BB_0x1032a234L, BB_0x1032a23eL,
        BB_0x1032a247L, BB_0x1032a252L, BB_0x1032a260L, BB_0x1032a26eL,
        BB_0x1032a27aL, BB_0x1032a286L, BB_0x1032a28cL, BB_0x1032a299L,
        BB_0x1032a29fL, BB_0x1032a2b0L, BB_0x1032a3e4L, BB_0x1032a3eaL,
        BB_0x1032a3f7L, BB_0x1032a3fdL, BB_0x1032a40eL, BB_0x1032a417L,
        BB_0x1032a4a4L, BB_0x1032a4b3L, BB_0x1032a4c1L, BB_0x1032a4c9L,

        // Family 3: Self-Looping Data & Stream Operations
        BB_0x1032a2b8L, BB_0x1032a2c2L, BB_0x1032a2ccL, BB_0x1032a315L,
        BB_0x1032a574L, BB_0x1032a5dcL, BB_0x1032a5e1L, BB_0x1032a604L,

        // Family 4: Arithmetic & Bitwise Logic
        BB_0x1032a31dL, BB_0x1032a328L, BB_0x1032a371L, BB_0x1032a376L,
        BB_0x1032a380L, BB_0x1032a3c9L, BB_0x1032a3ccL, BB_0x1032a3d1L,
        BB_0x1032a555L, BB_0x1032a55dL, BB_0x1032a56cL,

        // Family 5: Register Window & Sliding Frame Shifts
        BB_0x1032a41fL, BB_0x1032a432L, BB_0x1032a43dL, BB_0x1032a445L,
        BB_0x1032a464L, BB_0x1032a46cL, BB_0x1032a478L, BB_0x1032a48cL,
        BB_0x1032a730L, BB_0x1032a743L, BB_0x1032a74cL, BB_0x1032a751L,

        // Family 6: Memory Bounds & Pointer Alignment
        BB_0x1032a4d0L, BB_0x1032a4ddL, BB_0x1032a4e6L, BB_0x1032a4f8L,
        BB_0x1032a510L, BB_0x1032a518L, BB_0x1032a528L, BB_0x1032a53cL,
        BB_0x1032a60cL, BB_0x1032a621L, BB_0x1032a625L, BB_0x1032a634L,

        // Family 7: Stack Operations & Reset Guards
        BB_0x1032a640L, BB_0x1032a64dL, BB_0x1032a657L, BB_0x1032a660L,
        BB_0x1032a6bdL, BB_0x1032a6c1L, BB_0x1032a6caL, BB_0x1032a6d0L,
        BB_0x1032a6f0L, BB_0x1032a6f7L, BB_0x1032a706L, BB_0x1032a70dL,
        BB_0x1032a716L,

        Exit
    };

    RunVMDispatchLoop(vm, State::BB_0x1032a1f0L, State::Exit, [&](State state) -> State {
        switch (state) {

            // ================================================================
            // FAMILY 1: KERNEL CONTROL & DISPATCH GATEWAYS
            // ================================================================
            case State::BB_0x1032a1f0L:
                return (vm.pc != nullptr) ? State::BB_0x1032a210L : State::BB_0x1032a208L;

            case State::BB_0x1032a208L:
                vm.has_error = true;
                vm.error_code = 0x208;
                return State::BB_0x1032a210L;

            case State::BB_0x1032a210L:
                return (vm.fetch_u8() == 0x00) ? State::BB_0x1032a6ebL : State::BB_0x1032a219L;

            case State::BB_0x1032a219L:
                vm.load_imm();
                return State::BB_0x1032a234L;

            case State::BB_0x1032a6ebL: return State::BB_0x1032a720L;
            case State::BB_0x1032a720L: return State::Exit;
            case State::BB_0x1032a75eL: return State::Exit;

            // ================================================================
            // FAMILY 2: REGISTER LOAD, STORE & TRANSFER
            // ================================================================
            case State::BB_0x1032a221L: return State::BB_0x1032a22fL;
            case State::BB_0x1032a22fL: return State::BB_0x1032a417L;
            case State::BB_0x1032a234L: return State::BB_0x1032a247L;
            case State::BB_0x1032a23eL: return State::BB_0x1032a247L;
            case State::BB_0x1032a247L: return State::BB_0x1032a260L;
            case State::BB_0x1032a252L: return State::BB_0x1032a260L;
            case State::BB_0x1032a260L: return State::BB_0x1032a26eL;
            case State::BB_0x1032a26eL: return State::BB_0x1032a27aL;
            case State::BB_0x1032a27aL: return State::BB_0x1032a286L;
            case State::BB_0x1032a286L: return State::BB_0x1032a299L;
            case State::BB_0x1032a28cL: return State::BB_0x1032a299L;
            case State::BB_0x1032a299L: return State::BB_0x1032a2b0L;
            case State::BB_0x1032a29fL: return State::BB_0x1032a2b0L;
            case State::BB_0x1032a2b0L: return State::BB_0x1032a2b8L;
            case State::BB_0x1032a3e4L: return State::BB_0x1032a3f7L;
            case State::BB_0x1032a3eaL: return State::BB_0x1032a3f7L;
            case State::BB_0x1032a3f7L: return State::BB_0x1032a40eL;
            case State::BB_0x1032a3fdL: return State::BB_0x1032a40eL;
            case State::BB_0x1032a40eL: return State::BB_0x1032a432L;
            case State::BB_0x1032a417L: return State::BB_0x1032a432L;
            case State::BB_0x1032a4a4L: return State::BB_0x1032a4b3L;
            case State::BB_0x1032a4b3L: return State::BB_0x1032a4c1L;
            case State::BB_0x1032a4c1L: return State::BB_0x1032a4ddL;
            case State::BB_0x1032a4c9L: return State::BB_0x1032a4d0L;

            // ================================================================
            // FAMILY 3: SELF-LOOPING DATA & STREAM OPERATIONS
            // ================================================================
            case State::BB_0x1032a2b8L: return State::BB_0x1032a2c2L;
            case State::BB_0x1032a2c2L: return State::BB_0x1032a2ccL;
            case State::BB_0x1032a2ccL:
                vm.op_xor_stream(0xAA);
                return State::BB_0x1032a315L;
            case State::BB_0x1032a315L: return State::BB_0x1032a3ccL;
            case State::BB_0x1032a574L: return State::BB_0x1032a5dcL;
            case State::BB_0x1032a5dcL: return State::BB_0x1032a604L;
            case State::BB_0x1032a5e1L: return State::BB_0x1032a604L;
            case State::BB_0x1032a604L: return State::BB_0x1032a621L;

            // ================================================================
            // FAMILY 4: ARITHMETIC & BITWISE LOGIC
            // ================================================================
            case State::BB_0x1032a31dL: return State::BB_0x1032a328L;
            case State::BB_0x1032a328L:
                vm.op_add();
                return State::BB_0x1032a371L;
            case State::BB_0x1032a371L: return State::BB_0x1032a3ccL;
            case State::BB_0x1032a376L: return State::BB_0x1032a380L;
            case State::BB_0x1032a380L:
                vm.op_and();
                return State::BB_0x1032a3c9L;
            case State::BB_0x1032a3c9L: return State::BB_0x1032a3ccL;
            case State::BB_0x1032a3ccL: return State::BB_0x1032a3e4L;
            case State::BB_0x1032a3d1L: return State::BB_0x1032a3ccL;
            case State::BB_0x1032a555L: return State::BB_0x1032a56cL;
            case State::BB_0x1032a55dL:
                vm.op_or();
                return State::BB_0x1032a56cL;
            case State::BB_0x1032a56cL: return State::BB_0x1032a5dcL;

            // ================================================================
            // FAMILY 5: REGISTER WINDOW & SLIDING FRAME SHIFTS
            // ================================================================
            case State::BB_0x1032a41fL: return State::BB_0x1032a432L;
            case State::BB_0x1032a432L: return State::BB_0x1032a43dL;
            case State::BB_0x1032a43dL: return State::BB_0x1032a445L;
            case State::BB_0x1032a445L: return State::BB_0x1032a464L;
            case State::BB_0x1032a464L: return State::BB_0x1032a4a4L;
            case State::BB_0x1032a46cL: return State::BB_0x1032a4a4L;
            case State::BB_0x1032a478L: return State::BB_0x1032a4a4L;
            case State::BB_0x1032a48cL: return State::BB_0x1032a4a4L;
            case State::BB_0x1032a730L: return State::BB_0x1032a74cL;
            case State::BB_0x1032a743L: return State::BB_0x1032a74cL;
            case State::BB_0x1032a74cL: return State::BB_0x1032a75eL;
            case State::BB_0x1032a751L: return State::BB_0x1032a75eL;

            // ================================================================
            // FAMILY 6: MEMORY BOUNDS & POINTER ALIGNMENT
            // ================================================================
            case State::BB_0x1032a4d0L: return State::BB_0x1032a4ddL;
            case State::BB_0x1032a4ddL: return State::BB_0x1032a4e6L;
            case State::BB_0x1032a4e6L: return State::BB_0x1032a4f8L;
            case State::BB_0x1032a4f8L: return State::BB_0x1032a510L;
            case State::BB_0x1032a510L: return State::BB_0x1032a555L;
            case State::BB_0x1032a518L: return State::BB_0x1032a555L;
            case State::BB_0x1032a528L: return State::BB_0x1032a555L;
            case State::BB_0x1032a53cL: return State::BB_0x1032a555L;
            case State::BB_0x1032a60cL: return State::BB_0x1032a621L;
            case State::BB_0x1032a621L: return State::BB_0x1032a634L;
            case State::BB_0x1032a625L: return State::BB_0x1032a634L;
            case State::BB_0x1032a634L: return State::BB_0x1032a640L;

            // ================================================================
            // FAMILY 7: STACK OPERATIONS & RESET GUARDS
            // ================================================================
            case State::BB_0x1032a640L: return State::BB_0x1032a64dL;
            case State::BB_0x1032a64dL: return State::BB_0x1032a6bdL;
            case State::BB_0x1032a657L: return State::BB_0x1032a660L;
            case State::BB_0x1032a660L: return State::BB_0x1032a6bdL;
            case State::BB_0x1032a6bdL: return State::BB_0x1032a6c1L;
            case State::BB_0x1032a6c1L: return State::BB_0x1032a6ebL;
            case State::BB_0x1032a6caL: return State::BB_0x1032a6d0L;
            case State::BB_0x1032a6d0L: return State::BB_0x1032a6ebL;
            case State::BB_0x1032a6f0L: return State::BB_0x1032a706L;
            case State::BB_0x1032a6f7L: return State::BB_0x1032a706L;
            case State::BB_0x1032a706L: return State::BB_0x1032a720L;
            case State::BB_0x1032a70dL: return State::BB_0x1032a716L;
            case State::BB_0x1032a716L: return State::BB_0x1032a720L;

            case State::Exit:
                return State::Exit;
        }
        return State::Exit;
    });
}

} // namespace DoogEngine1
