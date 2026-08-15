#include "FUN_102d1250.h"
#include "FUN_1031e400.h"
#include "FUN_1031e390.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_102b9010.h"
#include "FUN_102d3010.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d1250L,
    BB_0x102d12aeL,
    BB_0x102d131cL,
    BB_0x102d1380L,
    BB_0x102d1385L,
    BB_0x102d13adL,
    BB_0x102d13b1L,
    BB_0x102d13d6L,
    BB_0x102d13feL,
    BB_0x102d1413L,
    BB_0x102d1421L,
    BB_0x102d1425L,
    BB_0x102d1438L,
    BB_0x102d143dL,
    BB_0x102d1468L,
    Exit
};

void FUN_102d1250() {
    State currentState = State::BB_0x102d1250L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102d1250L:
                currentState = State::BB_0x102d12aeL;
                break;

            case State::BB_0x102d12aeL:
                FUN_10298830();
                FUN_103283b0();
                currentState = State::BB_0x102d131cL;
                break;

            case State::BB_0x102d131cL:
                FUN_103283b0();
                FUN_103283b0();
                currentState = State::BB_0x102d1380L;
                break;

            case State::BB_0x102d1380L:
                currentState = State::BB_0x102d1385L;
                break;

            case State::BB_0x102d1385L:
                FUN_103283b0();
                currentState = State::BB_0x102d13b1L;
                break;

            case State::BB_0x102d13adL:
                currentState = State::BB_0x102d1380L;
                break;

            case State::BB_0x102d13b1L:
                FUN_102b9010();
                FUN_102d3010();
                currentState = State::BB_0x102d13d6L;
                break;

            case State::BB_0x102d13d6L:
                FUN_102d3010();
                currentState = State::BB_0x102d1468L;
                break;

            case State::BB_0x102d13feL:
                FUN_1031e400();
                currentState = State::BB_0x102d1413L;
                break;

            case State::BB_0x102d1413L:
                currentState = State::BB_0x102d1421L;
                break;

            case State::BB_0x102d1421L:
                currentState = State::BB_0x102d143dL;
                break;

            case State::BB_0x102d1425L:
                FUN_1031e390();
                currentState = State::BB_0x102d1438L;
                break;

            case State::BB_0x102d1438L:
                currentState = State::BB_0x102d1413L;
                break;

            case State::BB_0x102d143dL:
                FUN_102d3010();
                currentState = State::BB_0x102d13d6L;
                break;

            case State::BB_0x102d1468L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
