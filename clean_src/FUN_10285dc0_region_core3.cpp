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

RegionResult ProcessCoreLoopRegion_Case3(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 4) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x10287fc0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288020L : 0x10288016L);
                break;
            }
            case 0x10288016: {
                current = static_cast<FUN_10285dc0_State>(0x10288023L);
                break;
            }
            case 0x10288020: {
                current = static_cast<FUN_10285dc0_State>(0x10288023L);
                break;
            }
            case 0x10288023: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288bedL : 0x1028804dL);
                break;
            }
            case 0x1028804d: {
                current = static_cast<FUN_10285dc0_State>(0x10288070L);
                break;
            }
            case 0x10288070: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x102881b0L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028810eL);
                break;
            }
            case 0x1028810e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102881b0L : 0x1028811dL);
                break;
            }
            case 0x1028811d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288157L : 0x10288139L);
                break;
            }
            case 0x10288139: {
                current = static_cast<FUN_10285dc0_State>(0x10288140L);
                break;
            }
            case 0x10288140: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288151L));
                break;
            }
            case 0x10288151: {
                current = static_cast<FUN_10285dc0_State>(0x10288157L);
                break;
            }
            case 0x10288157: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288170L : 0x1028815bL);
                break;
            }
            case 0x1028815b: {
                current = static_cast<FUN_10285dc0_State>(0x10288160L);
                break;
            }
            case 0x10288160: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288170L));
                break;
            }
            case 0x10288170: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102881b0L : 0x10288178L);
                break;
            }
            case 0x10288178: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102881b0L : 0x1028818aL);
                break;
            }
            case 0x1028818a: {
                current = static_cast<FUN_10285dc0_State>(0x102881b0L);
                break;
            }
            case 0x102881b0: {
                current = static_cast<FUN_10285dc0_State>(0x102881f0L);
                break;
            }
            case 0x102881f0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102882d1L : 0x1028821fL);
                break;
            }
            case 0x1028821f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102882d1L : 0x10288227L);
                break;
            }
            case 0x10288227: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102882d1L : 0x10288230L);
                break;
            }
            case 0x10288230: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028826aL : 0x1028824fL);
                break;
            }
            case 0x1028824f: {
                current = static_cast<FUN_10285dc0_State>(0x10288253L);
                break;
            }
            case 0x10288253: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288264L));
                break;
            }
            case 0x10288264: {
                current = static_cast<FUN_10285dc0_State>(0x1028826aL);
                break;
            }
            case 0x1028826a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288280L : 0x1028826eL);
                break;
            }
            case 0x1028826e: {
                current = static_cast<FUN_10285dc0_State>(0x10288270L);
                break;
            }
            case 0x10288270: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288280L));
                break;
            }
            case 0x10288280: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102882ceL : 0x10288285L);
                break;
            }
            case 0x10288285: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028843aL : 0x102882aeL);
                break;
            }
            case 0x102882ae: {
                current = static_cast<FUN_10285dc0_State>(0x102882d7L);
                break;
            }
            case 0x102882ce: {
                current = static_cast<FUN_10285dc0_State>(0x102882d1L);
                break;
            }
            case 0x102882d1: {
                current = static_cast<FUN_10285dc0_State>(0x102882d4L);
                break;
            }
            case 0x102882d4: {
                current = static_cast<FUN_10285dc0_State>(0x102882d7L);
                break;
            }
            case 0x102882d7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102881f0L : 0x102882e7L);
                break;
            }
            case 0x102882e7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288451L : 0x102882f6L);
                break;
            }
            case 0x102882f6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288451L : 0x10288313L);
                break;
            }
            case 0x10288313: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288451L : 0x10288332L);
                break;
            }
            case 0x10288332: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288445L : 0x10288352L);
                break;
            }
            case 0x10288352: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028839bL : 0x1028837fL);
                break;
            }
            case 0x1028837f: {
                current = static_cast<FUN_10285dc0_State>(0x10288387L);
                break;
            }
            case 0x10288387: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288398L));
                break;
            }
            case 0x10288398: {
                current = static_cast<FUN_10285dc0_State>(0x1028839bL);
                break;
            }
            case 0x1028839b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102883b7L : 0x1028839fL);
                break;
            }
            case 0x1028839f: {
                current = static_cast<FUN_10285dc0_State>(0x102883a2L);
                break;
            }
            case 0x102883a2: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102883b7L));
                break;
            }
            case 0x102883b7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288442L : 0x102883c6L);
                break;
            }
            case 0x102883c6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288442L : 0x102883caL);
                break;
            }
            case 0x102883ca: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103281dL); // ERROR
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x10288442L);
                else             current = static_cast<FUN_10285dc0_State>(0x10288400L);
                break;
            }
            case 0x10288400: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288445L : 0x10288422L);
                break;
            }
            case 0x10288422: {
                current = static_cast<FUN_10285dc0_State>(0x10288447L);
                break;
            }
            case 0x1028843a: {
                current = static_cast<FUN_10285dc0_State>(0x102882d4L);
                break;
            }
            case 0x10288442: {
                current = static_cast<FUN_10285dc0_State>(0x10288445L);
                break;
            }
            case 0x10288445: {
                current = static_cast<FUN_10285dc0_State>(0x10288447L);
                break;
            }
            case 0x10288447: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288451L : 0x1028844eL);
                break;
            }
            case 0x1028844e: {
                current = static_cast<FUN_10285dc0_State>(0x10288451L);
                break;
            }
            case 0x10288451: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288c0dL : 0x10288470L);
                break;
            }
            case 0x10288470: {
                current = static_cast<FUN_10285dc0_State>(0x10288477L);
                break;
            }
            case 0x10288477: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288491L : 0x10288484L);
                break;
            }
            case 0x10288484: {
                current = static_cast<FUN_10285dc0_State>(0x10288493L);
                break;
            }
            case 0x10288491: {
                current = static_cast<FUN_10285dc0_State>(0x10288493L);
                break;
            }
            case 0x10288493: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x102885d0L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028852cL);
                break;
            }
            case 0x1028852c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102885d0L : 0x10288541L);
                break;
            }
            case 0x10288541: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028857bL : 0x10288560L);
                break;
            }
            case 0x10288560: {
                current = static_cast<FUN_10285dc0_State>(0x10288564L);
                break;
            }
            case 0x10288564: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288575L));
                break;
            }
            case 0x10288575: {
                current = static_cast<FUN_10285dc0_State>(0x1028857bL);
                break;
            }
            case 0x1028857b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288590L : 0x1028857fL);
                break;
            }
            case 0x1028857f: {
                current = static_cast<FUN_10285dc0_State>(0x10288580L);
                break;
            }
            case 0x10288580: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288590L));
                break;
            }
            case 0x10288590: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102885d0L : 0x10288595L);
                break;
            }
            case 0x10288595: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102885d0L : 0x102885a7L);
                break;
            }
            case 0x102885a7: {
                current = static_cast<FUN_10285dc0_State>(0x102885d0L);
                break;
            }
            case 0x102885d0: {
                current = static_cast<FUN_10285dc0_State>(0x10288610L);
                break;
            }
            case 0x10288610: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102886f1L : 0x1028863fL);
                break;
            }
            case 0x1028863f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102886f1L : 0x10288647L);
                break;
            }
            case 0x10288647: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102886f1L : 0x10288650L);
                break;
            }
            case 0x10288650: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288688L : 0x1028866dL);
                break;
            }
            case 0x1028866d: {
                current = static_cast<FUN_10285dc0_State>(0x10288671L);
                break;
            }
            case 0x10288671: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10288682L));
                break;
            }
            case 0x10288682: {
                current = static_cast<FUN_10285dc0_State>(0x10288688L);
                break;
            }
            case 0x10288688: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102886a0L : 0x1028868cL);
                break;
            }
            case 0x1028868c: {
                current = static_cast<FUN_10285dc0_State>(0x10288690L);
                break;
            }
            case 0x10288690: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102886a0L));
                break;
            }
            case 0x102886a0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102886eeL : 0x102886a5L);
                break;
            }
            case 0x102886a5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288859L : 0x102886ceL);
                break;
            }
            case 0x102886ce: {
                current = static_cast<FUN_10285dc0_State>(0x102886f7L);
                break;
            }
            case 0x102886ee: {
                current = static_cast<FUN_10285dc0_State>(0x102886f1L);
                break;
            }
            case 0x102886f1: {
                current = static_cast<FUN_10285dc0_State>(0x102886f4L);
                break;
            }
            case 0x102886f4: {
                current = static_cast<FUN_10285dc0_State>(0x102886f7L);
                break;
            }
            case 0x102886f7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288610L : 0x10288707L);
                break;
            }
            case 0x10288707: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288872L : 0x10288713L);
                break;
            }
            case 0x10288713: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288872L : 0x10288730L);
                break;
            }
            case 0x10288730: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288872L : 0x10288752L);
                break;
            }
            case 0x10288752: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288864L : 0x1028876fL);
                break;
            }
            case 0x1028876f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102887b8L : 0x1028879cL);
                break;
            }
            case 0x1028879c: {
                current = static_cast<FUN_10285dc0_State>(0x102887a4L);
                break;
            }
            case 0x102887a4: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102887b5L));
                break;
            }
            case 0x102887b5: {
                current = static_cast<FUN_10285dc0_State>(0x102887b8L);
                break;
            }
            case 0x102887b8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102887d5L : 0x102887bcL);
                break;
            }
            case 0x102887bc: {
                current = static_cast<FUN_10285dc0_State>(0x102887c0L);
                break;
            }
            case 0x102887c0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102887d5L));
                break;
            }
            case 0x102887d5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288861L : 0x102887e4L);
                break;
            }
            case 0x102887e4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288861L : 0x102887e8L);
                break;
            }
            case 0x102887e8: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103281d0L); // ERROR
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x10288861L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028881eL);
                break;
            }
            case 0x1028881e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288861L : 0x1028883fL);
                break;
            }
            case 0x1028883f: {
                current = static_cast<FUN_10285dc0_State>(0x10288869L);
                break;
            }
            case 0x10288859: {
                current = static_cast<FUN_10285dc0_State>(0x102886f4L);
                break;
            }
            case 0x10288861: {
                current = static_cast<FUN_10285dc0_State>(0x10288864L);
                break;
            }
            case 0x10288864: {
                current = static_cast<FUN_10285dc0_State>(0x10288869L);
                break;
            }
            case 0x10288869: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288875L : 0x1028886dL);
                break;
            }
            case 0x1028886d: {
                current = static_cast<FUN_10285dc0_State>(0x10288875L);
                break;
            }
            case 0x10288872: {
                current = static_cast<FUN_10285dc0_State>(0x10288875L);
                break;
            }
            case 0x10288875: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102888ccL : 0x10288893L);
                break;
            }
            case 0x10288893: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102888ccL : 0x102888bcL);
                break;
            }
            case 0x102888bc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102888ccL : 0x102888c4L);
                break;
            }
            case 0x102888c4: {
                current = static_cast<FUN_10285dc0_State>(0x10288477L);
                break;
            }
            case 0x102888cc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288951L : 0x102888eeL);
                break;
            }
            case 0x102888ee: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288903L : 0x102888ffL);
                break;
            }
            case 0x102888ff: {
                current = static_cast<FUN_10285dc0_State>(0x10288954L);
                break;
            }
            case 0x10288903: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028890fL : 0x10288908L);
                break;
            }
            case 0x10288908: {
                current = static_cast<FUN_10285dc0_State>(0x10288954L);
                break;
            }
            case 0x1028890f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288927L : 0x10288914L);
                break;
            }
            case 0x10288914: {
                current = static_cast<FUN_10285dc0_State>(0x10288954L);
                break;
            }
            case 0x10288927: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028893bL : 0x1028892cL);
                break;
            }
            case 0x1028892c: {
                current = static_cast<FUN_10285dc0_State>(0x10288954L);
                break;
            }
            case 0x1028893b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288947L : 0x10288940L);
                break;
            }
            case 0x10288940: {
                current = static_cast<FUN_10285dc0_State>(0x10288954L);
                break;
            }
            case 0x10288947: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288954L : 0x10288951L);
                break;
            }
            case 0x10288951: {
                current = static_cast<FUN_10285dc0_State>(0x10288954L);
                break;
            }
            case 0x10288954: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288972L : 0x10288958L);
                break;
            }
            case 0x10288958: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288972L : 0x1028895cL);
                break;
            }
            case 0x1028895c: {
                current = static_cast<FUN_10285dc0_State>(0x10288972L);
                break;
            }
            case 0x10288972: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028899aL : 0x10288996L);
                break;
            }
            case 0x10288996: {
                current = static_cast<FUN_10285dc0_State>(0x10288a06L);
                break;
            }
            case 0x1028899a: {
                current = static_cast<FUN_10285dc0_State>(0x10288a06L);
                break;
            }
            case 0x10288a06: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288a30L : 0x10288a2bL);
                break;
            }
            case 0x10288a2b: {
                current = static_cast<FUN_10285dc0_State>(0x10288a7fL);
                break;
            }
            case 0x10288a30: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288a4fL : 0x10288a38L);
                break;
            }
            case 0x10288a38: {
                current = static_cast<FUN_10285dc0_State>(0x10288a7fL);
                break;
            }
            case 0x10288a4f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288a65L : 0x10288a57L);
                break;
            }
            case 0x10288a57: {
                current = static_cast<FUN_10285dc0_State>(0x10288a7fL);
                break;
            }
            case 0x10288a65: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288a74L : 0x10288a6dL);
                break;
            }
            case 0x10288a6d: {
                current = static_cast<FUN_10285dc0_State>(0x10288a7fL);
                break;
            }
            case 0x10288a74: {
                current = static_cast<FUN_10285dc0_State>(0x10288a7fL);
                break;
            }
            case 0x10288a7f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288a8cL : 0x10288a84L);
                break;
            }
            case 0x10288a84: {
                current = static_cast<FUN_10285dc0_State>(0x10288ac6L);
                break;
            }
            case 0x10288a8c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288aabL : 0x10288a94L);
                break;
            }
            case 0x10288a94: {
                current = static_cast<FUN_10285dc0_State>(0x10288ac6L);
                break;
            }
            case 0x10288aab: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288ac1L : 0x10288ab3L);
                break;
            }
            case 0x10288ab3: {
                current = static_cast<FUN_10285dc0_State>(0x10288ac6L);
                break;
            }
            case 0x10288ac1: {
                current = static_cast<FUN_10285dc0_State>(0x10288ac6L);
                break;
            }
            case 0x10288ac6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288b00L : 0x10288adfL);
                break;
            }
            case 0x10288adf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288b00L : 0x10288ae5L);
                break;
            }
            case 0x10288ae5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288b00L : 0x10288aebL);
                break;
            }
            case 0x10288aeb: {
                current = static_cast<FUN_10285dc0_State>(0x10288b2dL);
                break;
            }
            case 0x10288b00: {
                current = static_cast<FUN_10285dc0_State>(0x10288b2dL);
                break;
            }
            case 0x10288b2d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288b8aL : 0x10288b69L);
                break;
            }
            case 0x10288b69: {
                current = static_cast<FUN_10285dc0_State>(0x10288b8aL);
                break;
            }
            case 0x10288b8a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288bccL : 0x10288b8eL);
                break;
            }
            case 0x10288b8e: {
                current = static_cast<FUN_10285dc0_State>(0x10288b90L);
                break;
            }
            case 0x10288b90: {
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
                        current = static_cast<FUN_10285dc0_State>(0x10288bccL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x10288bcc: {
                current = static_cast<FUN_10285dc0_State>(0x10288bd5L);
                break;
            }
            case 0x10288bd5: {
                current = static_cast<FUN_10285dc0_State>(0x10288bd8L);
                break;
            }
            case 0x10288bd8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288070L : 0x10288be7L);
                break;
            }
            case 0x10288be7: {
                current = static_cast<FUN_10285dc0_State>(0x10288bedL);
                break;
            }
            case 0x10288bed: {
                // Region exit state
                return { current, false, false };
            }
            case 0x10288c0d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288bd5L : 0x10288c20L);
                break;
            }
            case 0x10288c20: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288c94L : 0x10288c33L);
                break;
            }
            case 0x10288c33: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288bd8L : 0x10288c3fL);
                break;
            }
            case 0x10288c3f: {
                current = static_cast<FUN_10285dc0_State>(0x10288c50L);
                break;
            }
            case 0x10288c50: {
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
                        current = static_cast<FUN_10285dc0_State>(0x10288c8fL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x10288c8f: {
                current = static_cast<FUN_10285dc0_State>(0x10288bd8L);
                break;
            }
            case 0x10288c94: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10288bd8L : 0x10288ca4L);
                break;
            }
            case 0x10288ca4: {
                current = static_cast<FUN_10285dc0_State>(0x10288cc0L);
                break;
            }
            case 0x10288cc0: {
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
                        current = static_cast<FUN_10285dc0_State>(0x10288cffL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x10288cff: {
                current = static_cast<FUN_10285dc0_State>(0x10288bd8L);
                break;
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
