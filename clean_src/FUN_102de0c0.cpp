#include "FUN_102de0c0.h"
#include "FUN_10330e01.h"
#include "FUN_102de680.h"
#include "FUN_10330de6.h"
#include "FUN_102bb060.h"
#include "FUN_103283b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102de0c0L,
    BB_0x102de13cL,
    BB_0x102de141L,
    BB_0x102de1bcL,
    BB_0x102de1ddL,
    BB_0x102de1e6L,
    BB_0x102de1eaL,
    BB_0x102de237L,
    BB_0x102de24fL,
    BB_0x102de264L,
    BB_0x102de270L,
    BB_0x102de29cL,
    Exit
};

void FUN_102de0c0() {
    State currentState = State::BB_0x102de0c0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102de0c0L:
                currentState = State::BB_0x102de13cL;
                break;

            case State::BB_0x102de13cL:
                currentState = State::BB_0x102de141L;
                break;

            case State::BB_0x102de141L:
                FUN_103283b0();
                currentState = State::BB_0x102de1bcL;
                break;

            case State::BB_0x102de1bcL:
                FUN_102de680();
                FUN_102bb060();
                currentState = State::BB_0x102de1ddL;
                break;

            case State::BB_0x102de1ddL:
                FUN_10330de6();
                currentState = State::BB_0x102de1e6L;
                break;

            case State::BB_0x102de1e6L:
                currentState = State::BB_0x102de1eaL;
                break;

            case State::BB_0x102de1eaL:
                FUN_10330e01();
                currentState = State::BB_0x102de24fL;
                break;

            case State::BB_0x102de237L:
                currentState = State::BB_0x102de24fL;
                break;

            case State::BB_0x102de24fL:
                currentState = State::Exit;
                break;

            case State::BB_0x102de264L:
                currentState = State::BB_0x102de270L;
                break;

            case State::BB_0x102de270L:
                FUN_103283b0();
                currentState = State::BB_0x102de141L;
                break;

            case State::BB_0x102de29cL:
                currentState = State::BB_0x102de270L;
                break;
        }
    }
}

} // namespace DoogEngine1
