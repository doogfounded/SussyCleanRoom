#include "FUN_102bb350.h"
#include "FUN_1031e430.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102bb350L,
    Exit
};

void FUN_102bb350() {
    State currentState = State::BB_0x102bb350L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102bb350L:
                FUN_1031e430();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
