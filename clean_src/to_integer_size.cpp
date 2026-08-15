#include "to_integer_size.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033566bL,
    BB_0x10335678L,
    BB_0x1033567fL,
    BB_0x10335686L,
    BB_0x1033568bL,
    BB_0x1033568dL,
    BB_0x10335690L,
    BB_0x10335694L,
    BB_0x10335698L,
    Exit
};

void to_integer_size() {
    State currentState = State::BB_0x1033566bL;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x1033566bL:
                currentState = State::BB_0x10335678L;
                break;

            case State::BB_0x10335678L:
                currentState = State::BB_0x1033567fL;
                break;

            case State::BB_0x1033567fL:
                currentState = State::BB_0x10335698L;
                break;

            case State::BB_0x10335686L:
                currentState = State::BB_0x10335698L;
                break;

            case State::BB_0x1033568bL:
                currentState = State::BB_0x1033568dL;
                break;

            case State::BB_0x1033568dL:
                currentState = State::Exit;
                break;

            case State::BB_0x10335690L:
                currentState = State::BB_0x1033568dL;
                break;

            case State::BB_0x10335694L:
                currentState = State::BB_0x1033568dL;
                break;

            case State::BB_0x10335698L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
