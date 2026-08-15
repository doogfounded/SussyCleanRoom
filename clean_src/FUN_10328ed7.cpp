#include "FUN_10328ed7.h"
#include "FUN_1033f741.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10328ed7L,
    BB_0x10328ee6L,
    BB_0x10328eedL,
    BB_0x10328ef8L,
    Exit
};

void FUN_10328ed7() {
    State currentState = State::BB_0x10328ed7L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10328ed7L:
                currentState = State::BB_0x10328ee6L;
                break;

            case State::BB_0x10328ee6L:
                FUN_1033f741();
                currentState = State::BB_0x10328ef8L;
                break;

            case State::BB_0x10328eedL:
                currentState = State::BB_0x10328ef8L;
                break;

            case State::BB_0x10328ef8L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
