#include "FUN_102de900.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_102e1d80.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102de900L,
    BB_0x102de96dL,
    BB_0x102de9dbL,
    Exit
};

void FUN_102de900() {
    State currentState = State::BB_0x102de900L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102de900L:
                currentState = State::BB_0x102de96dL;
                break;

            case State::BB_0x102de96dL:
                FUN_10298830();
                FUN_103283b0();
                currentState = State::BB_0x102de9dbL;
                break;

            case State::BB_0x102de9dbL:
                FUN_103283b0();
                FUN_102e1d80();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
