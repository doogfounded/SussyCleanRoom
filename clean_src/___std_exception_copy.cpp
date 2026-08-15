#include "___std_exception_copy.h"
#include "FUN_10330e01.h"
#include "FUN_10330de6.h"
#include "FUN_10337c5e.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1032aaddL,
    BB_0x1032aaeaL,
    BB_0x1032aaf0L,
    BB_0x1032aaf3L,
    BB_0x1032aafaL,
    BB_0x1032ab0eL,
    BB_0x1032ab27L,
    BB_0x1032ab32L,
    BB_0x1032ab3dL,
    Exit
};

void ___std_exception_copy() {
    State currentState = State::BB_0x1032aaddL;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x1032aaddL:
                currentState = State::BB_0x1032aaeaL;
                break;

            case State::BB_0x1032aaeaL:
                currentState = State::BB_0x1032aaf0L;
                break;

            case State::BB_0x1032aaf0L:
                currentState = State::BB_0x1032aaf3L;
                break;

            case State::BB_0x1032aaf3L:
                currentState = State::BB_0x1032aafaL;
                break;

            case State::BB_0x1032aafaL:
                FUN_10330e01();
                currentState = State::BB_0x1032ab0eL;
                break;

            case State::BB_0x1032ab0eL:
                FUN_10337c5e();
                currentState = State::BB_0x1032ab27L;
                break;

            case State::BB_0x1032ab27L:
                FUN_10330de6();
                currentState = State::BB_0x1032ab3dL;
                break;

            case State::BB_0x1032ab32L:
                currentState = State::BB_0x1032ab3dL;
                break;

            case State::BB_0x1032ab3dL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
