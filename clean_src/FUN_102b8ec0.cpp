#include "FUN_102b8ec0.h"
#include "FUN_102db5a0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b8ec0L,
    BB_0x102b8ecbL,
    BB_0x102b8ed0L,
    BB_0x102b8edcL,
    BB_0x102b8ee0L,
    BB_0x102b8ef2L,
    BB_0x102b8efaL,
    BB_0x102b8f04L,
    BB_0x102b8f08L,
    BB_0x102b8f1aL,
    BB_0x102b8f26L,
    Exit
};

void FUN_102b8ec0() {
    State currentState = State::BB_0x102b8ec0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b8ec0L:
                currentState = State::BB_0x102b8ecbL;
                break;

            case State::BB_0x102b8ecbL:
                currentState = State::BB_0x102b8ed0L;
                break;

            case State::BB_0x102b8ed0L:
                currentState = State::BB_0x102b8edcL;
                break;

            case State::BB_0x102b8edcL:
                currentState = State::BB_0x102b8ee0L;
                break;

            case State::BB_0x102b8ee0L:
                FUN_102db5a0();
                currentState = State::BB_0x102b8ef2L;
                break;

            case State::BB_0x102b8ef2L:
                currentState = State::BB_0x102b8efaL;
                break;

            case State::BB_0x102b8efaL:
                currentState = State::BB_0x102b8f04L;
                break;

            case State::BB_0x102b8f04L:
                currentState = State::BB_0x102b8f08L;
                break;

            case State::BB_0x102b8f08L:
                FUN_102db5a0();
                currentState = State::BB_0x102b8f1aL;
                break;

            case State::BB_0x102b8f1aL:
                currentState = State::BB_0x102b8f26L;
                break;

            case State::BB_0x102b8f26L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
