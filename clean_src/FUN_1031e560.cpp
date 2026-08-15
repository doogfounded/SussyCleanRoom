#include "FUN_1031e560.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1031e560L,
    BB_0x1031e588L,
    BB_0x1031e58fL,
    BB_0x1031e596L,
    BB_0x1031e5a1L,
    BB_0x1031e5b8L,
    BB_0x1031e5d9L,
    BB_0x1031e5e0L,
    BB_0x1031e5fdL,
    BB_0x1031e604L,
    Exit
};

void FUN_1031e560() {
    State currentState = State::BB_0x1031e560L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x1031e560L:
                currentState = State::BB_0x1031e588L;
                break;

            case State::BB_0x1031e588L:
                currentState = State::BB_0x1031e58fL;
                break;

            case State::BB_0x1031e58fL:
                currentState = State::BB_0x1031e5a1L;
                break;

            case State::BB_0x1031e596L:
                currentState = State::BB_0x1031e604L;
                break;

            case State::BB_0x1031e5a1L:
                currentState = State::BB_0x1031e5b8L;
                break;

            case State::BB_0x1031e5b8L:
                currentState = State::BB_0x1031e5d9L;
                break;

            case State::BB_0x1031e5d9L:
                currentState = State::BB_0x1031e5e0L;
                break;

            case State::BB_0x1031e5e0L:
                currentState = State::BB_0x1031e5fdL;
                break;

            case State::BB_0x1031e5fdL:
                currentState = State::BB_0x1031e604L;
                break;

            case State::BB_0x1031e604L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
