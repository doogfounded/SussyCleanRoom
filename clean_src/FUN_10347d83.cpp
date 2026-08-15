#include "FUN_10347d83.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10347d83L,
    Exit
};

void FUN_10347d83() {
    State currentState = State::BB_0x10347d83L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10347d83L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
