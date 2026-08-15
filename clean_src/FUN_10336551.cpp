#include "FUN_10336551.h"
#include "FUN_103316a0.h"
#include "FUN_10336a03.h"
#include "FUN_10331700.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10336551L,
    BB_0x10336587L,
    BB_0x103365aaL,
    BB_0x103365aeL,
    BB_0x103365e8L,
    Exit
};

void FUN_10336551() {
    State currentState = State::BB_0x10336551L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10336551L:
                FUN_103316a0();
                currentState = State::BB_0x103365aaL;
                break;

            case State::BB_0x103365aaL:
                currentState = State::BB_0x10336587L;
                break;

            case State::BB_0x10336587L:
                FUN_10336a03();
                currentState = State::BB_0x103365e8L;
                break;

            case State::BB_0x103365aeL:
                currentState = State::BB_0x103365e8L;
                break;

            case State::BB_0x103365e8L:
                FUN_10331700();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
