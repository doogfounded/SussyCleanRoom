#include "FUN_10336ce7.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10336ce7L,
    Exit
};

void FUN_10336ce7() {
    State currentState = State::BB_0x10336ce7L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10336ce7L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
