#include "FUN_102b3460.h"
#include "FUN_102b1e00.h"
#include "FUN_102b8aa0.h"
#include "FUN_102ea260.h"
#include "FUN_102b1da0.h"
#include "FUN_10292e90.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b3460L,
    Exit
};

void FUN_102b3460() {
    State currentState = State::BB_0x102b3460L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102b3460L:
                FUN_102b1e00();
                FUN_102b8aa0();
                FUN_102ea260();
                FUN_102b1da0();
                FUN_10292e90();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
