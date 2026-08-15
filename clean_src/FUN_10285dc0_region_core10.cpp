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

RegionResult ProcessCoreLoopRegion_Case10(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 11) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x1028e3e0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028e42bL : 0x1028e421L);
                break;
            }
            case 0x1028e421: {
                current = static_cast<FUN_10285dc0_State>(0x1028e42eL);
                break;
            }
            case 0x1028e42b: {
                current = static_cast<FUN_10285dc0_State>(0x1028e42eL);
                break;
            }
            case 0x1028e42e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028f3d7L : 0x1028e455L);
                break;
            }
            case 0x1028e455: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x1028e550L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028e4aeL);
                break;
            }
            case 0x1028e4ae: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028e550L : 0x1028e4bdL);
                break;
            }
            case 0x1028e4bd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028e4f4L : 0x1028e4d8L);
                break;
            }
            case 0x1028e4d8: {
                current = static_cast<FUN_10285dc0_State>(0x1028e4e0L);
                break;
            }
            case 0x1028e4e0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028e4f1L));
                break;
            }
            case 0x1028e4f1: {
                current = static_cast<FUN_10285dc0_State>(0x1028e4f4L);
                break;
            }
            case 0x1028e4f4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028e510L : 0x1028e500L);
                break;
            }
            case 0x1028e500: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028e510L));
                break;
            }
            case 0x1028e510: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028e550L : 0x1028e518L);
                break;
            }
            case 0x1028e518: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028e550L : 0x1028e52aL);
                break;
            }
            case 0x1028e52a: {
                current = static_cast<FUN_10285dc0_State>(0x1028e550L);
                break;
            }
            case 0x1028e550: {
                current = static_cast<FUN_10285dc0_State>(0x1028e990L);
                break;
            }
            case 0x1028e990: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028e9a1L));
                break;
            }
            case 0x1028e9a1: {
                current = static_cast<FUN_10285dc0_State>(0x1028e9b8L);
                break;
            }
            case 0x1028e9a8: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028e9b8L));
                break;
            }
            case 0x1028e9b8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ea75L : 0x1028e9c1L);
                break;
            }
            case 0x1028e9c1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ea75L : 0x1028e9d8L);
                break;
            }
            case 0x1028e9d8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ea75L : 0x1028e9f0L);
                break;
            }
            case 0x1028e9f0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ea03L : 0x1028ea0eL);
                break;
            }
            case 0x1028ea03: {
                current = static_cast<FUN_10285dc0_State>(0x1028ea75L);
                break;
            }
            case 0x1028ea0e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ea2aL : 0x1028ea13L);
                break;
            }
            case 0x1028ea13: {
                current = static_cast<FUN_10285dc0_State>(0x1028ea75L);
                break;
            }
            case 0x1028ea2a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ea50L : 0x1028ea31L);
                break;
            }
            case 0x1028ea31: {
                current = static_cast<FUN_10285dc0_State>(0x1028ea75L);
                break;
            }
            case 0x1028ea50: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ea69L : 0x1028ea54L);
                break;
            }
            case 0x1028ea54: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ea6dL : 0x1028ea65L);
                break;
            }
            case 0x1028ea65: {
                current = static_cast<FUN_10285dc0_State>(0x1028ea75L);
                break;
            }
            case 0x1028ea6dL: {
                current = static_cast<FUN_10285dc0_State>(0x1028ea75L);
                break;
            }
            case 0x1028ea69: {
                current = static_cast<FUN_10285dc0_State>(0x1028ea75L);
                break;
            }
            case 0x1028ea75: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028eb78L : 0x1028ea7fL);
                break;
            }
            case 0x1028ea7f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028eb78L : 0x1028ea87L);
                break;
            }
            case 0x1028ea87: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028ea98L));
                break;
            }
            case 0x1028ea98: {
                current = static_cast<FUN_10285dc0_State>(0x1028eb78L);
                break;
            }
            case 0x1028eaa2: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028eab7L));
                break;
            }
            case 0x1028eab7: {
                current = static_cast<FUN_10285dc0_State>(0x1028eb78L);
                break;
            }
            case 0x1028eb78: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ebf0L : 0x1028ebb3L);
                break;
            }
            case 0x1028ebb3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ebf0L : 0x1028ebbfL);
                break;
            }
            case 0x1028ebbf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028e9c1L : 0x1028ebf0L);
                break;
            }
            case 0x1028ebf0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ec44L : 0x1028ebe1L);
                break;
            }
            case 0x1028ebe1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ebf6L : 0x1028ebf2L);
                break;
            }
            case 0x1028ebf2: {
                current = static_cast<FUN_10285dc0_State>(0x1028ec47L);
                break;
            }
            case 0x1028ebf6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ec02L : 0x1028ebfbL);
                break;
            }
            case 0x1028ebfb: {
                current = static_cast<FUN_10285dc0_State>(0x1028ec47L);
                break;
            }
            case 0x1028ec02: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ec1aL : 0x1028ec07L);
                break;
            }
            case 0x1028ec07: {
                current = static_cast<FUN_10285dc0_State>(0x1028ec47L);
                break;
            }
            case 0x1028ec1a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ec2eL : 0x1028ec1fL);
                break;
            }
            case 0x1028ec1f: {
                current = static_cast<FUN_10285dc0_State>(0x1028ec47L);
                break;
            }
            case 0x1028ec2e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ec3aL : 0x1028ec33L);
                break;
            }
            case 0x1028ec33: {
                current = static_cast<FUN_10285dc0_State>(0x1028ec47L);
                break;
            }
            case 0x1028ec3a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ec47L : 0x1028ec44L);
                break;
            }
            case 0x1028ec44: {
                current = static_cast<FUN_10285dc0_State>(0x1028ec47L);
                break;
            }
            case 0x1028ec47: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ec65L : 0x1028ec4bL);
                break;
            }
            case 0x1028ec4b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ec65L : 0x1028ec4fL);
                break;
            }
            case 0x1028ec4f: {
                current = static_cast<FUN_10285dc0_State>(0x1028ec65L);
                break;
            }
            case 0x1028ec65: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ec81L : 0x1028ec7dL);
                break;
            }
            case 0x1028ec7d: {
                current = static_cast<FUN_10285dc0_State>(0x1028ece5L);
                break;
            }
            case 0x1028ec81: {
                current = static_cast<FUN_10285dc0_State>(0x1028ece5L);
                break;
            }
            case 0x1028ece5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ed08L : 0x1028ed03L);
                break;
            }
            case 0x1028ed03: {
                current = static_cast<FUN_10285dc0_State>(0x1028ed57L);
                break;
            }
            case 0x1028ed08: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ed27L : 0x1028ed10L);
                break;
            }
            case 0x1028ed10: {
                current = static_cast<FUN_10285dc0_State>(0x1028ed57L);
                break;
            }
            case 0x1028ed27: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ed3dL : 0x1028ed2fL);
                break;
            }
            case 0x1028ed2f: {
                current = static_cast<FUN_10285dc0_State>(0x1028ed57L);
                break;
            }
            case 0x1028ed3d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ed4cL : 0x1028ed45L);
                break;
            }
            case 0x1028ed45: {
                current = static_cast<FUN_10285dc0_State>(0x1028ed57L);
                break;
            }
            case 0x1028ed4c: {
                current = static_cast<FUN_10285dc0_State>(0x1028ed57L);
                break;
            }
            case 0x1028ed57: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ed64L : 0x1028ed5cL);
                break;
            }
            case 0x1028ed5c: {
                current = static_cast<FUN_10285dc0_State>(0x1028ed9eL);
                break;
            }
            case 0x1028ed64: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ed83L : 0x1028ed6cL);
                break;
            }
            case 0x1028ed6c: {
                current = static_cast<FUN_10285dc0_State>(0x1028ed9eL);
                break;
            }
            case 0x1028ed83: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ed99L : 0x1028ed8bL);
                break;
            }
            case 0x1028ed8b: {
                current = static_cast<FUN_10285dc0_State>(0x1028ed9eL);
                break;
            }
            case 0x1028ed99: {
                current = static_cast<FUN_10285dc0_State>(0x1028ed9eL);
                break;
            }
            case 0x1028ed9e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028edd6L : 0x1028edb5L);
                break;
            }
            case 0x1028edb5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ddd6L : 0x1028edbbL);
                break;
            }
            case 0x1028edbb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ddd6L : 0x1028edc1L);
                break;
            }
            case 0x1028edc1: {
                current = static_cast<FUN_10285dc0_State>(0x1028ee03L);
                break;
            }
            case 0x1028edd6: {
                current = static_cast<FUN_10285dc0_State>(0x1028ee03L);
                break;
            }
            case 0x1028ee03: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ee5dL : 0x1028ee3dL);
                break;
            }
            case 0x1028ee3d: {
                current = static_cast<FUN_10285dc0_State>(0x1028ee5dL);
                break;
            }
            case 0x1028ee5d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ee9dL : 0x1028ee61L);
                break;
            }
            case 0x1028ee61: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028ee9aL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028ee9a: {
                current = static_cast<FUN_10285dc0_State>(0x1028ee9dL);
                break;
            }
            case 0x1028ee9d: {
                current = static_cast<FUN_10285dc0_State>(0x1028ef8aL);
                break;
            }
            case 0x1028eea7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ef8dL : 0x1028eebdL);
                break;
            }
            case 0x1028eebd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ef2cL : 0x1028eecdL);
                break;
            }
            case 0x1028eecd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ef8dL : 0x1028eeddL);
                break;
            }
            case 0x1028eedd: {
                current = static_cast<FUN_10285dc0_State>(0x1028eef0L);
                break;
            }
            case 0x1028eef0: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028ef2aL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028ef2a: {
                current = static_cast<FUN_10285dc0_State>(0x1028ef8aL);
                break;
            }
            case 0x1028ef2c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ef8dL : 0x1028ef38L);
                break;
            }
            case 0x1028ef38: {
                current = static_cast<FUN_10285dc0_State>(0x1028ef50L);
                break;
            }
            case 0x1028ef50: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028ef8aL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028ef8a: {
                current = static_cast<FUN_10285dc0_State>(0x1028ef8dL);
                break;
            }
            case 0x1028ef8d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028e455L : 0x1028ef9eL);
                break;
            }
            case 0x1028ef9e: {
                current = static_cast<FUN_10285dc0_State>(0x1028f290L);
                break;
            }
            case 0x1028f290: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028f2cdL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028f2cd: {
                current = static_cast<FUN_10285dc0_State>(0x1028f350L);
                break;
            }
            case 0x1028f350: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028f38dL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028f38d: {
                current = static_cast<FUN_10285dc0_State>(0x1028f3c0L);
                break;
            }
            case 0x1028f3c0: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028f3ddL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028f3dd: {
                current = static_cast<FUN_10285dc0_State>(0x1028f3d7L);
                break;
            }
            case 0x1028f3d7: {
                return { current, false, false };
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
