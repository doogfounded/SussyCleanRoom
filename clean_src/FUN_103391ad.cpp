#include "FUN_103391ad.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103391adL,
    BB_0x10336d9dL,
    Exit
};

void FUN_103391ad() {
    State currentState = State::BB_0x103391adL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103391adL:
                // Transition: BB_0x103391adL -> BB_0x10336d9dL
                currentState = State::BB_0x10336d9dL;
                break;

            case State::BB_0x10336d9dL:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
