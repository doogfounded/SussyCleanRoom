#include "FUN_1034834f.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034834fL,
    Exit
};

void FUN_1034834f() {
    State currentState = State::BB_0x1034834fL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034834fL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
