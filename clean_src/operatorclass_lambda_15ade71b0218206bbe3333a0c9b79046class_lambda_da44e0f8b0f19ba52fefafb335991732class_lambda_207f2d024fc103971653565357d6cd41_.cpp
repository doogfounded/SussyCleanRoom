#include "operatorclass_lambda_15ade71b0218206bbe3333a0c9b79046class_lambda_da44e0f8b0f19ba52fefafb335991732class_lambda_207f2d024fc103971653565357d6cd41_.h"
#include "FUN_10340fe6.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10340fa0L,
    BB_0x103298f0L,
    BB_0x1033da86L,
    BB_0x10340fe6L,
    Exit
};

void operatorclass_lambda_15ade71b0218206bbe3333a0c9b79046class_lambda_da44e0f8b0f19ba52fefafb335991732class_lambda_207f2d024fc103971653565357d6cd41_() {
    State currentState = State::BB_0x10340fa0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10340fa0L:
                // Transition: BB_0x10340fa0L -> BB_0x10340fe6L
                currentState = State::BB_0x10340fe6L;
                break;

            case State::BB_0x103298f0L:
                // Transition: BB_0x10340fa0L -> BB_0x103298f0L
                currentState = State::Exit;
                break;

            case State::BB_0x1033da86L:
                // Transition: BB_0x10340fa0L -> BB_0x1033da86L
                currentState = State::Exit;
                break;

            case State::BB_0x10340fe6L:
                // Transition: BB_0x10340fa0L -> BB_0x10340fe6L
                FUN_10340fe6();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
