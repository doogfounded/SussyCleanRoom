#include "FUN_102e1930.h"
#include "FUN_102dfa30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102e1930L,
    BB_0x102e193fL,
    BB_0x102e1943L,
    BB_0x102e194dL,
    BB_0x102e1951L,
    BB_0x102e196bL,
    BB_0x102e1973L,
    BB_0x102e1977L,
    BB_0x102e1979L,
    BB_0x102e197dL,
    BB_0x102e1983L,
    BB_0x102e198aL,
    BB_0x102e198eL,
    BB_0x102e19a8L,
    BB_0x102e19b0L,
    BB_0x102e19b4L,
    BB_0x102e19b6L,
    BB_0x102e19baL,
    BB_0x102e19caL,
    BB_0x102e19ccL,
    Exit
};

void FUN_102e1930() {
    State currentState = State::BB_0x102e1930L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102e1930L:
                currentState = State::BB_0x102e193fL;
                break;

            case State::BB_0x102e193fL:
                currentState = State::BB_0x102e1943L;
                break;

            case State::BB_0x102e1943L:
                currentState = State::BB_0x102e194dL;
                break;

            case State::BB_0x102e194dL:
                currentState = State::BB_0x102e1951L;
                break;

            case State::BB_0x102e1951L:
                FUN_102dfa30();
                currentState = State::BB_0x102e1977L;
                break;

            case State::BB_0x102e196bL:
                currentState = State::BB_0x102e1977L;
                break;

            case State::BB_0x102e1973L:
                currentState = State::BB_0x102e1979L;
                break;

            case State::BB_0x102e1977L:
                currentState = State::BB_0x102e1979L;
                break;

            case State::BB_0x102e1979L:
                currentState = State::BB_0x102e197dL;
                break;

            case State::BB_0x102e197dL:
                currentState = State::BB_0x102e1983L;
                break;

            case State::BB_0x102e1983L:
                currentState = State::BB_0x102e198aL;
                break;

            case State::BB_0x102e198aL:
                currentState = State::BB_0x102e198eL;
                break;

            case State::BB_0x102e198eL:
                FUN_102dfa30();
                currentState = State::BB_0x102e19b4L;
                break;

            case State::BB_0x102e19a8L:
                currentState = State::BB_0x102e19b4L;
                break;

            case State::BB_0x102e19b0L:
                currentState = State::BB_0x102e19b6L;
                break;

            case State::BB_0x102e19b4L:
                currentState = State::BB_0x102e19b6L;
                break;

            case State::BB_0x102e19b6L:
                currentState = State::BB_0x102e19baL;
                break;

            case State::BB_0x102e19baL:
                currentState = State::BB_0x102e19caL;
                break;

            case State::BB_0x102e19caL:
                currentState = State::BB_0x102e19ccL;
                break;

            case State::BB_0x102e19ccL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
