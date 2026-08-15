#include "FUN_10349ce9.h"
#include "FUN_10330a7a.h"
#include "FUN_10330a8d.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10349ce9L,
    BB_0x10349cf6L,
    BB_0x10349d0bL,
    BB_0x10349d0fL,
    BB_0x10349d17L,
    BB_0x10349d30L,
    BB_0x10349d36L,
    BB_0x10349d4eL,
    Exit
};

void FUN_10349ce9() {
    State currentState = State::BB_0x10349ce9L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10349ce9L:
                // Transition: BB_0x10349ce9L -> BB_0x10349cf6L
                currentState = State::BB_0x10349cf6L;
                break;

            case State::BB_0x10349cf6L:
                // Transition: BB_0x10349cf6L -> BB_0x10330a7aL
                FUN_10330a7a();
                FUN_10330a8d();
                currentState = State::BB_0x10349d4eL;
                break;

            case State::BB_0x10349d0bL:
                // Transition: BB_0x10349d0bL -> BB_0x10349d0fL
                currentState = State::BB_0x10349d0fL;
                break;

            case State::BB_0x10349d0fL:
                // Transition: BB_0x10349d0fL -> BB_0x10349d17L
                currentState = State::BB_0x10349d17L;
                break;

            case State::BB_0x10349d17L:
                // Transition: BB_0x10349d17L -> BB_0x10349d30L
                currentState = State::BB_0x10349d30L;
                break;

            case State::BB_0x10349d30L:
                // Exit block
                currentState = State::Exit;
                break;

            case State::BB_0x10349d36L:
                // Transition: BB_0x10349d36L -> BB_0x10330a7aL
                FUN_10330a7a();
                FUN_10330a8d();
                currentState = State::BB_0x10349d4eL;
                break;

            case State::BB_0x10349d4eL:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
