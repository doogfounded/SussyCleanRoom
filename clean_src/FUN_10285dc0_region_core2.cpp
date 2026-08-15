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

RegionResult ProcessCoreLoopRegion_Case2(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 3) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x10287390: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102873dbL : 0x102873d1L);
                break;
            }
            case 0x102873d1: {
                current = static_cast<FUN_10285dc0_State>(0x102873deL);
                break;
            }
            case 0x102873db: {
                current = static_cast<FUN_10285dc0_State>(0x102873deL);
                break;
            }
            case 0x102873de: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287f9eL : 0x10287405L);
                break;
            }
            case 0x10287405: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x10287515L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028747dL);
                break;
            }
            case 0x1028747d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287515L : 0x1028748fL);
                break;
            }
            case 0x1028748f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102874c4L : 0x102874a8L);
                break;
            }
            case 0x102874a8: {
                current = static_cast<FUN_10285dc0_State>(0x102874b0L);
                break;
            }
            case 0x102874b0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102874c1L));
                break;
            }
            case 0x102874c1: {
                current = static_cast<FUN_10285dc0_State>(0x102874c4L);
                break;
            }
            case 0x102874c4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102874d8L : 0x102874c8L);
                break;
            }
            case 0x102874c8: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102874d8L));
                break;
            }
            case 0x102874d8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287515L : 0x102874e0L);
                break;
            }
            case 0x102874e0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287515L : 0x102874f2L);
                break;
            }
            case 0x102874f2: {
                current = static_cast<FUN_10285dc0_State>(0x10287518L);
                break;
            }
            case 0x10287515: {
                current = static_cast<FUN_10285dc0_State>(0x10287518L);
                break;
            }
            case 0x10287518: {
                current = static_cast<FUN_10285dc0_State>(0x10287544L);
                break;
            }
            case 0x10287544: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028761bL : 0x10287570L);
                break;
            }
            case 0x10287570: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028761bL : 0x10287578L);
                break;
            }
            case 0x10287578: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028761bL : 0x10287581L);
                break;
            }
            case 0x10287581: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102875b7L : 0x1028759aL);
                break;
            }
            case 0x1028759a: {
                current = static_cast<FUN_10285dc0_State>(0x102875a0L);
                break;
            }
            case 0x102875a0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102875b1L));
                break;
            }
            case 0x102875b1: {
                current = static_cast<FUN_10285dc0_State>(0x102875b7L);
                break;
            }
            case 0x102875b7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102875d0L : 0x102875bbL);
                break;
            }
            case 0x102875bb: {
                current = static_cast<FUN_10285dc0_State>(0x102875c0L);
                break;
            }
            case 0x102875c0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102875d0L));
                break;
            }
            case 0x102875d0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287618L : 0x102875d8L);
                break;
            }
            case 0x102875d8: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x10287670L);
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x102875faL);
                else             current = static_cast<FUN_10285dc0_State>(0x1028761eL);
                break;
            }
            case 0x102875fa: {
                current = static_cast<FUN_10285dc0_State>(0x1028761eL);
                break;
            }
            case 0x10287618: {
                current = static_cast<FUN_10285dc0_State>(0x1028761bL);
                break;
            }
            case 0x1028761b: {
                current = static_cast<FUN_10285dc0_State>(0x1028761eL);
                break;
            }
            case 0x1028761e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287544L : 0x1028762eL);
                break;
            }
            case 0x1028762e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102877abL : 0x1028764dL);
                break;
            }
            case 0x1028764d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102877abL : 0x10287657L);
                break;
            }
            case 0x10287657: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028779dL : 0x10287668L);
                break;
            }
            case 0x10287668: {
                current = static_cast<FUN_10285dc0_State>(0x10287678L);
                break;
            }
            case 0x10287670: {
                current = static_cast<FUN_10285dc0_State>(0x1028761eL);
                break;
            }
            case 0x10287675: {
                current = static_cast<FUN_10285dc0_State>(0x10287678L);
                break;
            }
            case 0x10287678: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287775L : 0x102876bcL);
                break;
            }
            case 0x102876bc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287775L : 0x102876d6L);
                break;
            }
            case 0x102876d6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287775L : 0x102876dfL);
                break;
            }
            case 0x102876df: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287775L : 0x102876edL);
                break;
            }
            case 0x102876ed: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287729L : 0x1028770cL);
                break;
            }
            case 0x1028770c: {
                current = static_cast<FUN_10285dc0_State>(0x10287712L);
                break;
            }
            case 0x10287712: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10287723L));
                break;
            }
            case 0x10287723: {
                current = static_cast<FUN_10285dc0_State>(0x10287729L);
                break;
            }
            case 0x10287729: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028773dL : 0x1028772dL);
                break;
            }
            case 0x1028772d: {
                current = static_cast<FUN_10285dc0_State>(0x10287730L);
                break;
            }
            case 0x10287730: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028773dL));
                break;
            }
            case 0x1028773d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287772L : 0x10287742L);
                break;
            }
            case 0x10287742: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287772L : 0x10287747L);
                break;
            }
            case 0x10287747: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287772L : 0x10287769L);
                break;
            }
            case 0x10287769: {
                current = static_cast<FUN_10285dc0_State>(0x10287772L);
                break;
            }
            case 0x10287772: {
                current = static_cast<FUN_10285dc0_State>(0x10287775L);
                break;
            }
            case 0x10287775: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287675L : 0x10287792L);
                break;
            }
            case 0x10287792: {
                current = static_cast<FUN_10285dc0_State>(0x102877b1L);
                break;
            }
            case 0x1028779d: {
                current = static_cast<FUN_10285dc0_State>(0x102877b1L);
                break;
            }
            case 0x102877ab: {
                current = static_cast<FUN_10285dc0_State>(0x102877b1L);
                break;
            }
            case 0x102877b1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287ea7L : 0x102877beL);
                break;
            }
            case 0x102877be: {
                current = static_cast<FUN_10285dc0_State>(0x102877cbL);
                break;
            }
            case 0x102877cb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102877e8L : 0x102877dbL);
                break;
            }
            case 0x102877db: {
                current = static_cast<FUN_10285dc0_State>(0x102877eaL);
                break;
            }
            case 0x102877e8: {
                current = static_cast<FUN_10285dc0_State>(0x102877eaL);
                break;
            }
            case 0x102877ea: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x102878fbL);
                else             current = static_cast<FUN_10285dc0_State>(0x1028785aL);
                break;
            }
            case 0x1028785a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102878fbL : 0x1028786eL);
                break;
            }
            case 0x1028786e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102878a4L : 0x10287886L);
                break;
            }
            case 0x10287886: {
                current = static_cast<FUN_10285dc0_State>(0x10287890L);
                break;
            }
            case 0x10287890: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102878a1L));
                break;
            }
            case 0x102878a1: {
                current = static_cast<FUN_10285dc0_State>(0x102878a4L);
                break;
            }
            case 0x102878a4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102878b8L : 0x102878a8L);
                break;
            }
            case 0x102878a8: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102878b8L));
                break;
            }
            case 0x102878b8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102878f8L : 0x102878c0L);
                break;
            }
            case 0x102878c0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102878f8L : 0x102878d2L);
                break;
            }
            case 0x102878d2: {
                current = static_cast<FUN_10285dc0_State>(0x102878feL);
                break;
            }
            case 0x102878f8: {
                current = static_cast<FUN_10285dc0_State>(0x102878fbL);
                break;
            }
            case 0x102878fb: {
                current = static_cast<FUN_10285dc0_State>(0x102878feL);
                break;
            }
            case 0x102878fe: {
                current = static_cast<FUN_10285dc0_State>(0x10287930L);
                break;
            }
            case 0x10287930: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102879fdL : 0x10287959L);
                break;
            }
            case 0x10287959: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102879fdL : 0x10287961L);
                break;
            }
            case 0x10287961: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102879fdL : 0x1028796aL);
                break;
            }
            case 0x1028796a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028799eL : 0x10287983L);
                break;
            }
            case 0x10287983: {
                current = static_cast<FUN_10285dc0_State>(0x10287987L);
                break;
            }
            case 0x10287987: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10287998L));
                break;
            }
            case 0x10287998: {
                current = static_cast<FUN_10285dc0_State>(0x1028799eL);
                break;
            }
            case 0x1028799e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102879b2L : 0x102879a2L);
                break;
            }
            case 0x102879a2: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102879b2L));
                break;
            }
            case 0x102879b2: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102879faL : 0x102879baL);
                break;
            }
            case 0x102879ba: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102879faL : 0x102879d9L);
                break;
            }
            case 0x102879d9: {
                current = static_cast<FUN_10285dc0_State>(0x102879fdL);
                break;
            }
            case 0x102879fa: {
                current = static_cast<FUN_10285dc0_State>(0x102879fdL);
                break;
            }
            case 0x102879fd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287930L : 0x10287a10L);
                break;
            }
            case 0x10287a10: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b78L : 0x10287a2eL);
                break;
            }
            case 0x10287a2e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b78L : 0x10287a38L);
                break;
            }
            case 0x10287a38: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b6dL : 0x10287a49L);
                break;
            }
            case 0x10287a49: {
                current = static_cast<FUN_10285dc0_State>(0x10287a54L);
                break;
            }
            case 0x10287a51: {
                current = static_cast<FUN_10285dc0_State>(0x10287a54L);
                break;
            }
            case 0x10287a54: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b50L : 0x10287a9bL);
                break;
            }
            case 0x10287a9b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b50L : 0x10287ab5L);
                break;
            }
            case 0x10287ab5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b50L : 0x10287abeL);
                break;
            }
            case 0x10287abe: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b4dL : 0x10287acfL);
                break;
            }
            case 0x10287acf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b04L : 0x10287aecL);
                break;
            }
            case 0x10287aec: {
                current = static_cast<FUN_10285dc0_State>(0x10287af0L);
                break;
            }
            case 0x10287af0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10287b04L));
                break;
            }
            case 0x10287b04: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b15L : 0x10287b08L);
                break;
            }
            case 0x10287b08: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10287b15L));
                break;
            }
            case 0x10287b15: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b4dL : 0x10287b1dL);
                break;
            }
            case 0x10287b1d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b4dL : 0x10287b22L);
                break;
            }
            case 0x10287b22: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287b4dL : 0x10287b44L);
                break;
            }
            case 0x10287b44: {
                current = static_cast<FUN_10285dc0_State>(0x10287b4dL);
                break;
            }
            case 0x10287b4d: {
                current = static_cast<FUN_10285dc0_State>(0x10287b50L);
                break;
            }
            case 0x10287b50: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287a51L : 0x10287b6aL);
                break;
            }
            case 0x10287b6a: {
                current = static_cast<FUN_10285dc0_State>(0x10287b6dL);
                break;
            }
            case 0x10287b6d: {
                current = static_cast<FUN_10285dc0_State>(0x10287b7bL);
                break;
            }
            case 0x10287b78: {
                current = static_cast<FUN_10285dc0_State>(0x10287b7bL);
                break;
            }
            case 0x10287b7b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287bbfL : 0x10287b8dL);
                break;
            }
            case 0x10287b8d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287bbfL : 0x10287bb3L);
                break;
            }
            case 0x10287bb3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102877cbL : 0x10287bbfL);
                break;
            }
            case 0x10287bbf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287c44L : 0x10287be1L);
                break;
            }
            case 0x10287be1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287bf6L : 0x10287bf2L);
                break;
            }
            case 0x10287bf2: {
                current = static_cast<FUN_10285dc0_State>(0x10287c47L);
                break;
            }
            case 0x10287bf6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287c02L : 0x10287bfbL);
                break;
            }
            case 0x10287bfb: {
                current = static_cast<FUN_10285dc0_State>(0x10287c47L);
                break;
            }
            case 0x10287c02: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287c1aL : 0x10287c07L);
                break;
            }
            case 0x10287c07: {
                current = static_cast<FUN_10285dc0_State>(0x10287c47L);
                break;
            }
            case 0x10287c1a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287c2eL : 0x10287c1fL);
                break;
            }
            case 0x10287c1f: {
                current = static_cast<FUN_10285dc0_State>(0x10287c47L);
                break;
            }
            case 0x10287c2e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287c3aL : 0x10287c33L);
                break;
            }
            case 0x10287c33: {
                current = static_cast<FUN_10285dc0_State>(0x10287c47L);
                break;
            }
            case 0x10287c3a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287c47L : 0x10287c44L);
                break;
            }
            case 0x10287c44: {
                current = static_cast<FUN_10285dc0_State>(0x10287c47L);
                break;
            }
            case 0x10287c47: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287c65L : 0x10287c4bL);
                break;
            }
            case 0x10287c4b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287c65L : 0x10287c4fL);
                break;
            }
            case 0x10287c4f: {
                current = static_cast<FUN_10285dc0_State>(0x10287c65L);
                break;
            }
            case 0x10287c65: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287c81L : 0x10287c7dL);
                break;
            }
            case 0x10287c7d: {
                current = static_cast<FUN_10285dc0_State>(0x10287ce5L);
                break;
            }
            case 0x10287c81: {
                current = static_cast<FUN_10285dc0_State>(0x10287ce5L);
                break;
            }
            case 0x10287ce5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287d08L : 0x10287d03L);
                break;
            }
            case 0x10287d03: {
                current = static_cast<FUN_10285dc0_State>(0x10287d57L);
                break;
            }
            case 0x10287d08: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287d27L : 0x10287d10L);
                break;
            }
            case 0x10287d10: {
                current = static_cast<FUN_10285dc0_State>(0x10287d57L);
                break;
            }
            case 0x10287d27: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287d3dL : 0x10287d2fL);
                break;
            }
            case 0x10287d2f: {
                current = static_cast<FUN_10285dc0_State>(0x10287d57L);
                break;
            }
            case 0x10287d3d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287d4cL : 0x10287d45L);
                break;
            }
            case 0x10287d45: {
                current = static_cast<FUN_10285dc0_State>(0x10287d57L);
                break;
            }
            case 0x10287d4c: {
                current = static_cast<FUN_10285dc0_State>(0x10287d57L);
                break;
            }
            case 0x10287d57: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287d64L : 0x10287d5cL);
                break;
            }
            case 0x10287d5c: {
                current = static_cast<FUN_10285dc0_State>(0x10287d9eL);
                break;
            }
            case 0x10287d64: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287d83L : 0x10287d6cL);
                break;
            }
            case 0x10287d6c: {
                current = static_cast<FUN_10285dc0_State>(0x10287d9eL);
                break;
            }
            case 0x10287d83: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287d99L : 0x10287d8bL);
                break;
            }
            case 0x10287d8b: {
                current = static_cast<FUN_10285dc0_State>(0x10287d9eL);
                break;
            }
            case 0x10287d99: {
                current = static_cast<FUN_10285dc0_State>(0x10287d9eL);
                break;
            }
            case 0x10287d9e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287dd6L : 0x10287db5L);
                break;
            }
            case 0x10287db5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287dd6L : 0x10287dbbL);
                break;
            }
            case 0x10287dbb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287dd6L : 0x10287dc1L);
                break;
            }
            case 0x10287dc1: {
                current = static_cast<FUN_10285dc0_State>(0x10287e03L);
                break;
            }
            case 0x10287dd6: {
                current = static_cast<FUN_10285dc0_State>(0x10287e03L);
                break;
            }
            case 0x10287e03: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287e5dL : 0x10287e3dL);
                break;
            }
            case 0x10287e3d: {
                current = static_cast<FUN_10285dc0_State>(0x10287e5dL);
                break;
            }
            case 0x10287e5d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287e9dL : 0x10287e61L);
                break;
            }
            case 0x10287e61: {
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
                        current = static_cast<FUN_10285dc0_State>(0x10287e9aL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x10287e9a: {
                current = static_cast<FUN_10285dc0_State>(0x10287e9dL);
                break;
            }
            case 0x10287e9d: {
                current = static_cast<FUN_10285dc0_State>(0x10287f8aL);
                break;
            }
            case 0x10287ea7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287f8dL : 0x10287ebdL);
                break;
            }
            case 0x10287ebd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287f2cL : 0x10287ecdL);
                break;
            }
            case 0x10287ecd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287f8dL : 0x10287eddL);
                break;
            }
            case 0x10287edd: {
                current = static_cast<FUN_10285dc0_State>(0x10287ef0L);
                break;
            }
            case 0x10287ef0: {
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
                        current = static_cast<FUN_10285dc0_State>(0x10287f2aL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x10287f2a: {
                current = static_cast<FUN_10285dc0_State>(0x10287f8aL);
                break;
            }
            case 0x10287f2c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287f8dL : 0x10287f38L);
                break;
            }
            case 0x10287f38: {
                current = static_cast<FUN_10285dc0_State>(0x10287f50L);
                break;
            }
            case 0x10287f50: {
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
                        current = static_cast<FUN_10285dc0_State>(0x10287f8aL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x10287f8a: {
                current = static_cast<FUN_10285dc0_State>(0x10287f8dL);
                break;
            }
            case 0x10287f8d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287405L : 0x10287f9eL);
                break;
            }
            case 0x10287f9e: {
                return { current, false, false };
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
