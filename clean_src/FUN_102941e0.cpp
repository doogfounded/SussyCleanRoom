#include "FUN_102941e0.h"
#include "FUN_102b5010.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102941e0L,
    Exit
};

void FUN_102941e0() {
    State currentState = State::BB_0x102941e0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102941e0L:
                FUN_102b5010();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
