#include "FUN_10338344.h"
#include "FUN_1033cd98.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10338344L,
    BB_0x1033835dL,
    BB_0x10338362L,
    BB_0x10338373L,
    BB_0x1033838bL,
    BB_0x10338396L,
    BB_0x103383a0L,
    BB_0x103383a6L,
    BB_0x103383a8L,
    Exit
};

void FUN_10338344() {
    State currentState = State::BB_0x10338344L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10338344L:
                currentState = State::BB_0x1033835dL;
                break;

            case State::BB_0x1033835dL:
                currentState = State::BB_0x10338362L;
                break;

            case State::BB_0x10338362L:
                currentState = State::BB_0x10338373L;
                break;

            case State::BB_0x10338373L:
                FUN_1033cd98();
                currentState = State::BB_0x10338396L;
                break;

            case State::BB_0x1033838bL:
                currentState = State::BB_0x103383a8L;
                break;

            case State::BB_0x10338396L:
                currentState = State::BB_0x103383a0L;
                break;

            case State::BB_0x103383a0L:
                currentState = State::BB_0x103383a6L;
                break;

            case State::BB_0x103383a6L:
                currentState = State::BB_0x103383a8L;
                break;

            case State::BB_0x103383a8L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
