#include "FUN_102ed810.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102ed810L,
    BB_0x102ed81bL,
    BB_0x102ed822L,
    BB_0x102ed826L,
    BB_0x102ed82aL,
    BB_0x102ed82eL,
    BB_0x102ed832L,
    BB_0x102ed836L,
    BB_0x102ed83aL,
    BB_0x102ed83eL,
    BB_0x102ed842L,
    Exit
};

void FUN_102ed810() {
    State currentState = State::BB_0x102ed810L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102ed810L:
                currentState = State::BB_0x102ed81bL;
                break;

            case State::BB_0x102ed81bL:
                currentState = State::BB_0x102ed842L;
                break;

            case State::BB_0x102ed822L:
                currentState = State::BB_0x102ed842L;
                break;

            case State::BB_0x102ed826L:
                currentState = State::BB_0x102ed842L;
                break;

            case State::BB_0x102ed82aL:
                currentState = State::BB_0x102ed842L;
                break;

            case State::BB_0x102ed82eL:
                currentState = State::BB_0x102ed842L;
                break;

            case State::BB_0x102ed832L:
                currentState = State::BB_0x102ed842L;
                break;

            case State::BB_0x102ed836L:
                currentState = State::BB_0x102ed842L;
                break;

            case State::BB_0x102ed83aL:
                currentState = State::BB_0x102ed842L;
                break;

            case State::BB_0x102ed83eL:
                currentState = State::BB_0x102ed842L;
                break;

            case State::BB_0x102ed842L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
