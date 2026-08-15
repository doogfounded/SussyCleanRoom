#include "is_positional_parameter_reappearance_consistent.h"
#include "is_wide_character_specifier_char.h"
#include "is_integral_specifier.h"
#include "to_integer_size.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10333b00L,
    BB_0x10333b1cL,
    BB_0x10333b25L,
    BB_0x10333b2bL,
    BB_0x10333b32L,
    BB_0x10333b36L,
    BB_0x10333b3bL,
    BB_0x10333b42L,
    BB_0x10333b44L,
    BB_0x10333b48L,
    BB_0x10333b4eL,
    BB_0x10333b50L,
    BB_0x10333b55L,
    BB_0x10333b5aL,
    BB_0x10333b5cL,
    BB_0x10333b62L,
    BB_0x10333b6aL,
    BB_0x10333b6eL,
    BB_0x10333c06L,
    BB_0x10333c08L,
    Exit
};

void is_positional_parameter_reappearance_consistent() {
    State currentState = State::BB_0x10333b00L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10333b00L:
                currentState = State::BB_0x10333b1cL;
                break;

            case State::BB_0x10333b1cL:
                currentState = State::BB_0x10333b25L;
                break;

            case State::BB_0x10333b25L:
                currentState = State::BB_0x10333b32L;
                break;

            case State::BB_0x10333b2bL:
                currentState = State::BB_0x10333b36L;
                break;

            case State::BB_0x10333b32L:
                currentState = State::BB_0x10333b36L;
                break;

            case State::BB_0x10333b36L:
                currentState = State::BB_0x10333b42L;
                break;

            case State::BB_0x10333b3bL:
                currentState = State::BB_0x10333b44L;
                break;

            case State::BB_0x10333b42L:
                currentState = State::BB_0x10333b44L;
                break;

            case State::BB_0x10333b44L:
                currentState = State::BB_0x10333b4eL;
                break;

            case State::BB_0x10333b48L:
                currentState = State::BB_0x10333b4eL;
                break;

            case State::BB_0x10333b4eL:
                currentState = State::BB_0x10333b50L;
                break;

            case State::BB_0x10333b50L:
                currentState = State::BB_0x10333b5aL;
                break;

            case State::BB_0x10333b55L:
                currentState = State::BB_0x10333b5cL;
                break;

            case State::BB_0x10333b5aL:
                currentState = State::BB_0x10333b5cL;
                break;

            case State::BB_0x10333b5cL:
                currentState = State::BB_0x10333b62L;
                break;

            case State::BB_0x10333b62L:
                currentState = State::BB_0x10333b6aL;
                break;

            case State::BB_0x10333b6aL:
                currentState = State::BB_0x10333b6eL;
                break;

            case State::BB_0x10333b6eL:
                currentState = State::Exit;
                break;

            case State::BB_0x10333c06L:
                currentState = State::Exit;
                break;

            case State::BB_0x10333c08L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
