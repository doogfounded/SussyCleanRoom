#include "FUN_102b9f00.h"
#include "FUN_1031e450.h"
#include "FUN_1031e430.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b9f00L,
    BB_0x102b9f30L,
    BB_0x102b9f3dL,
    BB_0x102b9f45L,
    BB_0x102b9f73L,
    BB_0x102b9f79L,
    BB_0x102b9f86L,
    BB_0x102b9f8aL,
    BB_0x102b9fb4L,
    BB_0x102b9fcfL,
    BB_0x102b9fdeL,
    BB_0x102b9fe2L,
    BB_0x102ba00cL,
    BB_0x102ba01dL,
    BB_0x102ba02bL,
    BB_0x102ba037L,
    BB_0x102ba043L,
    Exit
};

void FUN_102b9f00() {
    State currentState = State::BB_0x102b9f00L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b9f00L:
                currentState = State::BB_0x102b9f30L;
                break;

            case State::BB_0x102b9f30L:
                currentState = State::BB_0x102b9f3dL;
                break;

            case State::BB_0x102b9f3dL:
                currentState = State::BB_0x102b9f45L;
                break;

            case State::BB_0x102b9f45L:
                FUN_1031e430();
                currentState = State::BB_0x102b9f73L;
                break;

            case State::BB_0x102b9f73L:
                currentState = State::BB_0x102b9f79L;
                break;

            case State::BB_0x102b9f79L:
                currentState = State::BB_0x102b9f86L;
                break;

            case State::BB_0x102b9f86L:
                currentState = State::BB_0x102b9f8aL;
                break;

            case State::BB_0x102b9f8aL:
                FUN_1031e430();
                currentState = State::BB_0x102b9fb4L;
                break;

            case State::BB_0x102b9fb4L:
                currentState = State::BB_0x102b9f30L;
                break;

            case State::BB_0x102b9fcfL:
                currentState = State::BB_0x102b9fdeL;
                break;

            case State::BB_0x102b9fdeL:
                currentState = State::BB_0x102b9fe2L;
                break;

            case State::BB_0x102b9fe2L:
                FUN_1031e430();
                currentState = State::BB_0x102ba00cL;
                break;

            case State::BB_0x102ba00cL:
                currentState = State::BB_0x102b9f30L;
                break;

            case State::BB_0x102ba01dL:
                currentState = State::BB_0x102ba02bL;
                break;

            case State::BB_0x102ba02bL:
                currentState = State::Exit;
                break;

            case State::BB_0x102ba037L:
                currentState = State::Exit;
                break;

            case State::BB_0x102ba043L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
