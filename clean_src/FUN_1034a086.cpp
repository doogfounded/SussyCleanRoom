#include "FUN_1034a086.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034a086L,
    BB_0x1034a093L,
    BB_0x1034a098L,
    BB_0x1034a09eL,
    BB_0x1034a0a3L,
    BB_0x1034a0aeL,
    Exit
};

void FUN_1034a086() {
    State currentState = State::BB_0x1034a086L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034a086L:
                currentState = State::BB_0x1034a098L;
                break;

            case State::BB_0x1034a093L:
                currentState = State::BB_0x1034a0aeL;
                break;

            case State::BB_0x1034a098L:
                currentState = State::BB_0x1034a09eL;
                break;

            case State::BB_0x1034a09eL:
                currentState = State::BB_0x1034a0aeL;
                break;

            case State::BB_0x1034a0a3L:
                currentState = State::BB_0x1034a0aeL;
                break;

            case State::BB_0x1034a0aeL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
