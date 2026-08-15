#include "FUN_10343ccb.h"
#include "siglookup.h"
#include "FUN_1034145b.h"
#include "FUN_1034130a.h"
#include "__exit.h"

namespace DoogEngine1 {

enum class State {
    BB_0x10343ccbL,
    BB_0x10343cecL,
    BB_0x10343ceeL,
    BB_0x10343cf7L,
    BB_0x10343cfbL,
    BB_0x10343cffL,
    BB_0x10343d03L,
    BB_0x10343d11L,
    BB_0x10343d19L,
    BB_0x10343d27L,
    BB_0x10343d39L,
    BB_0x10343d43L,
    BB_0x10343d4aL,
    BB_0x10343d4fL,
    BB_0x10343d54L,
    BB_0x10343d5dL,
    BB_0x10343d68L,
    BB_0x10343d70L,
    BB_0x10343d88L,
    BB_0x10343d94L,
    BB_0x10343da4L,
    BB_0x10343dacL,
    BB_0x10343db1L,
    BB_0x10343db6L,
    BB_0x10343dbbL,
    BB_0x10343dcaL,
    BB_0x10343de4L,
    BB_0x10343de9L,
    BB_0x10343dfbL,
    BB_0x10343e02L,
    BB_0x10343e0bL,
    BB_0x10343e15L,
    BB_0x10343e25L,
    BB_0x10343e2aL,
    BB_0x10343e65L,
    BB_0x10343e71L,
    BB_0x10343e77L,
    BB_0x10343e7cL,
    BB_0x10343e81L,
    BB_0x10343e8cL,
    BB_0x10343e97L,
    BB_0x10343e99L,
    BB_0x10343ea9L,
    BB_0x10343eadL,
    BB_0x10343eb5L,
    Exit
};

void FUN_10343ccb() {
    State currentState = State::BB_0x10343ccbL;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x10343ccbL:
                currentState = State::BB_0x10343cecL;
                break;

            case State::BB_0x10343cecL:
                currentState = State::BB_0x10343ceeL;
                break;

            case State::BB_0x10343ceeL:
                currentState = State::BB_0x10343cf7L;
                break;

            case State::BB_0x10343cf7L:
                currentState = State::BB_0x10343cfbL;
                break;

            case State::BB_0x10343cfbL:
                currentState = State::BB_0x10343cffL;
                break;

            case State::BB_0x10343cffL:
                currentState = State::BB_0x10343d03L;
                break;

            case State::BB_0x10343d03L:
                FUN_1034145b();
                currentState = State::BB_0x10343d19L;
                break;

            case State::BB_0x10343d11L:
                currentState = State::BB_0x10343e99L;
                break;

            case State::BB_0x10343d19L:
                siglookup();
                currentState = State::BB_0x10343d27L;
                break;

            case State::BB_0x10343d27L:
                currentState = State::BB_0x10343d11L;
                break;

            case State::BB_0x10343d39L:
                currentState = State::BB_0x10343d5dL;
                break;

            case State::BB_0x10343d43L:
                currentState = State::BB_0x10343d4aL;
                break;

            case State::BB_0x10343d4aL:
                currentState = State::BB_0x10343d4fL;
                break;

            case State::BB_0x10343d4fL:
                currentState = State::BB_0x10343d27L;
                break;

            case State::BB_0x10343d54L:
                currentState = State::BB_0x10343d5dL;
                break;

            case State::BB_0x10343d5dL:
                currentState = State::BB_0x10343d70L;
                break;

            case State::BB_0x10343d68L:
                currentState = State::BB_0x10343d70L;
                break;

            case State::BB_0x10343d70L:
                currentState = State::BB_0x10343d94L;
                break;

            case State::BB_0x10343d88L:
                currentState = State::BB_0x10343d94L;
                break;

            case State::BB_0x10343d94L:
                currentState = State::BB_0x10343da4L;
                break;

            case State::BB_0x10343da4L:
                currentState = State::BB_0x10343dacL;
                break;

            case State::BB_0x10343dacL:
                currentState = State::BB_0x10343db1L;
                break;

            case State::BB_0x10343db1L:
                currentState = State::BB_0x10343db6L;
                break;

            case State::BB_0x10343db6L:
                currentState = State::BB_0x10343dbbL;
                break;

            case State::BB_0x10343dbbL:
                currentState = State::BB_0x10343dcaL;
                break;

            case State::BB_0x10343dcaL:
                FUN_1034130a();
                currentState = State::BB_0x10343de4L;
                break;

            case State::BB_0x10343de4L:
                currentState = State::BB_0x10343de9L;
                break;

            case State::BB_0x10343de9L:
                currentState = State::BB_0x10343dfbL;
                break;

            case State::BB_0x10343dfbL:
                currentState = State::BB_0x10343e15L;
                break;

            case State::BB_0x10343e02L:
                currentState = State::BB_0x10343dfbL;
                break;

            case State::BB_0x10343e0bL:
                currentState = State::BB_0x10343e15L;
                break;

            case State::BB_0x10343e15L:
                currentState = State::BB_0x10343e25L;
                break;

            case State::BB_0x10343e25L:
                currentState = State::BB_0x10343e2aL;
                break;

            case State::BB_0x10343e2aL:
                FUN_1034130a();
                currentState = State::BB_0x10343e71L;
                break;

            case State::BB_0x10343e65L:
                currentState = State::BB_0x10343e71L;
                break;

            case State::BB_0x10343e71L:
                currentState = State::BB_0x10343e77L;
                break;

            case State::BB_0x10343e77L:
                currentState = State::BB_0x10343e7cL;
                break;

            case State::BB_0x10343e7cL:
                currentState = State::BB_0x10343e81L;
                break;

            case State::BB_0x10343e81L:
                currentState = State::BB_0x10343e8cL;
                break;

            case State::BB_0x10343e8cL:
                FUN_1034130a();
                currentState = State::BB_0x10343e97L;
                break;

            case State::BB_0x10343e97L:
                currentState = State::BB_0x10343e99L;
                break;

            case State::BB_0x10343e99L:
                currentState = State::BB_0x10343ea9L;
                break;

            case State::BB_0x10343ea9L:
                currentState = State::BB_0x10343eadL;
                break;

            case State::BB_0x10343eadL:
                currentState = State::BB_0x10343eb5L;
                break;

            case State::BB_0x10343eb5L:
                __exit();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
