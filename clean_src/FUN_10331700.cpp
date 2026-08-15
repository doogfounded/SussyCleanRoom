#include "FUN_10331700.h"
#include "FUN_10331790.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10331700L,
    BB_0x1033170cL,
    BB_0x10331715L,
    BB_0x1033171bL,
    BB_0x10331726L,
    BB_0x1033172cL,
    BB_0x10331739L,
    Exit
};

void FUN_10331700() {
    State currentState = State::BB_0x10331700L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10331700L:
                currentState = State::BB_0x10331715L;
                break;

            case State::BB_0x1033170cL:
                currentState = State::BB_0x10331715L;
                break;

            case State::BB_0x10331715L:
                currentState = State::BB_0x1033171bL;
                break;

            case State::BB_0x1033171bL:
                FUN_10331790();
                currentState = State::BB_0x10331726L;
                break;

            case State::BB_0x10331726L:
                currentState = State::BB_0x1033172cL;
                break;

            case State::BB_0x1033172cL:
                FUN_10331790();
                currentState = State::BB_0x10331739L;
                break;

            case State::BB_0x10331739L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
