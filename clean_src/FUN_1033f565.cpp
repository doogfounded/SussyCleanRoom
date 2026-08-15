#include "FUN_1033f565.h"
#include "FUN_1034169e.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033f565L,
    BB_0x1033f580L,
    BB_0x1033f5a2L,
    BB_0x1033f5b0L,
    BB_0x1033f5b2L,
    BB_0x1033f5b9L,
    BB_0x1033f5bcL,
    BB_0x1033f5c0L,
    BB_0x1033f5ddL,
    BB_0x1033f5fdL,
    BB_0x1033f614L,
    BB_0x1033f61dL,
    BB_0x1033f65fL,
    BB_0x1033f662L,
    Exit
};

void FUN_1033f565() {
    State currentState = State::BB_0x1033f565L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x1033f565L:
                currentState = State::BB_0x1033f580L;
                break;

            case State::BB_0x1033f580L:
                currentState = State::BB_0x1033f5a2L;
                break;

            case State::BB_0x1033f5a2L:
                currentState = State::BB_0x1033f5b2L;
                break;

            case State::BB_0x1033f5b0L:
                currentState = State::BB_0x1033f5b2L;
                break;

            case State::BB_0x1033f5b2L:
                currentState = State::BB_0x1033f5bcL;
                break;

            case State::BB_0x1033f5b9L:
                currentState = State::BB_0x1033f5bcL;
                break;

            case State::BB_0x1033f5bcL:
                currentState = State::BB_0x1033f5c0L;
                break;

            case State::BB_0x1033f5c0L:
                FUN_1034169e();
                currentState = State::BB_0x1033f5ddL;
                break;

            case State::BB_0x1033f5ddL:
                FUN_1034169e();
                currentState = State::BB_0x1033f5fdL;
                break;

            case State::BB_0x1033f5fdL:
                currentState = State::BB_0x1033f614L;
                break;

            case State::BB_0x1033f614L:
                currentState = State::BB_0x1033f61dL;
                break;

            case State::BB_0x1033f61dL:
                currentState = State::BB_0x1033f662L;
                break;

            case State::BB_0x1033f65fL:
                currentState = State::BB_0x1033f662L;
                break;

            case State::BB_0x1033f662L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
