#include "FUN_102f0140.h"
#include "FUN_102f0180.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102f0140L,
    Exit
};

void FUN_102f0140() {
    State currentState = State::BB_0x102f0140L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102f0140L:
                FUN_102f0180();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
