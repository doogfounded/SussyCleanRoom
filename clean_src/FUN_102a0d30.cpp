#include "FUN_102a0d30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102a0d30L,
    BB_0x102a0d67L,
    BB_0x102a0d88L,
    Exit
};

void FUN_102a0d30() {
    State currentState = State::BB_0x102a0d30L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102a0d30L:
                currentState = State::BB_0x102a0d88L;
                break;

            case State::BB_0x102a0d67L:
                currentState = State::Exit;
                break;

            case State::BB_0x102a0d88L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
