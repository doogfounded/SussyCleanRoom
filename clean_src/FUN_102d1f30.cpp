#include "FUN_102d1f30.h"
#include "FUN_102d1e90.h"
#include "FUN_102dec40.h"
#include "FUN_102ea260.h"
#include "FUN_102b1da0.h"
#include "FUN_102954d0.h"
#include "FUN_102d1890.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d1f30L,
    BB_0x102d1f49L,
    BB_0x102d1f50L,
    BB_0x102d1f57L,
    BB_0x102d1f6aL,
    BB_0x102d1f77L,
    BB_0x102d1f88L,
    BB_0x102d1faeL,
    BB_0x102d1feaL,
    BB_0x102d2008L,
    BB_0x102d202dL,
    BB_0x102d2036L,
    BB_0x102d203bL,
    BB_0x102d2064L,
    Exit
};

void FUN_102d1f30() {
    State currentState = State::BB_0x102d1f30L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102d1f30L:
                currentState = State::BB_0x102d1f49L;
                break;

            case State::BB_0x102d1f49L:
                currentState = State::BB_0x102d1f50L;
                break;

            case State::BB_0x102d1f50L:
                currentState = State::BB_0x102d1f57L;
                break;

            case State::BB_0x102d1f57L:
                FUN_102d1e90();
                currentState = State::BB_0x102d2064L;
                break;

            case State::BB_0x102d1f6aL:
                currentState = State::BB_0x102d1f77L;
                break;

            case State::BB_0x102d1f77L:
                FUN_102d1e90();
                currentState = State::BB_0x102d2064L;
                break;

            case State::BB_0x102d1f88L:
                FUN_102dec40();
                currentState = State::BB_0x102d1faeL;
                break;

            case State::BB_0x102d1faeL:
                FUN_102ea260();
                FUN_102ea260();
                FUN_102b1da0();
                currentState = State::BB_0x102d2064L;
                break;

            case State::BB_0x102d1feaL:
                FUN_102dec40();
                currentState = State::BB_0x102d2008L;
                break;

            case State::BB_0x102d2008L:
                FUN_102ea260();
                FUN_102b1da0();
                currentState = State::BB_0x102d2064L;
                break;

            case State::BB_0x102d202dL:
                currentState = State::BB_0x102d2036L;
                break;

            case State::BB_0x102d2036L:
                currentState = State::BB_0x102d203bL;
                break;

            case State::BB_0x102d203bL:
                FUN_102954d0();
                FUN_102d1890();
                currentState = State::BB_0x102d2064L;
                break;

            case State::BB_0x102d2064L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
