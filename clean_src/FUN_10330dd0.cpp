#include "FUN_10330dd0.h"
#include "FUN_10330bf0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330dd0L,
    Exit
};

void FUN_10330dd0() {
    State currentState = State::BB_0x10330dd0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330dd0L:
                FUN_10330bf0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
