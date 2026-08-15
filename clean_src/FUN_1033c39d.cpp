#include "FUN_1033c39d.h"
#include "FUN_1033c27c.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033c39dL,
    BB_0x1033c27cL,
    Exit
};

void FUN_1033c39d() {
    State currentState = State::BB_0x1033c39dL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033c39dL:
                // Transition: BB_0x1033c39dL -> BB_0x1033c27cL
                currentState = State::BB_0x1033c27cL;
                break;

            case State::BB_0x1033c27cL:
                // Transition: BB_0x1033c39dL -> BB_0x1033c27cL
                FUN_1033c27c();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
