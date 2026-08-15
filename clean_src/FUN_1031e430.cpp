#include "FUN_1031e430.h"
#include "FUN_1031e500.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1031e430L,
    Exit
};

void FUN_1031e430() {
    State currentState = State::BB_0x1031e430L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1031e430L:
                FUN_1031e500();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
