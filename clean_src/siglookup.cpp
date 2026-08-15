#include "siglookup.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10343c5eL,
    BB_0x10343c73L,
    BB_0x10343c76L,
    BB_0x10343c7bL,
    BB_0x10343c82L,
    BB_0x10343c84L,
    Exit
};

void siglookup() {
    State currentState = State::BB_0x10343c5eL;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10343c5eL:
                currentState = State::BB_0x10343c73L;
                break;

            case State::BB_0x10343c73L:
                currentState = State::BB_0x10343c76L;
                break;

            case State::BB_0x10343c76L:
                currentState = State::BB_0x10343c7bL;
                break;

            case State::BB_0x10343c7bL:
                currentState = State::BB_0x10343c82L;
                break;

            case State::BB_0x10343c82L:
                currentState = State::BB_0x10343c84L;
                break;

            case State::BB_0x10343c84L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
