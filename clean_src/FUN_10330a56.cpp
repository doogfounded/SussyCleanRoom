#include "FUN_10330a56.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330a56L,
    BB_0x103309f0L,
    Exit
};

void FUN_10330a56() {
    State currentState = State::BB_0x10330a56L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330a56L:
                // Transition: BB_0x10330a56L -> BB_0x103309f0L
                currentState = State::BB_0x103309f0L;
                break;

            case State::BB_0x103309f0L:
                // Exit block (CRT call bypassed)
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
