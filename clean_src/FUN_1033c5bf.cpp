#include "FUN_1033c5bf.h"
#include "FUN_10331850.h"
#include "FUN_10343900.h"
#include "FUN_1032a1f0.h"
#include "FUN_10342ebe.h"
#include "FUN_1034a0f5.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033c5bfL,
    BB_0x1033c631L,
    BB_0x1033c638L,
    BB_0x1033c65cL,
    BB_0x1033c664L,
    BB_0x1033c682L,
    BB_0x1033c693L,
    BB_0x1033c698L,
    BB_0x1033c69fL,
    BB_0x1033c6afL,
    BB_0x1033c6cdL,
    BB_0x1033c6d2L,
    BB_0x1033c6deL,
    BB_0x1033c6e7L,
    BB_0x1033c6faL,
    BB_0x1033c702L,
    BB_0x1033c714L,
    BB_0x1033c751L,
    BB_0x1033c753L,
    BB_0x1033c769L,
    BB_0x1033c79fL,
    BB_0x1033c7a2L,
    BB_0x1033c7aeL,
    BB_0x1033c7c1L,
    BB_0x1033c7dfL,
    BB_0x1033c7f0L,
    BB_0x1033c7ffL,
    BB_0x1033c81aL,
    BB_0x1033c81fL,
    BB_0x1033c825L,
    BB_0x1033c83aL,
    BB_0x1033c83dL,
    BB_0x1033c867L,
    BB_0x1033c882L,
    BB_0x1033c89fL,
    BB_0x1033c8a5L,
    BB_0x1033c8c8L,
    BB_0x1033c8d2L,
    BB_0x1033c8e1L,
    BB_0x1033c8e6L,
    BB_0x1033c8eeL,
    BB_0x1033c8f2L,
    BB_0x1033c8f8L,
    BB_0x1033c913L,
    BB_0x1033c916L,
    BB_0x1033c91bL,
    BB_0x1033c91fL,
    BB_0x1033c922L,
    BB_0x1033c93aL,
    BB_0x1033c93cL,
    BB_0x1033c95dL,
    BB_0x1033c965L,
    Exit
};

void FUN_1033c5bf() {
    State currentState = State::BB_0x1033c5bfL;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x1033c5bfL:
                currentState = State::BB_0x1033c631L;
                break;

            case State::BB_0x1033c631L:
                FUN_10331850();
                currentState = State::BB_0x1033c638L;
                break;

            case State::BB_0x1033c638L:
                currentState = State::BB_0x1033c65cL;
                break;

            case State::BB_0x1033c65cL:
                currentState = State::BB_0x1033c664L;
                break;

            case State::BB_0x1033c664L:
                currentState = State::BB_0x1033c682L;
                break;

            case State::BB_0x1033c682L:
                currentState = State::BB_0x1033c693L;
                break;

            case State::BB_0x1033c693L:
                currentState = State::BB_0x1033c69fL;
                break;

            case State::BB_0x1033c698L:
                currentState = State::BB_0x1033c69fL;
                break;

            case State::BB_0x1033c69fL:
                currentState = State::BB_0x1033c6afL;
                break;

            case State::BB_0x1033c6afL:
                currentState = State::BB_0x1033c6cdL;
                break;

            case State::BB_0x1033c6cdL:
                currentState = State::BB_0x1033c6d2L;
                break;

            case State::BB_0x1033c6d2L:
                currentState = State::BB_0x1033c6deL;
                break;

            case State::BB_0x1033c6deL:
                currentState = State::BB_0x1033c6e7L;
                break;

            case State::BB_0x1033c6e7L:
                FUN_1032a1f0();
                currentState = State::BB_0x1033c6faL;
                break;

            case State::BB_0x1033c6faL:
                currentState = State::BB_0x1033c702L;
                break;

            case State::BB_0x1033c702L:
                currentState = State::BB_0x1033c714L;
                break;

            case State::BB_0x1033c714L:
                FUN_1034a0f5();
                currentState = State::BB_0x1033c751L;
                break;

            case State::BB_0x1033c751L:
                currentState = State::BB_0x1033c7a2L;
                break;

            case State::BB_0x1033c753L:
                currentState = State::BB_0x1033c769L;
                break;

            case State::BB_0x1033c769L:
                FUN_1034a0f5();
                currentState = State::BB_0x1033c79fL;
                break;

            case State::BB_0x1033c79fL:
                currentState = State::BB_0x1033c7a2L;
                break;

            case State::BB_0x1033c7a2L:
                currentState = State::BB_0x1033c83dL;
                break;

            case State::BB_0x1033c7aeL:
                currentState = State::BB_0x1033c7dfL;
                break;

            case State::BB_0x1033c7c1L:
                currentState = State::BB_0x1033c825L;
                break;

            case State::BB_0x1033c7dfL:
                currentState = State::BB_0x1033c7f0L;
                break;

            case State::BB_0x1033c7f0L:
                currentState = State::BB_0x1033c7ffL;
                break;

            case State::BB_0x1033c7ffL:
                FUN_10342ebe();
                currentState = State::BB_0x1033c81aL;
                break;

            case State::BB_0x1033c81aL:
                currentState = State::BB_0x1033c83dL;
                break;

            case State::BB_0x1033c81fL:
                currentState = State::BB_0x1033c825L;
                break;

            case State::BB_0x1033c825L:
                FUN_10342ebe();
                currentState = State::BB_0x1033c83aL;
                break;

            case State::BB_0x1033c83aL:
                currentState = State::BB_0x1033c83dL;
                break;

            case State::BB_0x1033c83dL:
                FUN_10343900();
                currentState = State::BB_0x1033c867L;
                break;

            case State::BB_0x1033c867L:
                currentState = State::BB_0x1033c882L;
                break;

            case State::BB_0x1033c882L:
                currentState = State::BB_0x1033c89fL;
                break;

            case State::BB_0x1033c89fL:
                currentState = State::BB_0x1033c8a5L;
                break;

            case State::BB_0x1033c8a5L:
                currentState = State::BB_0x1033c8c8L;
                break;

            case State::BB_0x1033c8c8L:
                currentState = State::BB_0x1033c8d2L;
                break;

            case State::BB_0x1033c8d2L:
                currentState = State::BB_0x1033c8e1L;
                break;

            case State::BB_0x1033c8e1L:
                currentState = State::BB_0x1033c8e6L;
                break;

            case State::BB_0x1033c8e6L:
                currentState = State::Exit;
                break;

            case State::BB_0x1033c8eeL:
                currentState = State::BB_0x1033c8f2L;
                break;

            case State::BB_0x1033c8f2L:
                currentState = State::BB_0x1033c8f8L;
                break;

            case State::BB_0x1033c8f8L:
                currentState = State::BB_0x1033c913L;
                break;

            case State::BB_0x1033c913L:
                currentState = State::BB_0x1033c916L;
                break;

            case State::BB_0x1033c916L:
                currentState = State::BB_0x1033c965L;
                break;

            case State::BB_0x1033c91bL:
                currentState = State::BB_0x1033c91fL;
                break;

            case State::BB_0x1033c91fL:
                currentState = State::BB_0x1033c922L;
                break;

            case State::BB_0x1033c922L:
                currentState = State::BB_0x1033c93aL;
                break;

            case State::BB_0x1033c93aL:
                currentState = State::BB_0x1033c913L;
                break;

            case State::BB_0x1033c93cL:
                currentState = State::BB_0x1033c965L;
                break;

            case State::BB_0x1033c95dL:
                currentState = State::BB_0x1033c965L;
                break;

            case State::BB_0x1033c965L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
