#include "FUN_1034798f.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034798fL,
    BB_0x103479a0L,
    BB_0x103479a2L,
    BB_0x103479abL,
    BB_0x103479adL,
    BB_0x103479b2L,
    BB_0x103479b9L,
    BB_0x103479beL,
    BB_0x103479c3L,
    BB_0x103479c6L,
    BB_0x103479c8L,
    BB_0x103479ccL,
    BB_0x103479d3L,
    BB_0x103479daL,
    BB_0x103479dfL,
    BB_0x103479e1L,
    BB_0x103479e6L,
    BB_0x103479efL,
    BB_0x103479f1L,
    BB_0x103479f8L,
    BB_0x103479fdL,
    BB_0x10347a02L,
    BB_0x10347a09L,
    BB_0x10347a0eL,
    BB_0x10347a15L,
    BB_0x10347a1aL,
    BB_0x10347a1fL,
    Exit
};

void FUN_1034798f() {
    State currentState = State::BB_0x1034798fL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034798fL:
                currentState = State::BB_0x103479a0L;
                break;

            case State::BB_0x103479a0L:
                currentState = State::BB_0x103479a2L;
                break;

            case State::BB_0x103479a2L:
                currentState = State::BB_0x103479abL;
                break;

            case State::BB_0x103479abL:
                currentState = State::BB_0x103479adL;
                break;

            case State::BB_0x103479adL:
                currentState = State::BB_0x103479b2L;
                break;

            case State::BB_0x103479b2L:
                currentState = State::BB_0x103479b9L;
                break;

            case State::BB_0x103479b9L:
                currentState = State::BB_0x103479beL;
                break;

            case State::BB_0x103479beL:
                currentState = State::BB_0x103479c3L;
                break;

            case State::BB_0x103479c3L:
                currentState = State::BB_0x103479c6L;
                break;

            case State::BB_0x103479c6L:
                currentState = State::BB_0x10347a1aL;
                break;

            case State::BB_0x103479c8L:
                currentState = State::Exit;
                break;

            case State::BB_0x103479ccL:
                currentState = State::BB_0x103479d3L;
                break;

            case State::BB_0x103479d3L:
                currentState = State::BB_0x10347a1fL;
                break;

            case State::BB_0x103479daL:
                currentState = State::BB_0x103479dfL;
                break;

            case State::BB_0x103479dfL:
                currentState = State::BB_0x103479e1L;
                break;

            case State::BB_0x103479e1L:
                currentState = State::BB_0x103479c6L;
                break;

            case State::BB_0x103479e6L:
                currentState = State::BB_0x10347a02L;
                break;

            case State::BB_0x103479efL:
                currentState = State::BB_0x103479f1L;
                break;

            case State::BB_0x103479f1L:
                currentState = State::BB_0x103479f8L;
                break;

            case State::BB_0x103479f8L:
                currentState = State::BB_0x103479fdL;
                break;

            case State::BB_0x103479fdL:
                currentState = State::BB_0x103479dfL;
                break;

            case State::BB_0x10347a02L:
                currentState = State::BB_0x10347a09L;
                break;

            case State::BB_0x10347a09L:
                currentState = State::BB_0x10347a0eL;
                break;

            case State::BB_0x10347a0eL:
                currentState = State::BB_0x10347a15L;
                break;

            case State::BB_0x10347a15L:
                currentState = State::BB_0x10347a1fL;
                break;

            case State::BB_0x10347a1aL:
                currentState = State::Exit;
                break;

            case State::BB_0x10347a1fL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
