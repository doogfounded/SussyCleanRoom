#include "FUN_102b9100.h"
#include "FUN_10330e01.h"
#include "FUN_10336c14.h"
#include "FUN_103283b0.h"
#include "FUN_10336ce7.h"
#include "FUN_10330dd0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b9100L,
    BB_0x102b9110L,
    BB_0x102b9121L,
    BB_0x102b9126L,
    BB_0x102b9142L,
    BB_0x102b9143L,
    BB_0x102b9146L,
    BB_0x102b9155L,
    BB_0x102b916dL,
    BB_0x102b91d3L,
    Exit
};

void FUN_102b9100() {
    State currentState = State::BB_0x102b9100L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b9100L:
                currentState = State::BB_0x102b9121L;
                break;

            case State::BB_0x102b9110L:
                FUN_10330e01();
                currentState = State::BB_0x102b9143L;
                break;

            case State::BB_0x102b9121L:
                currentState = State::BB_0x102b9126L;
                break;

            case State::BB_0x102b9126L:
                FUN_10336c14();
                currentState = State::BB_0x102b9142L;
                break;

            case State::BB_0x102b9142L:
                currentState = State::BB_0x102b9143L;
                break;

            case State::BB_0x102b9143L:
                currentState = State::BB_0x102b9146L;
                break;

            case State::BB_0x102b9146L:
                currentState = State::BB_0x102b9155L;
                break;

            case State::BB_0x102b9155L:
                currentState = State::BB_0x102b916dL;
                break;

            case State::BB_0x102b916dL:
                FUN_103283b0();
                currentState = State::Exit;
                break;

            case State::BB_0x102b91d3L:
                FUN_10336ce7();
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
