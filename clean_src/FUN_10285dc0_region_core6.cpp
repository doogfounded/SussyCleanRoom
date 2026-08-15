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

RegionResult ProcessCoreLoopRegion_Case6(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 7) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x1028acc0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ad0bL : 0x1028ad01L);
                break;
            }
            case 0x1028ad01: {
                current = static_cast<FUN_10285dc0_State>(0x1028ad0eL);
                break;
            }
            case 0x1028ad0b: {
                current = static_cast<FUN_10285dc0_State>(0x1028ad0eL);
                break;
            }
            case 0x1028ad0e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bdc2L : 0x1028ad35L);
                break;
            }
            case 0x1028ad35: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x1028ae30L);
                else             current = static_cast<FUN_10285dc0_State>(0x1028ad8eL);
                break;
            }
            case 0x1028ad8e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ae30L : 0x1028ad9dL);
                break;
            }
            case 0x1028ad9d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028add4L : 0x1028adb8L);
                break;
            }
            case 0x1028adb8: {
                current = static_cast<FUN_10285dc0_State>(0x1028adc0L);
                break;
            }
            case 0x1028adc0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028add1L));
                break;
            }
            case 0x1028add1: {
                current = static_cast<FUN_10285dc0_State>(0x1028add4L);
                break;
            }
            case 0x1028add4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028adf0L : 0x1028ade0L);
                break;
            }
            case 0x1028ade0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028adf0L));
                break;
            }
            case 0x1028adf0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ae30L : 0x1028adf8L);
                break;
            }
            case 0x1028adf8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ae30L : 0x1028ae0aL);
                break;
            }
            case 0x1028ae0a: {
                current = static_cast<FUN_10285dc0_State>(0x1028ae30L);
                break;
            }
            case 0x1028ae30: {
                current = static_cast<FUN_10285dc0_State>(0x1028ae70L);
                break;
            }
            case 0x1028ae70: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028af51L : 0x1028ae8fL);
                break;
            }
            case 0x1028ae8f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028af51L : 0x1028ae97L);
                break;
            }
            case 0x1028ae97: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028af51L : 0x1028aea0L);
                break;
            }
            case 0x1028aea0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028aedaL : 0x1028aebfL);
                break;
            }
            case 0x1028aebf: {
                current = static_cast<FUN_10285dc0_State>(0x1028aec3L);
                break;
            }
            case 0x1028aec3: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028aed4L));
                break;
            }
            case 0x1028aed4: {
                current = static_cast<FUN_10285dc0_State>(0x1028aedaL);
                break;
            }
            case 0x1028aeda: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028aef0L : 0x1028aedeL);
                break;
            }
            case 0x1028aede: {
                current = static_cast<FUN_10285dc0_State>(0x1028aee0L);
                break;
            }
            case 0x1028aee0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028aef0L));
                break;
            }
            case 0x1028aef0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028af3eL : 0x1028aef5L);
                break;
            }
            case 0x1028aef5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028af3eL : 0x1028af07L);
                break;
            }
            case 0x1028af07: {
                current = static_cast<FUN_10285dc0_State>(0x1028af43L);
                break;
            }
            case 0x1028af3e: {
                current = static_cast<FUN_10285dc0_State>(0x1028af41L);
                break;
            }
            case 0x1028af41: {
                current = static_cast<FUN_10285dc0_State>(0x1028af43L);
                break;
            }
            case 0x1028af43: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ae70L : 0x1028af57L);
                break;
            }
            case 0x1028af57: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b0c1L : 0x1028af65L);
                break;
            }
            case 0x1028af65: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b0c1L : 0x1028af6aL);
                break;
            }
            case 0x1028af6a: {
                current = static_cast<FUN_10285dc0_State>(0x1028af6dL);
                break;
            }
            case 0x1028af6d: {
                current = static_cast<FUN_10285dc0_State>(0x1028af7aL);
                break;
            }
            case 0x1028af7a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b097L : 0x1028af7fL);
                break;
            }
            case 0x1028af7f: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b097L : 0x1028af83L);
                break;
            }
            case 0x1028af83: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b097L : 0x1028af89L);
                break;
            }
            case 0x1028af89: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028afa6L : 0x1028af8fL);
                break;
            }
            case 0x1028af8f: {
                current = static_cast<FUN_10285dc0_State>(0x1028af93L);
                break;
            }
            case 0x1028af93: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028afa3L));
                break;
            }
            case 0x1028afa3: {
                current = static_cast<FUN_10285dc0_State>(0x1028afa6L);
                break;
            }
            case 0x1028afa6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028afbeL : 0x1028afaeL);
                break;
            }
            case 0x1028afae: {
                current = static_cast<FUN_10285dc0_State>(0x1028afb0L);
                break;
            }
            case 0x1028afb0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028afbeL));
                break;
            }
            case 0x1028afbe: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b054L : 0x1028afbfL);
                break;
            }
            case 0x1028afbf: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b054L : 0x1028afcaL);
                break;
            }
            case 0x1028afca: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b054L : 0x1028afdaL);
                break;
            }
            case 0x1028afda: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b00eL : 0x1028b002L);
                break;
            }
            case 0x1028b002: {
                current = static_cast<FUN_10285dc0_State>(0x1028b057L);
                break;
            }
            case 0x1028b00e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b057L : 0x1028b025L);
                break;
            }
            case 0x1028b025: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b057L : 0x1028b033L);
                break;
            }
            case 0x1028b033: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b04fL : 0x1028b037L);
                break;
            }
            case 0x1028b037: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b04fL : 0x1028b03eL);
                break;
            }
            case 0x1028b03e: {
                current = static_cast<FUN_10285dc0_State>(0x1028b057L);
                break;
            }
            case 0x1028b04f: {
                current = static_cast<FUN_10285dc0_State>(0x1028b057L);
                break;
            }
            case 0x1028b054: {
                current = static_cast<FUN_10285dc0_State>(0x1028b057L);
                break;
            }
            case 0x1028b057: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b097L : 0x1028b05bL);
                break;
            }
            case 0x1028b05b: {
                current = static_cast<FUN_10285dc0_State>(0x1028b06eL);
                break;
            }
            case 0x1028b06e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b097L : 0x1028b077L);
                break;
            }
            case 0x1028b077: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b097L : 0x1028b082L);
                break;
            }
            case 0x1028b082: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b097L : 0x1028b08bL);
                break;
            }
            case 0x1028b08b: {
                current = static_cast<FUN_10285dc0_State>(0x1028b097L);
                break;
            }
            case 0x1028b097: {
                current = static_cast<FUN_10285dc0_State>(0x1028b09eL);
                break;
            }
            case 0x1028b09e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b0a8L : 0x1028b097L);
                break;
            }
            case 0x1028b0a8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b0c7L : 0x1028b0b2L);
                break;
            }
            case 0x1028b0b2: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028b0c7L));
                break;
            }
            case 0x1028b0c1: {
                current = static_cast<FUN_10285dc0_State>(0x1028b0c7L);
                break;
            }
            case 0x1028b0c7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b20bL : 0x1028b0d0L);
                break;
            }
            case 0x1028b0d0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b20bL : 0x1028b0d6L);
                break;
            }
            case 0x1028b0d6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b20bL : 0x1028b0dcL);
                break;
            }
            case 0x1028b0dc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b20bL : 0x1028b0eaL);
                break;
            }
            case 0x1028b0ea: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b20bL : 0x1028b0fbL);
                break;
            }
            case 0x1028b0fb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b11eL : 0x1028b101L);
                break;
            }
            case 0x1028b101: {
                current = static_cast<FUN_10285dc0_State>(0x1028b105L);
                break;
            }
            case 0x1028b105: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b11eL : 0x1028b10bL);
                break;
            }
            case 0x1028b10b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b105L : 0x1028b11eL);
                break;
            }
            case 0x1028b11e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b164L : 0x1028b123L);
                break;
            }
            case 0x1028b123: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b164L : 0x1028b129L);
                break;
            }
            case 0x1028b129: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b164L : 0x1028b14bL);
                break;
            }
            case 0x1028b14b: {
                current = static_cast<FUN_10285dc0_State>(0x1028b164L);
                break;
            }
            case 0x1028b164: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b1aaL : 0x1028b178L);
                break;
            }
            case 0x1028b178: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b1aaL : 0x1028b183L);
                break;
            }
            case 0x1028b183: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b1aaL : 0x1028b196L);
                break;
            }
            case 0x1028b196: {
                current = static_cast<FUN_10285dc0_State>(0x1028b1aaL);
                break;
            }
            case 0x1028b1aa: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b1f8L : 0x1028b1beL);
                break;
            }
            case 0x1028b1be: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b1f8L : 0x1028b1c9L);
                break;
            }
            case 0x1028b1c9: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b1f8L : 0x1028b1e2L);
                break;
            }
            case 0x1028b1e2: {
                current = static_cast<FUN_10285dc0_State>(0x1028b1f8L);
                break;
            }
            case 0x1028b1f8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b20bL : 0x1028b1fdL);
                break;
            }
            case 0x1028b1fd: {
                current = static_cast<FUN_10285dc0_State>(0x1028b20bL);
                break;
            }
            case 0x1028b20b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b23aL : 0x1028b20fL);
                break;
            }
            case 0x1028b20f: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028b220L));
                break;
            }
            case 0x1028b220: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b23aL : 0x1028b22aL);
                break;
            }
            case 0x1028b22a: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028b23aL));
                break;
            }
            case 0x1028b23a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b83dL : 0x1028b240L);
                break;
            }
            case 0x1028b240: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b83dL : 0x1028b252L);
                break;
            }
            case 0x1028b252: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b83dL : 0x1028b25bL);
                break;
            }
            case 0x1028b25b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b803L : 0x1028b26bL);
                break;
            }
            case 0x1028b26b: {
                current = static_cast<FUN_10285dc0_State>(0x1028b2a0L);
                break;
            }
            case 0x1028b2a0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b2bcL : 0x1028b2b5L);
                break;
            }
            case 0x1028b2b5: {
                current = static_cast<FUN_10285dc0_State>(0x1028b2ccL);
                break;
            }
            case 0x1028b2bc: {
                current = static_cast<FUN_10285dc0_State>(0x1028b2ccL);
                break;
            }
            case 0x1028b2cc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b2a0L : 0x1028b2eaL);
                break;
            }
            case 0x1028b2ea: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b3bdL : 0x1028b2eeL);
                break;
            }
            case 0x1028b2ee: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b3bdL : 0x1028b2f5L);
                break;
            }
            case 0x1028b2f5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b3bdL : 0x1028b30aL);
                break;
            }
            case 0x1028b30a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b335L : 0x1028b313L);
                break;
            }
            case 0x1028b313: {
                current = static_cast<FUN_10285dc0_State>(0x1028b317L);
                break;
            }
            case 0x1028b317: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b335L : 0x1028b320L);
                break;
            }
            case 0x1028b320: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b317L : 0x1028b335L);
                break;
            }
            case 0x1028b335: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b3bdL : 0x1028b339L);
                break;
            }
            case 0x1028b339: {
                current = static_cast<FUN_10285dc0_State>(0x1028b340L);
                break;
            }
            case 0x1028b340: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b3bdL : 0x1028b34dL);
                break;
            }
            case 0x1028b34d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b340L : 0x1028b3bdL);
                break;
            }
            case 0x1028b3bd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b83aL : 0x1028b3c0L);
                break;
            }
            case 0x1028b3c0: {
                current = static_cast<FUN_10285dc0_State>(0x1028b3c3L);
                break;
            }
            case 0x1028b3c3: {
                current = static_cast<FUN_10285dc0_State>(0x1028b83dL);
                break;
            }
            case 0x1028b803: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b83dL : 0x1028b816L);
                break;
            }
            case 0x1028b816: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028b83dL : 0x1028b81aL);
                break;
            }
            case 0x1028b81a: {
                current = static_cast<FUN_10285dc0_State>(0x1028b840L);
                break;
            }
            case 0x1028b83a: {
                current = static_cast<FUN_10285dc0_State>(0x1028b83dL);
                break;
            }
            case 0x1028b83d: {
                current = static_cast<FUN_10285dc0_State>(0x1028b840L);
                break;
            }
            case 0x1028b840: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028b87fL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028b87f: {
                current = static_cast<FUN_10285dc0_State>(0x1028b888L);
                break;
            }
            case 0x1028b888: {
                current = static_cast<FUN_10285dc0_State>(0x1028b88bL);
                break;
            }
            case 0x1028b88b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028ad0eL : 0x1028b89aL);
                break;
            }
            case 0x1028b89a: {
                current = static_cast<FUN_10285dc0_State>(0x1028b900L);
                break;
            }
            case 0x1028b900: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028b93dL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028b93d: {
                current = static_cast<FUN_10285dc0_State>(0x1028b970L);
                break;
            }
            case 0x1028b970: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028b9adL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028b9ad: {
                current = static_cast<FUN_10285dc0_State>(0x1028b0c7L);
                break;
            }
            case 0x1028bdc2: {
                return { current, false, false };
            }
            case 0x1028bc0dL: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bd5fL : 0x1028bc20L);
                break;
            }
            case 0x1028bc20: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x1028bc23L));
                break;
            }
            case 0x1028bc23: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028bc23L : 0x1028bdaeL);
                break;
            }
            case 0x1028bdae: {
                current = static_cast<FUN_10285dc0_State>(0x1028bdc2L);
                break;
            }
            case 0x1028bd5f: {
                current = static_cast<FUN_10285dc0_State>(0x1028bdaeL);
                break;
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
