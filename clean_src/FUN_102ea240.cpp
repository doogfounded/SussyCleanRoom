#include "FUN_102ea240.h"
#include "FUN_102fb450.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102ea240L,
    Exit
};

void FUN_102ea240() {
    State currentState = State::BB_0x102ea240L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102ea240L:
                FUN_102fb450();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
