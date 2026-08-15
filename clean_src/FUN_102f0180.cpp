#include "FUN_102f0180.h"
#include "FUN_102edd10.h"
#include "FUN_10292e90.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102f0180L,
    BB_0x102f01a3L,
    BB_0x102f01b6L,
    BB_0x102f01caL,
    BB_0x102f01e2L,
    BB_0x102f01f2L,
    BB_0x102f0201L,
    BB_0x102f0213L,
    BB_0x102f0219L,
    BB_0x102f0226L,
    BB_0x102f0234L,
    BB_0x102f0245L,
    BB_0x102f024aL,
    BB_0x102f027fL,
    BB_0x102f0286L,
    Exit
};

void FUN_102f0180() {
    State currentState = State::BB_0x102f0180L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102f0180L:
                currentState = State::BB_0x102f01a3L;
                break;

            case State::BB_0x102f01a3L:
                currentState = State::BB_0x102f01b6L;
                break;

            case State::BB_0x102f01b6L:
                currentState = State::BB_0x102f01caL;
                break;

            case State::BB_0x102f01caL:
                currentState = State::BB_0x102f01e2L;
                break;

            case State::BB_0x102f01e2L:
                currentState = State::BB_0x102f0201L;
                break;

            case State::BB_0x102f01f2L:
                currentState = State::BB_0x102f0201L;
                break;

            case State::BB_0x102f0201L:
                currentState = State::BB_0x102f0219L;
                break;

            case State::BB_0x102f0213L:
                currentState = State::BB_0x102f0219L;
                break;

            case State::BB_0x102f0219L:
                currentState = State::BB_0x102f0234L;
                break;

            case State::BB_0x102f0226L:
                FUN_102edd10();
                currentState = State::BB_0x102f0234L;
                break;

            case State::BB_0x102f0234L:
                currentState = State::BB_0x102f0245L;
                break;

            case State::BB_0x102f0245L:
                currentState = State::BB_0x102f024aL;
                break;

            case State::BB_0x102f024aL:
                FUN_10292e90();
                currentState = State::BB_0x102f0286L;
                break;

            case State::BB_0x102f027fL:
                currentState = State::BB_0x102f0286L;
                break;

            case State::BB_0x102f0286L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
