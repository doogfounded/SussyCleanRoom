#include "FUN_10330cb8.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330cb8L,
    BB_0x10330cc4L,
    BB_0x10330cceL,
    BB_0x10330cdbL,
    BB_0x10330ce6L,
    BB_0x10330cecL,
    BB_0x10330cf7L,
    Exit
};

void FUN_10330cb8() {
    State currentState = State::BB_0x10330cb8L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330cb8L:
                currentState = State::BB_0x10330cc4L;
                break;

            case State::BB_0x10330cc4L:
                currentState = State::BB_0x10330cceL;
                break;

            case State::BB_0x10330cceL:
                currentState = State::BB_0x10330cdbL;
                break;

            case State::BB_0x10330cdbL:
                currentState = State::BB_0x10330ce6L;
                break;

            case State::BB_0x10330ce6L:
                currentState = State::BB_0x10330cecL;
                break;

            case State::BB_0x10330cecL:
                currentState = State::BB_0x10330cf7L;
                break;

            case State::BB_0x10330cf7L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
