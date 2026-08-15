#include "FUN_1034a0b2.h"
#include "FUN_1034f83e.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034a0b2L,
    BB_0x1034a0d7L,
    BB_0x1034a0e2L,
    BB_0x1034a0e7L,
    BB_0x1034a0eeL,
    BB_0x1034a0f1L,
    Exit
};

void FUN_1034a0b2() {
    State currentState = State::BB_0x1034a0b2L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034a0b2L:
                FUN_1034f83e();
                currentState = State::BB_0x1034a0d7L;
                break;

            case State::BB_0x1034a0d7L:
                currentState = State::BB_0x1034a0e7L;
                break;

            case State::BB_0x1034a0e2L:
                currentState = State::BB_0x1034a0e7L;
                break;

            case State::BB_0x1034a0e7L:
                currentState = State::BB_0x1034a0f1L;
                break;

            case State::BB_0x1034a0eeL:
                currentState = State::BB_0x1034a0f1L;
                break;

            case State::BB_0x1034a0f1L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
