#include "FUN_10307700.h"
#include "FUN_10337c5e.h"
#include "FUN_102fba20.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10307700L,
    BB_0x1030770bL,
    BB_0x10307710L,
    BB_0x10307715L,
    BB_0x1030771cL,
    BB_0x10307732L,
    BB_0x1030773dL,
    Exit
};

void FUN_10307700() {
    State currentState = State::BB_0x10307700L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10307700L:
                currentState = State::BB_0x1030770bL;
                break;

            case State::BB_0x1030770bL:
                currentState = State::BB_0x10307710L;
                break;

            case State::BB_0x10307710L:
                currentState = State::BB_0x10307715L;
                break;

            case State::BB_0x10307715L:
                currentState = State::BB_0x1030771cL;
                break;

            case State::BB_0x1030771cL:
                FUN_102fba20();
                currentState = State::BB_0x10307732L;
                break;

            case State::BB_0x10307732L:
                FUN_10337c5e();
                currentState = State::BB_0x1030773dL;
                break;

            case State::BB_0x1030773dL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
