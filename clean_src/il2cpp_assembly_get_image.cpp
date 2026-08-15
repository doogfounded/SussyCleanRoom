#include "il2cpp_assembly_get_image.h"
#include "jinfo_get_method.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102b3ac0L,
    Exit
};

void il2cpp_assembly_get_image() {
    State currentState = State::BB_0x102b3ac0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x102b3ac0L:
                jinfo_get_method();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
