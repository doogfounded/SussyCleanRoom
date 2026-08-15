#include "FUN_103391b9.h"
#include "FUN_1034169e.h"
#include "FUN_10338344.h"
#include "set_buffer.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103391b9L,
    BB_0x103391f9L,
    BB_0x1033920cL,
    BB_0x10339215L,
    BB_0x1033922dL,
    BB_0x10339238L,
    BB_0x10339241L,
    BB_0x10339248L,
    BB_0x1033924dL,
    BB_0x10339255L,
    Exit
};

void FUN_103391b9() {
    State currentState = State::BB_0x103391b9L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103391b9L:
                FUN_10338344();
                currentState = State::BB_0x1033920cL;
                break;

            case State::BB_0x103391f9L:
                currentState = State::BB_0x1033924dL;
                break;

            case State::BB_0x1033920cL:
                currentState = State::BB_0x10339215L;
                break;

            case State::BB_0x10339215L:
                FUN_1034169e();
                currentState = State::BB_0x1033922dL;
                break;

            case State::BB_0x1033922dL:
                currentState = State::BB_0x10339255L;
                break;

            case State::BB_0x10339238L:
                currentState = State::BB_0x10339248L;
                break;

            case State::BB_0x10339241L:
                currentState = State::BB_0x10339248L;
                break;

            case State::BB_0x10339248L:
                currentState = State::BB_0x1033924dL;
                break;

            case State::BB_0x1033924dL:
                set_buffer();
                currentState = State::BB_0x10339255L;
                break;

            case State::BB_0x10339255L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
