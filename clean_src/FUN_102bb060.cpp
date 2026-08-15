#include "FUN_102bb060.h"
#include "FUN_103283b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102bb060L,
    Exit
};

void FUN_102bb060() {
    State currentState = State::BB_0x102bb060L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102bb060L:
                FUN_103283b0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
