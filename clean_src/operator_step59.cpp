#include "operator_step59.h"
#include "FUN_1034169e.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10347e38L,
    BB_0x10347e8cL,
    BB_0x10347e99L,
    BB_0x10347ea1L,
    Exit
};

void operator_step59() {
    State currentState = State::BB_0x10347e38L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10347e38L:
                currentState = State::BB_0x10347e8cL;
                break;

            case State::BB_0x10347e8cL:
                currentState = State::BB_0x10347e99L;
                break;

            case State::BB_0x10347e99L:
                FUN_1034169e();
                currentState = State::BB_0x10347ea1L;
                break;

            case State::BB_0x10347ea1L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
