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

RegionResult ProcessCoreLoopRegion_Case0(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        // Range check: does the current state belong to Region 1?
        if (classify_region(current) != 1) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x10285ed0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10285f1bL : 0x10285f11L);
                break;
            }
            case 0x10285f11: {
                current = static_cast<FUN_10285dc0_State>(0x10285f1eL);
                break;
            }
            case 0x10285f1b: {
                current = static_cast<FUN_10285dc0_State>(0x10285f1eL);
                break;
            }
            case 0x10285f1e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286a19L : 0x10285f45L);
                break;
            }
            case 0x10285f45: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // SINK: EXIT
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x1028606dL);
                else             current = static_cast<FUN_10285dc0_State>(0x10285fd5L);
                break;
            }
            case 0x10285fd5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028606dL : 0x10285fe7L);
                break;
            }
            case 0x10285fe7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286018L : 0x10285ffdL);
                break;
            }
            case 0x10285ffd: {
                current = static_cast<FUN_10285dc0_State>(0x10286001L);
                break;
            }
            case 0x10286001: {
                // Copy-loop head 1
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286012L));
                break;
            }
            case 0x10286012: {
                current = static_cast<FUN_10285dc0_State>(0x10286018L);
                break;
            }
            case 0x10286018: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286030L : 0x1028601cL);
                break;
            }
            case 0x1028601c: {
                current = static_cast<FUN_10285dc0_State>(0x10286020L);
                break;
            }
            case 0x10286020: {
                // Copy-loop head 2
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286030L));
                break;
            }
            case 0x10286030: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286067L : 0x10286035L);
                break;
            }
            case 0x10286035: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286067L : 0x10286047L);
                break;
            }
            case 0x10286047: {
                current = static_cast<FUN_10285dc0_State>(0x10286129L);
                break;
            }
            case 0x10286067: {
                current = static_cast<FUN_10285dc0_State>(0x1028606dL);
                break;
            }
            case 0x1028606d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028692cL : 0x10286090L);
                break;
            }
            case 0x10286090: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028692cL : 0x10286098L);
                break;
            }
            case 0x10286098: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028692cL : 0x102860a0L);
                break;
            }
            case 0x102860a0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102860d7L : 0x102860b6L);
                break;
            }
            case 0x102860b6: {
                current = static_cast<FUN_10285dc0_State>(0x102860c0L);
                break;
            }
            case 0x102860c0: {
                // Copy-loop head 3
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102860d1L));
                break;
            }
            case 0x102860d1: {
                current = static_cast<FUN_10285dc0_State>(0x102860d7L);
                break;
            }
            case 0x102860d7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102860f0L : 0x102860dbL);
                break;
            }
            case 0x102860db: {
                current = static_cast<FUN_10285dc0_State>(0x102860e0L);
                break;
            }
            case 0x102860e0: {
                // Copy-loop head 4
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x102860f0L));
                break;
            }
            case 0x102860f0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286165L : 0x102860f5L);
                break;
            }
            case 0x102860f5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286165L : 0x10286116L);
                break;
            }
            case 0x10286116: {
                current = static_cast<FUN_10285dc0_State>(0x10286126L);
                break;
            }
            case 0x10286126: {
                current = static_cast<FUN_10285dc0_State>(0x10286129L);
                break;
            }
            case 0x10286129: {
                current = static_cast<FUN_10285dc0_State>(0x1028612cL);
                break;
            }
            case 0x1028612c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286930L : 0x10286138L);
                break;
            }
            case 0x10286138: {
                current = static_cast<FUN_10285dc0_State>(0x10286145L);
                break;
            }
            case 0x10286145: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102862caL : 0x10286156L);
                break;
            }
            case 0x10286156: {
                current = static_cast<FUN_10285dc0_State>(0x102862ccL);
                break;
            }
            case 0x10286165: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286933L : 0x10286185L);
                break;
            }
            case 0x10286185: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102862bcL : 0x102861a7L);
                break;
            }
            case 0x102861a7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102862a4L : 0x102861c7L);
                break;
            }
            case 0x102861c7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286209L : 0x102861f1L);
                break;
            }
            case 0x102861f1: {
                current = static_cast<FUN_10285dc0_State>(0x102861f5L);
                break;
            }
            case 0x102861f5: {
                // Copy-loop head 5
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286206L));
                break;
            }
            case 0x10286206: {
                current = static_cast<FUN_10285dc0_State>(0x10286209L);
                break;
            }
            case 0x10286209: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028621dL : 0x1028620dL);
                break;
            }
            case 0x1028620d: {
                current = static_cast<FUN_10285dc0_State>(0x10286210L);
                break;
            }
            case 0x10286210: {
                // Copy-loop head 6
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028621dL));
                break;
            }
            case 0x1028621d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102862a1L : 0x1028622cL);
                break;
            }
            case 0x1028622c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102862a1L : 0x10286230L);
                break;
            }
            case 0x10286230: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103281d0L); // ERROR
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x102862a1L);
                else             current = static_cast<FUN_10285dc0_State>(0x10286263L);
                break;
            }
            case 0x10286263: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102862a7L : 0x10286287L);
                break;
            }
            case 0x10286287: {
                current = static_cast<FUN_10285dc0_State>(0x102862a9L);
                break;
            }
            case 0x102862a1: {
                current = static_cast<FUN_10285dc0_State>(0x102862a4L);
                break;
            }
            case 0x102862a4: {
                current = static_cast<FUN_10285dc0_State>(0x102862a7L);
                break;
            }
            case 0x102862a7: {
                current = static_cast<FUN_10285dc0_State>(0x102862a9L);
                break;
            }
            case 0x102862a9: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286126L : 0x102862b4L);
                break;
            }
            case 0x102862b4: {
                current = static_cast<FUN_10285dc0_State>(0x10286126L);
                break;
            }
            case 0x102862bc: {
                current = static_cast<FUN_10285dc0_State>(0x1028612cL);
                break;
            }
            case 0x102862ca: {
                current = static_cast<FUN_10285dc0_State>(0x102862ccL);
                break;
            }
            case 0x102862cc: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x102863daL);
                else             current = static_cast<FUN_10285dc0_State>(0x10286351L);
                break;
            }
            case 0x10286351: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102863daL : 0x10286364L);
                break;
            }
            case 0x10286364: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286394L : 0x1028637bL);
                break;
            }
            case 0x1028637b: {
                current = static_cast<FUN_10285dc0_State>(0x10286380L);
                break;
            }
            case 0x10286380: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286391L : 0x10286387L);
                break;
            }
            case 0x10286387: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286380L : 0x10286391L);
                break;
            }
            case 0x10286391: {
                current = static_cast<FUN_10285dc0_State>(0x10286394L);
                break;
            }
            case 0x10286394: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102863a8L : 0x10286398L);
                break;
            }
            case 0x10286398: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102863a8L : 0x1028639fL);
                break;
            }
            case 0x1028639f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286398L : 0x102863a8L);
                break;
            }
            case 0x102863a8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102863daL : 0x102863adL);
                break;
            }
            case 0x102863ad: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102863daL : 0x102863bfL);
                break;
            }
            case 0x102863bf: {
                current = static_cast<FUN_10285dc0_State>(0x102865f3L);
                break;
            }
            case 0x102863da: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865e2L : 0x1028640aL);
                break;
            }
            case 0x1028640a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865e2L : 0x10286412L);
                break;
            }
            case 0x10286412: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865e2L : 0x1028641aL);
                break;
            }
            case 0x1028641a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028644fL : 0x10286434L);
                break;
            }
            case 0x10286434: {
                current = static_cast<FUN_10285dc0_State>(0x10286438L);
                break;
            }
            case 0x10286438: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286449L : 0x1028643fL);
                break;
            }
            case 0x1028643f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286438L : 0x10286449L);
                break;
            }
            case 0x10286449: {
                current = static_cast<FUN_10285dc0_State>(0x1028644fL);
                break;
            }
            case 0x1028644f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286463L : 0x10286453L);
                break;
            }
            case 0x10286453: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286463L : 0x1028645aL);
                break;
            }
            case 0x1028645a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286453L : 0x10286463L);
                break;
            }
            case 0x10286463: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286496L : 0x10286468L);
                break;
            }
            case 0x10286468: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286496L : 0x10286489L);
                break;
            }
            case 0x10286489: {
                current = static_cast<FUN_10285dc0_State>(0x102865f0L);
                break;
            }
            case 0x10286496: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865eaL : 0x102864b4L);
                break;
            }
            case 0x102864b4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865eaL : 0x102864d6L);
                break;
            }
            case 0x102864d6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865d2L : 0x102864f3L);
                break;
            }
            case 0x102864f3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286531L : 0x10286510L);
                break;
            }
            case 0x10286510: {
                current = static_cast<FUN_10285dc0_State>(0x10286520L);
                break;
            }
            case 0x10286520: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286531L : 0x10286527L);
                break;
            }
            case 0x10286527: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286520L : 0x10286531L);
                break;
            }
            case 0x10286531: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286550L : 0x10286535L);
                break;
            }
            case 0x10286535: {
                current = static_cast<FUN_10285dc0_State>(0x10286540L);
                break;
            }
            case 0x10286540: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286550L : 0x1028654aL);
                break;
            }
            case 0x1028654a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286540L : 0x10286550L);
                break;
            }
            case 0x10286550: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865cfL : 0x1028655fL);
                break;
            }
            case 0x1028655f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865cfL : 0x10286563L);
                break;
            }
            case 0x10286563: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103281d0L); // ERROR
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x102865cfL);
                else             current = static_cast<FUN_10285dc0_State>(0x10286596L);
                break;
            }
            case 0x10286596: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865cfL : 0x102865b7L);
                break;
            }
            case 0x102865b7: {
                current = static_cast<FUN_10285dc0_State>(0x102865d9L);
                break;
            }
            case 0x102865cf: {
                current = static_cast<FUN_10285dc0_State>(0x102865d2L);
                break;
            }
            case 0x102865d2: {
                current = static_cast<FUN_10285dc0_State>(0x102865d9L);
                break;
            }
            case 0x102865d9: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102865f0L : 0x102865ddL);
                break;
            }
            case 0x102865dd: {
                current = static_cast<FUN_10285dc0_State>(0x102865f0L);
                break;
            }
            case 0x102865e2: {
                current = static_cast<FUN_10285dc0_State>(0x102865f3L);
                break;
            }
            case 0x102865ea: {
                current = static_cast<FUN_10285dc0_State>(0x102865f0L);
                break;
            }
            case 0x102865f0: {
                current = static_cast<FUN_10285dc0_State>(0x102865f3L);
                break;
            }
            case 0x102865f3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028663eL : 0x10286605L);
                break;
            }
            case 0x10286605: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286641L : 0x1028662bL);
                break;
            }
            case 0x1028662b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286641L : 0x10286633L);
                break;
            }
            case 0x10286633: {
                current = static_cast<FUN_10285dc0_State>(0x10286145L);
                break;
            }
            case 0x1028663e: {
                current = static_cast<FUN_10285dc0_State>(0x10286641L);
                break;
            }
            case 0x10286641: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102866c3L : 0x10286660L);
                break;
            }
            case 0x10286660: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286675L : 0x10286671L);
                break;
            }
            case 0x10286671: {
                current = static_cast<FUN_10285dc0_State>(0x102866c6L);
                break;
            }
            case 0x10286675: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286681L : 0x1028667aL);
                break;
            }
            case 0x1028667a: {
                current = static_cast<FUN_10285dc0_State>(0x102866c6L);
                break;
            }
            case 0x10286681: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286699L : 0x10286686L);
                break;
            }
            case 0x10286686: {
                current = static_cast<FUN_10285dc0_State>(0x102866c6L);
                break;
            }
            case 0x10286699: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102866adL : 0x1028669eL);
                break;
            }
            case 0x1028669e: {
                current = static_cast<FUN_10285dc0_State>(0x102866c6L);
                break;
            }
            case 0x102866ad: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102866b9L : 0x102866b2L);
                break;
            }
            case 0x102866b2: {
                current = static_cast<FUN_10285dc0_State>(0x102866c6L);
                break;
            }
            case 0x102866b9: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102866c6L : 0x102866c3L);
                break;
            }
            case 0x102866c3: {
                current = static_cast<FUN_10285dc0_State>(0x102866c6L);
                break;
            }
            case 0x102866c6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102866e4L : 0x102866caL);
                break;
            }
            case 0x102866ca: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102866e4L : 0x102866ceL);
                break;
            }
            case 0x102866ce: {
                current = static_cast<FUN_10285dc0_State>(0x102866e4L);
                break;
            }
            case 0x102866e4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028670bL : 0x10286707L);
                break;
            }
            case 0x10286707: {
                current = static_cast<FUN_10285dc0_State>(0x1028676fL);
                break;
            }
            case 0x1028670b: {
                current = static_cast<FUN_10285dc0_State>(0x1028676fL);
                break;
            }
            case 0x1028676f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286797L : 0x10286792L);
                break;
            }
            case 0x10286792: {
                current = static_cast<FUN_10285dc0_State>(0x102867e6L);
                break;
            }
            case 0x10286797: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102867b6L : 0x1028679fL);
                break;
            }
            case 0x1028679f: {
                current = static_cast<FUN_10285dc0_State>(0x102867e6L);
                break;
            }
            case 0x102867b6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102867ccL : 0x102867beL);
                break;
            }
            case 0x102867be: {
                current = static_cast<FUN_10285dc0_State>(0x102867e6L);
                break;
            }
            case 0x102867cc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102867dbL : 0x102867d4L);
                break;
            }
            case 0x102867d4: {
                current = static_cast<FUN_10285dc0_State>(0x102867e6L);
                break;
            }
            case 0x102867db: {
                current = static_cast<FUN_10285dc0_State>(0x102867e6L);
                break;
            }
            case 0x102867e6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102867f3L : 0x102867ebL);
                break;
            }
            case 0x102867eb: {
                current = static_cast<FUN_10285dc0_State>(0x1028682dL);
                break;
            }
            case 0x102867f3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286812L : 0x102867fbL);
                break;
            }
            case 0x102867fb: {
                current = static_cast<FUN_10285dc0_State>(0x1028682dL);
                break;
            }
            case 0x10286812: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286828L : 0x1028681aL);
                break;
            }
            case 0x1028681a: {
                current = static_cast<FUN_10285dc0_State>(0x1028682dL);
                break;
            }
            case 0x10286828: {
                current = static_cast<FUN_10285dc0_State>(0x1028682dL);
                break;
            }
            case 0x1028682d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286865L : 0x10286844L);
                break;
            }
            case 0x10286844: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286865L : 0x1028684aL);
                break;
            }
            case 0x1028684a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286865L : 0x10286850L);
                break;
            }
            case 0x10286850: {
                current = static_cast<FUN_10285dc0_State>(0x10286892L);
                break;
            }
            case 0x10286865: {
                current = static_cast<FUN_10285dc0_State>(0x10286892L);
                break;
            }
            case 0x10286892: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102868ecL : 0x102868ccL);
                break;
            }
            case 0x102868cc: {
                current = static_cast<FUN_10285dc0_State>(0x102868ecL);
                break;
            }
            case 0x102868ec: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286925L : 0x102868f0L);
                break;
            }
            case 0x102868f0: {
                current = static_cast<FUN_10285dc0_State>(0x102868f3L);
                break;
            }
            case 0x102868f3: {
                // Loop with max-iteration guard to prevent infinite loops
                size_t max_iters = 256;
                bool keep_looping = true;
                while (keep_looping && max_iters > 0) {
                    uint8_t b = read_byte(ctx);
                    if (b == 0) {
                        current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                        keep_looping = false;
                    } else if (b == 1) {
                        // self loop continue
                        max_iters--;
                    } else {
                        current = static_cast<FUN_10285dc0_State>(0x1028691fL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028691f: {
                current = static_cast<FUN_10285dc0_State>(0x10286925L);
                break;
            }
            case 0x10286925: {
                current = static_cast<FUN_10285dc0_State>(0x10286a01L);
                break;
            }
            case 0x1028692c: {
                current = static_cast<FUN_10285dc0_State>(0x10286933L);
                break;
            }
            case 0x10286930: {
                current = static_cast<FUN_10285dc0_State>(0x10286933L);
                break;
            }
            case 0x10286933: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286a07L : 0x1028694cL);
                break;
            }
            case 0x1028694c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102869b2L : 0x1028695cL);
                break;
            }
            case 0x1028695c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286a07L : 0x1028696cL);
                break;
            }
            case 0x1028696c: {
                current = static_cast<FUN_10285dc0_State>(0x10286980L);
                break;
            }
            case 0x10286980: {
                // Loop with max-iteration guard
                size_t max_iters = 256;
                bool keep_looping = true;
                while (keep_looping && max_iters > 0) {
                    uint8_t b = read_byte(ctx);
                    if (b == 0) {
                        current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                        keep_looping = false;
                    } else if (b == 1) {
                        // self loop continue
                        max_iters--;
                    } else {
                        current = static_cast<FUN_10285dc0_State>(0x102869b0L);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x102869b0: {
                current = static_cast<FUN_10285dc0_State>(0x10286a01L);
                break;
            }
            case 0x102869b2: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286a07L : 0x102869beL);
                break;
            }
            case 0x102869be: {
                current = static_cast<FUN_10285dc0_State>(0x102869d1L);
                break;
            }
            case 0x102869d1: {
                // Loop with max-iteration guard
                size_t max_iters = 256;
                bool keep_looping = true;
                while (keep_looping && max_iters > 0) {
                    uint8_t b = read_byte(ctx);
                    if (b == 0) {
                        current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                        keep_looping = false;
                    } else if (b == 1) {
                        // self loop continue
                        max_iters--;
                    } else {
                        current = static_cast<FUN_10285dc0_State>(0x10286a01L);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x10286a01: {
                current = static_cast<FUN_10285dc0_State>(0x10286a07L);
                break;
            }
            case 0x10286a07: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10285f45L : 0x10286a16L);
                break;
            }
            case 0x10286a16: {
                current = static_cast<FUN_10285dc0_State>(0x10286a19L);
                break;
            }
            case 0x10286a19: {
                // Region exit block
                return { current, false, false };
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
