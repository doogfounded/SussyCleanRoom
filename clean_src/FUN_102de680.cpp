#include "FUN_102de680.h"
#include "FUN_10298830.h"
#include "FUN_103283b0.h"
#include "FUN_102e1ad0.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102de680L,
    BB_0x102de6e1L,
    BB_0x102de74dL,
    Exit
};

void FUN_102de680() {
    State currentState = State::BB_0x102de680L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102de680L:
                currentState = State::BB_0x102de6e1L;
                break;

            case State::BB_0x102de6e1L:
                FUN_10298830();
                FUN_103283b0();
                currentState = State::BB_0x102de74dL;
                break;

            case State::BB_0x102de74dL:
                FUN_103283b0();
                FUN_102e1ad0();
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
