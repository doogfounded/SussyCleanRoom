#include "FUN_1034e5d0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034e5d0L,
    Exit
};

void FUN_1034e5d0() {
    State currentState = State::BB_0x1034e5d0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034e5d0L:
                // Terminal node: BB_0x1034e5d0L
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
