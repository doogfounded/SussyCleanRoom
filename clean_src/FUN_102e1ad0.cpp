#include "FUN_102e1ad0.h"
#include "FUN_103283b0.h"
#include "FUN_102b9100.h"
#include "FUN_102e1820.h"
#include "FUN_1031e560.h"
#include "FUN_102dfa30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102e1ad0L,
    BB_0x102e1af2L,
    BB_0x102e1af6L,
    BB_0x102e1b23L,
    BB_0x102e1b50L,
    BB_0x102e1b85L,
    BB_0x102e1ba8L,
    BB_0x102e1bb3L,
    BB_0x102e1bb7L,
    BB_0x102e1bddL,
    BB_0x102e1c15L,
    Exit
};

void FUN_102e1ad0() {
    State currentState = State::BB_0x102e1ad0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102e1ad0L:
                currentState = State::BB_0x102e1af2L;
                break;

            case State::BB_0x102e1af2L:
                currentState = State::BB_0x102e1af6L;
                break;

            case State::BB_0x102e1af6L:
                FUN_103283b0();
                currentState = State::BB_0x102e1b23L;
                break;

            case State::BB_0x102e1b23L:
                FUN_102b9100();
                FUN_102e1820();
                currentState = State::BB_0x102e1b50L;
                break;

            case State::BB_0x102e1b50L:
                FUN_102e1820();
                currentState = State::BB_0x102e1b85L;
                break;

            case State::BB_0x102e1b85L:
                FUN_1031e560();
                currentState = State::BB_0x102e1ba8L;
                break;

            case State::BB_0x102e1ba8L:
                currentState = State::BB_0x102e1bb3L;
                break;

            case State::BB_0x102e1bb3L:
                currentState = State::BB_0x102e1bb7L;
                break;

            case State::BB_0x102e1bb7L:
                FUN_102dfa30();
                currentState = State::BB_0x102e1bddL;
                break;

            case State::BB_0x102e1bddL:
                FUN_102e1820();
                currentState = State::BB_0x102e1c15L;
                break;

            case State::BB_0x102e1c15L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
