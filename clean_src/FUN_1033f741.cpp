#include "FUN_1033f741.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033f741L,
    Exit
};

void FUN_1033f741() {
    State currentState = State::BB_0x1033f741L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033f741L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
