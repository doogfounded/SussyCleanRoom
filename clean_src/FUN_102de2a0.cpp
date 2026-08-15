#include "FUN_102de2a0.h"
#include "FUN_10330e01.h"
#include "FUN_102de7c0.h"
#include "FUN_10330de6.h"
#include "FUN_102bb060.h"
#include "FUN_103283b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102de2a0L,
    BB_0x102de31cL,
    BB_0x102de321L,
    BB_0x102de39cL,
    BB_0x102de3bdL,
    BB_0x102de3c6L,
    BB_0x102de3caL,
    BB_0x102de42fL,
    BB_0x102de444L,
    BB_0x102de450L,
    BB_0x102de47cL,
    Exit
};

void FUN_102de2a0() {
    State currentState = State::BB_0x102de2a0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102de2a0L:
                currentState = State::BB_0x102de31cL;
                break;

            case State::BB_0x102de31cL:
                currentState = State::BB_0x102de321L;
                break;

            case State::BB_0x102de321L:
                FUN_103283b0();
                currentState = State::BB_0x102de39cL;
                break;

            case State::BB_0x102de39cL:
                FUN_102de7c0();
                FUN_102bb060();
                currentState = State::BB_0x102de3bdL;
                break;

            case State::BB_0x102de3bdL:
                FUN_10330de6();
                currentState = State::BB_0x102de3c6L;
                break;

            case State::BB_0x102de3c6L:
                currentState = State::BB_0x102de3caL;
                break;

            case State::BB_0x102de3caL:
                FUN_10330e01();
                currentState = State::BB_0x102de42fL;
                break;

            case State::BB_0x102de42fL:
                currentState = State::Exit;
                break;

            case State::BB_0x102de444L:
                currentState = State::BB_0x102de450L;
                break;

            case State::BB_0x102de450L:
                FUN_103283b0();
                currentState = State::BB_0x102de321L;
                break;

            case State::BB_0x102de47cL:
                currentState = State::BB_0x102de450L;
                break;
        }
    }
}

} // namespace DoogEngine1
