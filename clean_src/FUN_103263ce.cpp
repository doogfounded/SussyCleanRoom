#include "FUN_103263ce.h"
#include "FUN_103262c3.h"
#include "FUN_10329c6b.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103263ceL,
    Exit
};

void FUN_103263ce() {
    State currentState = State::BB_0x103263ceL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103263ceL:
                FUN_103262c3();
                FUN_10329c6b();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
