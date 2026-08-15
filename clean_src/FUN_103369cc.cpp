#include "FUN_103369cc.h"
#include "FUN_103316a0.h"
#include "FUN_10336a03.h"
#include "FUN_10331700.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103369ccL,
    Exit
};

void FUN_103369cc() {
    State currentState = State::BB_0x103369ccL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103369ccL:
                FUN_103316a0();
                FUN_10336a03();
                FUN_10331700();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
