#include "FUN_10330aed.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330aedL,
    Exit
};

void FUN_10330aed() {
    State currentState = State::BB_0x10330aedL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330aedL:
                // Terminal node: BB_0x10330aedL
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
