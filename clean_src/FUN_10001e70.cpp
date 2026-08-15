#include "FUN_10001e70.h"
#include "FUN_102af880.h"
#include "FUN_10328f05.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10001e70L,
    Exit
};

void FUN_10001e70() {
    State currentState = State::BB_0x10001e70L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10001e70L:
                FUN_102af880();
                FUN_10328f05();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
