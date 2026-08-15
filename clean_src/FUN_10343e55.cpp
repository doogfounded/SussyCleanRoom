#include "FUN_10343e55.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10343e55L,
    BB_0x10343e59L,
    BB_0x10343e64L,
    BB_0x1033daceL,
    Exit
};

void FUN_10343e55() {
    State currentState = State::BB_0x10343e55L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10343e55L:
                // Transition: BB_0x10343e55L -> BB_0x10343e59L
                currentState = State::BB_0x10343e59L;
                break;

            case State::BB_0x10343e59L:
                // Transition: BB_0x10343e59L -> BB_0x10343e64L
                currentState = State::BB_0x10343e64L;
                break;

            case State::BB_0x10343e64L:
                // Exit block
                currentState = State::Exit;
                break;

            case State::BB_0x1033daceL:
                // Exit block
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
