#include "FUN_102b9010.h"
#include "FUN_10330e01.h"
#include "FUN_10336ce7.h"
#include "FUN_10336c14.h"
#include "FUN_10330dd0.h"
#include "FUN_103283b0.h"
#include "_fprintf.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b9010L,
    BB_0x102b9020L,
    BB_0x102b9032L,
    BB_0x102b9037L,
    BB_0x102b9054L,
    BB_0x102b9055L,
    BB_0x102b9058L,
    BB_0x102b9064L,
    BB_0x102b9076L,
    BB_0x102b90dcL,
    Exit
};

void FUN_102b9010() {
    State currentState = State::BB_0x102b9010L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b9010L:
                currentState = State::BB_0x102b9020L;
                break;

            case State::BB_0x102b9020L:
                FUN_10330e01();
                currentState = State::BB_0x102b9055L;
                break;

            case State::BB_0x102b9032L:
                currentState = State::BB_0x102b9037L;
                break;

            case State::BB_0x102b9037L:
                FUN_10336c14();
                currentState = State::BB_0x102b90dcL;
                break;

            case State::BB_0x102b9054L:
                currentState = State::BB_0x102b9055L;
                break;

            case State::BB_0x102b9055L:
                currentState = State::BB_0x102b9058L;
                break;

            case State::BB_0x102b9058L:
                currentState = State::BB_0x102b9064L;
                break;

            case State::BB_0x102b9064L:
                currentState = State::BB_0x102b9076L;
                break;

            case State::BB_0x102b9076L:
                FUN_103283b0();
                FUN_103283b0();
                currentState = State::Exit;
                break;

            case State::BB_0x102b90dcL:
                FUN_10336ce7();
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
