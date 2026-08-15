#include "FUN_102b9680.h"
#include "FUN_10330e01.h"
#include "FUN_103283b0.h"
#include "FUN_102b8ec0.h"
#include "FUN_102db5a0.h"
#include "FUN_10336c14.h"
#include "FUN_10336ce7.h"
#include "FUN_10330dd0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b9680L,
    BB_0x102b96a0L,
    BB_0x102b96a5L,
    BB_0x102b96cdL,
    BB_0x102b96d1L,
    BB_0x102b96deL,
    BB_0x102b96edL,
    BB_0x102b96f0L,
    BB_0x102b96ffL,
    BB_0x102b9700L,
    BB_0x102b9718L,
    BB_0x102b97a0L,
    BB_0x102b97d5L,
    BB_0x102b97f1L,
    BB_0x102b97f3L,
    BB_0x102b9806L,
    BB_0x102b981bL,
    BB_0x102b981eL,
    BB_0x102b9826L,
    BB_0x102b9837L,
    BB_0x102b983bL,
    BB_0x102b984eL,
    BB_0x102b9853L,
    BB_0x102b985cL,
    BB_0x102b9876L,
    BB_0x102b987bL,
    BB_0x102b98b0L,
    BB_0x102b98bcL,
    Exit
};

void FUN_102b9680() {
    State currentState = State::BB_0x102b9680L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b9680L:
                currentState = State::BB_0x102b96a0L;
                break;

            case State::BB_0x102b96a0L:
                currentState = State::BB_0x102b96a5L;
                break;

            case State::BB_0x102b96a5L:
                FUN_103283b0();
                currentState = State::BB_0x102b96d1L;
                break;

            case State::BB_0x102b96cdL:
                currentState = State::BB_0x102b96a0L;
                break;

            case State::BB_0x102b96d1L:
                currentState = State::BB_0x102b96deL;
                break;

            case State::BB_0x102b96deL:
                FUN_10330e01();
                currentState = State::BB_0x102b96edL;
                break;

            case State::BB_0x102b96edL:
                currentState = State::BB_0x102b96f0L;
                break;

            case State::BB_0x102b96f0L:
                currentState = State::BB_0x102b96ffL;
                break;

            case State::BB_0x102b96ffL:
                currentState = State::BB_0x102b9700L;
                break;

            case State::BB_0x102b9700L:
                currentState = State::BB_0x102b9718L;
                break;

            case State::BB_0x102b9718L:
                FUN_103283b0();
                FUN_102b8ec0();
                currentState = State::BB_0x102b97a0L;
                break;

            case State::BB_0x102b97a0L:
                FUN_102b8ec0();
                currentState = State::BB_0x102b97d5L;
                break;

            case State::BB_0x102b97d5L:
                currentState = State::BB_0x102b97f1L;
                break;

            case State::BB_0x102b97f1L:
                currentState = State::BB_0x102b97f3L;
                break;

            case State::BB_0x102b97f3L:
                currentState = State::BB_0x102b981bL;
                break;

            case State::BB_0x102b9806L:
                currentState = State::BB_0x102b981bL;
                break;

            case State::BB_0x102b981bL:
                currentState = State::BB_0x102b981eL;
                break;

            case State::BB_0x102b981eL:
                currentState = State::BB_0x102b9826L;
                break;

            case State::BB_0x102b9826L:
                currentState = State::BB_0x102b9837L;
                break;

            case State::BB_0x102b9837L:
                currentState = State::BB_0x102b983bL;
                break;

            case State::BB_0x102b983bL:
                FUN_102db5a0();
                currentState = State::BB_0x102b984eL;
                break;

            case State::BB_0x102b984eL:
                currentState = State::BB_0x102b9826L;
                break;

            case State::BB_0x102b9853L:
                currentState = State::BB_0x102b985cL;
                break;

            case State::BB_0x102b985cL:
                FUN_10336c14();
                currentState = State::BB_0x102b98bcL;
                break;

            case State::BB_0x102b9876L:
                currentState = State::BB_0x102b96edL;
                break;

            case State::BB_0x102b987bL:
                FUN_102b8ec0();
                currentState = State::BB_0x102b97a0L;
                break;

            case State::BB_0x102b98b0L:
                currentState = State::Exit;
                break;

            case State::BB_0x102b98bcL:
                FUN_10336ce7();
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
