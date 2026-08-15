#include "FUN_102b0fa0.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_102b9200.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b0fa0L,
    BB_0x102b1001L,
    BB_0x102b106dL,
    Exit
};

void FUN_102b0fa0() {
    State currentState = State::BB_0x102b0fa0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102b0fa0L:
                currentState = State::BB_0x102b1001L;
                break;

            case State::BB_0x102b1001L:
                FUN_10298830();
                FUN_103283b0();
                currentState = State::BB_0x102b106dL;
                break;

            case State::BB_0x102b106dL:
                FUN_103283b0();
                FUN_102b9200();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
