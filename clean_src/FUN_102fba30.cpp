#include "FUN_102fba30.h"
#include "FUN_102fb320.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102fba30L,
    BB_0x102fba4aL,
    BB_0x102fba52L,
    Exit
};

void FUN_102fba30() {
    State currentState = State::BB_0x102fba30L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102fba30L:
                currentState = State::BB_0x102fba4aL;
                break;

            case State::BB_0x102fba4aL:
                FUN_102fb320();
                currentState = State::BB_0x102fba52L;
                break;

            case State::BB_0x102fba52L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
