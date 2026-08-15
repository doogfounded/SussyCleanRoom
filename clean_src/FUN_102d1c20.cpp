#include "FUN_102d1c20.h"
#include "FUN_102d1f30.h"
#include "FUN_102b3460.h"
#include "__alloca_probe_16.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102d1c20L,
    Exit
};

void FUN_102d1c20() {
    State currentState = State::BB_0x102d1c20L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102d1c20L:
                FUN_102d1f30();
                FUN_102b3460();
                __alloca_probe_16();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
