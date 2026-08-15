#include "FUN_1031e500.h"
#include "FUN_102dec40.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1031e500L,
    BB_0x1031e511L,
    BB_0x1031e517L,
    BB_0x1031e51bL,
    BB_0x1031e521L,
    BB_0x1031e52dL,
    BB_0x1031e534L,
    BB_0x1031e54cL,
    BB_0x1031e551L,
    BB_0x1031e558L,
    Exit
};

void FUN_1031e500() {
    State currentState = State::BB_0x1031e500L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x1031e500L:
                currentState = State::BB_0x1031e517L;
                break;

            case State::BB_0x1031e511L:
                currentState = State::Exit;
                break;

            case State::BB_0x1031e517L:
                currentState = State::BB_0x1031e51bL;
                break;

            case State::BB_0x1031e51bL:
                currentState = State::BB_0x1031e521L;
                break;

            case State::BB_0x1031e521L:
                currentState = State::BB_0x1031e52dL;
                break;

            case State::BB_0x1031e52dL:
                currentState = State::BB_0x1031e534L;
                break;

            case State::BB_0x1031e534L:
                FUN_102dec40();
                currentState = State::BB_0x1031e558L;
                break;

            case State::BB_0x1031e54cL:
                currentState = State::BB_0x1031e534L;
                break;

            case State::BB_0x1031e551L:
                currentState = State::Exit;
                break;

            case State::BB_0x1031e558L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
