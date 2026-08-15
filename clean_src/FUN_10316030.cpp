#include "FUN_10316030.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10316030L,
    BB_0x1031603aL,
    BB_0x10316041L,
    BB_0x1031604bL,
    BB_0x1031604fL,
    BB_0x10316057L,
    BB_0x1031605dL,
    BB_0x10316064L,
    BB_0x10316068L,
    BB_0x10316070L,
    BB_0x10316079L,
    BB_0x1031607bL,
    Exit
};

void FUN_10316030() {
    State currentState = State::BB_0x10316030L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10316030L:
                currentState = State::BB_0x1031603aL;
                break;

            case State::BB_0x1031603aL:
                currentState = State::BB_0x10316041L;
                break;

            case State::BB_0x10316041L:
                currentState = State::BB_0x1031604bL;
                break;

            case State::BB_0x1031604bL:
                currentState = State::BB_0x1031604fL;
                break;

            case State::BB_0x1031604fL:
                currentState = State::BB_0x10316057L;
                break;

            case State::BB_0x10316057L:
                currentState = State::BB_0x1031605dL;
                break;

            case State::BB_0x1031605dL:
                currentState = State::BB_0x10316064L;
                break;

            case State::BB_0x10316064L:
                currentState = State::BB_0x10316068L;
                break;

            case State::BB_0x10316068L:
                currentState = State::BB_0x10316070L;
                break;

            case State::BB_0x10316070L:
                currentState = State::BB_0x10316041L;
                break;

            case State::BB_0x10316079L:
                currentState = State::BB_0x1031607bL;
                break;

            case State::BB_0x1031607bL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
