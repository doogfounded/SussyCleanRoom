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

RegionResult ProcessCoreLoopRegion_Case5(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 6) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x10289cc0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289d0bL : 0x10289d01L);
                break;
            }
            case 0x10289d01: {
                current = static_cast<FUN_10285dc0_State>(0x10289d0eL);
                break;
            }
            case 0x10289d0b: {
                current = static_cast<FUN_10285dc0_State>(0x10289d0eL);
                break;
            }
            case 0x10289d0e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ac96L : 0x10289d35L);
                break;
            }
            case 0x10289d35: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x10289e30L);
                else             current = static_cast<FUN_10285dc0_State>(0x10289d8eL);
                break;
            }
            case 0x10289d8e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289e30L : 0x10289d9dL);
                break;
            }
            case 0x10289d9d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289dd4L : 0x10289db8L);
                break;
            }
            case 0x10289db8: {
                current = static_cast<FUN_10285dc0_State>(0x10289dc0L);
                break;
            }
            case 0x10289dc0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10289dd1L));
                break;
            }
            case 0x10289dd1: {
                current = static_cast<FUN_10285dc0_State>(0x10289dd4L);
                break;
            }
            case 0x10289dd4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289df0L : 0x10289de0L);
                break;
            }
            case 0x10289de0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10289df0L));
                break;
            }
            case 0x10289df0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289e30L : 0x10289df8L);
                break;
            }
            case 0x10289df8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289e30L : 0x10289e0aL);
                break;
            }
            case 0x10289e0a: {
                current = static_cast<FUN_10285dc0_State>(0x10289e30L);
                break;
            }
            case 0x10289e30: {
                current = static_cast<FUN_10285dc0_State>(0x10289e70L);
                break;
            }
            case 0x10289e70: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289f51L : 0x10289e8fL);
                break;
            }
            case 0x10289e8f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289f51L : 0x10289e97L);
                break;
            }
            case 0x10289e97: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289f51L : 0x10289ea0L);
                break;
            }
            case 0x10289ea0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289edaL : 0x10289ebfL);
                break;
            }
            case 0x10289ebf: {
                current = static_cast<FUN_10285dc0_State>(0x10289ec3L);
                break;
            }
            case 0x10289ec3: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10289ed4L));
                break;
            }
            case 0x10289ed4: {
                current = static_cast<FUN_10285dc0_State>(0x10289edaL);
                break;
            }
            case 0x10289eda: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289ef0L : 0x10289edeL);
                break;
            }
            case 0x10289ede: {
                current = static_cast<FUN_10285dc0_State>(0x10289ee0L);
                break;
            }
            case 0x10289ee0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10289ef0L));
                break;
            }
            case 0x10289ef0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289f3eL : 0x10289ef5L);
                break;
            }
            case 0x10289ef5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289f3eL : 0x10289f07L);
                break;
            }
            case 0x10289f07: {
                current = static_cast<FUN_10285dc0_State>(0x10289f43L);
                break;
            }
            case 0x10289f3e: {
                current = static_cast<FUN_10285dc0_State>(0x10289f41L);
                break;
            }
            case 0x10289f41: {
                current = static_cast<FUN_10285dc0_State>(0x10289f43L);
                break;
            }
            case 0x10289f43: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289e70L : 0x10289f57L);
                break;
            }
            case 0x10289f57: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a0c1L : 0x10289f65L);
                break;
            }
            case 0x10289f65: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a0c1L : 0x10289f6aL);
                break;
            }
            case 0x10289f6a: {
                current = static_cast<FUN_10285dc0_State>(0x10289f6dL);
                break;
            }
            case 0x10289f6d: {
                current = static_cast<FUN_10285dc0_State>(0x10289f7aL);
                break;
            }
            case 0x10289f7a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a097L : 0x10289f7fL);
                break;
            }
            case 0x10289f7f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a097L : 0x10289f83L);
                break;
            }
            case 0x10289f83: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a097L : 0x10289f89L);
                break;
            }
            case 0x10289f89: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289fa6L : 0x10289f8fL);
                break;
            }
            case 0x10289f8f: {
                current = static_cast<FUN_10285dc0_State>(0x10289f93L);
                break;
            }
            case 0x10289f93: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10289fa3L));
                break;
            }
            case 0x10289fa3: {
                current = static_cast<FUN_10285dc0_State>(0x10289fa6L);
                break;
            }
            case 0x10289fa6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289fbeL : 0x10289faeL);
                break;
            }
            case 0x10289fae: {
                current = static_cast<FUN_10285dc0_State>(0x10289fb0L);
                break;
            }
            case 0x10289fb0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10289fbeL));
                break;
            }
            case 0x10289fbe: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a054L : 0x10289fbfL);
                break;
            }
            case 0x10289fbf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a054L : 0x10289fcaL);
                break;
            }
            case 0x10289fca: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a054L : 0x10289fd9L);
                break;
            }
            case 0x10289fd9: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a00eL : 0x1028a002L);
                break;
            }
            case 0x1028a002: {
                current = static_cast<FUN_10285dc0_State>(0x1028a057L);
                break;
            }
            case 0x1028a00e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a057L : 0x1028a025L);
                break;
            }
            case 0x1028a025: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a057L : 0x1028a033L);
                break;
            }
            case 0x1028a033: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a04fL : 0x1028a037L);
                break;
            }
            case 0x1028a037: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a04fL : 0x1028a03eL);
                break;
            }
            case 0x1028a03e: {
                current = static_cast<FUN_10285dc0_State>(0x1028a057L);
                break;
            }
            case 0x1028a04f: {
                current = static_cast<FUN_10285dc0_State>(0x1028a057L);
                break;
            }
            case 0x1028a054: {
                current = static_cast<FUN_10285dc0_State>(0x1028a057L);
                break;
            }
            case 0x1028a057: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a097L : 0x1028a05bL);
                break;
            }
            case 0x1028a05b: {
                current = static_cast<FUN_10285dc0_State>(0x1028a06eL);
                break;
            }
            case 0x1028a06e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a097L : 0x1028a077L);
                break;
            }
            case 0x1028a077: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a097L : 0x1028a082L);
                break;
            }
            case 0x1028a082: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a097L : 0x1028a08bL);
                break;
            }
            case 0x1028a08b: {
                current = static_cast<FUN_10285dc0_State>(0x1028a097L);
                break;
            }
            case 0x1028a097: {
                current = static_cast<FUN_10285dc0_State>(0x1028a09eL);
                break;
            }
            case 0x1028a09e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a0a8L : 0x1028a097L);
                break;
            }
            case 0x1028a0a8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a0c7L : 0x1028a0b2L);
                break;
            }
            case 0x1028a0b2: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028a0c7L));
                break;
            }
            case 0x1028a0c1: {
                current = static_cast<FUN_10285dc0_State>(0x1028a0c7L);
                break;
            }
            case 0x1028a0c7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a20bL : 0x1028a0d0L);
                break;
            }
            case 0x1028a0d0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a20bL : 0x1028a0d6L);
                break;
            }
            case 0x1028a0d6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a20bL : 0x1028a0dcL);
                break;
            }
            case 0x1028a0dc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a20bL : 0x1028a0eaL);
                break;
            }
            case 0x1028a0ea: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a20bL : 0x1028a0fbL);
                break;
            }
            case 0x1028a0fb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a11eL : 0x1028a101L);
                break;
            }
            case 0x1028a101: {
                current = static_cast<FUN_10285dc0_State>(0x1028a105L);
                break;
            }
            case 0x1028a105: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a11eL : 0x1028a10bL);
                break;
            }
            case 0x1028a10b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a105L : 0x1028a11eL);
                break;
            }
            case 0x1028a11e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a164L : 0x1028a123L);
                break;
            }
            case 0x1028a123: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a164L : 0x1028a129L);
                break;
            }
            case 0x1028a129: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a164L : 0x1028a14bL);
                break;
            }
            case 0x1028a14b: {
                current = static_cast<FUN_10285dc0_State>(0x1028a164L);
                break;
            }
            case 0x1028a164: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a1aaL : 0x1028a178L);
                break;
            }
            case 0x1028a178: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a1aaL : 0x1028a183L);
                break;
            }
            case 0x1028a183: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a1aaL : 0x1028a196L);
                break;
            }
            case 0x1028a196: {
                current = static_cast<FUN_10285dc0_State>(0x1028a1aaL);
                break;
            }
            case 0x1028a1aa: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a1f8L : 0x1028a1beL);
                break;
            }
            case 0x1028a1be: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a1f8L : 0x1028a1c9L);
                break;
            }
            case 0x1028a1c9: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a1f8L : 0x1028a1e2L);
                break;
            }
            case 0x1028a1e2: {
                current = static_cast<FUN_10285dc0_State>(0x1028a1f8L);
                break;
            }
            case 0x1028a1f8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a20bL : 0x1028a1fdL);
                break;
            }
            case 0x1028a1fd: {
                current = static_cast<FUN_10285dc0_State>(0x1028a20bL);
                break;
            }
            case 0x1028a20b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a23aL : 0x1028a20fL);
                break;
            }
            case 0x1028a20f: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028a220L));
                break;
            }
            case 0x1028a220: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a23aL : 0x1028a22aL);
                break;
            }
            case 0x1028a22a: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028a23aL));
                break;
            }
            case 0x1028a23a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a83dL : 0x1028a240L);
                break;
            }
            case 0x1028a240: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a83dL : 0x1028a252L);
                break;
            }
            case 0x1028a252: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a83dL : 0x1028a25bL);
                break;
            }
            case 0x1028a25b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a803L : 0x1028a26bL);
                break;
            }
            case 0x1028a26b: {
                current = static_cast<FUN_10285dc0_State>(0x1028a2a0L);
                break;
            }
            case 0x1028a2a0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a2bcL : 0x1028a2b5L);
                break;
            }
            case 0x1028a2b5: {
                current = static_cast<FUN_10285dc0_State>(0x1028a2ccL);
                break;
            }
            case 0x1028a2bc: {
                current = static_cast<FUN_10285dc0_State>(0x1028a2ccL);
                break;
            }
            case 0x1028a2cc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a2a0L : 0x1028a2eaL);
                break;
            }
            case 0x1028a2ea: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a3bdL : 0x1028a2eeL);
                break;
            }
            case 0x1028a2ee: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a3bdL : 0x1028a2f5L);
                break;
            }
            case 0x1028a2f5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a3bdL : 0x1028a30aL);
                break;
            }
            case 0x1028a30a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a335L : 0x1028a313L);
                break;
            }
            case 0x1028a313: {
                current = static_cast<FUN_10285dc0_State>(0x1028a317L);
                break;
            }
            case 0x1028a317: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a335L : 0x1028a320L);
                break;
            }
            case 0x1028a320: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a317L : 0x1028a335L);
                break;
            }
            case 0x1028a335: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a3bdL : 0x1028a339L);
                break;
            }
            case 0x1028a339: {
                current = static_cast<FUN_10285dc0_State>(0x1028a340L);
                break;
            }
            case 0x1028a340: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a3bdL : 0x1028a34dL);
                break;
            }
            case 0x1028a34d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a340L : 0x1028a3bdL);
                break;
            }
            case 0x1028a3bd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a83aL : 0x1028a3c0L);
                break;
            }
            case 0x1028a3c0: {
                current = static_cast<FUN_10285dc0_State>(0x1028a3c3L);
                break;
            }
            case 0x1028a3c3: {
                current = static_cast<FUN_10285dc0_State>(0x1028a83dL);
                break;
            }
            case 0x1028a803: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a83dL : 0x1028a816L);
                break;
            }
            case 0x1028a816: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028a83dL : 0x1028a81aL);
                break;
            }
            case 0x1028a81a: {
                current = static_cast<FUN_10285dc0_State>(0x1028a840L);
                break;
            }
            case 0x1028a83a: {
                current = static_cast<FUN_10285dc0_State>(0x1028a83dL);
                break;
            }
            case 0x1028a83d: {
                current = static_cast<FUN_10285dc0_State>(0x1028a840L);
                break;
            }
            case 0x1028a840: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028a87fL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028a87f: {
                current = static_cast<FUN_10285dc0_State>(0x1028a888L);
                break;
            }
            case 0x1028a888: {
                current = static_cast<FUN_10285dc0_State>(0x1028a88bL);
                break;
            }
            case 0x1028a88b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10289d0eL : 0x1028a89aL);
                break;
            }
            case 0x1028a89a: {
                current = static_cast<FUN_10285dc0_State>(0x1028a900L);
                break;
            }
            case 0x1028a900: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028a93dL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028a93d: {
                current = static_cast<FUN_10285dc0_State>(0x1028a970L);
                break;
            }
            case 0x1028a970: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028a9adL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028a9ad: {
                current = static_cast<FUN_10285dc0_State>(0x1028a0c7L);
                break;
            }
            case 0x1028ac96: {
                return { current, false, false };
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
