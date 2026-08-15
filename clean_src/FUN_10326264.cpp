#include "FUN_10326264.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10326264L,
    Exit
};

void FUN_10326264() {
    State currentState = State::BB_0x10326264L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10326264L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
