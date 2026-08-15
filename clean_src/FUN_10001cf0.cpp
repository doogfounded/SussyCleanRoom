#include "FUN_10001cf0.h"
#include "FUN_102a0d30.h"
#include "FUN_102de0c0.h"
#include "FUN_10328f05.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10001cf0L,
    Exit
};

void FUN_10001cf0() {
    State currentState = State::BB_0x10001cf0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10001cf0L:
                FUN_102a0d30();
                FUN_102de0c0();
                FUN_10328f05();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
