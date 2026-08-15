#include "FUN_103418b2.h"
#include "_wcsncmp.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103418b2L,
    BB_0x103418c3L,
    BB_0x103418d6L,
    BB_0x103418dfL,
    BB_0x103418e1L,
    BB_0x103418fcL,
    BB_0x10341907L,
    BB_0x1034191bL,
    BB_0x1034192fL,
    BB_0x1034193eL,
    BB_0x1034194dL,
    BB_0x10341950L,
    BB_0x10341959L,
    BB_0x1034195bL,
    BB_0x10341960L,
    BB_0x10341972L,
    BB_0x10341979L,
    Exit
};

void FUN_103418b2() {
    State currentState = State::BB_0x103418b2L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x103418b2L:
                currentState = State::BB_0x10341950L;
                break;

            case State::BB_0x103418c3L:
                currentState = State::BB_0x103418e1L;
                break;

            case State::BB_0x103418d6L:
                currentState = State::BB_0x10341979L;
                break;

            case State::BB_0x103418dfL:
                currentState = State::BB_0x1034194dL;
                break;

            case State::BB_0x103418e1L:
                currentState = State::BB_0x103418fcL;
                break;

            case State::BB_0x103418fcL:
                currentState = State::BB_0x10341907L;
                break;

            case State::BB_0x10341907L:
                _wcsncmp();
                currentState = State::BB_0x1034191bL;
                break;

            case State::BB_0x1034191bL:
                _wcsncmp();
                currentState = State::BB_0x1034192fL;
                break;

            case State::BB_0x1034192fL:
                currentState = State::BB_0x1034193eL;
                break;

            case State::BB_0x1034193eL:
                currentState = State::BB_0x1034194dL;
                break;

            case State::BB_0x1034194dL:
                currentState = State::BB_0x10341950L;
                break;

            case State::BB_0x10341950L:
                currentState = State::BB_0x10341959L;
                break;

            case State::BB_0x10341959L:
                currentState = State::BB_0x1034195bL;
                break;

            case State::BB_0x1034195bL:
                currentState = State::Exit;
                break;

            case State::BB_0x10341960L:
                currentState = State::BB_0x10341972L;
                break;

            case State::BB_0x10341972L:
                currentState = State::BB_0x10341979L;
                break;

            case State::BB_0x10341979L:
                currentState = State::BB_0x1034195bL;
                break;
        }
    }
}

} // namespace DoogEngine1
