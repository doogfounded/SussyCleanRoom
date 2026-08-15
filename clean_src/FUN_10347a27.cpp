#include "FUN_10347a27.h"
#include "FUN_1034798f.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10347a27L,
    Exit
};

void FUN_10347a27() {
    State currentState = State::BB_0x10347a27L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10347a27L:
                FUN_1034798f();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
