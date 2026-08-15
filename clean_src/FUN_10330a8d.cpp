#include "FUN_10330a8d.h"
#include "FUN_1034145b.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330a8dL,
    BB_0x1034145bL,
    BB_0x10330a96L,
    BB_0x10330a9cL,
    Exit
};

void FUN_10330a8d() {
    State currentState = State::BB_0x10330a8dL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330a8dL:
                // Transition: BB_0x10330a8dL -> BB_0x1034145bL
                currentState = State::BB_0x1034145bL;
                break;

            case State::BB_0x1034145bL:
                // Transition: BB_0x10330a8dL -> BB_0x1034145bL
                FUN_1034145b();
                currentState = State::BB_0x10330a96L;
                break;

            case State::BB_0x10330a96L:
                // Exit block
                currentState = State::Exit;
                break;

            case State::BB_0x10330a9cL:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
