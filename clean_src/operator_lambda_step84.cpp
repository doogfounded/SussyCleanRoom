#include "operator_lambda_step84.h"
#include "FUN_1033f53a.h"
#include "FUN_1033f565.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1033f4ebL,
    Exit
};

void operator_lambda_step84() {
    State currentState = State::BB_0x1033f4ebL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1033f4ebL:
                FUN_1033f53a();
                FUN_1033f565();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
