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

RegionResult ProcessCoreLoopRegion_Case9(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 10) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x1028d720: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d780L : 0x1028d776L);
                break;
            }
            case 0x1028d776: {
                current = static_cast<FUN_10285dc0_State>(0x1028d783L);
                break;
            }
            case 0x1028d780: {
                current = static_cast<FUN_10285dc0_State>(0x1028d783L);
                break;
            }
            case 0x1028d783: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028e3e0L : 0x1028d7adL);
                break;
            }
            case 0x1028d7ad: {
                current = static_cast<FUN_10285dc0_State>(0x1028d810L);
                break;
            }
            case 0x1028d810: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x1028d950L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028d8aeL);
                break;
            }
            case 0x1028d8ae: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d950L : 0x1028d8bdL);
                break;
            }
            case 0x1028d8bd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d8f4L : 0x1028d8d8L);
                break;
            }
            case 0x1028d8d8: {
                current = static_cast<FUN_10285dc0_State>(0x1028d8e0L);
                break;
            }
            case 0x1028d8e0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028d8f1L));
                break;
            }
            case 0x1028d8f1: {
                current = static_cast<FUN_10285dc0_State>(0x1028d8f4L);
                break;
            }
            case 0x1028d8f4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d910L : 0x1028d900L);
                break;
            }
            case 0x1028d900: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028d910L));
                break;
            }
            case 0x1028d910: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d950L : 0x1028d918L);
                break;
            }
            case 0x1028d918: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d950L : 0x1028d92aL);
                break;
            }
            case 0x1028d92a: {
                current = static_cast<FUN_10285dc0_State>(0x1028d950L);
                break;
            }
            case 0x1028d950: {
                current = static_cast<FUN_10285dc0_State>(0x1028d990L);
                break;
            }
            case 0x1028d990: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028d9a1L));
                break;
            }
            case 0x1028d9a1: {
                current = static_cast<FUN_10285dc0_State>(0x1028d9b8L);
                break;
            }
            case 0x1028d9a8: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028d9b8L));
                break;
            }
            case 0x1028d9b8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028da75L : 0x1028d9c1L);
                break;
            }
            case 0x1028d9c1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028da75L : 0x1028d9d8L);
                break;
            }
            case 0x1028d9d8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028da75L : 0x1028d9f0L);
                break;
            }
            case 0x1028d9f0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028da03L : 0x1028da0eL);
                break;
            }
            case 0x1028da03: {
                current = static_cast<FUN_10285dc0_State>(0x1028da75L);
                break;
            }
            case 0x1028da0e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028da2aL : 0x1028da13L);
                break;
            }
            case 0x1028da13: {
                current = static_cast<FUN_10285dc0_State>(0x1028da75L);
                break;
            }
            case 0x1028da2a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028da50L : 0x1028da31L);
                break;
            }
            case 0x1028da31: {
                current = static_cast<FUN_10285dc0_State>(0x1028da75L);
                break;
            }
            case 0x1028da50: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028da69L : 0x1028da54L);
                break;
            }
            case 0x1028da54: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028da6dL : 0x1028da65L);
                break;
            }
            case 0x1028da65: {
                current = static_cast<FUN_10285dc0_State>(0x1028da75L);
                break;
            }
            case 0x1028da6dL: {
                current = static_cast<FUN_10285dc0_State>(0x1028da75L);
                break;
            }
            case 0x1028da69: {
                current = static_cast<FUN_10285dc0_State>(0x1028da75L);
                break;
            }
            case 0x1028da75: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028db78L : 0x1028da7fL);
                break;
            }
            case 0x1028da7f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028db78L : 0x1028da87L);
                break;
            }
            case 0x1028da87: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028da98L));
                break;
            }
            case 0x1028da98: {
                current = static_cast<FUN_10285dc0_State>(0x1028db78L);
                break;
            }
            case 0x1028daa2: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028dab7L));
                break;
            }
            case 0x1028dab7: {
                current = static_cast<FUN_10285dc0_State>(0x1028db78L);
                break;
            }
            case 0x1028db78: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dbf0L : 0x1028dbb3L);
                break;
            }
            case 0x1028dbb3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dbf0L : 0x1028dbbfL);
                break;
            }
            case 0x1028dbbf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d9c1L : 0x1028dbf0L);
                break;
            }
            case 0x1028dbf0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dc44L : 0x1028dbe1L);
                break;
            }
            case 0x1028dbe1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dbf6L : 0x1028dbf2L);
                break;
            }
            case 0x1028dbf2: {
                current = static_cast<FUN_10285dc0_State>(0x1028dc47L);
                break;
            }
            case 0x1028dbf6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dc02L : 0x1028dbfbL);
                break;
            }
            case 0x1028dbfb: {
                current = static_cast<FUN_10285dc0_State>(0x1028dc47L);
                break;
            }
            case 0x1028dc02: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dc1aL : 0x1028dc07L);
                break;
            }
            case 0x1028dc07: {
                current = static_cast<FUN_10285dc0_State>(0x1028dc47L);
                break;
            }
            case 0x1028dc1a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dc2eL : 0x1028dc1fL);
                break;
            }
            case 0x1028dc1f: {
                current = static_cast<FUN_10285dc0_State>(0x1028dc47L);
                break;
            }
            case 0x1028dc2e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dc3aL : 0x1028dc33L);
                break;
            }
            case 0x1028dc33: {
                current = static_cast<FUN_10285dc0_State>(0x1028dc47L);
                break;
            }
            case 0x1028dc3a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dc47L : 0x1028dc44L);
                break;
            }
            case 0x1028dc44: {
                current = static_cast<FUN_10285dc0_State>(0x1028dc47L);
                break;
            }
            case 0x1028dc47: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dc65L : 0x1028dc4bL);
                break;
            }
            case 0x1028dc4b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dc65L : 0x1028dc4fL);
                break;
            }
            case 0x1028dc4f: {
                current = static_cast<FUN_10285dc0_State>(0x1028dc65L);
                break;
            }
            case 0x1028dc65: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dc81L : 0x1028dc7dL);
                break;
            }
            case 0x1028dc7d: {
                current = static_cast<FUN_10285dc0_State>(0x1028dce5L);
                break;
            }
            case 0x1028dc81: {
                current = static_cast<FUN_10285dc0_State>(0x1028dce5L);
                break;
            }
            case 0x1028dce5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dd08L : 0x1028dd03L);
                break;
            }
            case 0x1028dd03: {
                current = static_cast<FUN_10285dc0_State>(0x1028dd57L);
                break;
            }
            case 0x1028dd08: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dd27L : 0x1028dd10L);
                break;
            }
            case 0x1028dd10: {
                current = static_cast<FUN_10285dc0_State>(0x1028dd57L);
                break;
            }
            case 0x1028dd27: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dd3dL : 0x1028dd2fL);
                break;
            }
            case 0x1028dd2f: {
                current = static_cast<FUN_10285dc0_State>(0x1028dd57L);
                break;
            }
            case 0x1028dd3d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dd4cL : 0x1028dd45L);
                break;
            }
            case 0x1028dd45: {
                current = static_cast<FUN_10285dc0_State>(0x1028dd57L);
                break;
            }
            case 0x1028dd4c: {
                current = static_cast<FUN_10285dc0_State>(0x1028dd57L);
                break;
            }
            case 0x1028dd57: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dd64L : 0x1028dd5cL);
                break;
            }
            case 0x1028dd5c: {
                current = static_cast<FUN_10285dc0_State>(0x1028dd9eL);
                break;
            }
            case 0x1028dd64: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dd83L : 0x1028dd6cL);
                break;
            }
            case 0x1028dd6c: {
                current = static_cast<FUN_10285dc0_State>(0x1028dd9eL);
                break;
            }
            case 0x1028dd83: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028dd99L : 0x1028dd8bL);
                break;
            }
            case 0x1028dd8b: {
                current = static_cast<FUN_10285dc0_State>(0x1028dd9eL);
                break;
            }
            case 0x1028dd99: {
                current = static_cast<FUN_10285dc0_State>(0x1028dd9eL);
                break;
            }
            case 0x1028dd9e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ddd6L : 0x1028ddb5L);
                break;
            }
            case 0x1028ddb5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ddd6L : 0x1028ddbbL);
                break;
            }
            case 0x1028ddbb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ddd6L : 0x1028ddc1L);
                break;
            }
            case 0x1028ddc1: {
                current = static_cast<FUN_10285dc0_State>(0x1028de03L);
                break;
            }
            case 0x1028ddd6: {
                current = static_cast<FUN_10285dc0_State>(0x1028de03L);
                break;
            }
            case 0x1028de03: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028de5dL : 0x1028de3dL);
                break;
            }
            case 0x1028de3d: {
                current = static_cast<FUN_10285dc0_State>(0x1028de5dL);
                break;
            }
            case 0x1028de5d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028de9dL : 0x1028de61L);
                break;
            }
            case 0x1028de61: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028de9aL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028de9a: {
                current = static_cast<FUN_10285dc0_State>(0x1028de9dL);
                break;
            }
            case 0x1028de9d: {
                current = static_cast<FUN_10285dc0_State>(0x1028df8aL);
                break;
            }
            case 0x1028dea7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028df8dL : 0x1028debdL);
                break;
            }
            case 0x1028debd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028df2cL : 0x1028decdL);
                break;
            }
            case 0x1028decd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028df8dL : 0x1028deddL);
                break;
            }
            case 0x1028dedd: {
                current = static_cast<FUN_10285dc0_State>(0x1028def0L);
                break;
            }
            case 0x1028def0: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028df2aL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028df2a: {
                current = static_cast<FUN_10285dc0_State>(0x1028df8aL);
                break;
            }
            case 0x1028df2c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028df8dL : 0x1028df38L);
                break;
            }
            case 0x1028df38: {
                current = static_cast<FUN_10285dc0_State>(0x1028df50L);
                break;
            }
            case 0x1028df50: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028df8aL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028df8a: {
                current = static_cast<FUN_10285dc0_State>(0x1028df8dL);
                break;
            }
            case 0x1028df8d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d810L : 0x1028df9eL);
                break;
            }
            case 0x1028df9e: {
                current = static_cast<FUN_10285dc0_State>(0x1028e290L);
                break;
            }
            case 0x1028e290: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028e2cdL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028e2cd: {
                current = static_cast<FUN_10285dc0_State>(0x1028e350L);
                break;
            }
            case 0x1028e350: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028e38dL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028e38d: {
                current = static_cast<FUN_10285dc0_State>(0x1028e3c0L);
                break;
            }
            case 0x1028e3c0: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028e3ddL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028e3dd: {
                current = static_cast<FUN_10285dc0_State>(0x1028e3e0L);
                break;
            }
            case 0x1028e3e0: {
                return { current, false, false };
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
