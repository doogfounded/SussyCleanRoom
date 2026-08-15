#include "FUN_102dec40.h"
#include "FUN_102dfa30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102dec40L,
    Exit
};

void FUN_102dec40() {
    State currentState = State::BB_0x102dec40L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102dec40L:
                FUN_102dfa30();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
