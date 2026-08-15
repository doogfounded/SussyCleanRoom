#include "FUN_1034130a.h"
#include "FUN_1034169e.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034130aL,
    BB_0x10341320L,
    BB_0x1034132aL,
    BB_0x10341335L,
    BB_0x1034133aL,
    BB_0x10341346L,
    BB_0x1034134aL,
    BB_0x1034135fL,
    BB_0x10341370L,
    BB_0x10341380L,
    BB_0x1034138fL,
    BB_0x10341397L,
    BB_0x103413aeL,
    BB_0x103413afL,
    BB_0x103413baL,
    BB_0x103413bfL,
    Exit
};

void FUN_1034130a() {
    State currentState = State::BB_0x1034130aL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034130aL:
                currentState = State::BB_0x10341320L;
                break;

            case State::BB_0x10341320L:
                currentState = State::BB_0x10341335L;
                break;

            case State::BB_0x1034132aL:
                currentState = State::BB_0x103413afL;
                break;

            case State::BB_0x10341335L:
                currentState = State::BB_0x1034133aL;
                break;

            case State::BB_0x1034133aL:
                currentState = State::BB_0x1034134aL;
                break;

            case State::BB_0x10341346L:
                currentState = State::BB_0x103413afL;
                break;

            case State::BB_0x1034134aL:
                currentState = State::BB_0x1034135fL;
                break;

            case State::BB_0x1034135fL:
                currentState = State::BB_0x1034138fL;
                break;

            case State::BB_0x10341370L:
                currentState = State::BB_0x10341380L;
                break;

            case State::BB_0x10341380L:
                currentState = State::BB_0x1034138fL;
                break;

            case State::BB_0x1034138fL:
                FUN_1034169e();
                currentState = State::BB_0x103413aeL;
                break;

            case State::BB_0x10341397L:
                FUN_1034169e();
                currentState = State::BB_0x103413aeL;
                break;

            case State::BB_0x103413aeL:
                currentState = State::BB_0x103413afL;
                break;

            case State::BB_0x103413afL:
                currentState = State::BB_0x103413baL;
                break;

            case State::BB_0x103413baL:
                currentState = State::Exit;
                break;

            case State::BB_0x103413bfL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
