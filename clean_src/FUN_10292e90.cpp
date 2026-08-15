#include "FUN_10292e90.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10292e90L,
    BB_0x10292ea3L,
    BB_0x10292ea8L,
    BB_0x10292eb0L,
    BB_0x10292eb5L,
    BB_0x10292ec2L,
    BB_0x10292ec6L,
    BB_0x10292ecaL,
    BB_0x10292eddL,
    BB_0x10292ee5L,
    Exit
};

void FUN_10292e90() {
    State currentState = State::BB_0x10292e90L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10292e90L:
                currentState = State::BB_0x10292ea3L;
                break;

            case State::BB_0x10292ea3L:
                currentState = State::BB_0x10292ea8L;
                break;

            case State::BB_0x10292ea8L:
                currentState = State::BB_0x10292eb0L;
                break;

            case State::BB_0x10292eb0L:
                currentState = State::BB_0x10292eb5L;
                break;

            case State::BB_0x10292eb5L:
                currentState = State::BB_0x10292ec6L;
                break;

            case State::BB_0x10292ec2L:
                currentState = State::BB_0x10292ea3L;
                break;

            case State::BB_0x10292ec6L:
                currentState = State::BB_0x10292eddL;
                break;

            case State::BB_0x10292ecaL:
                currentState = State::BB_0x10292eddL;
                break;

            case State::BB_0x10292eddL:
                currentState = State::Exit;
                break;

            case State::BB_0x10292ee5L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
