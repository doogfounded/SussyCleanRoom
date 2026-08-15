#include "FUN_1031e400.h"
#include "FUN_1031e560.h"
#include "FUN_102e0bc0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1031e400L,
    Exit
};

void FUN_1031e400() {
    State currentState = State::BB_0x1031e400L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1031e400L:
                FUN_1031e560();
                FUN_102e0bc0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
