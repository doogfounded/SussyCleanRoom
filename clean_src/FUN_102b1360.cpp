#include "FUN_102b1360.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_102b9100.h"
#include "FUN_102b8e70.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b1360L,
    BB_0x102b13c4L,
    BB_0x102b1432L,
    BB_0x102b1491L,
    BB_0x102b1496L,
    BB_0x102b14beL,
    BB_0x102b14c2L,
    BB_0x102b14f0L,
    BB_0x102b1521L,
    BB_0x102b1535L,
    BB_0x102b153dL,
    BB_0x102b1541L,
    BB_0x102b1550L,
    BB_0x102b1553L,
    BB_0x102b155bL,
    BB_0x102b1590L,
    Exit
};

void FUN_102b1360() {
    State currentState = State::BB_0x102b1360L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102b1360L:
                currentState = State::BB_0x102b13c4L;
                break;

            case State::BB_0x102b13c4L:
                FUN_10298830();
                FUN_103283b0();
                currentState = State::BB_0x102b1432L;
                break;

            case State::BB_0x102b1432L:
                FUN_103283b0();
                currentState = State::BB_0x102b1491L;
                break;

            case State::BB_0x102b1491L:
                currentState = State::BB_0x102b1496L;
                break;

            case State::BB_0x102b1496L:
                FUN_103283b0();
                currentState = State::BB_0x102b14c2L;
                break;

            case State::BB_0x102b14beL:
                currentState = State::BB_0x102b1491L;
                break;

            case State::BB_0x102b14c2L:
                FUN_102b9100();
                FUN_102b8e70();
                currentState = State::BB_0x102b14f0L;
                break;

            case State::BB_0x102b14f0L:
                FUN_102b8e70();
                currentState = State::BB_0x102b1521L;
                break;

            case State::BB_0x102b1521L:
                currentState = State::BB_0x102b1535L;
                break;

            case State::BB_0x102b1535L:
                currentState = State::BB_0x102b153dL;
                break;

            case State::BB_0x102b153dL:
                currentState = State::BB_0x102b1541L;
                break;

            case State::BB_0x102b1541L:
                currentState = State::BB_0x102b1550L;
                break;

            case State::BB_0x102b1550L:
                currentState = State::BB_0x102b1553L;
                break;

            case State::BB_0x102b1553L:
                currentState = State::BB_0x102b155bL;
                break;

            case State::BB_0x102b155bL:
                FUN_102b8e70();
                currentState = State::BB_0x102b1590L;
                break;

            case State::BB_0x102b1590L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
