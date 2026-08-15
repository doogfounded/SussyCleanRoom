#include "FUN_10002080.h"
#include "FUN_10328f05.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10002080L,
    BB_0x100020b4L,
    BB_0x100020beL,
    BB_0x100020c0L,
    Exit
};

void FUN_10002080() {
    State currentState = State::BB_0x10002080L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10002080L:
                currentState = State::BB_0x100020b4L;
                break;

            case State::BB_0x100020b4L:
                currentState = State::BB_0x100020c0L;
                break;

            case State::BB_0x100020beL:
                currentState = State::BB_0x100020c0L;
                break;

            case State::BB_0x100020c0L:
                FUN_10328f05();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
