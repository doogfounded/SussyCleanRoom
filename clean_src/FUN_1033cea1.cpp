#include "FUN_1033cea1.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033cea1L,
    Exit
};

void FUN_1033cea1() {
    State currentState = State::BB_0x1033cea1L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033cea1L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
