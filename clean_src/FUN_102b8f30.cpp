#include "FUN_102b8f30.h"
#include "FUN_102deb00.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b8f30L,
    BB_0x102b8f3bL,
    BB_0x102b8f40L,
    BB_0x102b8f4cL,
    BB_0x102b8f50L,
    BB_0x102b8f62L,
    BB_0x102b8f6aL,
    BB_0x102b8f74L,
    BB_0x102b8f78L,
    BB_0x102b8f8aL,
    BB_0x102b8f96L,
    Exit
};

void FUN_102b8f30() {
    State currentState = State::BB_0x102b8f30L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b8f30L:
                currentState = State::BB_0x102b8f3bL;
                break;

            case State::BB_0x102b8f3bL:
                currentState = State::BB_0x102b8f40L;
                break;

            case State::BB_0x102b8f40L:
                currentState = State::BB_0x102b8f4cL;
                break;

            case State::BB_0x102b8f4cL:
                currentState = State::BB_0x102b8f50L;
                break;

            case State::BB_0x102b8f50L:
                FUN_102deb00();
                currentState = State::BB_0x102b8f62L;
                break;

            case State::BB_0x102b8f62L:
                currentState = State::BB_0x102b8f6aL;
                break;

            case State::BB_0x102b8f6aL:
                currentState = State::BB_0x102b8f74L;
                break;

            case State::BB_0x102b8f74L:
                currentState = State::BB_0x102b8f78L;
                break;

            case State::BB_0x102b8f78L:
                FUN_102deb00();
                currentState = State::BB_0x102b8f8aL;
                break;

            case State::BB_0x102b8f8aL:
                currentState = State::BB_0x102b8f96L;
                break;

            case State::BB_0x102b8f96L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
