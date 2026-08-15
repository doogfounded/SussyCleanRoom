#include "FUN_10002150.h"
#include "FUN_10328f05.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10002150L,
    BB_0x10002184L,
    BB_0x1000218eL,
    BB_0x10002190L,
    Exit
};

void FUN_10002150() {
    State currentState = State::BB_0x10002150L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10002150L:
                currentState = State::BB_0x10002184L;
                break;

            case State::BB_0x10002184L:
                currentState = State::BB_0x10002190L;
                break;

            case State::BB_0x1000218eL:
                currentState = State::BB_0x10002190L;
                break;

            case State::BB_0x10002190L:
                FUN_10328f05();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
