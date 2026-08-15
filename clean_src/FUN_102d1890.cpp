#include "FUN_102d1890.h"
#include "FUN_102ea150.h"
#include "FUN_102b1da0.h"
#include "FUN_102d3080.h"
#include "FUN_102d3190.h"
#include "FUN_10292e90.h"
#include "FUN_102d3010.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d1890L,
    BB_0x102d18deL,
    BB_0x102d18eeL,
    BB_0x102d18fdL,
    BB_0x102d190fL,
    BB_0x102d1915L,
    BB_0x102d1936L,
    BB_0x102d1967L,
    BB_0x102d1981L,
    BB_0x102d198aL,
    BB_0x102d19afL,
    BB_0x102d19bbL,
    BB_0x102d19f4L,
    BB_0x102d19fdL,
    BB_0x102d1a02L,
    BB_0x102d1a37L,
    BB_0x102d1a3dL,
    Exit
};

void FUN_102d1890() {
    State currentState = State::BB_0x102d1890L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102d1890L:
                currentState = State::BB_0x102d18deL;
                break;

            case State::BB_0x102d18deL:
                currentState = State::BB_0x102d18fdL;
                break;

            case State::BB_0x102d18eeL:
                currentState = State::BB_0x102d18fdL;
                break;

            case State::BB_0x102d18fdL:
                currentState = State::BB_0x102d1915L;
                break;

            case State::BB_0x102d190fL:
                currentState = State::BB_0x102d1915L;
                break;

            case State::BB_0x102d1915L:
                currentState = State::BB_0x102d1936L;
                break;

            case State::BB_0x102d1936L:
                FUN_102d3010();
                currentState = State::BB_0x102d198aL;
                break;

            case State::BB_0x102d1967L:
                FUN_102d3080();
                currentState = State::BB_0x102d1936L;
                break;

            case State::BB_0x102d1981L:
                currentState = State::BB_0x102d198aL;
                break;

            case State::BB_0x102d198aL:
                FUN_102d3010();
                currentState = State::BB_0x102d19bbL;
                break;

            case State::BB_0x102d19afL:
                currentState = State::BB_0x102d19f4L;
                break;

            case State::BB_0x102d19bbL:
                FUN_102ea150();
                FUN_102d3190();
                FUN_102b1da0();
                currentState = State::BB_0x102d19f4L;
                break;

            case State::BB_0x102d19f4L:
                currentState = State::BB_0x102d19fdL;
                break;

            case State::BB_0x102d19fdL:
                currentState = State::BB_0x102d1a37L;
                break;

            case State::BB_0x102d1a02L:
                FUN_10292e90();
                currentState = State::BB_0x102d1a37L;
                break;

            case State::BB_0x102d1a37L:
                currentState = State::BB_0x102d1a3dL;
                break;

            case State::BB_0x102d1a3dL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
