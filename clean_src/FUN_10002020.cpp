#include "FUN_10002020.h"
#include "FUN_10328f05.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10002020L,
    Exit
};

void FUN_10002020() {
    State currentState = State::BB_0x10002020L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10002020L:
                FUN_10328f05();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
