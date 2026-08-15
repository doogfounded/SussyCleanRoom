#include "FUN_1033cea9.h"
#include "FUN_1033c39d.h"
#include "FUN_10336a03.h"
#include "FUN_1033c9ee.h"
#include "FUN_10330a56.h"
#include "FUN_1033c5bf.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033cea9L,
    BB_0x1033ced1L,
    BB_0x1033ced5L,
    BB_0x1033cef7L,
    BB_0x1033ceffL,
    BB_0x1033cf24L,
    BB_0x1033cf28L,
    BB_0x1033cf30L,
    BB_0x1033cf43L,
    BB_0x1033cf54L,
    BB_0x1033cf66L,
    BB_0x1033cf6eL,
    BB_0x1033cf73L,
    BB_0x1033cf7cL,
    BB_0x1033cf8eL,
    BB_0x1033cf95L,
    BB_0x1033cfadL,
    BB_0x1033cfc1L,
    BB_0x1033cfc9L,
    BB_0x1033cfceL,
    BB_0x1033cfd7L,
    BB_0x1033cfe9L,
    BB_0x1033cfeeL,
    BB_0x1033d002L,
    BB_0x1033d016L,
    BB_0x1033d038L,
    BB_0x1033d041L,
    BB_0x1033d044L,
    BB_0x1033d051L,
    BB_0x1033d056L,
    BB_0x1033d05cL,
    BB_0x1033d060L,
    BB_0x1033d067L,
    BB_0x1033d07eL,
    BB_0x1033d08cL,
    BB_0x1033d09aL,
    BB_0x1033d0a2L,
    BB_0x1033d0b9L,
    BB_0x1033d0beL,
    BB_0x1033d0c0L,
    Exit
};

void FUN_1033cea9() {
    State currentState = State::BB_0x1033cea9L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033cea9L:
                currentState = State::BB_0x1033ced1L;
                break;

            case State::BB_0x1033ced1L:
                currentState = State::BB_0x1033ceffL;
                break;

            case State::BB_0x1033ced5L:
                FUN_10336a03();
                currentState = State::BB_0x1033cef7L;
                break;

            case State::BB_0x1033cef7L:
                currentState = State::BB_0x1033d0c0L;
                break;

            case State::BB_0x1033ceffL:
                currentState = State::BB_0x1033cf28L;
                break;

            case State::BB_0x1033cf24L:
                currentState = State::BB_0x1033cf30L;
                break;

            case State::BB_0x1033cf28L:
                currentState = State::BB_0x1033ced5L;
                break;

            case State::BB_0x1033cf30L:
                currentState = State::BB_0x1033cf54L;
                break;

            case State::BB_0x1033cf43L:
                FUN_1033c39d();
                currentState = State::BB_0x1033cf54L;
                break;

            case State::BB_0x1033cf54L:
                FUN_1033c9ee();
                currentState = State::BB_0x1033cfadL;
                break;

            case State::BB_0x1033cf66L:
                currentState = State::BB_0x1033cf95L;
                break;

            case State::BB_0x1033cf6eL:
                currentState = State::BB_0x1033cf7cL;
                break;

            case State::BB_0x1033cf73L:
                currentState = State::BB_0x1033d056L;
                break;

            case State::BB_0x1033cf7cL:
                currentState = State::BB_0x1033cf8eL;
                break;

            case State::BB_0x1033cf8eL:
                currentState = State::BB_0x1033d044L;
                break;

            case State::BB_0x1033cf95L:
                FUN_1033c5bf();
                currentState = State::BB_0x1033cf8eL;
                break;

            case State::BB_0x1033cfadL:
                currentState = State::BB_0x1033d016L;
                break;

            case State::BB_0x1033cfc1L:
                currentState = State::BB_0x1033d002L;
                break;

            case State::BB_0x1033cfc9L:
                currentState = State::BB_0x1033cfeeL;
                break;

            case State::BB_0x1033cfceL:
                currentState = State::BB_0x1033d05cL;
                break;

            case State::BB_0x1033cfd7L:
                currentState = State::BB_0x1033cfe9L;
                break;

            case State::BB_0x1033cfe9L:
                currentState = State::BB_0x1033cf8eL;
                break;

            case State::BB_0x1033cfeeL:
                currentState = State::BB_0x1033cfe9L;
                break;

            case State::BB_0x1033d002L:
                currentState = State::BB_0x1033cfe9L;
                break;

            case State::BB_0x1033d016L:
                currentState = State::BB_0x1033d041L;
                break;

            case State::BB_0x1033d038L:
                currentState = State::BB_0x1033d041L;
                break;

            case State::BB_0x1033d041L:
                currentState = State::BB_0x1033d044L;
                break;

            case State::BB_0x1033d044L:
                currentState = State::BB_0x1033d0b9L;
                break;

            case State::BB_0x1033d051L:
                currentState = State::BB_0x1033d056L;
                break;

            case State::BB_0x1033d056L:
                currentState = State::BB_0x1033d05cL;
                break;

            case State::BB_0x1033d05cL:
                currentState = State::BB_0x1033d08cL;
                break;

            case State::BB_0x1033d060L:
                currentState = State::BB_0x1033d07eL;
                break;

            case State::BB_0x1033d067L:
                currentState = State::BB_0x1033cef7L;
                break;

            case State::BB_0x1033d07eL:
                FUN_10330a56();
                currentState = State::BB_0x1033cef7L;
                break;

            case State::BB_0x1033d08cL:
                currentState = State::BB_0x1033d0a2L;
                break;

            case State::BB_0x1033d09aL:
                currentState = State::BB_0x1033d0beL;
                break;

            case State::BB_0x1033d0a2L:
                currentState = State::BB_0x1033cef7L;
                break;

            case State::BB_0x1033d0b9L:
                currentState = State::BB_0x1033d0c0L;
                break;

            case State::BB_0x1033d0beL:
                currentState = State::BB_0x1033d0c0L;
                break;

            case State::BB_0x1033d0c0L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
