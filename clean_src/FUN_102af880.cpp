#include "FUN_102af880.h"
#include "FUN_103283b0.h"
#include "FUN_102b0fa0.h"
#include "FUN_102bb060.h"
#include "FUN_10330de6.h"
#include "FUN_10330e01.h"

namespace DoogEngine1 {

enum class State {
    BB_0x102af880L,
    BB_0x102af8fcL,
    BB_0x102af901L,
    BB_0x102af97cL,
    BB_0x102af99dL,
    BB_0x102af9a6L,
    BB_0x102af9aaL,
    BB_0x102af9f7L,
    BB_0x102afa0fL,
    BB_0x102afa24L,
    BB_0x102afa30L,
    BB_0x102afa5cL,
    Exit
};

void FUN_102af880() {
    State currentState = State::BB_0x102af880L;
    int loopCount = 0;

    while (currentState != State::Exit && loopCount < 100) {
        loopCount++;
        switch (currentState) {
            case State::BB_0x102af880L:
                currentState = State::BB_0x102af8fcL;
                break;

            case State::BB_0x102af8fcL:
                currentState = State::BB_0x102af901L;
                break;

            case State::BB_0x102af901L:
                FUN_103283b0();
                currentState = State::BB_0x102af97cL;
                break;

            case State::BB_0x102af97cL:
                FUN_102b0fa0();
                FUN_102bb060();
                currentState = State::BB_0x102af99dL;
                break;

            case State::BB_0x102af99dL:
                FUN_10330de6();
                currentState = State::BB_0x102af9a6L;
                break;

            case State::BB_0x102af9a6L:
                currentState = State::BB_0x102af9aaL;
                break;

            case State::BB_0x102af9aaL:
                FUN_10330e01();
                currentState = State::BB_0x102afa0fL;
                break;

            case State::BB_0x102af9f7L:
                currentState = State::BB_0x102afa0fL;
                break;

            case State::BB_0x102afa0fL:
                currentState = State::Exit;
                break;

            case State::BB_0x102afa24L:
                currentState = State::BB_0x102afa30L;
                break;

            case State::BB_0x102afa30L:
                FUN_103283b0();
                currentState = State::BB_0x102af901L;
                break;

            case State::BB_0x102afa5cL:
                currentState = State::BB_0x102afa30L;
                break;
        }
    }
}

} // namespace DoogEngine1
