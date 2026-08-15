#include "FUN_103147e0.h"
#include "FUN_103149d0.h"
#include "FUN_103283b0.h"
#include "FUN_10330de6.h"
#include "FUN_10330e01.h"
#include "FUN_10316d60.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103147e0L,
    BB_0x1031485cL,
    BB_0x10314861L,
    BB_0x103148ddL,
    BB_0x103148feL,
    BB_0x10314907L,
    BB_0x1031490bL,
    BB_0x1031495bL,
    BB_0x10314960L,
    BB_0x1031497eL,
    BB_0x10314993L,
    BB_0x103149a0L,
    BB_0x103149ccL,
    Exit
};

void FUN_103147e0() {
    State currentState = State::BB_0x103147e0L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x103147e0L:
                currentState = State::BB_0x1031485cL;
                break;

            case State::BB_0x1031485cL:
                currentState = State::BB_0x10314861L;
                break;

            case State::BB_0x10314861L:
                FUN_103283b0();
                currentState = State::BB_0x103148ddL;
                break;

            case State::BB_0x103148ddL:
                FUN_103149d0();
                FUN_10316d60();
                currentState = State::BB_0x103148feL;
                break;

            case State::BB_0x103148feL:
                FUN_10330de6();
                currentState = State::BB_0x10314907L;
                break;

            case State::BB_0x10314907L:
                currentState = State::BB_0x1031490bL;
                break;

            case State::BB_0x1031490bL:
                FUN_10330e01();
                currentState = State::BB_0x1031495bL;
                break;

            case State::BB_0x1031495bL:
                currentState = State::BB_0x10314960L;
                break;

            case State::BB_0x10314960L:
                currentState = State::BB_0x1031497eL;
                break;

            case State::BB_0x1031497eL:
                currentState = State::Exit;
                break;

            case State::BB_0x10314993L:
                currentState = State::BB_0x103149a0L;
                break;

            case State::BB_0x103149a0L:
                FUN_103283b0();
                currentState = State::BB_0x10314861L;
                break;

            case State::BB_0x103149ccL:
                currentState = State::BB_0x103149a0L;
                break;
        }
    }
}

} // namespace DoogEngine1
