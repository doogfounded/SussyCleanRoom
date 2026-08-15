#include "FUN_102e19d0.h"
#include "FUN_10330e01.h"
#include "FUN_103283b0.h"
#include "FUN_10336c14.h"
#include "FUN_10336ce7.h"
#include "FUN_10330dd0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102e19d0L,
    BB_0x102e19e5L,
    BB_0x102e19f3L,
    BB_0x102e19f6L,
    BB_0x102e1a05L,
    BB_0x102e1a23L,
    BB_0x102e1a8aL,
    BB_0x102e1a93L,
    BB_0x102e1aadL,
    Exit
};

void FUN_102e19d0() {
    State currentState = State::BB_0x102e19d0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102e19d0L:
                currentState = State::BB_0x102e19e5L;
                break;

            case State::BB_0x102e19e5L:
                FUN_10330e01();
                currentState = State::BB_0x102e19f3L;
                break;

            case State::BB_0x102e19f3L:
                currentState = State::BB_0x102e19f6L;
                break;

            case State::BB_0x102e19f6L:
                currentState = State::BB_0x102e1a23L;
                break;

            case State::BB_0x102e1a05L:
                currentState = State::BB_0x102e1a23L;
                break;

            case State::BB_0x102e1a23L:
                FUN_103283b0();
                currentState = State::Exit;
                break;

            case State::BB_0x102e1a8aL:
                currentState = State::BB_0x102e1a93L;
                break;

            case State::BB_0x102e1a93L:
                FUN_10336c14();
                currentState = State::BB_0x102e1aadL;
                break;

            case State::BB_0x102e1aadL:
                FUN_10336ce7();
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
