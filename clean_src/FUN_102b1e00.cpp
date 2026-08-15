#include "FUN_102b1e00.h"
#include "FUN_102a2260.h"
#include "FUN_102bb350.h"
#include "FUN_102ba540.h"
#include "FUN_102a2390.h"
#include "FUN_1031e430.h"
#include "FUN_10330dd0.h"
#include "FUN_102b9f00.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b1e00L,
    Exit
};

void FUN_102b1e00() {
    State currentState = State::BB_0x102b1e00L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102b1e00L:
                FUN_102a2260();
                FUN_102bb350();
                FUN_102ba540();
                FUN_102a2390();
                FUN_1031e430();
                FUN_10330dd0();
                FUN_102b9f00();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
