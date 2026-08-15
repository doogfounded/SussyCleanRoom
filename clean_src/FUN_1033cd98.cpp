#include "FUN_1033cd98.h"
#include "FUN_1033cea9.h"
#include "FUN_10336a03.h"
#include "FUN_1033cea1.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033cd98L,
    BB_0x1033cdacL,
    BB_0x1033cdc2L,
    BB_0x1033cdcaL,
    BB_0x1033cdceL,
    BB_0x1033cdd6L,
    BB_0x1033cdddL,
    BB_0x1033cde1L,
    BB_0x1033cde5L,
    BB_0x1033ce0aL,
    BB_0x1033ce2bL,
    BB_0x1033ce4fL,
    BB_0x1033ce66L,
    BB_0x1033ce7dL,
    BB_0x1033ce8bL,
    Exit
};

void FUN_1033cd98() {
    State currentState = State::BB_0x1033cd98L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033cd98L:
                currentState = State::BB_0x1033cdcaL;
                break;

            case State::BB_0x1033cdacL:
                currentState = State::BB_0x1033cdc2L;
                break;

            case State::BB_0x1033cdc2L:
                currentState = State::BB_0x1033ce8bL;
                break;

            case State::BB_0x1033cdcaL:
                currentState = State::BB_0x1033cdddL;
                break;

            case State::BB_0x1033cdceL:
                currentState = State::BB_0x1033cdddL;
                break;

            case State::BB_0x1033cdd6L:
                currentState = State::BB_0x1033cde1L;
                break;

            case State::BB_0x1033cdddL:
                currentState = State::BB_0x1033cde1L;
                break;

            case State::BB_0x1033cde1L:
                currentState = State::BB_0x1033ce0aL;
                break;

            case State::BB_0x1033cde5L:
                FUN_10336a03();
                currentState = State::BB_0x1033cdc2L;
                break;

            case State::BB_0x1033ce0aL:
                currentState = State::BB_0x1033ce2bL;
                break;

            case State::BB_0x1033ce2bL:
                currentState = State::BB_0x1033ce66L;
                break;

            case State::BB_0x1033ce4fL:
                currentState = State::BB_0x1033ce7dL;
                break;

            case State::BB_0x1033ce66L:
                FUN_1033cea9();
                currentState = State::BB_0x1033ce7dL;
                break;

            case State::BB_0x1033ce7dL:
                FUN_1033cea1();
                currentState = State::BB_0x1033ce8bL;
                break;

            case State::BB_0x1033ce8bL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
