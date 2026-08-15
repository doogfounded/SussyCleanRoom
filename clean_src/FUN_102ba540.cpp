#include "FUN_102ba540.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_10330de6.h"
#include "FUN_102b0b30.h"
#include "FUN_102baf10.h"
#include "FUN_10330dd0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102ba540L,
    BB_0x102ba567L,
    BB_0x102ba579L,
    BB_0x102ba589L,
    BB_0x102ba58fL,
    BB_0x102ba598L,
    BB_0x102ba5acL,
    BB_0x102ba5c1L,
    BB_0x102ba5f4L,
    BB_0x102ba5fcL,
    BB_0x102ba62dL,
    BB_0x102ba62fL,
    BB_0x102ba652L,
    BB_0x102ba65bL,
    BB_0x102ba670L,
    Exit
};

void FUN_102ba540() {
    State currentState = State::BB_0x102ba540L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102ba540L:
                currentState = State::BB_0x102ba567L;
                break;

            case State::BB_0x102ba567L:
                currentState = State::BB_0x102ba579L;
                break;

            case State::BB_0x102ba579L:
                currentState = State::BB_0x102ba589L;
                break;

            case State::BB_0x102ba589L:
                currentState = State::BB_0x102ba598L;
                break;

            case State::BB_0x102ba58fL:
                currentState = State::BB_0x102ba5acL;
                break;

            case State::BB_0x102ba598L:
                FUN_10298830();
                currentState = State::BB_0x102ba5c1L;
                break;

            case State::BB_0x102ba5acL:
                currentState = State::Exit;
                break;

            case State::BB_0x102ba5c1L:
                FUN_10298830();
                FUN_10298830();
                currentState = State::BB_0x102ba5f4L;
                break;

            case State::BB_0x102ba5f4L:
                currentState = State::BB_0x102ba5fcL;
                break;

            case State::BB_0x102ba5fcL:
                FUN_103283b0();
                currentState = State::BB_0x102ba62fL;
                break;

            case State::BB_0x102ba62dL:
                currentState = State::BB_0x102ba62fL;
                break;

            case State::BB_0x102ba62fL:
                FUN_102b0b30();
                FUN_102baf10();
                currentState = State::BB_0x102ba652L;
                break;

            case State::BB_0x102ba652L:
                FUN_10330de6();
                currentState = State::BB_0x102ba65bL;
                break;

            case State::BB_0x102ba65bL:
                currentState = State::Exit;
                break;

            case State::BB_0x102ba670L:
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
