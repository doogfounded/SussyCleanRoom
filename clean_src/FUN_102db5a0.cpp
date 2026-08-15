#include "FUN_102db5a0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102db5a0L,
    BB_0x102db5b0L,
    BB_0x102db5b6L,
    BB_0x102db5baL,
    BB_0x102db5c2L,
    BB_0x102db5ccL,
    BB_0x102db5d7L,
    Exit
};

void FUN_102db5a0() {
    State currentState = State::BB_0x102db5a0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102db5a0L:
                currentState = State::BB_0x102db5b0L;
                break;

            case State::BB_0x102db5b0L:
                currentState = State::BB_0x102db5b6L;
                break;

            case State::BB_0x102db5b6L:
                currentState = State::BB_0x102db5baL;
                break;

            case State::BB_0x102db5baL:
                currentState = State::BB_0x102db5c2L;
                break;

            case State::BB_0x102db5c2L:
                currentState = State::BB_0x102db5ccL;
                break;

            case State::BB_0x102db5ccL:
                currentState = State::BB_0x102db5d7L;
                break;

            case State::BB_0x102db5d7L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
