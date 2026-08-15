#include "FUN_103415f5.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103415f5L,
    Exit
};

void FUN_103415f5() {
    State currentState = State::BB_0x103415f5L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103415f5L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
