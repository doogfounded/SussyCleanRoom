#include "FUN_1034145b.h"

namespace DoogEngine1 {

// Forward declaration for symbol compiled in step 14
void FUN_1034169e();

enum class State {
    BB_0x1034145bL,
    BB_0x10341471L,
    BB_0x1034147bL,
    BB_0x10341486L,
    BB_0x1034148bL,
    BB_0x10341497L,
    BB_0x1034149bL,
    BB_0x103414b0L,
    BB_0x103414c1L,
    BB_0x103414d1L,
    BB_0x103414e0L,
    BB_0x103414e8L,
    BB_0x103414ffL,
    BB_0x10341500L,
    Exit
};

void FUN_1034145b() {
    thread_local int callDepth = 0;
    if (callDepth >= 1) return;
    callDepth++;

    State currentState = State::BB_0x1034145bL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034145bL:
                // Transition: BB_0x1034145bL -> BB_0x10341471L
                currentState = State::BB_0x10341471L;
                break;

            case State::BB_0x10341471L:
                // Transition: BB_0x10341471L -> BB_0x10341486L
                currentState = State::BB_0x10341486L;
                break;

            case State::BB_0x1034147bL:
                // Transition: BB_0x1034147bL -> BB_0x10341500L
                currentState = State::BB_0x10341500L;
                break;

            case State::BB_0x10341486L:
                // Transition: BB_0x10341486L -> BB_0x1034148bL
                currentState = State::BB_0x1034148bL;
                break;

            case State::BB_0x1034148bL:
                // Transition: BB_0x1034148bL -> BB_0x1034149bL
                currentState = State::BB_0x1034149bL;
                break;

            case State::BB_0x10341497L:
                // Transition: BB_0x10341497L -> BB_0x10341500L
                currentState = State::BB_0x10341500L;
                break;

            case State::BB_0x1034149bL:
                // Transition: BB_0x1034149bL -> BB_0x103414c1L (CRT __calloc_base call bypassed)
                currentState = State::BB_0x103414c1L;
                break;

            case State::BB_0x103414b0L:
                // Transition: BB_0x103414b0L -> BB_0x103414e0L
                currentState = State::BB_0x103414e0L;
                break;

            case State::BB_0x103414c1L:
                // Transition: BB_0x103414c1L -> BB_0x103414e8L
                currentState = State::BB_0x103414e8L;
                break;

            case State::BB_0x103414d1L:
                // Transition: BB_0x103414d1L -> BB_0x103414e0L
                currentState = State::BB_0x103414e0L;
                break;

            case State::BB_0x103414e0L:
                // Transition: BB_0x103414e0L -> BB_0x1034169eL
                FUN_1034169e();
                currentState = State::BB_0x103414ffL;
                break;

            case State::BB_0x103414e8L:
                // Transition: BB_0x103414e8L -> BB_0x103414ffL (CRT construct_ptd call bypassed)
                FUN_1034169e();
                currentState = State::BB_0x103414ffL;
                break;

            case State::BB_0x103414ffL:
                // Transition: BB_0x103414ffL -> BB_0x10341500L
                currentState = State::BB_0x10341500L;
                break;

            case State::BB_0x10341500L:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }

    callDepth--;
}

} // namespace DoogEngine1
