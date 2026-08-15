#include "FUN_10330e01.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330e01L,
    Exit
};

void FUN_10330e01() {
    State currentState = State::BB_0x10330e01L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330e01L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
