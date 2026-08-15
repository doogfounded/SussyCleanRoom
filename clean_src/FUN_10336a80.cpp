#include "FUN_10336a80.h"
#include "FUN_103369cc.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10336a80L,
    Exit
};

void FUN_10336a80() {
    State currentState = State::BB_0x10336a80L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10336a80L:
                FUN_103369cc();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
