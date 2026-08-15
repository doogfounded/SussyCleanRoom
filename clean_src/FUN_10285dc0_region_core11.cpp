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

RegionResult ProcessCoreLoopRegion_Case11(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 12) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x1028f400: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028f43bL : 0x1028f431L);
                break;
            }
            case 0x1028f431: {
                current = static_cast<FUN_10285dc0_State>(0x1028f43eL);
                break;
            }
            case 0x1028f43b: {
                current = static_cast<FUN_10285dc0_State>(0x1028f43eL);
                break;
            }
            case 0x1028f43e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10290664L : 0x1028f465L);
                break;
            }
            case 0x1028f465: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x1028f550L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028f4aeL);
                break;
            }
            case 0x1028f4ae: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028f550L : 0x1028f4bdL);
                break;
            }
            case 0x1028f4bd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028f4f4L : 0x1028f4d8L);
                break;
            }
            case 0x1028f4d8: {
                current = static_cast<FUN_10285dc0_State>(0x1028f4e0L);
                break;
            }
            case 0x1028f4e0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028f4f1L));
                break;
            }
            case 0x1028f4f1: {
                current = static_cast<FUN_10285dc0_State>(0x1028f4f4L);
                break;
            }
            case 0x1028f4f4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028f510L : 0x1028f500L);
                break;
            }
            case 0x1028f500: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028f510L));
                break;
            }
            case 0x1028f510: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028f550L : 0x1028f518L);
                break;
            }
            case 0x1028f518: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028f550L : 0x1028f52aL);
                break;
            }
            case 0x1028f52a: {
                current = static_cast<FUN_10285dc0_State>(0x1028f550L);
                break;
            }
            case 0x1028f550: {
                current = static_cast<FUN_10285dc0_State>(0x1028f990L);
                break;
            }
            case 0x1028f990: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028f9a1L));
                break;
            }
            case 0x1028f9a1: {
                current = static_cast<FUN_10285dc0_State>(0x1028f9b8L);
                break;
            }
            case 0x1028f9a8: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028f9b8L));
                break;
            }
            case 0x1028f9b8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fa75L : 0x1028f9c1L);
                break;
            }
            case 0x1028f9c1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fa75L : 0x1028f9d8L);
                break;
            }
            case 0x1028f9d8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fa75L : 0x1028f9f0L);
                break;
            }
            case 0x1028f9f0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fa03L : 0x1028fa0eL);
                break;
            }
            case 0x1028fa03: {
                current = static_cast<FUN_10285dc0_State>(0x1028fa75L);
                break;
            }
            case 0x1028fa0e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fa2aL : 0x1028fa13L);
                break;
            }
            case 0x1028fa13: {
                current = static_cast<FUN_10285dc0_State>(0x1028fa75L);
                break;
            }
            case 0x1028fa2a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fa50L : 0x1028fa31L);
                break;
            }
            case 0x1028fa31: {
                current = static_cast<FUN_10285dc0_State>(0x1028fa75L);
                break;
            }
            case 0x1028fa50: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fa69L : 0x1028fa54L);
                break;
            }
            case 0x1028fa54: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fa6dL : 0x1028fa65L);
                break;
            }
            case 0x1028fa65: {
                current = static_cast<FUN_10285dc0_State>(0x1028fa75L);
                break;
            }
            case 0x1028fa6d: {
                current = static_cast<FUN_10285dc0_State>(0x1028fa75L);
                break;
            }
            case 0x1028fa69: {
                current = static_cast<FUN_10285dc0_State>(0x1028fa75L);
                break;
            }
            case 0x1028fa75: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fb78L : 0x1028fa7fL);
                break;
            }
            case 0x1028fa7f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fb78L : 0x1028fa87L);
                break;
            }
            case 0x1028fa87: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028fa98L));
                break;
            }
            case 0x1028fa98: {
                current = static_cast<FUN_10285dc0_State>(0x1028fb78L);
                break;
            }
            case 0x1028faa2: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028fab7L));
                break;
            }
            case 0x1028fab7: {
                current = static_cast<FUN_10285dc0_State>(0x1028fb78L);
                break;
            }
            case 0x1028fb78: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fbf0L : 0x1028fbb3L);
                break;
            }
            case 0x1028fbb3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fbf0L : 0x1028fbbfL);
                break;
            }
            case 0x1028fbbf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028f9c1L : 0x1028fbf0L);
                break;
            }
            case 0x1028fbf0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10290150L : 0x1028fbe1L);
                break;
            }
            case 0x1028fbe1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fbf6L : 0x1028fbf2L);
                break;
            }
            case 0x1028fbf2: {
                current = static_cast<FUN_10285dc0_State>(0x10290150L);
                break;
            }
            case 0x1028fbf6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fc02L : 0x1028fbfbL);
                break;
            }
            case 0x1028fbfb: {
                current = static_cast<FUN_10285dc0_State>(0x10290150L);
                break;
            }
            case 0x1028fc02: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fc1aL : 0x1028fc07L);
                break;
            }
            case 0x1028fc07: {
                current = static_cast<FUN_10285dc0_State>(0x10290150L);
                break;
            }
            case 0x1028fc1a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fc2eL : 0x1028fc1fL);
                break;
            }
            case 0x1028fc1f: {
                current = static_cast<FUN_10285dc0_State>(0x10290150L);
                break;
            }
            case 0x1028fc2e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028fc3aL : 0x1028fc33L);
                break;
            }
            case 0x1028fc33: {
                current = static_cast<FUN_10285dc0_State>(0x10290150L);
                break;
            }
            case 0x1028fc3a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10290150L : 0x1028fc3aL);
                break;
            }
            case 0x10290150: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10290161L));
                break;
            }
            case 0x10290161: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1029017eL : 0x1029016eL);
                break;
            }
            case 0x1029016e: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1029017eL));
                break;
            }
            case 0x1029017e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102902bfL : 0x10290182L);
                break;
            }
            case 0x10290182: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102902bfL : 0x10290194L);
                break;
            }
            case 0x10290194: {
                current = static_cast<FUN_10285dc0_State>(0x102902bfL);
                break;
            }
            case 0x102902bf: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102902d0L));
                break;
            }
            case 0x102902d0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102902eaL : 0x102902d5L);
                break;
            }
            case 0x102902d5: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102902eaL));
                break;
            }
            case 0x102902ea: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10290650L : 0x10290320L);
                break;
            }
            case 0x10290320: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10290650L : 0x1029035dL);
                break;
            }
            case 0x1029035d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10290650L : 0x10290369L);
                break;
            }
            case 0x10290369: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>(0x10290650L); // linear jump
                break;
            }
            case 0x10290650: {
                current = static_cast<FUN_10285dc0_State>(0x10290664L);
                break;
            }
            case 0x10290664: {
                return { current, false, false };
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
