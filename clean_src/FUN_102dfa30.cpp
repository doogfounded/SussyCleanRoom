#include "FUN_102dfa30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102dfa30L,
    BB_0x102dfa40L,
    BB_0x102dfa4cL,
    BB_0x102dfa56L,
    BB_0x102dfa5eL,
    BB_0x102dfa74L,
    BB_0x102dfa78L,
    BB_0x102dfa7eL,
    BB_0x102dfa86L,
    BB_0x102dfa96L,
    BB_0x102dfa9dL,
    BB_0x102dfaa4L,
    BB_0x102dfaaaL,
    BB_0x102dfab6L,
    BB_0x102dfabaL,
    BB_0x102dfac0L,
    BB_0x102dfac8L,
    BB_0x102dfad1L,
    BB_0x102dfadbL,
    BB_0x102dfae6L,
    BB_0x102dfaf4L,
    BB_0x102dfaf8L,
    BB_0x102dfafeL,
    BB_0x102dfb02L,
    BB_0x102dfb08L,
    BB_0x102dfb0cL,
    BB_0x102dfb20L,
    BB_0x102dfb26L,
    BB_0x102dfb3eL,
    BB_0x102dfb43L,
    BB_0x102dfb48L,
    BB_0x102dfb4cL,
    BB_0x102dfb5fL,
    BB_0x102dfb69L,
    BB_0x102dfb6bL,
    Exit
};

void FUN_102dfa30() {
    State currentState = State::BB_0x102dfa30L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102dfa30L:
                currentState = State::BB_0x102dfa40L;
                break;

            case State::BB_0x102dfa40L:
                currentState = State::BB_0x102dfa56L;
                break;

            case State::BB_0x102dfa4cL:
                currentState = State::BB_0x102dfa56L;
                break;

            case State::BB_0x102dfa56L:
                currentState = State::BB_0x102dfa5eL;
                break;

            case State::BB_0x102dfa5eL:
                currentState = State::BB_0x102dfa7eL;
                break;

            case State::BB_0x102dfa74L:
                currentState = State::BB_0x102dfa7eL;
                break;

            case State::BB_0x102dfa78L:
                currentState = State::BB_0x102dfa7eL;
                break;

            case State::BB_0x102dfa7eL:
                currentState = State::BB_0x102dfa86L;
                break;

            case State::BB_0x102dfa86L:
                currentState = State::BB_0x102dfa96L;
                break;

            case State::BB_0x102dfa96L:
                currentState = State::BB_0x102dfa9dL;
                break;

            case State::BB_0x102dfa9dL:
                currentState = State::BB_0x102dfaa4L;
                break;

            case State::BB_0x102dfaa4L:
                currentState = State::BB_0x102dfb6bL;
                break;

            case State::BB_0x102dfaaaL:
                currentState = State::BB_0x102dfab6L;
                break;

            case State::BB_0x102dfab6L:
                currentState = State::BB_0x102dfac0L;
                break;

            case State::BB_0x102dfabaL:
                currentState = State::BB_0x102dfac0L;
                break;

            case State::BB_0x102dfac0L:
                currentState = State::BB_0x102dfac8L;
                break;

            case State::BB_0x102dfac8L:
                currentState = State::BB_0x102dfb6bL;
                break;

            case State::BB_0x102dfad1L:
                currentState = State::BB_0x102dfadbL;
                break;

            case State::BB_0x102dfadbL:
                currentState = State::BB_0x102dfb6bL;
                break;

            case State::BB_0x102dfae6L:
                currentState = State::BB_0x102dfaf4L;
                break;

            case State::BB_0x102dfaf4L:
                currentState = State::BB_0x102dfaf8L;
                break;

            case State::BB_0x102dfaf8L:
                currentState = State::BB_0x102dfb02L;
                break;

            case State::BB_0x102dfafeL:
                currentState = State::BB_0x102dfb08L;
                break;

            case State::BB_0x102dfb02L:
                currentState = State::BB_0x102dfb08L;
                break;

            case State::BB_0x102dfb08L:
                currentState = State::BB_0x102dfb0cL;
                break;

            case State::BB_0x102dfb0cL:
                currentState = State::BB_0x102dfb20L;
                break;

            case State::BB_0x102dfb20L:
                currentState = State::BB_0x102dfb26L;
                break;

            case State::BB_0x102dfb26L:
                currentState = State::BB_0x102dfb3eL;
                break;

            case State::BB_0x102dfb3eL:
                currentState = State::BB_0x102dfb43L;
                break;

            case State::BB_0x102dfb43L:
                currentState = State::BB_0x102dfb48L;
                break;

            case State::BB_0x102dfb48L:
                currentState = State::BB_0x102dfb4cL;
                break;

            case State::BB_0x102dfb4cL:
                currentState = State::BB_0x102dfb6bL;
                break;

            case State::BB_0x102dfb5fL:
                currentState = State::BB_0x102dfb69L;
                break;

            case State::BB_0x102dfb69L:
                currentState = State::BB_0x102dfb6bL;
                break;

            case State::BB_0x102dfb6bL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
