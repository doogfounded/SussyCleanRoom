#include "FUN_102ea260.h"
#include "FUN_102fba30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102ea260L,
    Exit
};

void FUN_102ea260() {
    State currentState = State::BB_0x102ea260L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102ea260L:
                FUN_102fba30();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
