#include "FUN_102fb450.h"
#include "FUN_102fb320.h"
#include "_memset.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102fb450L,
    BB_0x102fb471L,
    BB_0x102fb477L,
    Exit
};

void FUN_102fb450() {
    State currentState = State::BB_0x102fb450L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102fb450L:
                currentState = State::BB_0x102fb471L;
                break;

            case State::BB_0x102fb471L:
                FUN_102fb320();
                currentState = State::BB_0x102fb477L;
                break;

            case State::BB_0x102fb477L:
                _memset();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
