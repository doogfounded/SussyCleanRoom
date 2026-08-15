#include "FUN_1033f53a.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033f53aL,
    BB_0x1033daceL,
    Exit
};

void FUN_1033f53a() {
    State currentState = State::BB_0x1033f53aL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033f53aL:
                // Transition: BB_0x1033f53aL -> BB_0x1033daceL
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
