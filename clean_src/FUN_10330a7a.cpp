#include "FUN_10330a7a.h"
#include "FUN_1034145b.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330a7aL,
    BB_0x1034145bL,
    BB_0x10330a83L,
    BB_0x10330a89L,
    Exit
};

void FUN_10330a7a() {
    State currentState = State::BB_0x10330a7aL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330a7aL:
                // Transition: BB_0x10330a7aL -> BB_0x1034145bL
                currentState = State::BB_0x1034145bL;
                break;

            case State::BB_0x1034145bL:
                // Transition: BB_0x10330a7aL -> BB_0x1034145bL
                FUN_1034145b();
                currentState = State::BB_0x10330a83L;
                break;

            case State::BB_0x10330a83L:
                // Exit block
                currentState = State::Exit;
                break;

            case State::BB_0x10330a89L:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
