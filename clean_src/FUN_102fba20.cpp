#include "FUN_102fba20.h"
#include "FUN_10330e01.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102fba20L,
    Exit
};

void FUN_102fba20() {
    State currentState = State::BB_0x102fba20L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102fba20L:
                FUN_10330e01();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
