#include "FUN_10331790.h"
#include "FUN_1034150c.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10331790L,
    BB_0x1033179eL,
    BB_0x103317adL,
    BB_0x103317bcL,
    BB_0x103317bfL,
    BB_0x103317dfL,
    BB_0x103317e6L,
    Exit
};

void FUN_10331790() {
    State currentState = State::BB_0x10331790L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10331790L:
                currentState = State::BB_0x1033179eL;
                break;

            case State::BB_0x1033179eL:
                currentState = State::BB_0x103317adL;
                break;

            case State::BB_0x103317adL:
                currentState = State::BB_0x103317bfL;
                break;

            case State::BB_0x103317bcL:
                currentState = State::BB_0x103317bfL;
                break;

            case State::BB_0x103317bfL:
                FUN_1034150c();
                currentState = State::BB_0x103317dfL;
                break;

            case State::BB_0x103317dfL:
                currentState = State::Exit;
                break;

            case State::BB_0x103317e6L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
