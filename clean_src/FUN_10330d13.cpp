#include "FUN_10330d13.h"
#include "guard_check_icall.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330d13L,
    BB_0x10330d52L,
    BB_0x10330d66L,
    BB_0x10330d73L,
    BB_0x10330d79L,
    BB_0x10330d82L,
    Exit
};

void FUN_10330d13() {
    State currentState = State::BB_0x10330d13L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330d13L:
                currentState = State::BB_0x10330d52L;
                break;

            case State::BB_0x10330d52L:
                currentState = State::BB_0x10330d66L;
                break;

            case State::BB_0x10330d66L:
                guard_check_icall();
                currentState = State::BB_0x10330d73L;
                break;

            case State::BB_0x10330d73L:
                currentState = State::BB_0x10330d79L;
                break;

            case State::BB_0x10330d79L:
                currentState = State::BB_0x10330d82L;
                break;

            case State::BB_0x10330d82L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
