#include "FUN_102e1820.h"
#include "FUN_102dfa30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102e1820L,
    BB_0x102e182bL,
    BB_0x102e1832L,
    BB_0x102e183cL,
    BB_0x102e1840L,
    BB_0x102e185aL,
    BB_0x102e1860L,
    BB_0x102e186aL,
    BB_0x102e186eL,
    BB_0x102e1888L,
    BB_0x102e1891L,
    BB_0x102e1893L,
    Exit
};

void FUN_102e1820() {
    State currentState = State::BB_0x102e1820L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102e1820L:
                currentState = State::BB_0x102e182bL;
                break;

            case State::BB_0x102e182bL:
                currentState = State::BB_0x102e1832L;
                break;

            case State::BB_0x102e1832L:
                currentState = State::BB_0x102e183cL;
                break;

            case State::BB_0x102e183cL:
                currentState = State::BB_0x102e1840L;
                break;

            case State::BB_0x102e1840L:
                FUN_102dfa30();
                currentState = State::BB_0x102e185aL;
                break;

            case State::BB_0x102e185aL:
                currentState = State::BB_0x102e1860L;
                break;

            case State::BB_0x102e1860L:
                currentState = State::BB_0x102e186aL;
                break;

            case State::BB_0x102e186aL:
                currentState = State::BB_0x102e186eL;
                break;

            case State::BB_0x102e186eL:
                FUN_102dfa30();
                currentState = State::BB_0x102e1891L;
                break;

            case State::BB_0x102e1888L:
                currentState = State::BB_0x102e1832L;
                break;

            case State::BB_0x102e1891L:
                currentState = State::BB_0x102e1893L;
                break;

            case State::BB_0x102e1893L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
