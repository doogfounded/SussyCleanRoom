#include "FUN_102d3010.h"
#include "FUN_1031e390.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d3010L,
    BB_0x102d301bL,
    BB_0x102d3020L,
    BB_0x102d302cL,
    BB_0x102d3030L,
    BB_0x102d3042L,
    BB_0x102d304aL,
    BB_0x102d3054L,
    BB_0x102d3058L,
    BB_0x102d306aL,
    BB_0x102d3076L,
    Exit
};

void FUN_102d3010() {
    State currentState = State::BB_0x102d3010L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102d3010L:
                currentState = State::BB_0x102d301bL;
                break;

            case State::BB_0x102d301bL:
                currentState = State::BB_0x102d3020L;
                break;

            case State::BB_0x102d3020L:
                currentState = State::BB_0x102d302cL;
                break;

            case State::BB_0x102d302cL:
                currentState = State::BB_0x102d3030L;
                break;

            case State::BB_0x102d3030L:
                FUN_1031e390();
                currentState = State::BB_0x102d3042L;
                break;

            case State::BB_0x102d3042L:
                currentState = State::BB_0x102d304aL;
                break;

            case State::BB_0x102d304aL:
                currentState = State::BB_0x102d3054L;
                break;

            case State::BB_0x102d3054L:
                currentState = State::BB_0x102d3058L;
                break;

            case State::BB_0x102d3058L:
                FUN_1031e390();
                currentState = State::BB_0x102d306aL;
                break;

            case State::BB_0x102d306aL:
                currentState = State::BB_0x102d3020L;
                break;

            case State::BB_0x102d3076L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
