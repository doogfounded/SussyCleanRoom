#include "FUN_10316470.h"
#include "FUN_10330e01.h"
#include "FUN_10316030.h"
#include "FUN_103283b0.h"
#include "FUN_10336ce7.h"
#include "FUN_10330dd0.h"
#include "FUN_10336c14.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10316470L,
    BB_0x10316490L,
    BB_0x10316495L,
    BB_0x103164c1L,
    BB_0x103164ceL,
    BB_0x103164dcL,
    BB_0x103164dfL,
    BB_0x103164f1L,
    BB_0x103164f3L,
    BB_0x10316511L,
    BB_0x10316514L,
    BB_0x10316591L,
    BB_0x103165c0L,
    BB_0x103165d4L,
    BB_0x103165e0L,
    BB_0x103165e4L,
    BB_0x103165ecL,
    BB_0x103165efL,
    BB_0x103165f6L,
    BB_0x103165ffL,
    BB_0x10316618L,
    BB_0x1031661dL,
    BB_0x10316655L,
    BB_0x10316661L,
    Exit
};

void FUN_10316470() {
    State currentState = State::BB_0x10316470L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10316470L:
                currentState = State::BB_0x10316490L;
                break;

            case State::BB_0x10316490L:
                currentState = State::BB_0x10316495L;
                break;

            case State::BB_0x10316495L:
                FUN_103283b0();
                currentState = State::BB_0x103164c1L;
                break;

            case State::BB_0x103164c1L:
                currentState = State::BB_0x103164ceL;
                break;

            case State::BB_0x103164ceL:
                FUN_10330e01();
                currentState = State::BB_0x103164dcL;
                break;

            case State::BB_0x103164dcL:
                currentState = State::BB_0x103164dfL;
                break;

            case State::BB_0x103164dfL:
                currentState = State::BB_0x103164f1L;
                break;

            case State::BB_0x103164f1L:
                currentState = State::BB_0x103164f3L;
                break;

            case State::BB_0x103164f3L:
                currentState = State::BB_0x10316511L;
                break;

            case State::BB_0x10316511L:
                currentState = State::BB_0x10316514L;
                break;

            case State::BB_0x10316514L:
                FUN_103283b0();
                FUN_10316030();
                currentState = State::BB_0x10316591L;
                break;

            case State::BB_0x10316591L:
                FUN_10316030();
                currentState = State::BB_0x103165c0L;
                break;

            case State::BB_0x103165c0L:
                currentState = State::BB_0x103165d4L;
                break;

            case State::BB_0x103165d4L:
                currentState = State::BB_0x103165e0L;
                break;

            case State::BB_0x103165e0L:
                currentState = State::BB_0x103165e4L;
                break;

            case State::BB_0x103165e4L:
                currentState = State::BB_0x103165ecL;
                break;

            case State::BB_0x103165ecL:
                currentState = State::BB_0x103165efL;
                break;

            case State::BB_0x103165efL:
                currentState = State::BB_0x103165d4L;
                break;

            case State::BB_0x103165f6L:
                currentState = State::BB_0x103164dfL;
                break;

            case State::BB_0x103165ffL:
                FUN_10336c14();
                currentState = State::BB_0x10316618L;
                break;

            case State::BB_0x10316618L:
                currentState = State::BB_0x103164dcL;
                break;

            case State::BB_0x1031661dL:
                FUN_10316030();
                currentState = State::BB_0x10316591L;
                break;

            case State::BB_0x10316655L:
                currentState = State::Exit;
                break;

            case State::BB_0x10316661L:
                FUN_10336ce7();
                FUN_10330dd0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
