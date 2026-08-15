#include "FUN_102859a0.h"
#include "FUN_10284800.h"
#include "FUN_10329c6b.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102859a0L,
    Exit
};

void FUN_102859a0() {
    State currentState = State::BB_0x102859a0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102859a0L:
                FUN_10284800();
                FUN_10329c6b();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
