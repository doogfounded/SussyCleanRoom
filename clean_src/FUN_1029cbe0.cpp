#include "FUN_1029cbe0.h"
#include "FUN_102859c0.h"
#include "FUN_1032a1f0.h"
#include "FUN_10285930.h"
#include "_memset.h"
#include "FUN_102846a0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1029cbe0L,
    Exit
};

void FUN_1029cbe0() {
    State currentState = State::BB_0x1029cbe0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1029cbe0L:
                FUN_102859c0();
                FUN_1032a1f0();
                FUN_10285930();
                _memset();
                FUN_102846a0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
