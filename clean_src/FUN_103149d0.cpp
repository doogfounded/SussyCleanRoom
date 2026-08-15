#include "FUN_103149d0.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_10316470.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103149d0L,
    BB_0x10314a37L,
    BB_0x10314aa5L,
    Exit
};

void FUN_103149d0() {
    State currentState = State::BB_0x103149d0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x103149d0L:
                currentState = State::BB_0x10314a37L;
                break;

            case State::BB_0x10314a37L:
                FUN_10298830();
                FUN_103283b0();
                currentState = State::BB_0x10314aa5L;
                break;

            case State::BB_0x10314aa5L:
                FUN_103283b0();
                FUN_10316470();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
