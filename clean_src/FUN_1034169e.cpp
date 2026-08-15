#include "FUN_1034169e.h"
#include "FUN_10330a8d.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034169eL,
    BB_0x103416a9L,
    BB_0x103416beL,
    BB_0x103416d6L,
    Exit
};

void FUN_1034169e() {
    State currentState = State::BB_0x1034169eL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034169eL:
                // Transition: BB_0x1034169eL -> BB_0x103416a9L
                currentState = State::BB_0x103416a9L;
                break;

            case State::BB_0x103416a9L:
                // Transition: BB_0x103416a9L -> BB_0x103416beL
                currentState = State::BB_0x103416beL;
                break;

            case State::BB_0x103416beL:
                // Transition: BB_0x103416beL -> BB_0x10330a8dL
                FUN_10330a8d();
                currentState = State::BB_0x103416d6L;
                break;

            case State::BB_0x103416d6L:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
