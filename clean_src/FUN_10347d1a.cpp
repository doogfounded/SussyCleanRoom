#include "FUN_10347d1a.h"
#include "FUN_10347d7a.h"
#include "FUN_1034130a.h"
#include "FUN_10347d83.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10347d1aL,
    BB_0x10347d40L,
    BB_0x10347d46L,
    BB_0x10347d75L,
    BB_0x10347d95L,
    Exit
};

void FUN_10347d1a() {
    State currentState = State::BB_0x10347d1aL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x10347d1aL:
                FUN_1034130a();
                currentState = State::BB_0x10347d40L;
                break;

            case State::BB_0x10347d40L:
                FUN_10347d83();
                currentState = State::BB_0x10347d46L;
                break;

            case State::BB_0x10347d46L:
                FUN_10347d7a();
                currentState = State::BB_0x10347d75L;
                break;

            case State::BB_0x10347d75L:
                FUN_10347d83();
                currentState = State::Exit;
                break;

            case State::BB_0x10347d95L:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
