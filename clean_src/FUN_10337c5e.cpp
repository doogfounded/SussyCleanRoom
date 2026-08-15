#include "FUN_10337c5e.h"
#include "FUN_10336a80.h"
#include "FUN_10330a8d.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10337c5eL,
    BB_0x10337c6cL,
    BB_0x10337c73L,
    BB_0x10337c7aL,
    BB_0x10337c7dL,
    BB_0x10337c84L,
    BB_0x10337c8cL,
    BB_0x10337c92L,
    BB_0x10337c96L,
    BB_0x10337ca0L,
    BB_0x10337ca5L,
    BB_0x10337ca9L,
    BB_0x10337cb4L,
    Exit
};

void FUN_10337c5e() {
    State currentState = State::BB_0x10337c5eL;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10337c5eL:
                currentState = State::BB_0x10337c6cL;
                break;

            case State::BB_0x10337c6cL:
                currentState = State::BB_0x10337c73L;
                break;

            case State::BB_0x10337c73L:
                currentState = State::BB_0x10337c7aL;
                break;

            case State::BB_0x10337c7aL:
                currentState = State::BB_0x10337c7dL;
                break;

            case State::BB_0x10337c7dL:
                FUN_10330a8d();
                currentState = State::BB_0x10337c84L;
                break;

            case State::BB_0x10337c84L:
                FUN_10336a80();
                currentState = State::BB_0x10337c8cL;
                break;

            case State::BB_0x10337c8cL:
                currentState = State::Exit;
                break;

            case State::BB_0x10337c92L:
                currentState = State::BB_0x10337c96L;
                break;

            case State::BB_0x10337c96L:
                currentState = State::BB_0x10337ca0L;
                break;

            case State::BB_0x10337ca0L:
                currentState = State::BB_0x10337c96L;
                break;

            case State::BB_0x10337ca5L:
                currentState = State::BB_0x10337cb4L;
                break;

            case State::BB_0x10337ca9L:
                FUN_10330a8d();
                currentState = State::BB_0x10337c84L;
                break;

            case State::BB_0x10337cb4L:
                currentState = State::BB_0x10337c8cL;
                break;
        }
    }
}

} // namespace DoogEngine1
