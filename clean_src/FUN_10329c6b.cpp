#include "FUN_10329c6b.h"
#include "guard_check_icall.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10329c6bL,
    BB_0x10329c85L,
    BB_0x10329c8aL,
    BB_0x10329ca8L,
    BB_0x10329cb3L,
    Exit
};

void FUN_10329c6b() {
    State currentState = State::BB_0x10329c6bL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10329c6bL:
                currentState = State::BB_0x10329c85L;
                break;

            case State::BB_0x10329c85L:
                currentState = State::BB_0x10329c8aL;
                break;

            case State::BB_0x10329c8aL:
                guard_check_icall();
                currentState = State::BB_0x10329ca8L;
                break;

            case State::BB_0x10329ca8L:
                currentState = State::BB_0x10329cb3L;
                break;

            case State::BB_0x10329cb3L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
