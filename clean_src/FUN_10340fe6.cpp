#include "FUN_10340fe6.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10340fe6L,
    BB_0x1033daceL,
    Exit
};

void FUN_10340fe6() {
    State currentState = State::BB_0x10340fe6L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10340fe6L:
                // Transition: BB_0x10340fe6L -> BB_0x1033daceL
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
