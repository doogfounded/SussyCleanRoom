#include "_memset.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1032a090L,
    BB_0x1032a0a7L,
    BB_0x1032a0b6L,
    BB_0x1032a0c2L,
    BB_0x1032a0ccL,
    BB_0x1032a0d5L,
    BB_0x1032a0e3L,
    BB_0x1032a101L,
    BB_0x1032a110L,
    BB_0x1032a14bL,
    BB_0x1032a14dL,
    BB_0x1032a157L,
    BB_0x1032a160L,
    BB_0x1032a165L,
    BB_0x1032a179L,
    BB_0x1032a181L,
    BB_0x1032a195L,
    BB_0x1032a19dL,
    BB_0x1032a1abL,
    BB_0x1032a1b3L,
    BB_0x1032a1bbL,
    BB_0x1032a1c3L,
    BB_0x1032a1d0L,
    BB_0x1032a1e3L,
    Exit
};

void _memset() {
    State currentState = State::BB_0x1032a090L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x1032a090L:
                currentState = State::BB_0x1032a0a7L;
                break;

            case State::BB_0x1032a0a7L:
                currentState = State::BB_0x1032a0b6L;
                break;

            case State::BB_0x1032a0b6L:
                currentState = State::BB_0x1032a0c2L;
                break;

            case State::BB_0x1032a0c2L:
                currentState = State::BB_0x1032a0d5L;
                break;

            case State::BB_0x1032a0ccL:
                currentState = State::BB_0x1032a0d5L;
                break;

            case State::BB_0x1032a0d5L:
                currentState = State::BB_0x1032a0e3L;
                break;

            case State::BB_0x1032a0e3L:
                currentState = State::BB_0x1032a101L;
                break;

            case State::BB_0x1032a101L:
                currentState = State::BB_0x1032a110L;
                break;

            case State::BB_0x1032a110L:
                currentState = State::BB_0x1032a14bL;
                break;

            case State::BB_0x1032a14bL:
                currentState = State::BB_0x1032a160L;
                break;

            case State::BB_0x1032a14dL:
                currentState = State::BB_0x1032a157L;
                break;

            case State::BB_0x1032a157L:
                currentState = State::BB_0x1032a160L;
                break;

            case State::BB_0x1032a160L:
                currentState = State::BB_0x1032a165L;
                break;

            case State::BB_0x1032a165L:
                currentState = State::BB_0x1032a179L;
                break;

            case State::BB_0x1032a179L:
                currentState = State::BB_0x1032a181L;
                break;

            case State::BB_0x1032a181L:
                currentState = State::BB_0x1032a195L;
                break;

            case State::BB_0x1032a195L:
                currentState = State::BB_0x1032a19dL;
                break;

            case State::BB_0x1032a19dL:
                currentState = State::BB_0x1032a1abL;
                break;

            case State::BB_0x1032a1abL:
                currentState = State::BB_0x1032a1bbL;
                break;

            case State::BB_0x1032a1b3L:
                currentState = State::BB_0x1032a1bbL;
                break;

            case State::BB_0x1032a1bbL:
                currentState = State::BB_0x1032a1c3L;
                break;

            case State::BB_0x1032a1c3L:
                currentState = State::BB_0x1032a1d0L;
                break;

            case State::BB_0x1032a1d0L:
                currentState = State::BB_0x1032a1e3L;
                break;

            case State::BB_0x1032a1e3L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
