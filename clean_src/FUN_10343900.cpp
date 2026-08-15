#include "FUN_10343900.h"
#include "FUN_10343870.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10343900L,
    BB_0x10343913L,
    BB_0x1034391bL,
    BB_0x1034391fL,
    BB_0x10343921L,
    BB_0x1034394aL,
    BB_0x1034394eL,
    BB_0x10343951L,
    Exit
};

void FUN_10343900() {
    State currentState = State::BB_0x10343900L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10343900L:
                currentState = State::BB_0x10343913L;
                break;

            case State::BB_0x10343913L:
                currentState = State::BB_0x1034391bL;
                break;

            case State::BB_0x1034391bL:
                currentState = State::BB_0x10343921L;
                break;

            case State::BB_0x1034391fL:
                currentState = State::BB_0x10343921L;
                break;

            case State::BB_0x10343921L:
                FUN_10343870();
                currentState = State::BB_0x1034394aL;
                break;

            case State::BB_0x1034394aL:
                currentState = State::BB_0x1034394eL;
                break;

            case State::BB_0x1034394eL:
                currentState = State::BB_0x10343951L;
                break;

            case State::BB_0x10343951L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
