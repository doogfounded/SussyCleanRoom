#include "FUN_10330c87.h"
#include "FUN_10330cfa.h"
#include "FUN_10330d13.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330c87L,
    BB_0x10330c95L,
    BB_0x10330ca5L,
    Exit
};

void FUN_10330c87() {
    State currentState = State::BB_0x10330c87L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330c87L:
                FUN_10330cfa();
                currentState = State::BB_0x10330c95L;
                break;

            case State::BB_0x10330c95L:
                currentState = State::BB_0x10330ca5L;
                break;

            case State::BB_0x10330ca5L:
                FUN_10330d13();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
