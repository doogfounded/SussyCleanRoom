#include "FUN_1031e390.h"
#include "FUN_102dec40.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1031e390L,
    BB_0x1031e3abL,
    BB_0x1031e3b3L,
    BB_0x1031e3bfL,
    BB_0x1031e3c6L,
    BB_0x1031e3deL,
    BB_0x1031e3e3L,
    BB_0x1031e3ecL,
    Exit
};

void FUN_1031e390() {
    State currentState = State::BB_0x1031e390L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x1031e390L:
                currentState = State::BB_0x1031e3abL;
                break;

            case State::BB_0x1031e3abL:
                currentState = State::BB_0x1031e3b3L;
                break;

            case State::BB_0x1031e3b3L:
                currentState = State::BB_0x1031e3abL;
                break;

            case State::BB_0x1031e3bfL:
                currentState = State::BB_0x1031e3c6L;
                break;

            case State::BB_0x1031e3c6L:
                FUN_102dec40();
                currentState = State::BB_0x1031e3ecL;
                break;

            case State::BB_0x1031e3deL:
                currentState = State::BB_0x1031e3c6L;
                break;

            case State::BB_0x1031e3e3L:
                currentState = State::Exit;
                break;

            case State::BB_0x1031e3ecL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
