#include "FUN_102e18a0.h"
#include "FUN_102d1580.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102e18a0L,
    BB_0x102e18abL,
    BB_0x102e18b0L,
    BB_0x102e18bcL,
    BB_0x102e18c0L,
    BB_0x102e18ccL,
    BB_0x102e18d0L,
    BB_0x102e18e0L,
    BB_0x102e18e4L,
    BB_0x102e18ecL,
    BB_0x102e18f6L,
    BB_0x102e18faL,
    BB_0x102e1906L,
    BB_0x102e190aL,
    BB_0x102e191aL,
    BB_0x102e191eL,
    BB_0x102e192aL,
    Exit
};

void FUN_102e18a0() {
    State currentState = State::BB_0x102e18a0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102e18a0L:
                currentState = State::BB_0x102e18abL;
                break;

            case State::BB_0x102e18abL:
                currentState = State::BB_0x102e18b0L;
                break;

            case State::BB_0x102e18b0L:
                currentState = State::BB_0x102e18bcL;
                break;

            case State::BB_0x102e18bcL:
                currentState = State::BB_0x102e18c0L;
                break;

            case State::BB_0x102e18c0L:
                currentState = State::BB_0x102e18d0L;
                break;

            case State::BB_0x102e18ccL:
                currentState = State::BB_0x102e18e0L;
                break;

            case State::BB_0x102e18d0L:
                FUN_102d1580();
                currentState = State::BB_0x102e18e0L;
                break;

            case State::BB_0x102e18e0L:
                currentState = State::BB_0x102e18e4L;
                break;

            case State::BB_0x102e18e4L:
                currentState = State::BB_0x102e18ecL;
                break;

            case State::BB_0x102e18ecL:
                currentState = State::BB_0x102e18f6L;
                break;

            case State::BB_0x102e18f6L:
                currentState = State::BB_0x102e18faL;
                break;

            case State::BB_0x102e18faL:
                currentState = State::BB_0x102e190aL;
                break;

            case State::BB_0x102e1906L:
                currentState = State::BB_0x102e191aL;
                break;

            case State::BB_0x102e190aL:
                FUN_102d1580();
                currentState = State::BB_0x102e191aL;
                break;

            case State::BB_0x102e191aL:
                currentState = State::BB_0x102e191eL;
                break;

            case State::BB_0x102e191eL:
                currentState = State::BB_0x102e192aL;
                break;

            case State::BB_0x102e192aL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
