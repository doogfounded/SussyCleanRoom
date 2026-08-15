#include "FUN_102d3080.h"
#include "FUN_1031e400.h"
#include "FUN_1031e390.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d3080L,
    BB_0x102d30b0L,
    BB_0x102d30bdL,
    BB_0x102d30c5L,
    BB_0x102d30d7L,
    BB_0x102d30ddL,
    BB_0x102d30eaL,
    BB_0x102d30eeL,
    BB_0x102d3100L,
    BB_0x102d3118L,
    BB_0x102d3127L,
    BB_0x102d312bL,
    BB_0x102d313dL,
    BB_0x102d314eL,
    BB_0x102d315cL,
    BB_0x102d3168L,
    BB_0x102d3174L,
    Exit
};

void FUN_102d3080() {
    State currentState = State::BB_0x102d3080L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102d3080L:
                currentState = State::BB_0x102d30b0L;
                break;

            case State::BB_0x102d30b0L:
                currentState = State::BB_0x102d30bdL;
                break;

            case State::BB_0x102d30bdL:
                currentState = State::BB_0x102d30c5L;
                break;

            case State::BB_0x102d30c5L:
                FUN_1031e390();
                currentState = State::BB_0x102d30d7L;
                break;

            case State::BB_0x102d30d7L:
                currentState = State::BB_0x102d3118L;
                break;

            case State::BB_0x102d30ddL:
                currentState = State::BB_0x102d3118L;
                break;

            case State::BB_0x102d30eaL:
                currentState = State::BB_0x102d3100L;
                break;

            case State::BB_0x102d30eeL:
                FUN_1031e390();
                currentState = State::BB_0x102d3100L;
                break;

            case State::BB_0x102d3100L:
                currentState = State::BB_0x102d30b0L;
                break;

            case State::BB_0x102d3118L:
                currentState = State::BB_0x102d313dL;
                break;

            case State::BB_0x102d3127L:
                currentState = State::BB_0x102d3174L;
                break;

            case State::BB_0x102d312bL:
                FUN_1031e390();
                currentState = State::BB_0x102d313dL;
                break;

            case State::BB_0x102d313dL:
                currentState = State::BB_0x102d30b0L;
                break;

            case State::BB_0x102d314eL:
                currentState = State::BB_0x102d3168L;
                break;

            case State::BB_0x102d315cL:
                currentState = State::Exit;
                break;

            case State::BB_0x102d3168L:
                currentState = State::Exit;
                break;

            case State::BB_0x102d3174L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
