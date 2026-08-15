#include "FUN_1034197d.h"
#include "FUN_103418b2.h"

namespace DoogEngine1 {

enum class State {
    BB_0x1034197dL,
    BB_0x103419a9L,
    BB_0x103419adL,
    BB_0x103419b1L,
    BB_0x103419b5L,
    BB_0x103419c7L,
    BB_0x103419d7L,
    BB_0x103419e4L,
    BB_0x103419fdL,
    BB_0x103419feL,
    Exit
};

void FUN_1034197d() {
    State currentState = State::BB_0x1034197dL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x1034197dL:
                currentState = State::BB_0x103419adL;
                break;

            case State::BB_0x103419a9L:
                currentState = State::BB_0x103419feL;
                break;

            case State::BB_0x103419adL:
                currentState = State::BB_0x103419b5L;
                break;

            case State::BB_0x103419b1L:
                currentState = State::BB_0x103419feL;
                break;

            case State::BB_0x103419b5L:
                FUN_103418b2();
                currentState = State::BB_0x103419c7L;
                break;

            case State::BB_0x103419c7L:
                currentState = State::BB_0x103419e4L;
                break;

            case State::BB_0x103419d7L:
                currentState = State::BB_0x103419fdL;
                break;

            case State::BB_0x103419e4L:
                currentState = State::BB_0x103419fdL;
                break;

            case State::BB_0x103419fdL:
                currentState = State::BB_0x103419feL;
                break;

            case State::BB_0x103419feL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
