#include "FUN_1034150c.h"
#include "FUN_1034169e.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034150cL,
    BB_0x1034151fL,
    BB_0x1034152bL,
    BB_0x10341530L,
    BB_0x10341532L,
    BB_0x10341537L,
    BB_0x10341543L,
    BB_0x10341557L,
    BB_0x10341564L,
    BB_0x1034156cL,
    BB_0x1034157cL,
    BB_0x1034158bL,
    BB_0x103415a0L,
    BB_0x103415a9L,
    Exit
};

void FUN_1034150c() {
    State currentState = State::BB_0x1034150cL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034150cL:
                currentState = State::BB_0x1034151fL;
                break;

            case State::BB_0x1034151fL:
                currentState = State::BB_0x10341532L;
                break;

            case State::BB_0x1034152bL:
                currentState = State::BB_0x10341530L;
                break;

            case State::BB_0x10341530L:
                currentState = State::BB_0x103415a0L;
                break;

            case State::BB_0x10341532L:
                currentState = State::BB_0x10341537L;
                break;

            case State::BB_0x10341537L:
                currentState = State::BB_0x10341543L;
                break;

            case State::BB_0x10341543L:
                currentState = State::BB_0x10341557L;
                break;

            case State::BB_0x10341557L:
                currentState = State::BB_0x10341564L;
                break;

            case State::BB_0x10341564L:
                FUN_1034169e();
                currentState = State::BB_0x103415a9L;
                break;

            case State::BB_0x1034156cL:
                currentState = State::BB_0x1034158bL;
                break;

            case State::BB_0x1034157cL:
                currentState = State::BB_0x10341564L;
                break;

            case State::BB_0x1034158bL:
                FUN_1034169e();
                currentState = State::BB_0x103415a0L;
                break;

            case State::BB_0x103415a0L:
                currentState = State::BB_0x103415a9L;
                break;

            case State::BB_0x103415a9L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
