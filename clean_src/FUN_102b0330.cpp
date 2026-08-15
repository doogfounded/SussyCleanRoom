#include "FUN_102b0330.h"
#include "FUN_102b15a0.h"
#include "FUN_103283b0.h"
#include "FUN_10330de6.h"
#include "FUN_10330e01.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b0330L,
    BB_0x102b03aaL,
    BB_0x102b03afL,
    BB_0x102b042eL,
    BB_0x102b0592L,
    BB_0x102b059bL,
    BB_0x102b059fL,
    BB_0x102b05ecL,
    BB_0x102b05f0L,
    BB_0x102b0608L,
    BB_0x102b061cL,
    BB_0x102b0621L,
    BB_0x102b064eL,
    Exit
};

void FUN_102b0330() {
    State currentState = State::BB_0x102b0330L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b0330L:
                currentState = State::BB_0x102b03aaL;
                break;

            case State::BB_0x102b03aaL:
                currentState = State::BB_0x102b03afL;
                break;

            case State::BB_0x102b03afL:
                FUN_103283b0();
                currentState = State::BB_0x102b042eL;
                break;

            case State::BB_0x102b042eL:
                FUN_102b15a0();
                currentState = State::BB_0x102b0592L;
                break;

            case State::BB_0x102b0592L:
                FUN_10330de6();
                currentState = State::BB_0x102b059bL;
                break;

            case State::BB_0x102b059bL:
                currentState = State::BB_0x102b059fL;
                break;

            case State::BB_0x102b059fL:
                FUN_10330e01();
                currentState = State::BB_0x102b0608L;
                break;

            case State::BB_0x102b05ecL:
                currentState = State::BB_0x102b05f0L;
                break;

            case State::BB_0x102b05f0L:
                currentState = State::BB_0x102b0608L;
                break;

            case State::BB_0x102b0608L:
                currentState = State::Exit;
                break;

            case State::BB_0x102b061cL:
                currentState = State::BB_0x102b0621L;
                break;

            case State::BB_0x102b0621L:
                FUN_103283b0();
                currentState = State::BB_0x102b03afL;
                break;

            case State::BB_0x102b064eL:
                currentState = State::BB_0x102b0621L;
                break;
        }
    }
}

} // namespace DoogEngine1
