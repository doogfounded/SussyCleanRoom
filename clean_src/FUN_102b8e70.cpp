#include "FUN_102b8e70.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b8e70L,
    BB_0x102b8e7aL,
    BB_0x102b8e81L,
    BB_0x102b8e8bL,
    BB_0x102b8e8fL,
    BB_0x102b8e97L,
    BB_0x102b8e9dL,
    BB_0x102b8ea4L,
    BB_0x102b8ea8L,
    BB_0x102b8eb0L,
    BB_0x102b8eb9L,
    BB_0x102b8ebbL,
    Exit
};

void FUN_102b8e70() {
    State currentState = State::BB_0x102b8e70L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b8e70L:
                currentState = State::BB_0x102b8e7aL;
                break;

            case State::BB_0x102b8e7aL:
                currentState = State::BB_0x102b8e81L;
                break;

            case State::BB_0x102b8e81L:
                currentState = State::BB_0x102b8e8bL;
                break;

            case State::BB_0x102b8e8bL:
                currentState = State::BB_0x102b8e8fL;
                break;

            case State::BB_0x102b8e8fL:
                currentState = State::BB_0x102b8e97L;
                break;

            case State::BB_0x102b8e97L:
                currentState = State::BB_0x102b8e9dL;
                break;

            case State::BB_0x102b8e9dL:
                currentState = State::BB_0x102b8ea4L;
                break;

            case State::BB_0x102b8ea4L:
                currentState = State::BB_0x102b8ea8L;
                break;

            case State::BB_0x102b8ea8L:
                currentState = State::BB_0x102b8eb0L;
                break;

            case State::BB_0x102b8eb0L:
                currentState = State::BB_0x102b8eb9L;
                break;

            case State::BB_0x102b8eb9L:
                currentState = State::BB_0x102b8ebbL;
                break;

            case State::BB_0x102b8ebbL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
