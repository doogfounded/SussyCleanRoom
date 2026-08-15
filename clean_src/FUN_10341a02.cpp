#include "FUN_10341a02.h"
#include "FUN_1034197d.h"
#include "guard_check_icall.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10341a02L,
    BB_0x10341a27L,
    BB_0x10341a38L,
    BB_0x10341a3dL,
    Exit
};

void FUN_10341a02() {
    State currentState = State::BB_0x10341a02L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10341a02L:
                FUN_1034197d();
                currentState = State::BB_0x10341a27L;
                break;

            case State::BB_0x10341a27L:
                guard_check_icall();
                currentState = State::BB_0x10341a3dL;
                break;

            case State::BB_0x10341a38L:
                currentState = State::BB_0x10341a3dL;
                break;

            case State::BB_0x10341a3dL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
