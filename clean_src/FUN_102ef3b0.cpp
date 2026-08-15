#include "FUN_102ef3b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102ef3b0L,
    BB_0x102ef3c4L,
    BB_0x102ef3c8L,
    BB_0x102ef3d6L,
    Exit
};

void FUN_102ef3b0() {
    State currentState = State::BB_0x102ef3b0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102ef3b0L:
                currentState = State::BB_0x102ef3c4L;
                break;

            case State::BB_0x102ef3c4L:
                currentState = State::BB_0x102ef3d6L;
                break;

            case State::BB_0x102ef3c8L:
                currentState = State::BB_0x102ef3d6L;
                break;

            case State::BB_0x102ef3d6L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
