#include "FUN_102afc50.h"
#include "FUN_103283b0.h"
#include "FUN_102b9680.h"
#include "FUN_10330de6.h"
#include "FUN_10330e01.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102afc50L,
    BB_0x102afccaL,
    BB_0x102afccfL,
    BB_0x102afd4eL,
    BB_0x102afdb5L,
    BB_0x102afdc5L,
    BB_0x102afdcaL,
    BB_0x102afdf2L,
    BB_0x102afdf6L,
    BB_0x102afe00L,
    BB_0x102afe2dL,
    BB_0x102afe31L,
    BB_0x102afe90L,
    BB_0x102afedfL,
    BB_0x102b0031L,
    BB_0x102b003aL,
    BB_0x102b003eL,
    BB_0x102b008bL,
    BB_0x102b0090L,
    BB_0x102b00a8L,
    Exit
};

void FUN_102afc50() {
    State currentState = State::BB_0x102afc50L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102afc50L:
                currentState = State::BB_0x102afccaL;
                break;

            case State::BB_0x102afccaL:
                currentState = State::BB_0x102afccfL;
                break;

            case State::BB_0x102afccfL:
                FUN_103283b0();
                currentState = State::BB_0x102afd4eL;
                break;

            case State::BB_0x102afd4eL:
                currentState = State::BB_0x102afe90L;
                break;

            case State::BB_0x102afdb5L:
                currentState = State::BB_0x102afdc5L;
                break;

            case State::BB_0x102afdc5L:
                currentState = State::BB_0x102afdcaL;
                break;

            case State::BB_0x102afdcaL:
                FUN_103283b0();
                currentState = State::BB_0x102afe31L;
                break;

            case State::BB_0x102afdf2L:
                currentState = State::BB_0x102afdc5L;
                break;

            case State::BB_0x102afdf6L:
                currentState = State::BB_0x102afe00L;
                break;

            case State::BB_0x102afe00L:
                FUN_103283b0();
                currentState = State::BB_0x102afccfL;
                break;

            case State::BB_0x102afe2dL:
                currentState = State::BB_0x102afe00L;
                break;

            case State::BB_0x102afe31L:
                FUN_103283b0();
                currentState = State::BB_0x102afedfL;
                break;

            case State::BB_0x102afe90L:
                FUN_103283b0();
                FUN_102b9680();
                currentState = State::BB_0x102afedfL;
                break;

            case State::BB_0x102afedfL:
                FUN_103283b0();
                currentState = State::BB_0x102b0031L;
                break;

            case State::BB_0x102b0031L:
                FUN_10330de6();
                currentState = State::BB_0x102b003aL;
                break;

            case State::BB_0x102b003aL:
                currentState = State::BB_0x102b003eL;
                break;

            case State::BB_0x102b003eL:
                FUN_10330e01();
                currentState = State::BB_0x102b00a8L;
                break;

            case State::BB_0x102b008bL:
                currentState = State::BB_0x102b0090L;
                break;

            case State::BB_0x102b0090L:
                currentState = State::BB_0x102b00a8L;
                break;

            case State::BB_0x102b00a8L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
