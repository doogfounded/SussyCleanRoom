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

RegionResult ProcessCoreLoopRegion_Case7(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 8) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x1028bdf0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028be3eL : 0x1028be34L);
                break;
            }
            case 0x1028be34: {
                current = static_cast<FUN_10285dc0_State>(0x1028be41L);
                break;
            }
            case 0x1028be3e: {
                current = static_cast<FUN_10285dc0_State>(0x1028be41L);
                break;
            }
            case 0x1028be41: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bebaL : 0x1028be65L);
                break;
            }
            case 0x1028be65: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bebaL : 0x1028be93L);
                break;
            }
            case 0x1028be93: {
                current = static_cast<FUN_10285dc0_State>(0x1028bebaL);
                break;
            }
            case 0x1028beba: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ccf8L : 0x1028bec8L);
                break;
            }
            case 0x1028bec8: {
                current = static_cast<FUN_10285dc0_State>(0x1028bed0L);
                break;
            }
            case 0x1028bed0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bff0L : 0x1028bf34L);
                break;
            }
            case 0x1028bf34: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bfddL : 0x1028bf4bL);
                break;
            }
            case 0x1028bf4b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bfddL : 0x1028bf53L);
                break;
            }
            case 0x1028bf53: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bfddL : 0x1028bf60L);
                break;
            }
            case 0x1028bf60: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bfddL : 0x1028bf67L);
                break;
            }
            case 0x1028bf67: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bfd7L : 0x1028bf78L);
                break;
            }
            case 0x1028bf78: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bfaaL : 0x1028bf92L);
                break;
            }
            case 0x1028bf92: {
                current = static_cast<FUN_10285dc0_State>(0x1028bf96L);
                break;
            }
            case 0x1028bf96: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028bfa7L));
                break;
            }
            case 0x1028bfa7: {
                current = static_cast<FUN_10285dc0_State>(0x1028bfaaL);
                break;
            }
            case 0x1028bfaa: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bfc0L : 0x1028bfaeL);
                break;
            }
            case 0x1028bfae: {
                current = static_cast<FUN_10285dc0_State>(0x1028bfb0L);
                break;
            }
            case 0x1028bfb0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028bfc0L));
                break;
            }
            case 0x1028bfc0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c032L : 0x1028bfc5L);
                break;
            }
            case 0x1028bfc5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bfd1L : 0x1028bfcaL);
                break;
            }
            case 0x1028bfca: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c035L : 0x1028bfd1L);
                break;
            }
            case 0x1028bfd1: {
                current = static_cast<FUN_10285dc0_State>(0x1028bfd7L);
                break;
            }
            case 0x1028bfd7: {
                current = static_cast<FUN_10285dc0_State>(0x1028bfdaL);
                break;
            }
            case 0x1028bfda: {
                current = static_cast<FUN_10285dc0_State>(0x1028bfddL);
                break;
            }
            case 0x1028bfdd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bf34L : 0x1028bff0L);
                break;
            }
            case 0x1028bff0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c08fL : 0x1028c027L);
                break;
            }
            case 0x1028c027: {
                current = static_cast<FUN_10285dc0_State>(0x1028c091L);
                break;
            }
            case 0x1028c032: {
                current = static_cast<FUN_10285dc0_State>(0x1028c035L);
                break;
            }
            case 0x1028c035: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bfd1L : 0x1028c046L);
                break;
            }
            case 0x1028c046: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c060L : 0x1028c04aL);
                break;
            }
            case 0x1028c04a: {
                current = static_cast<FUN_10285dc0_State>(0x1028c060L);
                break;
            }
            case 0x1028c060: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c084L : 0x1028c068L);
                break;
            }
            case 0x1028c068: {
                current = static_cast<FUN_10285dc0_State>(0x1028bfdaL);
                break;
            }
            case 0x1028c084: {
                current = static_cast<FUN_10285dc0_State>(0x1028bfdaL);
                break;
            }
            case 0x1028c08f: {
                current = static_cast<FUN_10285dc0_State>(0x1028c091L);
                break;
            }
            case 0x1028c091: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c1abL : 0x1028c09fL);
                break;
            }
            case 0x1028c09f: {
                current = static_cast<FUN_10285dc0_State>(0x1028c0b0L);
                break;
            }
            case 0x1028c0b0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c1a2L : 0x1028c0ceL);
                break;
            }
            case 0x1028c0ce: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c197L : 0x1028c0e2L);
                break;
            }
            case 0x1028c0e2: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c197L : 0x1028c0eeL);
                break;
            }
            case 0x1028c0ee: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c194L : 0x1028c105L);
                break;
            }
            case 0x1028c105: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c135L : 0x1028c11cL);
                break;
            }
            case 0x1028c11c: {
                current = static_cast<FUN_10285dc0_State>(0x1028c121L);
                break;
            }
            case 0x1028c121: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c132L));
                break;
            }
            case 0x1028c132: {
                current = static_cast<FUN_10285dc0_State>(0x1028c135L);
                break;
            }
            case 0x1028c135: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c150L : 0x1028c139L);
                break;
            }
            case 0x1028c139: {
                current = static_cast<FUN_10285dc0_State>(0x1028c140L);
                break;
            }
            case 0x1028c140: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c150L));
                break;
            }
            case 0x1028c150: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c191L : 0x1028c158L);
                break;
            }
            case 0x1028c158: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c18cL : 0x1028c17dL);
                break;
            }
            case 0x1028c17d: {
                current = static_cast<FUN_10285dc0_State>(0x1028c18cL);
                break;
            }
            case 0x1028c18c: {
                current = static_cast<FUN_10285dc0_State>(0x1028c197L);
                break;
            }
            case 0x1028c191: {
                current = static_cast<FUN_10285dc0_State>(0x1028c194L);
                break;
            }
            case 0x1028c194: {
                current = static_cast<FUN_10285dc0_State>(0x1028c197L);
                break;
            }
            case 0x1028c197: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c0b0L : 0x1028c1a2L);
                break;
            }
            case 0x1028c1a2: {
                current = static_cast<FUN_10285dc0_State>(0x1028c1abL);
                break;
            }
            case 0x1028c1ab: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c35dL : 0x1028c1d0L);
                break;
            }
            case 0x1028c1d0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c35dL : 0x1028c1e8L);
                break;
            }
            case 0x1028c1e8: {
                current = static_cast<FUN_10285dc0_State>(0x1028c210L);
                break;
            }
            case 0x1028c210: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c341L : 0x1028c224L);
                break;
            }
            case 0x1028c224: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c248L : 0x1028c240L);
                break;
            }
            case 0x1028c240: {
                current = static_cast<FUN_10285dc0_State>(0x1028c333L);
                break;
            }
            case 0x1028c248: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c284L : 0x1028c268L);
                break;
            }
            case 0x1028c268: {
                current = static_cast<FUN_10285dc0_State>(0x1028c273L);
                break;
            }
            case 0x1028c273: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c284L));
                break;
            }
            case 0x1028c284: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c2a0L : 0x1028c288L);
                break;
            }
            case 0x1028c288: {
                current = static_cast<FUN_10285dc0_State>(0x1028c290L);
                break;
            }
            case 0x1028c290: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c2a0L));
                break;
            }
            case 0x1028c2a0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c32aL : 0x1028c2afL);
                break;
            }
            case 0x1028c2af: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c32aL : 0x1028c2b3L);
                break;
            }
            case 0x1028c2b3: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103281d0L); // ERROR
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x1028c32aL);
                else             current = static_cast<FUN_10285dc0_State>(0x1028c2e6L);
                break;
            }
            case 0x1028c2e6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c32aL : 0x1028c308L);
                break;
            }
            case 0x1028c308: {
                current = static_cast<FUN_10285dc0_State>(0x1028c338L);
                break;
            }
            case 0x1028c32a: {
                current = static_cast<FUN_10285dc0_State>(0x1028c333L);
                break;
            }
            case 0x1028c333: {
                current = static_cast<FUN_10285dc0_State>(0x1028c338L);
                break;
            }
            case 0x1028c338: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c344L : 0x1028c33cL);
                break;
            }
            case 0x1028c33c: {
                current = static_cast<FUN_10285dc0_State>(0x1028c344L);
                break;
            }
            case 0x1028c341: {
                current = static_cast<FUN_10285dc0_State>(0x1028c344L);
                break;
            }
            case 0x1028c344: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c210L : 0x1028c357L);
                break;
            }
            case 0x1028c357: {
                current = static_cast<FUN_10285dc0_State>(0x1028c35dL);
                break;
            }
            case 0x1028c35d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cbd7L : 0x1028c370L);
                break;
            }
            case 0x1028c370: {
                current = static_cast<FUN_10285dc0_State>(0x1028c377L);
                break;
            }
            case 0x1028c377: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c394L : 0x1028c387L);
                break;
            }
            case 0x1028c387: {
                current = static_cast<FUN_10285dc0_State>(0x1028c396L);
                break;
            }
            case 0x1028c394: {
                current = static_cast<FUN_10285dc0_State>(0x1028c396L);
                break;
            }
            case 0x1028c396: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c4c8L : 0x1028c405L);
                break;
            }
            case 0x1028c405: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c4b5L : 0x1028c41aL);
                break;
            }
            case 0x1028c41a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c4b5L : 0x1028c422L);
                break;
            }
            case 0x1028c422: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c4b5L : 0x1028c431L);
                break;
            }
            case 0x1028c431: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c4b5L : 0x1028c43dL);
                break;
            }
            case 0x1028c43d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c4b2L : 0x1028c451L);
                break;
            }
            case 0x1028c451: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c484L : 0x1028c46cL);
                break;
            }
            case 0x1028c46c: {
                current = static_cast<FUN_10285dc0_State>(0x1028c470L);
                break;
            }
            case 0x1028c470: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c481L));
                break;
            }
            case 0x1028c481: {
                current = static_cast<FUN_10285dc0_State>(0x1028c484L);
                break;
            }
            case 0x1028c484: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c498L : 0x1028c488L);
                break;
            }
            case 0x1028c488: {
                current = static_cast<FUN_10285dc0_State>(0x1028c48fL);
                break;
            }
            case 0x1028c48f: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c498L));
                break;
            }
            case 0x1028c498: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c507L : 0x1028c49dL);
                break;
            }
            case 0x1028c49d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c4a9L : 0x1028c4a2L);
                break;
            }
            case 0x1028c4a2: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c50aL : 0x1028c4a9L);
                break;
            }
            case 0x1028c4a9: {
                current = static_cast<FUN_10285dc0_State>(0x1028c4b2L);
                break;
            }
            case 0x1028c4b2: {
                current = static_cast<FUN_10285dc0_State>(0x1028c4b5L);
                break;
            }
            case 0x1028c4b5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c405L : 0x1028c4c8L);
                break;
            }
            case 0x1028c4c8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c56aL : 0x1028c4ffL);
                break;
            }
            case 0x1028c4ff: {
                current = static_cast<FUN_10285dc0_State>(0x1028c56cL);
                break;
            }
            case 0x1028c507: {
                current = static_cast<FUN_10285dc0_State>(0x1028c50aL);
                break;
            }
            case 0x1028c50a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c4a9L : 0x1028c51bL);
                break;
            }
            case 0x1028c51b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c535L : 0x1028c51fL);
                break;
            }
            case 0x1028c51f: {
                current = static_cast<FUN_10285dc0_State>(0x1028c535L);
                break;
            }
            case 0x1028c535: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c55cL : 0x1028c53dL);
                break;
            }
            case 0x1028c53d: {
                current = static_cast<FUN_10285dc0_State>(0x1028c4b5L);
                break;
            }
            case 0x1028c55c: {
                current = static_cast<FUN_10285dc0_State>(0x1028c4b5L);
                break;
            }
            case 0x1028c56a: {
                current = static_cast<FUN_10285dc0_State>(0x1028c56cL);
                break;
            }
            case 0x1028c56c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c679L : 0x1028c57aL);
                break;
            }
            case 0x1028c57a: {
                current = static_cast<FUN_10285dc0_State>(0x1028c580L);
                break;
            }
            case 0x1028c580: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c670L : 0x1028c5a0L);
                break;
            }
            case 0x1028c5a0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c664L : 0x1028c5b5L);
                break;
            }
            case 0x1028c5b5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c664L : 0x1028c5c1L);
                break;
            }
            case 0x1028c5c1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c661L : 0x1028c5d6L);
                break;
            }
            case 0x1028c5d6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c606L : 0x1028c5edL);
                break;
            }
            case 0x1028c5ed: {
                current = static_cast<FUN_10285dc0_State>(0x1028c5f2L);
                break;
            }
            case 0x1028c5f2: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c603L));
                break;
            }
            case 0x1028c603: {
                current = static_cast<FUN_10285dc0_State>(0x1028c606L);
                break;
            }
            case 0x1028c606: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c620L : 0x1028c60aL);
                break;
            }
            case 0x1028c60a: {
                current = static_cast<FUN_10285dc0_State>(0x1028c610L);
                break;
            }
            case 0x1028c610: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c620L));
                break;
            }
            case 0x1028c620: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c65eL : 0x1028c625L);
                break;
            }
            case 0x1028c625: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c659L : 0x1028c64aL);
                break;
            }
            case 0x1028c64a: {
                current = static_cast<FUN_10285dc0_State>(0x1028c659L);
                break;
            }
            case 0x1028c659: {
                current = static_cast<FUN_10285dc0_State>(0x1028c664L);
                break;
            }
            case 0x1028c65e: {
                current = static_cast<FUN_10285dc0_State>(0x1028c661L);
                break;
            }
            case 0x1028c661: {
                current = static_cast<FUN_10285dc0_State>(0x1028c664L);
                break;
            }
            case 0x1028c664: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c580L : 0x1028c670L);
                break;
            }
            case 0x1028c670: {
                current = static_cast<FUN_10285dc0_State>(0x1028c679L);
                break;
            }
            case 0x1028c679: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c81eL : 0x1028c69eL);
                break;
            }
            case 0x1028c69e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c81eL : 0x1028c6b6L);
                break;
            }
            case 0x1028c6b6: {
                current = static_cast<FUN_10285dc0_State>(0x1028c6d7L);
                break;
            }
            case 0x1028c6d7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c805L : 0x1028c6ebL);
                break;
            }
            case 0x1028c6eb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c7f4L : 0x1028c708L);
                break;
            }
            case 0x1028c708: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c744L : 0x1028c728L);
                break;
            }
            case 0x1028c728: {
                current = static_cast<FUN_10285dc0_State>(0x1028c733L);
                break;
            }
            case 0x1028c733: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c744L));
                break;
            }
            case 0x1028c744: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c760L : 0x1028c748L);
                break;
            }
            case 0x1028c748: {
                current = static_cast<FUN_10285dc0_State>(0x1028c750L);
                break;
            }
            case 0x1028c750: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028c760L));
                break;
            }
            case 0x1028c760: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c7ebL : 0x1028c773L);
                break;
            }
            case 0x1028c773: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c7ebL : 0x1028c777L);
                break;
            }
            case 0x1028c777: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103281d0L); // ERROR
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x1028c7ebL);
                else             current = static_cast<FUN_10285dc0_State>(0x1028c7aaL);
                break;
            }
            case 0x1028c7aa: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c7ebL : 0x1028c7c9L);
                break;
            }
            case 0x1028c7c9: {
                current = static_cast<FUN_10285dc0_State>(0x1028c7f9L);
                break;
            }
            case 0x1028c7eb: {
                current = static_cast<FUN_10285dc0_State>(0x1028c7f4L);
                break;
            }
            case 0x1028c7f4: {
                current = static_cast<FUN_10285dc0_State>(0x1028c7f9L);
                break;
            }
            case 0x1028c7f9: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c808L : 0x1028c800L);
                break;
            }
            case 0x1028c800: {
                current = static_cast<FUN_10285dc0_State>(0x1028c808L);
                break;
            }
            case 0x1028c805: {
                current = static_cast<FUN_10285dc0_State>(0x1028c808L);
                break;
            }
            case 0x1028c808: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c6d7L : 0x1028c81bL);
                break;
            }
            case 0x1028c81b: {
                current = static_cast<FUN_10285dc0_State>(0x1028c81eL);
                break;
            }
            case 0x1028c81e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c868L : 0x1028c82dL);
                break;
            }
            case 0x1028c82d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c868L : 0x1028c85cL);
                break;
            }
            case 0x1028c85c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c377L : 0x1028c868L);
                break;
            }
            case 0x1028c868: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c8efL : 0x1028c88dL);
                break;
            }
            case 0x1028c88d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c89fL : 0x1028c89bL);
                break;
            }
            case 0x1028c89b: {
                current = static_cast<FUN_10285dc0_State>(0x1028c8f2L);
                break;
            }
            case 0x1028c89f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c8abL : 0x1028c8a4L);
                break;
            }
            case 0x1028c8a4: {
                current = static_cast<FUN_10285dc0_State>(0x1028c8f2L);
                break;
            }
            case 0x1028c8ab: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c8c3L : 0x1028c8b0L);
                break;
            }
            case 0x1028c8b0: {
                current = static_cast<FUN_10285dc0_State>(0x1028c8f2L);
                break;
            }
            case 0x1028c8c3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c8d7L : 0x1028c8c8L);
                break;
            }
            case 0x1028c8c8: {
                current = static_cast<FUN_10285dc0_State>(0x1028c8f2L);
                break;
            }
            case 0x1028c8d7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c8e3L : 0x1028c8dcL);
                break;
            }
            case 0x1028c8dc: {
                current = static_cast<FUN_10285dc0_State>(0x1028c8f2L);
                break;
            }
            case 0x1028c8e3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c8efL : 0x1028c8e8L);
                break;
            }
            case 0x1028c8e8: {
                current = static_cast<FUN_10285dc0_State>(0x1028c8f2L);
                break;
            }
            case 0x1028c8ef: {
                current = static_cast<FUN_10285dc0_State>(0x1028c8f2L);
                break;
            }
            case 0x1028c8f2: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c969L : 0x1028c8f7L);
                break;
            }
            case 0x1028c8f7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c969L : 0x1028c8fbL);
                break;
            }
            case 0x1028c8fb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c969L : 0x1028c919L);
                break;
            }
            case 0x1028c919: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c969L : 0x1028c942L);
                break;
            }
            case 0x1028c942: {
                current = static_cast<FUN_10285dc0_State>(0x1028c969L);
                break;
            }
            case 0x1028c969: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028c991L : 0x1028c98dL);
                break;
            }
            case 0x1028c98d: {
                current = static_cast<FUN_10285dc0_State>(0x1028c9f5L);
                break;
            }
            case 0x1028c991: {
                current = static_cast<FUN_10285dc0_State>(0x1028c9f5L);
                break;
            }
            case 0x1028c9f5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ca1bL : 0x1028ca16L);
                break;
            }
            case 0x1028ca16: {
                current = static_cast<FUN_10285dc0_State>(0x1028ca6aL);
                break;
            }
            case 0x1028ca1b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ca3aL : 0x1028ca23L);
                break;
            }
            case 0x1028ca23: {
                current = static_cast<FUN_10285dc0_State>(0x1028ca6aL);
                break;
            }
            case 0x1028ca3a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ca50L : 0x1028ca42L);
                break;
            }
            case 0x1028ca42: {
                current = static_cast<FUN_10285dc0_State>(0x1028ca6aL);
                break;
            }
            case 0x1028ca50: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ca5fL : 0x1028ca58L);
                break;
            }
            case 0x1028ca58: {
                current = static_cast<FUN_10285dc0_State>(0x1028ca6aL);
                break;
            }
            case 0x1028ca5f: {
                current = static_cast<FUN_10285dc0_State>(0x1028ca6aL);
                break;
            }
            case 0x1028ca6a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ca77L : 0x1028ca6fL);
                break;
            }
            case 0x1028ca6f: {
                current = static_cast<FUN_10285dc0_State>(0x1028cab1L);
                break;
            }
            case 0x1028ca77: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ca96L : 0x1028ca7fL);
                break;
            }
            case 0x1028ca7f: {
                current = static_cast<FUN_10285dc0_State>(0x1028cab1L);
                break;
            }
            case 0x1028ca96: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028caacL : 0x1028ca9eL);
                break;
            }
            case 0x1028ca9e: {
                current = static_cast<FUN_10285dc0_State>(0x1028cab1L);
                break;
            }
            case 0x1028caac: {
                current = static_cast<FUN_10285dc0_State>(0x1028cab1L);
                break;
            }
            case 0x1028cab1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cae9L : 0x1028cac8L);
                break;
            }
            case 0x1028cac8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cae9L : 0x1028caceL);
                break;
            }
            case 0x1028cace: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cae9L : 0x1028cad4L);
                break;
            }
            case 0x1028cad4: {
                current = static_cast<FUN_10285dc0_State>(0x1028cb16L);
                break;
            }
            case 0x1028cae9: {
                current = static_cast<FUN_10285dc0_State>(0x1028cb16L);
                break;
            }
            case 0x1028cb16: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cb75L : 0x1028cb55L);
                break;
            }
            case 0x1028cb55: {
                current = static_cast<FUN_10285dc0_State>(0x1028cb75L);
                break;
            }
            case 0x1028cb75: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cbcdL : 0x1028cb79L);
                break;
            }
            case 0x1028cb79: {
                current = static_cast<FUN_10285dc0_State>(0x1028cb80L);
                break;
            }
            case 0x1028cb80: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028cbc7L));
                break;
            }
            case 0x1028cbc7: {
                current = static_cast<FUN_10285dc0_State>(0x1028cbcdL);
                break;
            }
            case 0x1028cbcd: {
                current = static_cast<FUN_10285dc0_State>(0x1028cce1L);
                break;
            }
            case 0x1028cbd7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ccdeL : 0x1028cbe8L);
                break;
            }
            case 0x1028cbe8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cc6eL : 0x1028cbf7L);
                break;
            }
            case 0x1028cbf7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cce1L : 0x1028cc0aL);
                break;
            }
            case 0x1028cc0a: {
                current = static_cast<FUN_10285dc0_State>(0x1028cc20L);
                break;
            }
            case 0x1028cc20: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028cc6cL));
                break;
            }
            case 0x1028cc6c: {
                current = static_cast<FUN_10285dc0_State>(0x1028cce1L);
                break;
            }
            case 0x1028cc6e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cce1L : 0x1028cc7dL);
                break;
            }
            case 0x1028cc7d: {
                current = static_cast<FUN_10285dc0_State>(0x1028cc90L);
                break;
            }
            case 0x1028cc90: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028ccdcL));
                break;
            }
            case 0x1028ccdc: {
                current = static_cast<FUN_10285dc0_State>(0x1028cce1L);
                break;
            }
            case 0x1028ccde: {
                current = static_cast<FUN_10285dc0_State>(0x1028cce1L);
                break;
            }
            case 0x1028cce1: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bed0L : 0x1028ccf8L);
                break;
            }
            case 0x1028ccf8: {
                return { current, false, false };
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
