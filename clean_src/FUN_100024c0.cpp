#include "FUN_100024c0.h"
#include "FUN_10328f05.h"
#include "FUN_103147e0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x100024c0L,
    Exit
};

void FUN_100024c0() {
    State currentState = State::BB_0x100024c0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x100024c0L:
                FUN_103147e0();
                FUN_10328f05();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
