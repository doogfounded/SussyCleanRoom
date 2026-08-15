#include "FUN_103316a0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103316a0L,
    BB_0x103316c4L,
    BB_0x103316d9L,
    BB_0x103316e2L,
    BB_0x103316f7L,
    Exit
};

void FUN_103316a0() {
    State currentState = State::BB_0x103316a0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103316a0L:
                // Transition: BB_0x103316a0L -> BB_0x103316d9L
                currentState = State::BB_0x103316d9L;
                break;

            case State::BB_0x103316c4L:
                // Exit block
                currentState = State::Exit;
                break;

            case State::BB_0x103316d9L:
                // Transition: BB_0x103316d9L -> BB_0x103316e2L
                currentState = State::BB_0x103316e2L;
                break;

            case State::BB_0x103316e2L:
                // Transition: BB_0x103316e2L -> BB_0x103316f7L
                currentState = State::BB_0x103316f7L;
                break;

            case State::BB_0x103316f7L:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
