#include "FUN_102b8d50.h"
#include "FUN_1031e430.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b8d50L,
    BB_0x102b8d65L,
    BB_0x102b8d71L,
    BB_0x102b8d75L,
    BB_0x102b8d9fL,
    BB_0x102b8da7L,
    BB_0x102b8db1L,
    BB_0x102b8db5L,
    BB_0x102b8ddfL,
    BB_0x102b8defL,
    Exit
};

void FUN_102b8d50() {
    State currentState = State::BB_0x102b8d50L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b8d50L:
                currentState = State::BB_0x102b8d65L;
                break;

            case State::BB_0x102b8d65L:
                currentState = State::BB_0x102b8d71L;
                break;

            case State::BB_0x102b8d71L:
                currentState = State::BB_0x102b8d75L;
                break;

            case State::BB_0x102b8d75L:
                FUN_1031e430();
                currentState = State::BB_0x102b8d9fL;
                break;

            case State::BB_0x102b8d9fL:
                currentState = State::BB_0x102b8da7L;
                break;

            case State::BB_0x102b8da7L:
                currentState = State::BB_0x102b8db1L;
                break;

            case State::BB_0x102b8db1L:
                currentState = State::BB_0x102b8db5L;
                break;

            case State::BB_0x102b8db5L:
                FUN_1031e430();
                currentState = State::BB_0x102b8ddfL;
                break;

            case State::BB_0x102b8ddfL:
                currentState = State::BB_0x102b8d65L;
                break;

            case State::BB_0x102b8defL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
