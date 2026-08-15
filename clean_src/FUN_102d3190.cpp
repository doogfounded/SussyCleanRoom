#include "FUN_102d3190.h"
#include "FUN_1031e390.h"
#include "FUN_102d3080.h"
#include "FUN_10330dd0.h"
#include "FUN_102d3360.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d3190L,
    BB_0x102d31b8L,
    BB_0x102d31c5L,
    BB_0x102d31d6L,
    BB_0x102d31e0L,
    BB_0x102d31edL,
    BB_0x102d31f1L,
    BB_0x102d3203L,
    BB_0x102d320fL,
    BB_0x102d3216L,
    BB_0x102d321aL,
    BB_0x102d3228L,
    BB_0x102d322dL,
    BB_0x102d3230L,
    BB_0x102d3249L,
    BB_0x102d3265L,
    Exit
};

void FUN_102d3190() {
    State currentState = State::BB_0x102d3190L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102d3190L:
                currentState = State::BB_0x102d31b8L;
                break;

            case State::BB_0x102d31b8L:
                currentState = State::BB_0x102d3249L;
                break;

            case State::BB_0x102d31c5L:
                currentState = State::BB_0x102d31d6L;
                break;

            case State::BB_0x102d31d6L:
                currentState = State::BB_0x102d31e0L;
                break;

            case State::BB_0x102d31e0L:
                currentState = State::BB_0x102d31edL;
                break;

            case State::BB_0x102d31edL:
                currentState = State::BB_0x102d3203L;
                break;

            case State::BB_0x102d31f1L:
                FUN_1031e390();
                currentState = State::BB_0x102d322dL;
                break;

            case State::BB_0x102d3203L:
                currentState = State::BB_0x102d3228L;
                break;

            case State::BB_0x102d320fL:
                currentState = State::BB_0x102d3228L;
                break;

            case State::BB_0x102d3216L:
                currentState = State::BB_0x102d3228L;
                break;

            case State::BB_0x102d321aL:
                FUN_1031e390();
                currentState = State::BB_0x102d3228L;
                break;

            case State::BB_0x102d3228L:
                currentState = State::BB_0x102d3230L;
                break;

            case State::BB_0x102d322dL:
                currentState = State::BB_0x102d3230L;
                break;

            case State::BB_0x102d3230L:
                currentState = State::BB_0x102d3249L;
                break;

            case State::BB_0x102d3249L:
                currentState = State::Exit;
                break;

            case State::BB_0x102d3265L:
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
