#include "FUN_103483af.h"
#include "FUN_103482c7.h"
#include "FUN_1034130a.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103483afL,
    Exit
};

void FUN_103483af() {
    State currentState = State::BB_0x103483afL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103483afL:
                FUN_1034130a();
                FUN_103482c7();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
