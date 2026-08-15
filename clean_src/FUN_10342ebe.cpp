#include "FUN_10342ebe.h"
#include "FUN_10331850.h"
#include "FUN_10347a27.h"
#include "FUN_1034a0b2.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10342ebeL,
    BB_0x10342ed2L,
    BB_0x10342eddL,
    BB_0x10342ee2L,
    BB_0x10342eedL,
    BB_0x10342ef7L,
    BB_0x10342f00L,
    BB_0x10342f07L,
    BB_0x10342f18L,
    BB_0x10342f33L,
    BB_0x10342f3bL,
    BB_0x10342f45L,
    BB_0x10342f50L,
    BB_0x10342f58L,
    BB_0x10342f63L,
    BB_0x10342f6eL,
    BB_0x10342f72L,
    BB_0x10342f91L,
    BB_0x10342f99L,
    BB_0x10342f9fL,
    BB_0x10342fa7L,
    BB_0x10342fb7L,
    BB_0x10342fd7L,
    BB_0x10342fdcL,
    BB_0x10342feaL,
    BB_0x10342fecL,
    Exit
};

void FUN_10342ebe() {
    State currentState = State::BB_0x10342ebeL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10342ebeL:
                currentState = State::BB_0x10342ed2L;
                break;

            case State::BB_0x10342ed2L:
                currentState = State::BB_0x10342eddL;
                break;

            case State::BB_0x10342eddL:
                currentState = State::BB_0x10342ef7L;
                break;

            case State::BB_0x10342ee2L:
                currentState = State::BB_0x10342feaL;
                break;

            case State::BB_0x10342eedL:
                currentState = State::BB_0x10342feaL;
                break;

            case State::BB_0x10342ef7L:
                currentState = State::BB_0x10342f00L;
                break;

            case State::BB_0x10342f00L:
                FUN_10331850();
                currentState = State::BB_0x10342f07L;
                break;

            case State::BB_0x10342f07L:
                currentState = State::BB_0x10342f18L;
                break;

            case State::BB_0x10342f18L:
                FUN_1034a0b2();
                currentState = State::BB_0x10342f33L;
                break;

            case State::BB_0x10342f33L:
                currentState = State::BB_0x10342fecL;
                break;

            case State::BB_0x10342f3bL:
                currentState = State::BB_0x10342f58L;
                break;

            case State::BB_0x10342f45L:
                currentState = State::BB_0x10342fd7L;
                break;

            case State::BB_0x10342f50L:
                currentState = State::BB_0x10342fd7L;
                break;

            case State::BB_0x10342f58L:
                currentState = State::BB_0x10342f63L;
                break;

            case State::BB_0x10342f63L:
                currentState = State::BB_0x10342f6eL;
                break;

            case State::BB_0x10342f6eL:
                currentState = State::BB_0x10342f72L;
                break;

            case State::BB_0x10342f72L:
                FUN_10347a27();
                currentState = State::BB_0x10342f91L;
                break;

            case State::BB_0x10342f91L:
                currentState = State::BB_0x10342fa7L;
                break;

            case State::BB_0x10342f99L:
                currentState = State::BB_0x10342fa7L;
                break;

            case State::BB_0x10342f9fL:
                currentState = State::BB_0x10342fecL;
                break;

            case State::BB_0x10342fa7L:
                currentState = State::BB_0x10342f33L;
                break;

            case State::BB_0x10342fb7L:
                FUN_10347a27();
                currentState = State::BB_0x10342fa7L;
                break;

            case State::BB_0x10342fd7L:
                currentState = State::BB_0x10342fecL;
                break;

            case State::BB_0x10342fdcL:
                currentState = State::BB_0x10342feaL;
                break;

            case State::BB_0x10342feaL:
                currentState = State::BB_0x10342fecL;
                break;

            case State::BB_0x10342fecL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
