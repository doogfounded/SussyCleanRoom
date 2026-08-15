#include "__exit.h"
#include "FUN_10330bf0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330db3L,
    Exit
};

void __exit() {
    State currentState = State::BB_0x10330db3L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330db3L:
                FUN_10330bf0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
