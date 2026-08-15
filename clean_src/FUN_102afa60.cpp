#include "FUN_102afa60.h"
#include "FUN_103283b0.h"
#include "FUN_102b10e0.h"
#include "FUN_102bb060.h"
#include "FUN_10330de6.h"
#include "FUN_10330e01.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102afa60L,
    BB_0x102afadcL,
    BB_0x102afae1L,
    BB_0x102afb5cL,
    BB_0x102afb7dL,
    BB_0x102afb86L,
    BB_0x102afb8aL,
    BB_0x102afbd7L,
    BB_0x102afbefL,
    BB_0x102afc04L,
    BB_0x102afc10L,
    BB_0x102afc3cL,
    Exit
};

void FUN_102afa60() {
    State currentState = State::BB_0x102afa60L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102afa60L:
                currentState = State::BB_0x102afadcL;
                break;

            case State::BB_0x102afadcL:
                currentState = State::BB_0x102afae1L;
                break;

            case State::BB_0x102afae1L:
                FUN_103283b0();
                currentState = State::BB_0x102afb5cL;
                break;

            case State::BB_0x102afb5cL:
                FUN_102b10e0();
                FUN_102bb060();
                currentState = State::BB_0x102afb7dL;
                break;

            case State::BB_0x102afb7dL:
                FUN_10330de6();
                currentState = State::BB_0x102afb86L;
                break;

            case State::BB_0x102afb86L:
                currentState = State::BB_0x102afb8aL;
                break;

            case State::BB_0x102afb8aL:
                FUN_10330e01();
                currentState = State::BB_0x102afbefL;
                break;

            case State::BB_0x102afbd7L:
                currentState = State::BB_0x102afbefL;
                break;

            case State::BB_0x102afbefL:
                currentState = State::Exit;
                break;

            case State::BB_0x102afc04L:
                currentState = State::BB_0x102afc10L;
                break;

            case State::BB_0x102afc10L:
                FUN_103283b0();
                currentState = State::BB_0x102afae1L;
                break;

            case State::BB_0x102afc3cL:
                currentState = State::BB_0x102afc10L;
                break;
        }
    }
}

} // namespace DoogEngine1
