#include "FUN_10285dc0.h"
#include "FUN_10285dc0_regions.h"

namespace DoogEngine1 {

static inline uint8_t read_byte(BufferContext& ctx) {
    if (ctx.cursor < ctx.buffer.size()) {
        return ctx.buffer[ctx.cursor++];
    }
    ctx.has_overflow = true;
    return 0;
}

RegionResult ProcessCoreLoopRegion_Case4(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 5) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x10288d10: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288d5bL : 0x10288d51L);
                break;
            }
            case 0x10288d51: {
                current = static_cast<FUN_10285dc0_State>(0x10288d5eL);
                break;
            }
            case 0x10288d5b: {
                current = static_cast<FUN_10285dc0_State>(0x10288d5eL);
                break;
            }
            case 0x10288d5e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289c99L : 0x10288d85L);
                break;
            }
            case 0x10288d85: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x10288e80L);
                else             current = static_cast<FUN_10285dc0_State>(0x10288ddeL);
                break;
            }
            case 0x10288dde: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288e80L : 0x10288dedL);
                break;
            }
            case 0x10288ded: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288e24L : 0x10288e08L);
                break;
            }
            case 0x10288e08: {
                current = static_cast<FUN_10285dc0_State>(0x10288e10L);
                break;
            }
            case 0x10288e10: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288e21L));
                break;
            }
            case 0x10288e21: {
                current = static_cast<FUN_10285dc0_State>(0x10288e24L);
                break;
            }
            case 0x10288e24: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288e40L : 0x10288e30L);
                break;
            }
            case 0x10288e30: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288e40L));
                break;
            }
            case 0x10288e40: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288e80L : 0x10288e48L);
                break;
            }
            case 0x10288e48: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288e80L : 0x10288e5aL);
                break;
            }
            case 0x10288e5a: {
                current = static_cast<FUN_10285dc0_State>(0x10288e80L);
                break;
            }
            case 0x10288e80: {
                current = static_cast<FUN_10285dc0_State>(0x10288ec0L);
                break;
            }
            case 0x10288ec0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288fa1L : 0x10288edfL);
                break;
            }
            case 0x10288edf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288fa1L : 0x10288ee7L);
                break;
            }
            case 0x10288ee7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288fa1L : 0x10288ef0L);
                break;
            }
            case 0x10288ef0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288f2aL : 0x10288f0fL);
                break;
            }
            case 0x10288f0f: {
                current = static_cast<FUN_10285dc0_State>(0x10288f13L);
                break;
            }
            case 0x10288f13: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288f24L));
                break;
            }
            case 0x10288f24: {
                current = static_cast<FUN_10285dc0_State>(0x10288f2aL);
                break;
            }
            case 0x10288f2a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288f40L : 0x10288f2eL);
                break;
            }
            case 0x10288f2e: {
                current = static_cast<FUN_10285dc0_State>(0x10288f30L);
                break;
            }
            case 0x10288f30: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288f40L));
                break;
            }
            case 0x10288f40: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288f8eL : 0x10288f45L);
                break;
            }
            case 0x10288f45: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288f8eL : 0x10288f57L);
                break;
            }
            case 0x10288f57: {
                current = static_cast<FUN_10285dc0_State>(0x10288f93L);
                break;
            }
            case 0x10288f8e: {
                current = static_cast<FUN_10285dc0_State>(0x10288f91L);
                break;
            }
            case 0x10288f91: {
                current = static_cast<FUN_10285dc0_State>(0x10288f93L);
                break;
            }
            case 0x10288f93: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288ec0L : 0x10288fa7L);
                break;
            }
            case 0x10288fa7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289111L : 0x10288fb5L);
                break;
            }
            case 0x10288fb5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289111L : 0x10288fbaL);
                break;
            }
            case 0x10288fba: {
                current = static_cast<FUN_10285dc0_State>(0x10288fbdL);
                break;
            }
            case 0x10288fbd: {
                current = static_cast<FUN_10285dc0_State>(0x10288fcaL);
                break;
            }
            case 0x10288fca: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102890e7L : 0x10288fcfL);
                break;
            }
            case 0x10288fcf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102890e7L : 0x10288fd3L);
                break;
            }
            case 0x10288fd3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102890e7L : 0x10288fd9L);
                break;
            }
            case 0x10288fd9: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288ff6L : 0x10288fdfL);
                break;
            }
            case 0x10288fdf: {
                current = static_cast<FUN_10285dc0_State>(0x10288fe3L);
                break;
            }
            case 0x10288fe3: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288ff3L));
                break;
            }
            case 0x10288ff3: {
                current = static_cast<FUN_10285dc0_State>(0x10288ff6L);
                break;
            }
            case 0x10288ff6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289006L : 0x10288ffaL);
                break;
            }
            case 0x10288ffa: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10289006L));
                break;
            }
            case 0x10289006: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102890e7L : 0x1028900eL);
                break;
            }
            case 0x1028900e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102890e7L : 0x10289025L);
                break;
            }
            case 0x10289025: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102890e7L : 0x10289033L);
                break;
            }
            case 0x10289033: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028908fL : 0x10289037L);
                break;
            }
            case 0x10289037: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028908fL : 0x10289052L);
                break;
            }
            case 0x10289052: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028905cL : 0x10289058L);
                break;
            }
            case 0x10289058: {
                current = static_cast<FUN_10285dc0_State>(0x1028908fL);
                break;
            }
            case 0x1028905c: {
                current = static_cast<FUN_10285dc0_State>(0x1028908fL);
                break;
            }
            case 0x1028908f: {
                current = static_cast<FUN_10285dc0_State>(0x102890e7L);
                break;
            }
            case 0x102890e7: {
                current = static_cast<FUN_10285dc0_State>(0x102890eeL);
                break;
            }
            case 0x102890ee: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102890f8L : 0x102890e7L);
                break;
            }
            case 0x102890f8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289117L : 0x10289102L);
                break;
            }
            case 0x10289102: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10289117L));
                break;
            }
            case 0x10289111: {
                current = static_cast<FUN_10285dc0_State>(0x10289117L);
                break;
            }
            case 0x10289117: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102891dfL : 0x10289128L);
                break;
            }
            case 0x10289128: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102891dfL : 0x1028912eL);
                break;
            }
            case 0x1028912e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102891dfL : 0x10289134L);
                break;
            }
            case 0x10289134: {
                current = static_cast<FUN_10285dc0_State>(0x10289176L);
                break;
            }
            case 0x10289176: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102891dbL : 0x102891b8L);
                break;
            }
            case 0x102891b8: {
                current = static_cast<FUN_10285dc0_State>(0x102891dbL);
                break;
            }
            case 0x102891db: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028924cL : 0x102891dfL);
                break;
            }
            case 0x102891df: {
                current = static_cast<FUN_10285dc0_State>(0x102891e0L);
                break;
            }
            case 0x102891e0: {
                // Loop with max-iteration guard
                size_t max_iters = 256;
                bool keep_looping = true;
                while (keep_looping && max_iters > 0) {
                    uint8_t b = read_byte(ctx);
                    if (b == 0) {
                        current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                        keep_looping = false;
                    } else if (b == 1) {
                        max_iters--;
                    } else {
                        current = static_cast<FUN_10285dc0_State>(0x10289249L);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x10289249: {
                current = static_cast<FUN_10285dc0_State>(0x1028924cL);
                break;
            }
            case 0x1028924c: {
                current = static_cast<FUN_10285dc0_State>(0x102893c3L);
                break;
            }
            case 0x10289259: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102893c3L : 0x1028926aL);
                break;
            }
            case 0x1028926a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289323L : 0x10289281L);
                break;
            }
            case 0x10289281: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102893c0L : 0x10289294L);
                break;
            }
            case 0x10289294: {
                current = static_cast<FUN_10285dc0_State>(0x102892b0L);
                break;
            }
            case 0x102892b0: {
                current = static_cast<FUN_10285dc0_State>(0x102892b3L);
                break;
            }
            case 0x102892b3: {
                // Loop with max-iteration guard
                size_t max_iters = 256;
                bool keep_looping = true;
                while (keep_looping && max_iters > 0) {
                    uint8_t b = read_byte(ctx);
                    if (b == 0) {
                        current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                        keep_looping = false;
                    } else if (b == 1) {
                        max_iters--;
                    } else {
                        current = static_cast<FUN_10285dc0_State>(0x1028931eL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028931e: {
                current = static_cast<FUN_10285dc0_State>(0x102893c3L);
                break;
            }
            case 0x10289323: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102893c0L : 0x10289336L);
                break;
            }
            case 0x10289336: {
                current = static_cast<FUN_10285dc0_State>(0x10289350L);
                break;
            }
            case 0x10289350: {
                current = static_cast<FUN_10285dc0_State>(0x10289353L);
                break;
            }
            case 0x10289353: {
                // Loop with max-iteration guard
                size_t max_iters = 256;
                bool keep_looping = true;
                while (keep_looping && max_iters > 0) {
                    uint8_t b = read_byte(ctx);
                    if (b == 0) {
                        current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                        keep_looping = false;
                    } else if (b == 1) {
                        max_iters--;
                    } else {
                        current = static_cast<FUN_10285dc0_State>(0x102893beL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x102893be: {
                current = static_cast<FUN_10285dc0_State>(0x102893c3L);
                break;
            }
            case 0x102893c0: {
                current = static_cast<FUN_10285dc0_State>(0x102893c3L);
                break;
            }
            case 0x102893c3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288c0dL : 0x102893d7L);
                break;
            }
            case 0x102893d7: {
                // Region exit state
                return { current, false, false };
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
