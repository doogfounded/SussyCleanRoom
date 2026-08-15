#include "FUN_1031e450.h"
#include "FUN_1031e560.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1031e450L,
    Exit
};

void FUN_1031e450() {
    State currentState = State::BB_0x1031e450L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1031e450L:
                FUN_1031e560();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
