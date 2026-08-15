#include "FUN_10336a03.h"
#include "guard_check_icall.h"
#include "FUN_10331740.h"
#include "FUN_1033685b.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10336a03L,
    BB_0x10336a13L,
    BB_0x10336a1eL,
    BB_0x10336a28L,
    BB_0x10336a37L,
    BB_0x10336a48L,
    BB_0x10336a7aL,
    Exit
};

void FUN_10336a03() {
    State currentState = State::BB_0x10336a03L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10336a03L:
                currentState = State::BB_0x10336a13L;
                break;

            case State::BB_0x10336a13L:
                FUN_10331740();
                currentState = State::BB_0x10336a48L;
                break;

            case State::BB_0x10336a1eL:
                currentState = State::BB_0x10336a48L;
                break;

            case State::BB_0x10336a28L:
                currentState = State::BB_0x10336a37L;
                break;

            case State::BB_0x10336a37L:
                guard_check_icall();
                currentState = State::Exit;
                break;

            case State::BB_0x10336a48L:
                FUN_1033685b();
                currentState = State::BB_0x10336a37L;
                break;

            case State::BB_0x10336a7aL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
