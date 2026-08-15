#include "FUN_102b3b80.h"
#include "FUN_102deb30.h"
#include "FUN_102dec40.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b3b80L,
    BB_0x102b3bc9L,
    BB_0x102b3bd0L,
    BB_0x102b3bf4L,
    BB_0x102b3c03L,
    BB_0x102b3c05L,
    BB_0x102b3c0cL,
    BB_0x102b3c12L,
    BB_0x102b3c19L,
    BB_0x102b3c2fL,
    BB_0x102b3c31L,
    Exit
};

void FUN_102b3b80() {
    State currentState = State::BB_0x102b3b80L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b3b80L:
                currentState = State::BB_0x102b3bc9L;
                break;

            case State::BB_0x102b3bc9L:
                currentState = State::BB_0x102b3bd0L;
                break;

            case State::BB_0x102b3bd0L:
                FUN_102deb30();
                currentState = State::BB_0x102b3bf4L;
                break;

            case State::BB_0x102b3bf4L:
                currentState = State::BB_0x102b3c05L;
                break;

            case State::BB_0x102b3c03L:
                currentState = State::BB_0x102b3c05L;
                break;

            case State::BB_0x102b3c05L:
                currentState = State::BB_0x102b3c0cL;
                break;

            case State::BB_0x102b3c0cL:
                currentState = State::BB_0x102b3c12L;
                break;

            case State::BB_0x102b3c12L:
                currentState = State::BB_0x102b3c19L;
                break;

            case State::BB_0x102b3c19L:
                FUN_102dec40();
                currentState = State::BB_0x102b3c2fL;
                break;

            case State::BB_0x102b3c2fL:
                currentState = State::BB_0x102b3c31L;
                break;

            case State::BB_0x102b3c31L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
