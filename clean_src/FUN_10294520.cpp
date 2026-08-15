#include "FUN_10294520.h"
#include "il2cpp_assembly_get_image.h"
#include "FUN_102b3ad0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10294520L,
    Exit
};

void FUN_10294520() {
    State currentState = State::BB_0x10294520L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10294520L:
                il2cpp_assembly_get_image();
                FUN_102b3ad0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
