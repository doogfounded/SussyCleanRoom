#include "FUN_102de480.h"
#include "FUN_103283b0.h"
#include "FUN_102de900.h"
#include "FUN_10298bf0.h"
#include "FUN_10330de6.h"
#include "FUN_10330e01.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102de480L,
    BB_0x102de503L,
    BB_0x102de508L,
    BB_0x102de58aL,
    BB_0x102de5abL,
    BB_0x102de5b4L,
    BB_0x102de5b8L,
    BB_0x102de60fL,
    BB_0x102de610L,
    BB_0x102de62eL,
    BB_0x102de643L,
    BB_0x102de650L,
    BB_0x102de67cL,
    Exit
};

void FUN_102de480() {
    State currentState = State::BB_0x102de480L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102de480L:
                currentState = State::BB_0x102de503L;
                break;

            case State::BB_0x102de503L:
                currentState = State::BB_0x102de508L;
                break;

            case State::BB_0x102de508L:
                FUN_103283b0();
                currentState = State::BB_0x102de58aL;
                break;

            case State::BB_0x102de58aL:
                FUN_102de900();
                FUN_10298bf0();
                currentState = State::BB_0x102de5abL;
                break;

            case State::BB_0x102de5abL:
                FUN_10330de6();
                currentState = State::BB_0x102de5b4L;
                break;

            case State::BB_0x102de5b4L:
                currentState = State::BB_0x102de5b8L;
                break;

            case State::BB_0x102de5b8L:
                FUN_10330e01();
                currentState = State::BB_0x102de62eL;
                break;

            case State::BB_0x102de60fL:
                currentState = State::BB_0x102de610L;
                break;

            case State::BB_0x102de610L:
                currentState = State::BB_0x102de62eL;
                break;

            case State::BB_0x102de62eL:
                currentState = State::Exit;
                break;

            case State::BB_0x102de643L:
                currentState = State::BB_0x102de650L;
                break;

            case State::BB_0x102de650L:
                FUN_103283b0();
                currentState = State::BB_0x102de508L;
                break;

            case State::BB_0x102de67cL:
                currentState = State::BB_0x102de650L;
                break;
        }
    }
}

} // namespace DoogEngine1
