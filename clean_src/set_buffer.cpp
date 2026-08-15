#include "set_buffer.h"

namespace DoogEngine1 {

enum class State {
    BB_0x103392efL,
    Exit
};

void set_buffer() {
    State currentState = State::BB_0x103392efL;

    while (currentState != State::Exit) {
        switch (currentState) {
            case State::BB_0x103392efL:
                currentState = State::Exit;
                break;
        }
    }
}

} // namespace DoogEngine1
