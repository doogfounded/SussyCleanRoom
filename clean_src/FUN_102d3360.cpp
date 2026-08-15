#include "FUN_102d3360.h"
#include "FUN_102d3270.h"
#include "FUN_10330de6.h"
#include "FUN_102baf10.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_10330dd0.h"
#include "FUN_102d1250.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d3360L,
    BB_0x102d3387L,
    BB_0x102d3399L,
    BB_0x102d33a9L,
    BB_0x102d33afL,
    BB_0x102d33b8L,
    BB_0x102d33ccL,
    BB_0x102d33e1L,
    BB_0x102d3414L,
    BB_0x102d341cL,
    BB_0x102d344dL,
    BB_0x102d344fL,
    BB_0x102d3472L,
    BB_0x102d347bL,
    BB_0x102d3490L,
    Exit
};

void FUN_102d3360() {
    State currentState = State::BB_0x102d3360L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102d3360L:
                currentState = State::BB_0x102d3387L;
                break;

            case State::BB_0x102d3387L:
                FUN_102d3270();
                currentState = State::BB_0x102d3399L;
                break;

            case State::BB_0x102d3399L:
                currentState = State::BB_0x102d33a9L;
                break;

            case State::BB_0x102d33a9L:
                currentState = State::BB_0x102d33afL;
                break;

            case State::BB_0x102d33afL:
                currentState = State::BB_0x102d33b8L;
                break;

            case State::BB_0x102d33b8L:
                FUN_10298830();
                currentState = State::BB_0x102d33e1L;
                break;

            case State::BB_0x102d33ccL:
                currentState = State::BB_0x102d33e1L;
                break;

            case State::BB_0x102d33e1L:
                FUN_10298830();
                FUN_10298830();
                currentState = State::BB_0x102d3414L;
                break;

            case State::BB_0x102d3414L:
                currentState = State::BB_0x102d341cL;
                break;

            case State::BB_0x102d341cL:
                FUN_103283b0();
                currentState = State::BB_0x102d344dL;
                break;

            case State::BB_0x102d344dL:
                currentState = State::BB_0x102d344fL;
                break;

            case State::BB_0x102d344fL:
                FUN_102d1250();
                FUN_102baf10();
                currentState = State::BB_0x102d3472L;
                break;

            case State::BB_0x102d3472L:
                FUN_10330de6();
                currentState = State::BB_0x102d347bL;
                break;

            case State::BB_0x102d347bL:
                currentState = State::Exit;
                break;

            case State::BB_0x102d3490L:
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
