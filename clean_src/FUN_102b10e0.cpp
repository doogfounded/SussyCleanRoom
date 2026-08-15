#include "FUN_102b10e0.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_102b9430.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b10e0L,
    BB_0x102b1141L,
    BB_0x102b11adL,
    Exit
};

void FUN_102b10e0() {
    State currentState = State::BB_0x102b10e0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102b10e0L:
                currentState = State::BB_0x102b1141L;
                break;

            case State::BB_0x102b1141L:
                FUN_10298830();
                FUN_103283b0();
                currentState = State::BB_0x102b11adL;
                break;

            case State::BB_0x102b11adL:
                FUN_103283b0();
                FUN_102b9430();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
