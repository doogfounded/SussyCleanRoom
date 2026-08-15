#include "FUN_10002810.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10002810L,
    BB_0x10002828L,
    BB_0x10002838L,
    BB_0x1000283dL,
    Exit
};

void FUN_10002810() {
    State currentState = State::BB_0x10002810L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10002810L:
                currentState = State::BB_0x10002828L;
                break;

            case State::BB_0x10002828L:
                currentState = State::BB_0x10002838L;
                break;

            case State::BB_0x10002838L:
                currentState = State::BB_0x1000283dL;
                break;

            case State::BB_0x1000283dL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
