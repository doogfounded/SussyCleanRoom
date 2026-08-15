#include "FUN_103262c3.h"
#include "FUN_1030f540.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103262c3L,
    Exit
};

void FUN_103262c3() {
    State currentState = State::BB_0x103262c3L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103262c3L:
                FUN_1030f540();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
