#include "FUN_1033c27c.h"
#include "FUN_10349ce9.h"
#include "FUN_10330a56.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033c27cL,
    BB_0x1033c296L,
    BB_0x1033c2a4L,
    BB_0x1033c2aaL,
    BB_0x1033c2c2L,
    BB_0x1033c2d5L,
    BB_0x1033c2e1L,
    BB_0x1033c2fbL,
    Exit
};

void FUN_1033c27c() {
    State currentState = State::BB_0x1033c27cL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033c27cL:
                // Transition: BB_0x1033c27cL -> BB_0x10349ce9L
                FUN_10349ce9();
                currentState = State::BB_0x1033c2aaL;
                break;

            case State::BB_0x1033c296L:
                // Transition: BB_0x1033c296L -> BB_0x1033c2a4L
                currentState = State::BB_0x1033c2a4L;
                break;

            case State::BB_0x1033c2a4L:
                // Transition: BB_0x1033c2a4L -> BB_0x1033c2fbL
                currentState = State::BB_0x1033c2fbL;
                break;

            case State::BB_0x1033c2aaL:
                // Transition: BB_0x1033c2aaL -> BB_0x1033c2c2L
                currentState = State::BB_0x1033c2c2L;
                break;

            case State::BB_0x1033c2c2L:
                // Transition: BB_0x1033c2c2L -> BB_0x10330a56L
                FUN_10330a56();
                currentState = State::BB_0x1033c2a4L;
                break;

            case State::BB_0x1033c2d5L:
                // Transition: BB_0x1033c2d5L -> BB_0x1033c2e1L
                currentState = State::BB_0x1033c2e1L;
                break;

            case State::BB_0x1033c2e1L:
                // Transition: BB_0x1033c2e1L -> BB_0x1033c2fbL
                currentState = State::BB_0x1033c2fbL;
                break;

            case State::BB_0x1033c2fbL:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
