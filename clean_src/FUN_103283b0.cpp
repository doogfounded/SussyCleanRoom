#include "FUN_103283b0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103283b0L,
    BB_0x103283b9L,
    BB_0x103283cfL,
    BB_0x103283ddL,
    BB_0x103283e3L,
    BB_0x103283eaL,
    BB_0x10328403L,
    BB_0x10328405L,
    BB_0x10328409L,
    BB_0x10328411L,
    Exit
};

void FUN_103283b0() {
    State currentState = State::BB_0x103283b0L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103283b0L:
                currentState = State::BB_0x103283cfL;
                break;

            case State::BB_0x103283b9L:
                currentState = State::BB_0x103283cfL;
                break;

            case State::BB_0x103283cfL:
                currentState = State::BB_0x103283e3L;
                break;

            case State::BB_0x103283ddL:
                currentState = State::BB_0x103283e3L;
                break;

            case State::BB_0x103283e3L:
                currentState = State::BB_0x10328403L;
                break;

            case State::BB_0x103283eaL:
                currentState = State::BB_0x10328403L;
                break;

            case State::BB_0x10328403L:
                currentState = State::BB_0x10328409L;
                break;

            case State::BB_0x10328405L:
                currentState = State::BB_0x10328409L;
                break;

            case State::BB_0x10328409L:
                currentState = State::BB_0x10328411L;
                break;

            case State::BB_0x10328411L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
