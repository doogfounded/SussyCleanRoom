#include "FUN_102e1d80.h"
#include "FUN_103283b0.h"
#include "FUN_102e19d0.h"
#include "FUN_102e1930.h"
#include "FUN_1031e560.h"
#include "FUN_102dfa30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102e1d80L,
    BB_0x102e1da0L,
    BB_0x102e1da5L,
    BB_0x102e1dcdL,
    BB_0x102e1dd1L,
    BB_0x102e1e00L,
    BB_0x102e1e2fL,
    BB_0x102e1e60L,
    BB_0x102e1e6cL,
    BB_0x102e1e70L,
    BB_0x102e1e8dL,
    BB_0x102e1e95L,
    BB_0x102e1e99L,
    BB_0x102e1e9bL,
    BB_0x102e1e9fL,
    BB_0x102e1ea5L,
    BB_0x102e1eacL,
    BB_0x102e1ee7L,
    Exit
};

void FUN_102e1d80() {
    State currentState = State::BB_0x102e1d80L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102e1d80L:
                currentState = State::BB_0x102e1da0L;
                break;

            case State::BB_0x102e1da0L:
                currentState = State::BB_0x102e1da5L;
                break;

            case State::BB_0x102e1da5L:
                FUN_103283b0();
                currentState = State::BB_0x102e1dd1L;
                break;

            case State::BB_0x102e1dcdL:
                currentState = State::BB_0x102e1da0L;
                break;

            case State::BB_0x102e1dd1L:
                FUN_102e19d0();
                FUN_102e1930();
                currentState = State::BB_0x102e1e00L;
                break;

            case State::BB_0x102e1e00L:
                FUN_102e1930();
                currentState = State::BB_0x102e1e2fL;
                break;

            case State::BB_0x102e1e2fL:
                FUN_1031e560();
                currentState = State::BB_0x102e1e60L;
                break;

            case State::BB_0x102e1e60L:
                currentState = State::BB_0x102e1e6cL;
                break;

            case State::BB_0x102e1e6cL:
                currentState = State::BB_0x102e1e70L;
                break;

            case State::BB_0x102e1e70L:
                FUN_102dfa30();
                currentState = State::BB_0x102e1e8dL;
                break;

            case State::BB_0x102e1e8dL:
                currentState = State::BB_0x102e1e95L;
                break;

            case State::BB_0x102e1e95L:
                currentState = State::BB_0x102e1e9bL;
                break;

            case State::BB_0x102e1e99L:
                currentState = State::BB_0x102e1e9bL;
                break;

            case State::BB_0x102e1e9bL:
                currentState = State::BB_0x102e1eacL;
                break;

            case State::BB_0x102e1e9fL:
                currentState = State::BB_0x102e1ea5L;
                break;

            case State::BB_0x102e1ea5L:
                currentState = State::BB_0x102e1e60L;
                break;

            case State::BB_0x102e1eacL:
                FUN_102e1930();
                currentState = State::BB_0x102e1ee7L;
                break;

            case State::BB_0x102e1ee7L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
