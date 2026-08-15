#include "FUN_103360ca.h"
#include "is_positional_parameter_reappearance_consistent.h"
#include "FUN_10336a03.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103360caL,
    BB_0x103360dcL,
    BB_0x103360edL,
    BB_0x103360efL,
    BB_0x103360f5L,
    BB_0x10336108L,
    Exit
};

void FUN_103360ca() {
    State currentState = State::BB_0x103360caL;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x103360caL:
                currentState = State::BB_0x103360dcL;
                break;

            case State::BB_0x103360dcL:
                currentState = State::BB_0x103360edL;
                break;

            case State::BB_0x103360edL:
                currentState = State::BB_0x103360efL;
                break;

            case State::BB_0x103360efL:
                currentState = State::Exit;
                break;

            case State::BB_0x103360f5L:
                is_positional_parameter_reappearance_consistent();
                currentState = State::BB_0x103360edL;
                break;

            case State::BB_0x10336108L:
                FUN_10336a03();
                currentState = State::BB_0x103360efL;
                break;
        }
    }
}

} // namespace DoogEngine1
