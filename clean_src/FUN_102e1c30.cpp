#include "FUN_102e1c30.h"
#include "FUN_103283b0.h"
#include "FUN_102b9100.h"
#include "FUN_102e18a0.h"
#include "FUN_102d14c0.h"
#include "FUN_102d1580.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102e1c30L,
    BB_0x102e1c50L,
    BB_0x102e1c54L,
    BB_0x102e1c7dL,
    BB_0x102e1c81L,
    BB_0x102e1cb0L,
    BB_0x102e1ce5L,
    BB_0x102e1cfaL,
    BB_0x102e1d0bL,
    BB_0x102e1d0fL,
    BB_0x102e1d1cL,
    BB_0x102e1d20L,
    BB_0x102e1d30L,
    BB_0x102e1d34L,
    BB_0x102e1d39L,
    BB_0x102e1d6eL,
    Exit
};

void FUN_102e1c30() {
    State currentState = State::BB_0x102e1c30L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102e1c30L:
                currentState = State::BB_0x102e1c50L;
                break;

            case State::BB_0x102e1c50L:
                currentState = State::BB_0x102e1c54L;
                break;

            case State::BB_0x102e1c54L:
                FUN_103283b0();
                currentState = State::BB_0x102e1c81L;
                break;

            case State::BB_0x102e1c7dL:
                currentState = State::BB_0x102e1c50L;
                break;

            case State::BB_0x102e1c81L:
                FUN_102b9100();
                FUN_102e18a0();
                currentState = State::BB_0x102e1cb0L;
                break;

            case State::BB_0x102e1cb0L:
                FUN_102e18a0();
                currentState = State::BB_0x102e1ce5L;
                break;

            case State::BB_0x102e1ce5L:
                FUN_102d14c0();
                currentState = State::BB_0x102e1cfaL;
                break;

            case State::BB_0x102e1cfaL:
                currentState = State::BB_0x102e1d0bL;
                break;

            case State::BB_0x102e1d0bL:
                currentState = State::BB_0x102e1d0fL;
                break;

            case State::BB_0x102e1d0fL:
                currentState = State::BB_0x102e1d20L;
                break;

            case State::BB_0x102e1d1cL:
                currentState = State::BB_0x102e1d30L;
                break;

            case State::BB_0x102e1d20L:
                FUN_102d1580();
                currentState = State::BB_0x102e1d30L;
                break;

            case State::BB_0x102e1d30L:
                currentState = State::BB_0x102e1d39L;
                break;

            case State::BB_0x102e1d34L:
                currentState = State::BB_0x102e1cfaL;
                break;

            case State::BB_0x102e1d39L:
                FUN_102e18a0();
                currentState = State::BB_0x102e1d6eL;
                break;

            case State::BB_0x102e1d6eL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
