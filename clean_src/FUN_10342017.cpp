#include "FUN_10342017.h"
#include "FUN_10347d1a.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10342017L,
    BB_0x1034202eL,
    BB_0x1034203eL,
    BB_0x10342045L,
    Exit
};

void FUN_10342017() {
    State currentState = State::BB_0x10342017L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10342017L:
                currentState = State::BB_0x1034202eL;
                break;

            case State::BB_0x1034202eL:
                currentState = State::BB_0x1034203eL;
                break;

            case State::BB_0x1034203eL:
                FUN_10347d1a();
                currentState = State::BB_0x10342045L;
                break;

            case State::BB_0x10342045L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
