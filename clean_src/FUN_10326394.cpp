#include "FUN_10326394.h"
#include "FUN_10326264.h"
#include "FUN_10329c6b.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10326394L,
    Exit
};

void FUN_10326394() {
    State currentState = State::BB_0x10326394L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10326394L:
                FUN_10326264();
                FUN_10329c6b();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
