#include "FUN_10330cfa.h"
#include "FUN_1034161a.h"
#include "FUN_103415f5.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10330cfaL,
    BB_0x10330d04L,
    BB_0x10330d10L,
    Exit
};

void FUN_10330cfa() {
    State currentState = State::BB_0x10330cfaL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10330cfaL:
                FUN_1034161a();
                currentState = State::BB_0x10330d04L;
                break;

            case State::BB_0x10330d04L:
                FUN_103415f5();
                currentState = State::BB_0x10330d10L;
                break;

            case State::BB_0x10330d10L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
