#include "FUN_100027b0.h"
#include "FUN_103581e0.h"
#include "FUN_102dc7a0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x100027b0L,
    BB_0x100027c9L,
    BB_0x100027cbL,
    Exit
};

void FUN_100027b0() {
    State currentState = State::BB_0x100027b0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x100027b0L:
                currentState = State::BB_0x100027c9L;
                break;

            case State::BB_0x100027c9L:
                currentState = State::BB_0x100027cbL;
                break;

            case State::BB_0x100027cbL:
                FUN_103581e0();
                FUN_102dc7a0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
