#include "FUN_102fb320.h"
#include "FUN_10330e01.h"
#include "FUN_10329277.h"
#include "FUN_102fc1c0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102fb320L,
    BB_0x102fb354L,
    BB_0x102fb35eL,
    BB_0x102fb360L,
    BB_0x102fb367L,
    BB_0x102fb370L,
    BB_0x102fb3b6L,
    BB_0x102fb3d0L,
    Exit
};

void FUN_102fb320() {
    State currentState = State::BB_0x102fb320L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102fb320L:
                currentState = State::BB_0x102fb354L;
                break;

            case State::BB_0x102fb354L:
                currentState = State::BB_0x102fb360L;
                break;

            case State::BB_0x102fb35eL:
                currentState = State::BB_0x102fb360L;
                break;

            case State::BB_0x102fb360L:
                currentState = State::BB_0x102fb367L;
                break;

            case State::BB_0x102fb367L:
                currentState = State::BB_0x102fb370L;
                break;

            case State::BB_0x102fb370L:
                FUN_10329277();
                FUN_102fc1c0();
                currentState = State::BB_0x102fb3d0L;
                break;

            case State::BB_0x102fb3b6L:
                currentState = State::BB_0x102fb3d0L;
                break;

            case State::BB_0x102fb3d0L:
                FUN_102fc1c0();
                FUN_10330e01();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
