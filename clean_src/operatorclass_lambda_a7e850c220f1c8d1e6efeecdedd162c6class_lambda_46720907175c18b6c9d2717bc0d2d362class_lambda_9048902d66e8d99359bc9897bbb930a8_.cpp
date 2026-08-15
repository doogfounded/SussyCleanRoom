#include "operatorclass_lambda_a7e850c220f1c8d1e6efeecdedd162c6class_lambda_46720907175c18b6c9d2717bc0d2d362class_lambda_9048902d66e8d99359bc9897bbb930a8_.h"
#include "replace_current_thread_locale_nolock.h"
#include "FUN_10341100.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103410b2L,
    BB_0x103298f0L,
    BB_0x1033da86L,
    BB_0x10341293L,
    BB_0x10341100L,
    Exit
};

void operatorclass_lambda_a7e850c220f1c8d1e6efeecdedd162c6class_lambda_46720907175c18b6c9d2717bc0d2d362class_lambda_9048902d66e8d99359bc9897bbb930a8_() {
    State currentState = State::BB_0x103410b2L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103410b2L:
                // Transition: BB_0x103410b2L -> BB_0x10341293L
                currentState = State::BB_0x10341293L;
                break;

            case State::BB_0x103298f0L:
                // Transition: BB_0x103410b2L -> BB_0x103298f0L
                currentState = State::Exit;
                break;

            case State::BB_0x1033da86L:
                // Transition: BB_0x103410b2L -> BB_0x1033da86L
                currentState = State::Exit;
                break;

            case State::BB_0x10341293L:
                // Transition: BB_0x103410b2L -> BB_0x10341293L
                replace_current_thread_locale_nolock();
                currentState = State::BB_0x10341100L;
                break;

            case State::BB_0x10341100L:
                // Transition: BB_0x103410b2L -> BB_0x10341100L
                FUN_10341100();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
