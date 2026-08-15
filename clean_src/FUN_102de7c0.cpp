#include "FUN_102de7c0.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_102e1c30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102de7c0L,
    BB_0x102de821L,
    BB_0x102de88dL,
    Exit
};

void FUN_102de7c0() {
    State currentState = State::BB_0x102de7c0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102de7c0L:
                currentState = State::BB_0x102de821L;
                break;

            case State::BB_0x102de821L:
                FUN_10298830();
                FUN_103283b0();
                currentState = State::BB_0x102de88dL;
                break;

            case State::BB_0x102de88dL:
                FUN_103283b0();
                FUN_102e1c30();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
