#include "FUN_10298bf0.h"
#include "FUN_103283b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10298bf0L,
    Exit
};

void FUN_10298bf0() {
    State currentState = State::BB_0x10298bf0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10298bf0L:
                FUN_103283b0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
