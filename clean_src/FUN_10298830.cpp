#include "FUN_10298830.h"
#include "FUN_103283b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10298830L,
    BB_0x10298840L,
    BB_0x10298844L,
    BB_0x1029886dL,
    BB_0x10298871L,
    Exit
};

void FUN_10298830() {
    State currentState = State::BB_0x10298830L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10298830L:
                currentState = State::BB_0x10298840L;
                break;

            case State::BB_0x10298840L:
                currentState = State::BB_0x10298844L;
                break;

            case State::BB_0x10298844L:
                FUN_103283b0();
                currentState = State::BB_0x10298871L;
                break;

            case State::BB_0x1029886dL:
                currentState = State::BB_0x10298840L;
                break;

            case State::BB_0x10298871L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
