#include "FUN_10285dc0.h"

namespace DoogEngine1 {

RegionResult ProcessEntryRegion(BufferContext& ctx, FUN_10285dc0_State state) {
    // Address-annotated range: BB_0x10285dc0L to BB_0x10285e4bL
    switch (state) {
        case FUN_10285dc0_State::ENTRY: {
            if (ctx.cursor >= ctx.buffer.size()) {
                return { static_cast<FUN_10285dc0_State>(0x10285e4b), false, false };
            }
            return { FUN_10285dc0_State::S_10285dd1, false, false };
        }
        case FUN_10285dc0_State::S_10285dd1: {
            return { FUN_10285dc0_State::S_10285dd8, false, false };
        }
        case FUN_10285dc0_State::S_10285dd8: {
            if (ctx.cursor >= ctx.buffer.size()) {
                ctx.has_overflow = true;
                return { FUN_10285dc0_State::ERROR, false, true };
            }
            uint8_t choice = ctx.buffer[ctx.cursor++];
            FUN_10285dc0_State next;
            switch (choice % 13) {
                case 0:  next = static_cast<FUN_10285dc0_State>(0x10285ddf); break;
                case 1:  next = static_cast<FUN_10285dc0_State>(0x10285de8); break;
                case 2:  next = static_cast<FUN_10285dc0_State>(0x10285df1); break;
                case 3:  next = static_cast<FUN_10285dc0_State>(0x10285dfa); break;
                case 4:  next = static_cast<FUN_10285dc0_State>(0x10285e03); break;
                case 5:  next = static_cast<FUN_10285dc0_State>(0x10285e4b); break;
                case 6:  next = static_cast<FUN_10285dc0_State>(0x10285e30); break;
                case 7:  next = static_cast<FUN_10285dc0_State>(0x10285e0c); break;
                case 8:  next = static_cast<FUN_10285dc0_State>(0x10285e15); break;
                case 9:  next = static_cast<FUN_10285dc0_State>(0x10285e1e); break;
                case 10: next = static_cast<FUN_10285dc0_State>(0x10285e27); break;
                case 11: next = static_cast<FUN_10285dc0_State>(0x10285e39); break;
                case 12: next = static_cast<FUN_10285dc0_State>(0x10285e42); break;
                default: next = FUN_10285dc0_State::ERROR; break;
            }
            return { next, false, next == FUN_10285dc0_State::ERROR };
        }
        default:
            return { FUN_10285dc0_State::ERROR, false, true };
    }
}

} // namespace DoogEngine1
