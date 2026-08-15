#include "FUN_1027eb50.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1027eb50L,
    Exit
};

void FUN_1027eb50() {
    State currentState = State::BB_0x1027eb50L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1027eb50L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
