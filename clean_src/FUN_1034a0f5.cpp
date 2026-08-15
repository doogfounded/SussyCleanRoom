#include "FUN_1034a0f5.h"
#include "FUN_1034f83e.h"
#include "FUN_1034a086.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034a0f5L,
    BB_0x1034a10eL,
    BB_0x1034a118L,
    BB_0x1034a13cL,
    BB_0x1034a140L,
    BB_0x1034a14bL,
    BB_0x1034a150L,
    BB_0x1034a176L,
    BB_0x1034a183L,
    BB_0x1034a18dL,
    BB_0x1034a191L,
    BB_0x1034a19aL,
    BB_0x1034a1b2L,
    BB_0x1034a1c2L,
    BB_0x1034a1c6L,
    BB_0x1034a1cbL,
    BB_0x1034a1ccL,
    BB_0x1034a1d8L,
    BB_0x1034a1edL,
    BB_0x1034a1f8L,
    Exit
};

void FUN_1034a0f5() {
    State currentState = State::BB_0x1034a0f5L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034a0f5L:
                currentState = State::BB_0x1034a10eL;
                break;

            case State::BB_0x1034a10eL:
                currentState = State::BB_0x1034a118L;
                break;

            case State::BB_0x1034a118L:
                FUN_1034a086();
                FUN_1034f83e();
                currentState = State::BB_0x1034a13cL;
                break;

            case State::BB_0x1034a13cL:
                currentState = State::BB_0x1034a140L;
                break;

            case State::BB_0x1034a140L:
                currentState = State::BB_0x1034a14bL;
                break;

            case State::BB_0x1034a14bL:
                currentState = State::BB_0x1034a150L;
                break;

            case State::BB_0x1034a150L:
                currentState = State::BB_0x1034a176L;
                break;

            case State::BB_0x1034a176L:
                currentState = State::BB_0x1034a183L;
                break;

            case State::BB_0x1034a183L:
                currentState = State::BB_0x1034a18dL;
                break;

            case State::BB_0x1034a18dL:
                currentState = State::BB_0x1034a1f8L;
                break;

            case State::BB_0x1034a191L:
                currentState = State::BB_0x1034a183L;
                break;

            case State::BB_0x1034a19aL:
                currentState = State::BB_0x1034a1f8L;
                break;

            case State::BB_0x1034a1b2L:
                FUN_1034a086();
                currentState = State::BB_0x1034a1d8L;
                break;

            case State::BB_0x1034a1c2L:
                currentState = State::BB_0x1034a1c6L;
                break;

            case State::BB_0x1034a1c6L:
                currentState = State::BB_0x1034a1ccL;
                break;

            case State::BB_0x1034a1cbL:
                currentState = State::BB_0x1034a1ccL;
                break;

            case State::BB_0x1034a1ccL:
                FUN_1034a086();
                currentState = State::BB_0x1034a1d8L;
                break;

            case State::BB_0x1034a1d8L:
                FUN_1034f83e();
                currentState = State::BB_0x1034a1edL;
                break;

            case State::BB_0x1034a1edL:
                currentState = State::BB_0x1034a1f8L;
                break;

            case State::BB_0x1034a1f8L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
