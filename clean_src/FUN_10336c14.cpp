#include "FUN_10336c14.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10336c14L,
    Exit
};

void FUN_10336c14() {
    State currentState = State::BB_0x10336c14L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10336c14L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
