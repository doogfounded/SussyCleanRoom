#include "FUN_102fb440.h"
#include "FUN_10337a28.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102fb440L,
    Exit
};

void FUN_102fb440() {
    State currentState = State::BB_0x102fb440L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102fb440L:
                FUN_10337a28();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
