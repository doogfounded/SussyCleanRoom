#include "FUN_10285930.h"
#include "FUN_10329277.h"
#include "FUN_10336a90.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10285930L,
    BB_0x1028595eL,
    BB_0x1028596eL,
    BB_0x10285970L,
    BB_0x10285988L,
    Exit
};

void FUN_10285930() {
    State currentState = State::BB_0x10285930L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10285930L:
                currentState = State::BB_0x1028595eL;
                break;

            case State::BB_0x1028595eL:
                currentState = State::BB_0x1028596eL;
                break;

            case State::BB_0x1028596eL:
                currentState = State::BB_0x10285970L;
                break;

            case State::BB_0x10285970L:
                FUN_10329277();
                currentState = State::Exit;
                break;

            case State::BB_0x10285988L:
                FUN_10336a90();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
