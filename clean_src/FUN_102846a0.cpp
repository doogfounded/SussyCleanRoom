#include "FUN_102846a0.h"
#include "FUN_102859a0.h"
#include "FUN_10336a90.h"
#include "FUN_10329247.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102846a0L,
    BB_0x102846aeL,
    BB_0x102846b5L,
    BB_0x102846bcL,
    BB_0x102846c3L,
    BB_0x102846d2L,
    BB_0x102846e0L,
    BB_0x102846eeL,
    BB_0x102846f3L,
    Exit
};

void FUN_102846a0() {
    State currentState = State::BB_0x102846a0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102846a0L:
                currentState = State::BB_0x102846aeL;
                break;

            case State::BB_0x102846aeL:
                currentState = State::BB_0x102846b5L;
                break;

            case State::BB_0x102846b5L:
                currentState = State::BB_0x102846bcL;
                break;

            case State::BB_0x102846bcL:
                currentState = State::BB_0x102846c3L;
                break;

            case State::BB_0x102846c3L:
                FUN_10329247();
                currentState = State::BB_0x102846d2L;
                break;

            case State::BB_0x102846d2L:
                currentState = State::Exit;
                break;

            case State::BB_0x102846e0L:
                FUN_10329247();
                currentState = State::Exit;
                break;

            case State::BB_0x102846eeL:
                FUN_102859a0();
                currentState = State::Exit;
                break;

            case State::BB_0x102846f3L:
                FUN_10336a90();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
