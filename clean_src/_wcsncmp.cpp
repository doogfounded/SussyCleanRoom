#include "_wcsncmp.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033fa7aL,
    BB_0x1033fa86L,
    BB_0x1033fa88L,
    BB_0x1033fa8fL,
    BB_0x1033fa94L,
    BB_0x1033fa9cL,
    BB_0x1033faa1L,
    BB_0x1033faa9L,
    Exit
};

void _wcsncmp() {
    State currentState = State::BB_0x1033fa7aL;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x1033fa7aL:
                currentState = State::BB_0x1033fa88L;
                break;

            case State::BB_0x1033fa86L:
                currentState = State::BB_0x1033faa9L;
                break;

            case State::BB_0x1033fa88L:
                currentState = State::BB_0x1033fa8fL;
                break;

            case State::BB_0x1033fa8fL:
                currentState = State::BB_0x1033fa94L;
                break;

            case State::BB_0x1033fa94L:
                currentState = State::BB_0x1033fa9cL;
                break;

            case State::BB_0x1033fa9cL:
                currentState = State::BB_0x1033faa1L;
                break;

            case State::BB_0x1033faa1L:
                currentState = State::Exit;
                break;

            case State::BB_0x1033faa9L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
