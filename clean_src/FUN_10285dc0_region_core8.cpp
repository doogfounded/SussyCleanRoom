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

RegionResult ProcessCoreLoopRegion_Case8(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 9) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x1028cd20: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cd80L : 0x1028cd76L);
                break;
            }
            case 0x1028cd76: {
                current = static_cast<FUN_10285dc0_State>(0x1028cd83L);
                break;
            }
            case 0x1028cd80: {
                current = static_cast<FUN_10285dc0_State>(0x1028cd83L);
                break;
            }
            case 0x1028cd83: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d5f9L : 0x1028cdadL);
                break;
            }
            case 0x1028cdad: {
                current = static_cast<FUN_10285dc0_State>(0x1028cdd0L);
                break;
            }
            case 0x1028cdd0: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x1028cef3L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028ce4bL);
                break;
            }
            case 0x1028ce4b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cef3L : 0x1028ce5aL);
                break;
            }
            case 0x1028ce5a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ce97L : 0x1028ce76L);
                break;
            }
            case 0x1028ce76: {
                current = static_cast<FUN_10285dc0_State>(0x1028ce80L);
                break;
            }
            case 0x1028ce80: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028ce91L));
                break;
            }
            case 0x1028ce91: {
                current = static_cast<FUN_10285dc0_State>(0x1028ce97L);
                break;
            }
            case 0x1028ce97: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ceb0L : 0x1028ce9bL);
                break;
            }
            case 0x1028ce9b: {
                current = static_cast<FUN_10285dc0_State>(0x1028cea0L);
                break;
            }
            case 0x1028cea0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028ceb0L));
                break;
            }
            case 0x1028ceb0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cef0L : 0x1028ceb8L);
                break;
            }
            case 0x1028ceb8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cef0L : 0x1028cecaL);
                break;
            }
            case 0x1028ceca: {
                current = static_cast<FUN_10285dc0_State>(0x1028cef3L);
                break;
            }
            case 0x1028cef0: {
                current = static_cast<FUN_10285dc0_State>(0x1028cef3L);
                break;
            }
            case 0x1028cef3: {
                current = static_cast<FUN_10285dc0_State>(0x1028cf21L);
                break;
            }
            case 0x1028cf21: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cffaL : 0x1028cf4dL);
                break;
            }
            case 0x1028cf4d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cffaL : 0x1028cf55L);
                break;
            }
            case 0x1028cf55: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cffaL : 0x1028cf5eL);
                break;
            }
            case 0x1028cf5e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cf98L : 0x1028cf7dL);
                break;
            }
            case 0x1028cf7d: {
                current = static_cast<FUN_10285dc0_State>(0x1028cf81L);
                break;
            }
            case 0x1028cf81: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028cf92L));
                break;
            }
            case 0x1028cf92: {
                current = static_cast<FUN_10285dc0_State>(0x1028cf98L);
                break;
            }
            case 0x1028cf98: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cfb0L : 0x1028cf9cL);
                break;
            }
            case 0x1028cf9c: {
                current = static_cast<FUN_10285dc0_State>(0x1028cfa0L);
                break;
            }
            case 0x1028cfa0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028cfb0L));
                break;
            }
            case 0x1028cfb0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cff7L : 0x1028cfb5L);
                break;
            }
            case 0x1028cfb5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d050L : 0x1028cfdaL);
                break;
            }
            case 0x1028cfda: {
                current = static_cast<FUN_10285dc0_State>(0x1028cffdL);
                break;
            }
            case 0x1028cff7: {
                current = static_cast<FUN_10285dc0_State>(0x1028cffaL);
                break;
            }
            case 0x1028cffa: {
                current = static_cast<FUN_10285dc0_State>(0x1028cffdL);
                break;
            }
            case 0x1028cffl: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cf21L : 0x1028d00dL);
                break;
            }
            case 0x1028d00d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d616L : 0x1028d02cL);
                break;
            }
            case 0x1028d02c: {
                current = static_cast<FUN_10285dc0_State>(0x1028d033L);
                break;
            }
            case 0x1028d033: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d055L : 0x1028d043L);
                break;
            }
            case 0x1028d043: {
                current = static_cast<FUN_10285dc0_State>(0x1028d057L);
                break;
            }
            case 0x1028d050: {
                current = static_cast<FUN_10285dc0_State>(0x1028cffdL);
                break;
            }
            case 0x1028d055: {
                current = static_cast<FUN_10285dc0_State>(0x1028d057L);
                break;
            }
            case 0x1028d057: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x1028d170L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028d0ccL);
                break;
            }
            case 0x1028d0cc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d170L : 0x1028d0dfL);
                break;
            }
            case 0x1028d0df: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d117L : 0x1028d0fbL);
                break;
            }
            case 0x1028d0fb: {
                current = static_cast<FUN_10285dc0_State>(0x1028d100L);
                break;
            }
            case 0x1028d100: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028d111L));
                break;
            }
            case 0x1028d111: {
                current = static_cast<FUN_10285dc0_State>(0x1028d117L);
                break;
            }
            case 0x1028d117: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d130L : 0x1028d11bL);
                break;
            }
            case 0x1028d11b: {
                current = static_cast<FUN_10285dc0_State>(0x1028d120L);
                break;
            }
            case 0x1028d120: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028d130L));
                break;
            }
            case 0x1028d130: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d170L : 0x1028d138L);
                break;
            }
            case 0x1028d138: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d170L : 0x1028d14aL);
                break;
            }
            case 0x1028d14a: {
                current = static_cast<FUN_10285dc0_State>(0x1028d170L);
                break;
            }
            case 0x1028d170: {
                current = static_cast<FUN_10285dc0_State>(0x1028d1a0L);
                break;
            }
            case 0x1028d1a0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d282L : 0x1028d1c7L);
                break;
            }
            case 0x1028d1c7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d282L : 0x1028d1cfL);
                break;
            }
            case 0x1028d1cf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d282L : 0x1028d1d8L);
                break;
            }
            case 0x1028d1d8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d217L : 0x1028d1f4L);
                break;
            }
            case 0x1028d1f4: {
                current = static_cast<FUN_10285dc0_State>(0x1028d200L);
                break;
            }
            case 0x1028d200: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028d211L));
                break;
            }
            case 0x1028d211: {
                current = static_cast<FUN_10285dc0_State>(0x1028d217L);
                break;
            }
            case 0x1028d217: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d230L : 0x1028d21bL);
                break;
            }
            case 0x1028d21b: {
                current = static_cast<FUN_10285dc0_State>(0x1028d220L);
                break;
            }
            case 0x1028d220: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028d230L));
                break;
            }
            case 0x1028d230: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d27cL : 0x1028d235L);
                break;
            }
            case 0x1028d235: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d27cL : 0x1028d257L);
                break;
            }
            case 0x1028d257: {
                current = static_cast<FUN_10285dc0_State>(0x1028d285L);
                break;
            }
            case 0x1028d27c: {
                current = static_cast<FUN_10285dc0_State>(0x1028d282L);
                break;
            }
            case 0x1028d282: {
                current = static_cast<FUN_10285dc0_State>(0x1028d285L);
                break;
            }
            case 0x1028d285: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d1a0L : 0x1028d295L);
                break;
            }
            case 0x1028d295: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d2e2L : 0x1028d2b3L);
                break;
            }
            case 0x1028d2b3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d2e2L : 0x1028d2d6L);
                break;
            }
            case 0x1028d2d6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d033L : 0x1028d2e2L);
                break;
            }
            case 0x1028d2e2: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d375L : 0x1028d304L);
                break;
            }
            case 0x1028d304: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d31cL : 0x1028d318L);
                break;
            }
            case 0x1028d318: {
                current = static_cast<FUN_10285dc0_State>(0x1028d378L);
                break;
            }
            case 0x1028d31c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d32eL : 0x1028d327L);
                break;
            }
            case 0x1028d327: {
                current = static_cast<FUN_10285dc0_State>(0x1028d378L);
                break;
            }
            case 0x1028d32e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d346L : 0x1028d333L);
                break;
            }
            case 0x1028d333: {
                current = static_cast<FUN_10285dc0_State>(0x1028d378L);
                break;
            }
            case 0x1028d346: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d35aL : 0x1028d34bL);
                break;
            }
            case 0x1028d34b: {
                current = static_cast<FUN_10285dc0_State>(0x1028d378L);
                break;
            }
            case 0x1028d35a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d369L : 0x1028d362L);
                break;
            }
            case 0x1028d362: {
                current = static_cast<FUN_10285dc0_State>(0x1028d378L);
                break;
            }
            case 0x1028d369: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d375L : 0x1028d36eL);
                break;
            }
            case 0x1028d36e: {
                current = static_cast<FUN_10285dc0_State>(0x1028d378L);
                break;
            }
            case 0x1028d375: {
                current = static_cast<FUN_10285dc0_State>(0x1028d378L);
                break;
            }
            case 0x1028d378: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d399L : 0x1028d37fL);
                break;
            }
            case 0x1028d37f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d399L : 0x1028d383L);
                break;
            }
            case 0x1028d383: {
                current = static_cast<FUN_10285dc0_State>(0x1028d399L);
                break;
            }
            case 0x1028d399: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d3b5L : 0x1028d3b1L);
                break;
            }
            case 0x1028d3b1: {
                current = static_cast<FUN_10285dc0_State>(0x1028d421L);
                break;
            }
            case 0x1028d3b5: {
                current = static_cast<FUN_10285dc0_State>(0x1028d421L);
                break;
            }
            case 0x1028d421: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d448L : 0x1028d443L);
                break;
            }
            case 0x1028d443: {
                current = static_cast<FUN_10285dc0_State>(0x1028d497L);
                break;
            }
            case 0x1028d448: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d467L : 0x1028d450L);
                break;
            }
            case 0x1028d450: {
                current = static_cast<FUN_10285dc0_State>(0x1028d497L);
                break;
            }
            case 0x1028d467: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d47dL : 0x1028d46fL);
                break;
            }
            case 0x1028d46f: {
                current = static_cast<FUN_10285dc0_State>(0x1028d497L);
                break;
            }
            case 0x1028d47d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d48cL : 0x1028d485L);
                break;
            }
            case 0x1028d485: {
                current = static_cast<FUN_10285dc0_State>(0x1028d497L);
                break;
            }
            case 0x1028d48c: {
                current = static_cast<FUN_10285dc0_State>(0x1028d497L);
                break;
            }
            case 0x1028d497: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d4a4L : 0x1028d49cL);
                break;
            }
            case 0x1028d49c: {
                current = static_cast<FUN_10285dc0_State>(0x1028d4deL);
                break;
            }
            case 0x1028d4a4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d4c3L : 0x1028d4acL);
                break;
            }
            case 0x1028d4ac: {
                current = static_cast<FUN_10285dc0_State>(0x1028d4deL);
                break;
            }
            case 0x1028d4c3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d4d9L : 0x1028d4cbL);
                break;
            }
            case 0x1028d4cb: {
                current = static_cast<FUN_10285dc0_State>(0x1028d4deL);
                break;
            }
            case 0x1028d4d9: {
                current = static_cast<FUN_10285dc0_State>(0x1028d4deL);
                break;
            }
            case 0x1028d4de: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d518L : 0x1028d4f7L);
                break;
            }
            case 0x1028d4f7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d518L : 0x1028d4fdL);
                break;
            }
            case 0x1028d4fd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d518L : 0x1028d503L);
                break;
            }
            case 0x1028d503: {
                current = static_cast<FUN_10285dc0_State>(0x1028d545L);
                break;
            }
            case 0x1028d518: {
                current = static_cast<FUN_10285dc0_State>(0x1028d545L);
                break;
            }
            case 0x1028d545: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d59aL : 0x1028d57dL);
                break;
            }
            case 0x1028d57d: {
                current = static_cast<FUN_10285dc0_State>(0x1028d59aL);
                break;
            }
            case 0x1028d59a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d5dcL : 0x1028d59eL);
                break;
            }
            case 0x1028d59e: {
                current = static_cast<FUN_10285dc0_State>(0x1028d5a0L);
                break;
            }
            case 0x1028d5a0: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028d5dcL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028d5dc: {
                current = static_cast<FUN_10285dc0_State>(0x1028d5e2L);
                break;
            }
            case 0x1028d5e2: {
                current = static_cast<FUN_10285dc0_State>(0x1028d5e5L);
                break;
            }
            case 0x1028d5e5: {
                current = static_cast<FUN_10285dc0_State>(0x1028d5e8L);
                break;
            }
            case 0x1028d5e8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028cdd0L : 0x1028d5f6L);
                break;
            }
            case 0x1028d5f6: {
                current = static_cast<FUN_10285dc0_State>(0x1028d5f9L);
                break;
            }
            case 0x1028d5f9: {
                // Region exit block
                return { current, false, false };
            }
            case 0x1028d616: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d709L : 0x1028d62bL);
                break;
            }
            case 0x1028d62b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d6a3L : 0x1028d63dL);
                break;
            }
            case 0x1028d63d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d5e5L : 0x1028d649L);
                break;
            }
            case 0x1028d649: {
                current = static_cast<FUN_10285dc0_State>(0x1028d660L);
                break;
            }
            case 0x1028d660: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028d69eL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028d69e: {
                current = static_cast<FUN_10285dc0_State>(0x1028d5e2L);
                break;
            }
            case 0x1028d6a3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028d5e5L : 0x1028d6b3L);
                break;
            }
            case 0x1028d6b3: {
                current = static_cast<FUN_10285dc0_State>(0x1028d6c6L);
                break;
            }
            case 0x1028d6c6: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028d704L);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028d704: {
                current = static_cast<FUN_10285dc0_State>(0x1028d5e2L);
                break;
            }
            case 0x1028d709: {
                current = static_cast<FUN_10285dc0_State>(0x1028d5e8L);
                break;
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
