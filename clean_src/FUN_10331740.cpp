#include "FUN_10331740.h"
#include "FUN_1034150c.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10331740L,
    BB_0x10331759L,
    BB_0x10331768L,
    BB_0x1033176bL,
    Exit
};

void FUN_10331740() {
    State currentState = State::BB_0x10331740L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10331740L:
                currentState = State::BB_0x10331759L;
                break;

            case State::BB_0x10331759L:
                currentState = State::BB_0x1033176bL;
                break;

            case State::BB_0x10331768L:
                currentState = State::BB_0x1033176bL;
                break;

            case State::BB_0x1033176bL:
                FUN_1034150c();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
