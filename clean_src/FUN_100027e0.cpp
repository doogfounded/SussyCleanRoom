#include "FUN_100027e0.h"
#include "FUN_103581e0.h"
#include "FUN_102dc7a0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x100027e0L,
    BB_0x100027f9L,
    BB_0x100027fbL,
    Exit
};

void FUN_100027e0() {
    State currentState = State::BB_0x100027e0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x100027e0L:
                currentState = State::BB_0x100027f9L;
                break;

            case State::BB_0x100027f9L:
                currentState = State::BB_0x100027fbL;
                break;

            case State::BB_0x100027fbL:
                FUN_103581e0();
                FUN_102dc7a0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
