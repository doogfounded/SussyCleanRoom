#include "FUN_102dc7a0.h"
#include "FUN_102eade0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102dc7a0L,
    Exit
};

void FUN_102dc7a0() {
    State currentState = State::BB_0x102dc7a0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102dc7a0L:
                FUN_102eade0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
