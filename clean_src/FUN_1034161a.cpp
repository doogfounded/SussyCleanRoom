#include "FUN_1034161a.h"
#include "FUN_10341607.h"
#include "FUN_10341a02.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034161aL,
    BB_0x1034162dL,
    BB_0x10341636L,
    Exit
};

void FUN_1034161a() {
    State currentState = State::BB_0x1034161aL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034161aL:
                FUN_10341607();
                currentState = State::BB_0x1034162dL;
                break;

            case State::BB_0x1034162dL:
                FUN_10341a02();
                currentState = State::BB_0x10341636L;
                break;

            case State::BB_0x10341636L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
