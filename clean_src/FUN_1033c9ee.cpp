#include "FUN_1033c9ee.h"
#include "FUN_10331850.h"
#include "FUN_1034a030.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033c9eeL,
    BB_0x1033ca05L,
    BB_0x1033ca1eL,
    BB_0x1033ca27L,
    BB_0x1033ca2eL,
    BB_0x1033ca3aL,
    BB_0x1033ca48L,
    BB_0x1033ca64L,
    BB_0x1033ca66L,
    Exit
};

void FUN_1033c9ee() {
    State currentState = State::BB_0x1033c9eeL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033c9eeL:
                FUN_1034a030();
                currentState = State::BB_0x1033ca05L;
                break;

            case State::BB_0x1033ca05L:
                currentState = State::BB_0x1033ca1eL;
                break;

            case State::BB_0x1033ca1eL:
                currentState = State::BB_0x1033ca27L;
                break;

            case State::BB_0x1033ca27L:
                FUN_10331850();
                currentState = State::BB_0x1033ca2eL;
                break;

            case State::BB_0x1033ca2eL:
                currentState = State::BB_0x1033ca3aL;
                break;

            case State::BB_0x1033ca3aL:
                currentState = State::BB_0x1033ca48L;
                break;

            case State::BB_0x1033ca48L:
                currentState = State::BB_0x1033ca66L;
                break;

            case State::BB_0x1033ca64L:
                currentState = State::BB_0x1033ca66L;
                break;

            case State::BB_0x1033ca66L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
