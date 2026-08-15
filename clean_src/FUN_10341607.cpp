#include "FUN_10341607.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10341607L,
    Exit
};

void FUN_10341607() {
    State currentState = State::BB_0x10341607L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10341607L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
