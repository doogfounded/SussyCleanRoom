#include "FUN_1033685b.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033685bL,
    BB_0x10336866L,
    BB_0x1033687fL,
    Exit
};

void FUN_1033685b() {
    State currentState = State::BB_0x1033685bL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033685bL:
                currentState = State::BB_0x10336866L;
                break;

            case State::BB_0x10336866L:
                currentState = State::Exit;
                break;

            case State::BB_0x1033687fL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
