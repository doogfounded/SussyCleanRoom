#include "FUN_10342075.h"
#include "FUN_103483af.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10342075L,
    BB_0x1034208cL,
    BB_0x1034209cL,
    BB_0x103420a3L,
    Exit
};

void FUN_10342075() {
    State currentState = State::BB_0x10342075L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10342075L:
                currentState = State::BB_0x1034208cL;
                break;

            case State::BB_0x1034208cL:
                currentState = State::BB_0x1034209cL;
                break;

            case State::BB_0x1034209cL:
                FUN_103483af();
                currentState = State::BB_0x103420a3L;
                break;

            case State::BB_0x103420a3L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
