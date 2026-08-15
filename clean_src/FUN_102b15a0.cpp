#include "FUN_102b15a0.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_102b9100.h"
#include "FUN_102b8f30.h"
#include "FUN_102d14c0.h"
#include "FUN_102deb00.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b15a0L,
    BB_0x102b1604L,
    BB_0x102b1672L,
    BB_0x102b16d1L,
    BB_0x102b16d6L,
    BB_0x102b16feL,
    BB_0x102b1702L,
    BB_0x102b1730L,
    BB_0x102b1761L,
    BB_0x102b1776L,
    BB_0x102b1787L,
    BB_0x102b178bL,
    BB_0x102b179eL,
    BB_0x102b17a3L,
    BB_0x102b17d8L,
    Exit
};

void FUN_102b15a0() {
    State currentState = State::BB_0x102b15a0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b15a0L:
                currentState = State::BB_0x102b1604L;
                break;

            case State::BB_0x102b1604L:
                FUN_10298830();
                FUN_103283b0();
                currentState = State::BB_0x102b1672L;
                break;

            case State::BB_0x102b1672L:
                FUN_103283b0();
                currentState = State::BB_0x102b16d1L;
                break;

            case State::BB_0x102b16d1L:
                currentState = State::BB_0x102b16d6L;
                break;

            case State::BB_0x102b16d6L:
                FUN_103283b0();
                currentState = State::BB_0x102b1702L;
                break;

            case State::BB_0x102b16feL:
                currentState = State::BB_0x102b16d1L;
                break;

            case State::BB_0x102b1702L:
                FUN_102b9100();
                FUN_102b8f30();
                currentState = State::BB_0x102b1730L;
                break;

            case State::BB_0x102b1730L:
                FUN_102b8f30();
                currentState = State::BB_0x102b1761L;
                break;

            case State::BB_0x102b1761L:
                FUN_102d14c0();
                currentState = State::BB_0x102b1776L;
                break;

            case State::BB_0x102b1776L:
                currentState = State::BB_0x102b1787L;
                break;

            case State::BB_0x102b1787L:
                currentState = State::BB_0x102b178bL;
                break;

            case State::BB_0x102b178bL:
                FUN_102deb00();
                currentState = State::BB_0x102b17a3L;
                break;

            case State::BB_0x102b179eL:
                currentState = State::BB_0x102b1776L;
                break;

            case State::BB_0x102b17a3L:
                FUN_102b8f30();
                currentState = State::BB_0x102b17d8L;
                break;

            case State::BB_0x102b17d8L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
