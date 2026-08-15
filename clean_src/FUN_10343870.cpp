#include "FUN_10343870.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10343870L,
    BB_0x10343881L,
    BB_0x10343883L,
    BB_0x1034388cL,
    BB_0x1034388eL,
    BB_0x10343893L,
    BB_0x1034389aL,
    BB_0x1034389fL,
    BB_0x103438a4L,
    BB_0x103438a9L,
    BB_0x103438b0L,
    BB_0x103438b7L,
    BB_0x103438beL,
    BB_0x103438c7L,
    BB_0x103438c9L,
    BB_0x103438d0L,
    BB_0x103438d5L,
    BB_0x103438daL,
    BB_0x103438e1L,
    BB_0x103438e6L,
    BB_0x103438ebL,
    BB_0x103438edL,
    BB_0x103438f0L,
    BB_0x103438f2L,
    BB_0x103438fcL,
    Exit
};

void FUN_10343870() {
    State currentState = State::BB_0x10343870L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10343870L:
                currentState = State::BB_0x10343881L;
                break;

            case State::BB_0x10343881L:
                currentState = State::BB_0x10343883L;
                break;

            case State::BB_0x10343883L:
                currentState = State::BB_0x1034388cL;
                break;

            case State::BB_0x1034388cL:
                currentState = State::BB_0x1034388eL;
                break;

            case State::BB_0x1034388eL:
                currentState = State::BB_0x10343893L;
                break;

            case State::BB_0x10343893L:
                currentState = State::BB_0x1034389aL;
                break;

            case State::BB_0x1034389aL:
                currentState = State::BB_0x1034389fL;
                break;

            case State::BB_0x1034389fL:
                currentState = State::BB_0x103438a4L;
                break;

            case State::BB_0x103438a4L:
                currentState = State::BB_0x103438f0L;
                break;

            case State::BB_0x103438a9L:
                currentState = State::BB_0x103438b0L;
                break;

            case State::BB_0x103438b0L:
                currentState = State::BB_0x103438b7L;
                break;

            case State::BB_0x103438b7L:
                currentState = State::BB_0x103438ebL;
                break;

            case State::BB_0x103438beL:
                currentState = State::BB_0x103438c7L;
                break;

            case State::BB_0x103438c7L:
                currentState = State::BB_0x103438c9L;
                break;

            case State::BB_0x103438c9L:
                currentState = State::BB_0x103438d0L;
                break;

            case State::BB_0x103438d0L:
                currentState = State::BB_0x103438d5L;
                break;

            case State::BB_0x103438d5L:
                currentState = State::BB_0x103438ebL;
                break;

            case State::BB_0x103438daL:
                currentState = State::BB_0x103438e1L;
                break;

            case State::BB_0x103438e1L:
                currentState = State::BB_0x103438e6L;
                break;

            case State::BB_0x103438e6L:
                currentState = State::BB_0x103438ebL;
                break;

            case State::BB_0x103438ebL:
                currentState = State::BB_0x103438edL;
                break;

            case State::BB_0x103438edL:
                currentState = State::BB_0x103438f0L;
                break;

            case State::BB_0x103438f0L:
                currentState = State::BB_0x103438fcL;
                break;

            case State::BB_0x103438f2L:
                currentState = State::BB_0x103438fcL;
                break;

            case State::BB_0x103438fcL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
