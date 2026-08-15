#include "FUN_10336a90.h"
#include "FUN_103369cc.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10336a90L,
    Exit
};

void FUN_10336a90() {
    State currentState = State::BB_0x10336a90L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10336a90L:
                FUN_103369cc();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
