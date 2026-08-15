#include "FUN_1034a030.h"
#include "FUN_10330a8d.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034a030L,
    BB_0x1034a03dL,
    BB_0x1034a04aL,
    BB_0x1034a04eL,
    BB_0x1034a056L,
    BB_0x1034a072L,
    BB_0x1034a082L,
    Exit
};

void FUN_1034a030() {
    State currentState = State::BB_0x1034a030L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034a030L:
                currentState = State::BB_0x1034a03dL;
                break;

            case State::BB_0x1034a03dL:
                FUN_10330a8d();
                currentState = State::BB_0x1034a082L;
                break;

            case State::BB_0x1034a04aL:
                currentState = State::BB_0x1034a04eL;
                break;

            case State::BB_0x1034a04eL:
                currentState = State::BB_0x1034a072L;
                break;

            case State::BB_0x1034a056L:
                currentState = State::Exit;
                break;

            case State::BB_0x1034a072L:
                FUN_10330a8d();
                currentState = State::BB_0x1034a082L;
                break;

            case State::BB_0x1034a082L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
