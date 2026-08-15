#include "FUN_10330bf0.h"
#include "FUN_10330cb8.h"
#include "FUN_10330d13.h"
#include "FUN_10330c87.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330bf0L,
    BB_0x10330c1dL,
    BB_0x10330c26L,
    BB_0x10330c2fL,
    BB_0x10330c6cL,
    BB_0x10330c79L,
    Exit
};

void FUN_10330bf0() {
    State currentState = State::BB_0x10330bf0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330bf0L:
                currentState = State::BB_0x10330c1dL;
                break;

            case State::BB_0x10330c1dL:
                FUN_10330cb8();
                currentState = State::BB_0x10330c26L;
                break;

            case State::BB_0x10330c26L:
                FUN_10330d13();
                currentState = State::BB_0x10330c2fL;
                break;

            case State::BB_0x10330c2fL:
                currentState = State::BB_0x10330c79L;
                break;

            case State::BB_0x10330c6cL:
                currentState = State::Exit;
                break;

            case State::BB_0x10330c79L:
                FUN_10330c87();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
