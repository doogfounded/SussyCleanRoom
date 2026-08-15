#include "FUN_10350185.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10350185L,
    Exit
};

void FUN_10350185() {
    State currentState = State::BB_0x10350185L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10350185L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
