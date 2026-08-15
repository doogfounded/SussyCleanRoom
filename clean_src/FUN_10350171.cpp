#include "FUN_10350171.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10350171L,
    Exit
};

void FUN_10350171() {
    State currentState = State::BB_0x10350171L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10350171L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
