#include "FUN_102b3ad0.h"
#include "FUN_102ef3b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b3ad0L,
    Exit
};

void FUN_102b3ad0() {
    State currentState = State::BB_0x102b3ad0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102b3ad0L:
                FUN_102ef3b0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
