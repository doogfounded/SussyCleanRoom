#include "FUN_102d3270.h"
#include "FUN_10330de6.h"
#include "FUN_102baf10.h"
#include "FUN_102d1250.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d3270L,
    BB_0x102d32a2L,
    BB_0x102d32aaL,
    BB_0x102d32b4L,
    BB_0x102d32c3L,
    BB_0x102d32e0L,
    BB_0x102d3303L,
    BB_0x102d330aL,
    BB_0x102d332fL,
    BB_0x102d3338L,
    Exit
};

void FUN_102d3270() {
    State currentState = State::BB_0x102d3270L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102d3270L:
                currentState = State::BB_0x102d32a2L;
                break;

            case State::BB_0x102d32a2L:
                currentState = State::BB_0x102d32aaL;
                break;

            case State::BB_0x102d32aaL:
                currentState = State::BB_0x102d32b4L;
                break;

            case State::BB_0x102d32b4L:
                currentState = State::BB_0x102d32c3L;
                break;

            case State::BB_0x102d32c3L:
                currentState = State::BB_0x102d32e0L;
                break;

            case State::BB_0x102d32e0L:
                currentState = State::BB_0x102d3303L;
                break;

            case State::BB_0x102d3303L:
                currentState = State::BB_0x102d330aL;
                break;

            case State::BB_0x102d330aL:
                FUN_102d1250();
                FUN_102baf10();
                currentState = State::BB_0x102d332fL;
                break;

            case State::BB_0x102d332fL:
                FUN_10330de6();
                currentState = State::BB_0x102d3338L;
                break;

            case State::BB_0x102d3338L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
