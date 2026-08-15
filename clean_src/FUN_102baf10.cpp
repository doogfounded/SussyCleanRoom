#include "FUN_102baf10.h"
#include "FUN_103283b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102baf10L,
    Exit
};

void FUN_102baf10() {
    State currentState = State::BB_0x102baf10L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102baf10L:
                FUN_103283b0();
                FUN_103283b0();
                FUN_103283b0();
                FUN_103283b0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
