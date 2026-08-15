#include "FUN_102edd10.h"
#include "FUN_102fb440.h"
#include "FUN_102b23f0.h"
#include "FUN_102b3b80.h"
#include "FUN_102ed810.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102edd10L,
    BB_0x102edd63L,
    BB_0x102edd70L,
    BB_0x102edd74L,
    BB_0x102edd80L,
    BB_0x102edd85L,
    BB_0x102edd8dL,
    BB_0x102edd8fL,
    BB_0x102eddbaL,
    BB_0x102eddbeL,
    BB_0x102eddc3L,
    BB_0x102eddceL,
    BB_0x102eddf6L,
    BB_0x102eddfaL,
    BB_0x102ede04L,
    BB_0x102edf80L,
    BB_0x102edf9bL,
    BB_0x102edfa1L,
    BB_0x102edfbcL,
    BB_0x102edfcbL,
    BB_0x102edfd3L,
    BB_0x102edfd7L,
    BB_0x102edfe2L,
    BB_0x102edff3L,
    Exit
};

void FUN_102edd10() {
    State currentState = State::BB_0x102edd10L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102edd10L:
                currentState = State::BB_0x102edd63L;
                break;

            case State::BB_0x102edd63L:
                currentState = State::BB_0x102edd70L;
                break;

            case State::BB_0x102edd70L:
                currentState = State::BB_0x102edd74L;
                break;

            case State::BB_0x102edd74L:
                currentState = State::BB_0x102eddbeL;
                break;

            case State::BB_0x102edd80L:
                currentState = State::BB_0x102edd85L;
                break;

            case State::BB_0x102edd85L:
                currentState = State::BB_0x102edd8dL;
                break;

            case State::BB_0x102edd8dL:
                currentState = State::BB_0x102edd8fL;
                break;

            case State::BB_0x102edd8fL:
                currentState = State::BB_0x102eddbaL;
                break;

            case State::BB_0x102eddbaL:
                currentState = State::BB_0x102eddceL;
                break;

            case State::BB_0x102eddbeL:
                currentState = State::BB_0x102edd8fL;
                break;

            case State::BB_0x102eddc3L:
                currentState = State::BB_0x102eddceL;
                break;

            case State::BB_0x102eddceL:
                currentState = State::BB_0x102eddf6L;
                break;

            case State::BB_0x102eddf6L:
                currentState = State::BB_0x102ede04L;
                break;

            case State::BB_0x102eddfaL:
                currentState = State::BB_0x102ede04L;
                break;

            case State::BB_0x102ede04L:
                FUN_102ed810();
                FUN_102b3b80();
                currentState = State::BB_0x102edf80L;
                break;

            case State::BB_0x102edf80L:
                FUN_102b23f0();
                currentState = State::BB_0x102edf9bL;
                break;

            case State::BB_0x102edf9bL:
                currentState = State::BB_0x102edfa1L;
                break;

            case State::BB_0x102edfa1L:
                FUN_102b23f0();
                currentState = State::BB_0x102edfbcL;
                break;

            case State::BB_0x102edfbcL:
                currentState = State::BB_0x102edff3L;
                break;

            case State::BB_0x102edfcbL:
                currentState = State::BB_0x102edfd3L;
                break;

            case State::BB_0x102edfd3L:
                currentState = State::BB_0x102edfe2L;
                break;

            case State::BB_0x102edfd7L:
                currentState = State::BB_0x102edfe2L;
                break;

            case State::BB_0x102edfe2L:
                FUN_102b23f0();
                currentState = State::BB_0x102edff3L;
                break;

            case State::BB_0x102edff3L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
