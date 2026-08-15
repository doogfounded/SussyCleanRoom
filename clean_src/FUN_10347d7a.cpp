#include "FUN_10347d7a.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10347d7aL,
    BB_0x1033daceL,
    Exit
};

void FUN_10347d7a() {
    State currentState = State::BB_0x10347d7aL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10347d7aL:
                currentState = State::BB_0x1033daceL;
                break;

            case State::BB_0x1033daceL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
