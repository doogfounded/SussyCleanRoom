#include "FUN_102eade0.h"
#include "FUN_102e70d0.h"
#include "FUN_10329c6b.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102eade0L,
    Exit
};

void FUN_102eade0() {
    State currentState = State::BB_0x102eade0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102eade0L:
                FUN_102e70d0();
                FUN_10329c6b();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
