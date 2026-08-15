#include "FUN_10002610.h"
#include "FUN_102af880.h"
#include "FUN_10328f05.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10002610L,
    Exit
};

void FUN_10002610() {
    State currentState = State::BB_0x10002610L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10002610L:
                FUN_102af880();
                FUN_10328f05();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
