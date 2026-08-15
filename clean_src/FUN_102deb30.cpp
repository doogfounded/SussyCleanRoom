#include "FUN_102deb30.h"
#include "FUN_102dfa30.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102deb30L,
    Exit
};

void FUN_102deb30() {
    State currentState = State::BB_0x102deb30L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102deb30L:
                FUN_102dfa30();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
