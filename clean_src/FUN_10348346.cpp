#include "FUN_10348346.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10348346L,
    BB_0x1033daceL,
    Exit
};

void FUN_10348346() {
    State currentState = State::BB_0x10348346L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10348346L:
                currentState = State::BB_0x1033daceL;
                break;

            case State::BB_0x1033daceL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
