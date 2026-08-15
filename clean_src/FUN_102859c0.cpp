#include "FUN_102859c0.h"
#include "FUN_103263ce.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102859c0L,
    Exit
};

void FUN_102859c0() {
    State currentState = State::BB_0x102859c0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102859c0L:
                FUN_103263ce();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
