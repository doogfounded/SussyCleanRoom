#include "FUN_102b9200.h"
#include "FUN_10330e01.h"
#include "FUN_103283b0.h"
#include "FUN_102b8e70.h"
#include "FUN_10336c14.h"
#include "FUN_10336ce7.h"
#include "FUN_10330dd0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b9200L,
    BB_0x102b9220L,
    BB_0x102b9225L,
    BB_0x102b924dL,
    BB_0x102b9251L,
    BB_0x102b925eL,
    BB_0x102b926dL,
    BB_0x102b9270L,
    BB_0x102b927fL,
    BB_0x102b9280L,
    BB_0x102b9298L,
    BB_0x102b9320L,
    BB_0x102b9355L,
    BB_0x102b9370L,
    BB_0x102b9378L,
    BB_0x102b937cL,
    BB_0x102b938bL,
    BB_0x102b938eL,
    BB_0x102b9396L,
    BB_0x102b939fL,
    BB_0x102b93b9L,
    BB_0x102b93beL,
    BB_0x102b93f3L,
    BB_0x102b93ffL,
    Exit
};

void FUN_102b9200() {
    State currentState = State::BB_0x102b9200L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b9200L:
                currentState = State::BB_0x102b9220L;
                break;

            case State::BB_0x102b9220L:
                currentState = State::BB_0x102b9225L;
                break;

            case State::BB_0x102b9225L:
                FUN_103283b0();
                currentState = State::BB_0x102b9251L;
                break;

            case State::BB_0x102b924dL:
                currentState = State::BB_0x102b9220L;
                break;

            case State::BB_0x102b9251L:
                currentState = State::BB_0x102b925eL;
                break;

            case State::BB_0x102b925eL:
                FUN_10330e01();
                currentState = State::BB_0x102b926dL;
                break;

            case State::BB_0x102b926dL:
                currentState = State::BB_0x102b9270L;
                break;

            case State::BB_0x102b9270L:
                currentState = State::BB_0x102b927fL;
                break;

            case State::BB_0x102b927fL:
                currentState = State::BB_0x102b9280L;
                break;

            case State::BB_0x102b9280L:
                currentState = State::BB_0x102b9298L;
                break;

            case State::BB_0x102b9298L:
                FUN_103283b0();
                FUN_102b8e70();
                currentState = State::BB_0x102b9320L;
                break;

            case State::BB_0x102b9320L:
                FUN_102b8e70();
                currentState = State::BB_0x102b9355L;
                break;

            case State::BB_0x102b9355L:
                currentState = State::BB_0x102b9370L;
                break;

            case State::BB_0x102b9370L:
                currentState = State::BB_0x102b9378L;
                break;

            case State::BB_0x102b9378L:
                currentState = State::BB_0x102b938eL;
                break;

            case State::BB_0x102b937cL:
                currentState = State::BB_0x102b938eL;
                break;

            case State::BB_0x102b938bL:
                currentState = State::BB_0x102b938eL;
                break;

            case State::BB_0x102b938eL:
                currentState = State::Exit;
                break;

            case State::BB_0x102b9396L:
                currentState = State::BB_0x102b939fL;
                break;

            case State::BB_0x102b939fL:
                FUN_10336c14();
                currentState = State::BB_0x102b93ffL;
                break;

            case State::BB_0x102b93b9L:
                currentState = State::BB_0x102b926dL;
                break;

            case State::BB_0x102b93beL:
                FUN_102b8e70();
                currentState = State::BB_0x102b9320L;
                break;

            case State::BB_0x102b93f3L:
                currentState = State::Exit;
                break;

            case State::BB_0x102b93ffL:
                FUN_10336ce7();
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
