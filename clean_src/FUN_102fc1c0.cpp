#include "FUN_102fc1c0.h"
#include "FUN_103263ce.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102fc1c0L,
    BB_0x102fc1eaL,
    BB_0x102fc22fL,
    Exit
};

void FUN_102fc1c0() {
    State currentState = State::BB_0x102fc1c0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102fc1c0L:
                currentState = State::BB_0x102fc1eaL;
                break;

            case State::BB_0x102fc1eaL:
                currentState = State::BB_0x102fc22fL;
                break;

            case State::BB_0x102fc22fL:
                FUN_103263ce();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
