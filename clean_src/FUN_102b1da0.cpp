#include "FUN_102b1da0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b1da0L,
    BB_0x102b1dc1L,
    BB_0x102b1dddL,
    BB_0x102b1de1L,
    BB_0x102b1deaL,
    Exit
};

void FUN_102b1da0() {
    State currentState = State::BB_0x102b1da0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b1da0L:
                currentState = State::BB_0x102b1dc1L;
                break;

            case State::BB_0x102b1dc1L:
                currentState = State::BB_0x102b1dddL;
                break;

            case State::BB_0x102b1dddL:
                currentState = State::BB_0x102b1deaL;
                break;

            case State::BB_0x102b1de1L:
                currentState = State::BB_0x102b1dc1L;
                break;

            case State::BB_0x102b1deaL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
