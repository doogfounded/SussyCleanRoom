#include "FUN_1030f540.h"
#include "___std_exception_copy.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1030f540L,
    Exit
};

void FUN_1030f540() {
    State currentState = State::BB_0x1030f540L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1030f540L:
                ___std_exception_copy();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
