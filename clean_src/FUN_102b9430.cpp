#include "FUN_102b9430.h"
#include "FUN_10330e01.h"
#include "FUN_103283b0.h"
#include "FUN_102b8e70.h"
#include "FUN_10336c14.h"
#include "FUN_10336ce7.h"
#include "FUN_10330dd0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b9430L,
    BB_0x102b9450L,
    BB_0x102b9455L,
    BB_0x102b947dL,
    BB_0x102b9481L,
    BB_0x102b948eL,
    BB_0x102b949dL,
    BB_0x102b94a0L,
    BB_0x102b94afL,
    BB_0x102b94b0L,
    BB_0x102b94c8L,
    BB_0x102b9550L,
    BB_0x102b9585L,
    BB_0x102b95d0L,
    BB_0x102b95d8L,
    BB_0x102b95dcL,
    BB_0x102b95e5L,
    BB_0x102b95e8L,
    BB_0x102b95f0L,
    BB_0x102b95f9L,
    BB_0x102b9613L,
    BB_0x102b9618L,
    BB_0x102b964cL,
    BB_0x102b9658L,
    Exit
};

void FUN_102b9430() {
    State currentState = State::BB_0x102b9430L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b9430L:
                currentState = State::BB_0x102b9450L;
                break;

            case State::BB_0x102b9450L:
                currentState = State::BB_0x102b9455L;
                break;

            case State::BB_0x102b9455L:
                FUN_103283b0();
                currentState = State::BB_0x102b9481L;
                break;

            case State::BB_0x102b947dL:
                currentState = State::BB_0x102b9450L;
                break;

            case State::BB_0x102b9481L:
                currentState = State::BB_0x102b948eL;
                break;

            case State::BB_0x102b948eL:
                FUN_10330e01();
                currentState = State::BB_0x102b949dL;
                break;

            case State::BB_0x102b949dL:
                currentState = State::BB_0x102b94a0L;
                break;

            case State::BB_0x102b94a0L:
                currentState = State::BB_0x102b94afL;
                break;

            case State::BB_0x102b94afL:
                currentState = State::BB_0x102b94b0L;
                break;

            case State::BB_0x102b94b0L:
                currentState = State::BB_0x102b94c8L;
                break;

            case State::BB_0x102b94c8L:
                FUN_103283b0();
                FUN_102b8e70();
                currentState = State::BB_0x102b9550L;
                break;

            case State::BB_0x102b9550L:
                FUN_102b8e70();
                currentState = State::BB_0x102b9585L;
                break;

            case State::BB_0x102b9585L:
                currentState = State::BB_0x102b95d0L;
                break;

            case State::BB_0x102b95d0L:
                currentState = State::BB_0x102b95d8L;
                break;

            case State::BB_0x102b95d8L:
                currentState = State::BB_0x102b95e8L;
                break;

            case State::BB_0x102b95dcL:
                currentState = State::BB_0x102b95e8L;
                break;

            case State::BB_0x102b95e5L:
                currentState = State::BB_0x102b95e8L;
                break;

            case State::BB_0x102b95e8L:
                currentState = State::Exit;
                break;

            case State::BB_0x102b95f0L:
                currentState = State::BB_0x102b95f9L;
                break;

            case State::BB_0x102b95f9L:
                FUN_10336c14();
                currentState = State::BB_0x102b9658L;
                break;

            case State::BB_0x102b9613L:
                currentState = State::BB_0x102b949dL;
                break;

            case State::BB_0x102b9618L:
                FUN_102b8e70();
                currentState = State::BB_0x102b9550L;
                break;

            case State::BB_0x102b964cL:
                currentState = State::Exit;
                break;

            case State::BB_0x102b9658L:
                FUN_10336ce7();
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
