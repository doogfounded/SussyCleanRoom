#include "FUN_102d1580.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d1580L,
    BB_0x102d158fL,
    BB_0x102d1597L,
    BB_0x102d159bL,
    Exit
};

void FUN_102d1580() {
    State currentState = State::BB_0x102d1580L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102d1580L:
                currentState = State::BB_0x102d158fL;
                break;

            case State::BB_0x102d158fL:
                currentState = State::BB_0x102d159bL;
                break;

            case State::BB_0x102d1597L:
                currentState = State::BB_0x102d159bL;
                break;

            case State::BB_0x102d159bL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
