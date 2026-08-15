#include "FUN_1033f9dc.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033f9dcL,
    BB_0x1033daceL,
    Exit
};

void FUN_1033f9dc() {
    State currentState = State::BB_0x1033f9dcL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033f9dcL:
                // Transition: BB_0x1033f9dcL -> BB_0x1033daceL
                currentState = State::BB_0x1033daceL;
                break;

            case State::BB_0x1033daceL:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
