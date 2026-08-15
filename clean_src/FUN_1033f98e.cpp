#include "FUN_1033f98e.h"
#include "FUN_10330aed.h"
#include "FUN_1033f9dc.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033f98eL,
    BB_0x103298f0L,
    BB_0x1033da86L,
    BB_0x10330aedL,
    BB_0x1033f9dcL,
    Exit
};

void FUN_1033f98e() {
    State currentState = State::BB_0x1033f98eL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033f98eL:
                // Transition: BB_0x1033f98eL -> BB_0x10330aedL
                currentState = State::BB_0x10330aedL;
                break;

            case State::BB_0x103298f0L:
                // Transition: BB_0x1033f98eL -> BB_0x103298f0L
                currentState = State::Exit;
                break;

            case State::BB_0x1033da86L:
                // Transition: BB_0x1033f98eL -> BB_0x1033da86L
                currentState = State::Exit;
                break;

            case State::BB_0x10330aedL:
                // Transition: BB_0x1033f98eL -> BB_0x10330aedL
                FUN_10330aed();
                currentState = State::BB_0x1033f9dcL;
                break;

            case State::BB_0x1033f9dcL:
                // Transition: BB_0x1033f98eL -> BB_0x1033f9dcL
                FUN_1033f9dc();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
