#include "FUN_102b00c0.h"
#include "FUN_102b1360.h"
#include "FUN_103283b0.h"
#include "FUN_10330de6.h"
#include "FUN_10330e01.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b00c0L,
    BB_0x102b013aL,
    BB_0x102b013fL,
    BB_0x102b01beL,
    BB_0x102b026bL,
    BB_0x102b0274L,
    BB_0x102b0278L,
    BB_0x102b02c5L,
    BB_0x102b02ddL,
    BB_0x102b02f1L,
    BB_0x102b02f6L,
    BB_0x102b0323L,
    Exit
};

void FUN_102b00c0() {
    State currentState = State::BB_0x102b00c0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b00c0L:
                currentState = State::BB_0x102b013aL;
                break;

            case State::BB_0x102b013aL:
                currentState = State::BB_0x102b013fL;
                break;

            case State::BB_0x102b013fL:
                FUN_103283b0();
                currentState = State::BB_0x102b01beL;
                break;

            case State::BB_0x102b01beL:
                FUN_102b1360();
                currentState = State::BB_0x102b026bL;
                break;

            case State::BB_0x102b026bL:
                FUN_10330de6();
                currentState = State::BB_0x102b0274L;
                break;

            case State::BB_0x102b0274L:
                currentState = State::BB_0x102b0278L;
                break;

            case State::BB_0x102b0278L:
                FUN_10330e01();
                currentState = State::BB_0x102b02ddL;
                break;

            case State::BB_0x102b02c5L:
                currentState = State::BB_0x102b02ddL;
                break;

            case State::BB_0x102b02ddL:
                currentState = State::Exit;
                break;

            case State::BB_0x102b02f1L:
                currentState = State::BB_0x102b02f6L;
                break;

            case State::BB_0x102b02f6L:
                FUN_103283b0();
                currentState = State::BB_0x102b013fL;
                break;

            case State::BB_0x102b0323L:
                currentState = State::BB_0x102b02f6L;
                break;
        }
    }
}

} // namespace DoogEngine1
