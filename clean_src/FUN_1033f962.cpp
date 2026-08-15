#include "FUN_1033f962.h"
#include "guard_check_icall.h"
#include "FUN_1033f98e.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033f962L,
    BB_0x1033f973L,
    BB_0x1033f989L,
    BB_0x1033f98bL,
    BB_0x1033f98eL,
    BB_0x100039e0L,
    Exit
};

void FUN_1033f962() {
    State currentState = State::BB_0x1033f962L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033f962L:
                // Transition: BB_0x1033f962L -> BB_0x1033f973L
                currentState = State::BB_0x1033f973L;
                break;

            case State::BB_0x1033f973L:
                // Transition: BB_0x1033f973L -> BB_0x100039e0L
                guard_check_icall();
                currentState = State::BB_0x1033f98bL;
                break;

            case State::BB_0x1033f989L:
                // Transition: BB_0x1033f989L -> BB_0x1033f98bL
                currentState = State::BB_0x1033f98bL;
                break;

            case State::BB_0x1033f98eL:
                // Transition: BB_0x1033f962L -> BB_0x1033f98eL
                FUN_1033f98e();
                currentState = State::Exit;
                break;

            case State::BB_0x100039e0L:
                // Terminal transition
                currentState = State::Exit;
                break;

            case State::BB_0x1033f98bL:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
