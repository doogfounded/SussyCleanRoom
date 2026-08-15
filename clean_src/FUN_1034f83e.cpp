#include "FUN_1034f83e.h"
#include "FUN_10350171.h"
#include "FUN_10350185.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034f83eL,
    BB_0x1034f86cL,
    BB_0x1034f871L,
    BB_0x1034f87aL,
    BB_0x1034f88bL,
    BB_0x1034f892L,
    BB_0x1034f89aL,
    BB_0x1034f89dL,
    BB_0x1034f8a3L,
    BB_0x1034f8aaL,
    BB_0x1034f8aeL,
    BB_0x1034f8b6L,
    BB_0x1034f8c2L,
    BB_0x1034f8caL,
    BB_0x1034f8ceL,
    BB_0x1034f8d6L,
    BB_0x1034f8daL,
    BB_0x1034f8e6L,
    BB_0x1034f8e8L,
    BB_0x1034f8ffL,
    BB_0x1034f916L,
    BB_0x1034f91fL,
    BB_0x1034f927L,
    BB_0x1034f934L,
    BB_0x1034f936L,
    BB_0x1034f93dL,
    BB_0x1034f954L,
    BB_0x1034f962L,
    BB_0x1034f966L,
    BB_0x1034f96dL,
    BB_0x1034f984L,
    BB_0x1034f989L,
    BB_0x1034f991L,
    BB_0x1034f999L,
    BB_0x1034f9a1L,
    BB_0x1034f9bfL,
    BB_0x1034f9c6L,
    BB_0x1034f9c8L,
    BB_0x1034f9d7L,
    BB_0x1034f9d8L,
    BB_0x1034f9deL,
    BB_0x1034f9e0L,
    Exit
};

void FUN_1034f83e() {
    State currentState = State::BB_0x1034f83eL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034f83eL:
                currentState = State::BB_0x1034f871L;
                break;

            case State::BB_0x1034f86cL:
                currentState = State::BB_0x1034f871L;
                break;

            case State::BB_0x1034f871L:
                currentState = State::BB_0x1034f88bL;
                break;

            case State::BB_0x1034f87aL:
                currentState = State::BB_0x1034f89dL;
                break;

            case State::BB_0x1034f88bL:
                currentState = State::BB_0x1034f89aL;
                break;

            case State::BB_0x1034f892L:
                currentState = State::BB_0x1034f9e0L;
                break;

            case State::BB_0x1034f89aL:
                currentState = State::BB_0x1034f89dL;
                break;

            case State::BB_0x1034f89dL:
                currentState = State::BB_0x1034f8a3L;
                break;

            case State::BB_0x1034f8a3L:
                currentState = State::BB_0x1034f8c2L;
                break;

            case State::BB_0x1034f8aaL:
                currentState = State::BB_0x1034f8b6L;
                break;

            case State::BB_0x1034f8aeL:
                currentState = State::BB_0x1034f8b6L;
                break;

            case State::BB_0x1034f8b6L:
                currentState = State::BB_0x1034f9e0L;
                break;

            case State::BB_0x1034f8c2L:
                currentState = State::BB_0x1034f8ceL;
                break;

            case State::BB_0x1034f8caL:
                currentState = State::BB_0x1034f8e8L;
                break;

            case State::BB_0x1034f8ceL:
                currentState = State::BB_0x1034f8daL;
                break;

            case State::BB_0x1034f8d6L:
                currentState = State::BB_0x1034f8e8L;
                break;

            case State::BB_0x1034f8daL:
                currentState = State::BB_0x1034f8e6L;
                break;

            case State::BB_0x1034f8e6L:
                currentState = State::BB_0x1034f8e8L;
                break;

            case State::BB_0x1034f8e8L:
                currentState = State::BB_0x1034f927L;
                break;

            case State::BB_0x1034f8ffL:
                currentState = State::BB_0x1034f916L;
                break;

            case State::BB_0x1034f916L:
                currentState = State::BB_0x1034f91fL;
                break;

            case State::BB_0x1034f91fL:
                currentState = State::BB_0x1034f927L;
                break;

            case State::BB_0x1034f927L:
                currentState = State::BB_0x1034f936L;
                break;

            case State::BB_0x1034f934L:
                currentState = State::BB_0x1034f936L;
                break;

            case State::BB_0x1034f936L:
                currentState = State::BB_0x1034f962L;
                break;

            case State::BB_0x1034f93dL:
                currentState = State::BB_0x1034f954L;
                break;

            case State::BB_0x1034f954L:
                currentState = State::BB_0x1034f962L;
                break;

            case State::BB_0x1034f962L:
                currentState = State::BB_0x1034f966L;
                break;

            case State::BB_0x1034f966L:
                currentState = State::BB_0x1034f96dL;
                break;

            case State::BB_0x1034f96dL:
                currentState = State::BB_0x1034f892L;
                break;

            case State::BB_0x1034f984L:
                currentState = State::BB_0x1034f9d8L;
                break;

            case State::BB_0x1034f989L:
                currentState = State::BB_0x1034f991L;
                break;

            case State::BB_0x1034f991L:
                currentState = State::BB_0x1034f999L;
                break;

            case State::BB_0x1034f999L:
                currentState = State::BB_0x1034f9a1L;
                break;

            case State::BB_0x1034f9a1L:
                currentState = State::BB_0x1034f9bfL;
                break;

            case State::BB_0x1034f9bfL:
                currentState = State::BB_0x1034f9c8L;
                break;

            case State::BB_0x1034f9c6L:
                currentState = State::BB_0x1034f9c8L;
                break;

            case State::BB_0x1034f9c8L:
                FUN_10350171();
                currentState = State::BB_0x1034f9deL;
                break;

            case State::BB_0x1034f9d7L:
                currentState = State::BB_0x1034f9d8L;
                break;

            case State::BB_0x1034f9d8L:
                FUN_10350185();
                currentState = State::BB_0x1034f9deL;
                break;

            case State::BB_0x1034f9deL:
                currentState = State::BB_0x1034f9e0L;
                break;

            case State::BB_0x1034f9e0L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
