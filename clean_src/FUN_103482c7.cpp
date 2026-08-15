#include "FUN_103482c7.h"
#include "FUN_10348346.h"
#include "FUN_1034169e.h"
#include "FUN_1034834f.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103482c7L,
    BB_0x103482e8L,
    BB_0x103482edL,
    BB_0x103482f0L,
    BB_0x103482f4L,
    BB_0x103482f6L,
    BB_0x1034830eL,
    BB_0x10348312L,
    BB_0x1034831bL,
    BB_0x10348323L,
    BB_0x1034832aL,
    BB_0x10348335L,
    Exit
};

void FUN_103482c7() {
    State currentState = State::BB_0x103482c7L;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103482c7L:
                currentState = State::BB_0x103482f6L;
                break;

            case State::BB_0x103482e8L:
                currentState = State::BB_0x103482edL;
                break;

            case State::BB_0x103482edL:
                currentState = State::BB_0x103482f0L;
                break;

            case State::BB_0x103482f0L:
                currentState = State::BB_0x103482f4L;
                break;

            case State::BB_0x103482f4L:
                FUN_1034834f();
                currentState = State::Exit;
                break;

            case State::BB_0x103482f6L:
                currentState = State::BB_0x1034830eL;
                break;

            case State::BB_0x1034830eL:
                currentState = State::BB_0x10348312L;
                break;

            case State::BB_0x10348312L:
                currentState = State::BB_0x1034831bL;
                break;

            case State::BB_0x1034831bL:
                currentState = State::BB_0x10348323L;
                break;

            case State::BB_0x10348323L:
                FUN_1034169e();
                currentState = State::BB_0x1034832aL;
                break;

            case State::BB_0x1034832aL:
                currentState = State::BB_0x10348335L;
                break;

            case State::BB_0x10348335L:
                FUN_10348346();
                currentState = State::BB_0x103482f0L;
                break;
        }
    }
}

} // namespace DoogEngine1
