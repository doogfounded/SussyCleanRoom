#include "FUN_102b8aa0.h"
#include "FUN_102a23a0.h"
#include "FUN_102b9f00.h"
#include "FUN_102a2270.h"
#include "FUN_102b8d50.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b8aa0L,
    Exit
};

void FUN_102b8aa0() {
    State currentState = State::BB_0x102b8aa0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102b8aa0L:
                FUN_102a23a0();
                FUN_102b9f00();
                FUN_102a2270();
                FUN_102b8d50();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
