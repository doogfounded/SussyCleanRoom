#include "FUN_10316d60.h"
#include "FUN_103283b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10316d60L,
    Exit
};

void FUN_10316d60() {
    State currentState = State::BB_0x10316d60L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10316d60L:
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
