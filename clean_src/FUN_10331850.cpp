#include "FUN_10331850.h"
#include "FUN_10342017.h"
#include "FUN_10342075.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10331850L,
    BB_0x10331897L,
    BB_0x103318a4L,
    Exit
};

void FUN_10331850() {
    State currentState = State::BB_0x10331850L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10331850L:
                FUN_10342017();
                FUN_10342075();
                currentState = State::BB_0x10331897L;
                break;

            case State::BB_0x10331897L:
                currentState = State::BB_0x103318a4L;
                break;

            case State::BB_0x103318a4L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
