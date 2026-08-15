#include "FUN_102b5010.h"
#include "FUN_102f0140.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b5010L,
    BB_0x102b501aL,
    BB_0x102b501cL,
    Exit
};

void FUN_102b5010() {
    State currentState = State::BB_0x102b5010L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b5010L:
                currentState = State::BB_0x102b501aL;
                break;

            case State::BB_0x102b501aL:
                currentState = State::BB_0x102b501cL;
                break;

            case State::BB_0x102b501cL:
                FUN_102f0140();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
