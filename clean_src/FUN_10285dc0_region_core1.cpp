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

RegionResult ProcessCoreLoopRegion_Case1(BufferContext& ctx, FUN_10285dc0_State state) {
    FUN_10285dc0_State current = state;

    while (true) {
        if (classify_region(current) != 2) {
            return { current, false, false };
        }

        switch (static_cast<uint32_t>(current)) {
            case 0x10286a40: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286a8bL : 0x10286a81L);
                break;
            }
            case 0x10286a81: {
                current = static_cast<FUN_10285dc0_State>(0x10286a8eL);
                break;
            }
            case 0x10286a8b: {
                current = static_cast<FUN_10285dc0_State>(0x10286a8eL);
                break;
            }
            case 0x10286a8e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287372L : 0x10286ab5L);
                break;
            }
            case 0x10286ab5: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x10286bbdL);
                else             current = static_cast<FUN_10285dc0_State>(0x10286b27L);
                break;
            }
            case 0x10286b27: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286bbdL : 0x10286b39L);
                break;
            }
            case 0x10286b39: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286b6aL : 0x10286b52L);
                break;
            }
            case 0x10286b52: {
                current = static_cast<FUN_10285dc0_State>(0x10286b56L);
                break;
            }
            case 0x10286b56: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286b67L));
                break;
            }
            case 0x10286b67: {
                current = static_cast<FUN_10285dc0_State>(0x10286b6aL);
                break;
            }
            case 0x10286b6a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286b80L : 0x10286b6eL);
                break;
            }
            case 0x10286b6e: {
                current = static_cast<FUN_10285dc0_State>(0x10286b70L);
                break;
            }
            case 0x10286b70: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286b80L));
                break;
            }
            case 0x10286b80: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286bbdL : 0x10286b88L);
                break;
            }
            case 0x10286b88: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286bbdL : 0x10286b9aL);
                break;
            }
            case 0x10286b9a: {
                current = static_cast<FUN_10285dc0_State>(0x10286bc0L);
                break;
            }
            case 0x10286bbd: {
                current = static_cast<FUN_10285dc0_State>(0x10286bc0L);
                break;
            }
            case 0x10286bc0: {
                current = static_cast<FUN_10285dc0_State>(0x10286bf0L);
                break;
            }
            case 0x10286bf0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286ccbL : 0x10286c1cL);
                break;
            }
            case 0x10286c1c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286ccbL : 0x10286c24L);
                break;
            }
            case 0x10286c24: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286ccbL : 0x10286c2dL);
                break;
            }
            case 0x10286c2d: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286c67L : 0x10286c46L);
                break;
            }
            case 0x10286c46: {
                current = static_cast<FUN_10285dc0_State>(0x10286c50L);
                break;
            }
            case 0x10286c50: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286c67L));
                break;
            }
            case 0x10286c67: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286c80L : 0x10286c6bL);
                break;
            }
            case 0x10286c6b: {
                current = static_cast<FUN_10285dc0_State>(0x10286c70L);
                break;
            }
            case 0x10286c70: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286c80L));
                break;
            }
            case 0x10286c80: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286cc8L : 0x10286c88L);
                break;
            }
            case 0x10286c88: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286d21L : 0x10286caaL);
                break;
            }
            case 0x10286caa: {
                current = static_cast<FUN_10285dc0_State>(0x10286cceL);
                break;
            }
            case 0x10286cc8: {
                current = static_cast<FUN_10285dc0_State>(0x10286ccbL);
                break;
            }
            case 0x10286ccb: {
                current = static_cast<FUN_10285dc0_State>(0x10286cceL);
                break;
            }
            case 0x10286cce: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286bf0L : 0x10286cdeL);
                break;
            }
            case 0x10286cde: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287276L : 0x10286cf7L);
                break;
            }
            case 0x10286cf7: {
                current = static_cast<FUN_10285dc0_State>(0x10286d04L);
                break;
            }
            case 0x10286d04: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286d26L : 0x10286d14L);
                break;
            }
            case 0x10286d14: {
                current = static_cast<FUN_10285dc0_State>(0x10286d28L);
                break;
            }
            case 0x10286d21: {
                current = static_cast<FUN_10285dc0_State>(0x10286cceL);
                break;
            }
            case 0x10286d26: {
                current = static_cast<FUN_10285dc0_State>(0x10286d28L);
                break;
            }
            case 0x10286d28: {
                uint8_t b = read_byte(ctx);
                if (b == 0)      current = static_cast<FUN_10285dc0_State>(0x103282d0L); // EXIT SINK
                else if (b == 1) current = static_cast<FUN_10285dc0_State>(0x10286e32L);
                else             current = static_cast<FUN_10285dc0_State>(0x10286d9aL);
                break;
            }
            case 0x10286d9a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286e32L : 0x10286dadL);
                break;
            }
            case 0x10286dad: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286de4L : 0x10286dc6L);
                break;
            }
            case 0x10286dc6: {
                current = static_cast<FUN_10285dc0_State>(0x10286dd0L);
                break;
            }
            case 0x10286dd0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286de4L));
                break;
            }
            case 0x10286de4: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286df8L : 0x10286de8L);
                break;
            }
            case 0x10286de8: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286df8L));
                break;
            }
            case 0x10286df8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286e32L : 0x10286e00L);
                break;
            }
            case 0x10286e00: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286e32L : 0x10286e12L);
                break;
            }
            case 0x10286e12: {
                current = static_cast<FUN_10285dc0_State>(0x10286e32L);
                break;
            }
            case 0x10286e32: {
                current = static_cast<FUN_10285dc0_State>(0x10286e60L);
                break;
            }
            case 0x10286e60: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286f32L : 0x10286e86L);
                break;
            }
            case 0x10286e86: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286f32L : 0x10286e8eL);
                break;
            }
            case 0x10286e8e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286f32L : 0x10286e97L);
                break;
            }
            case 0x10286e97: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286eccL : 0x10286eb0L);
                break;
            }
            case 0x10286eb0: {
                current = static_cast<FUN_10285dc0_State>(0x10286eb5L);
                break;
            }
            case 0x10286eb5: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286eccL));
                break;
            }
            case 0x10286ecc: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286ee0L : 0x10286ed0L);
                break;
            }
            case 0x10286ed0: {
                current = safe_copy_loop(ctx, 256, [](BufferContext& c) {
                    return (read_byte(c) & 1) != 0;
                }, static_cast<FUN_10285dc0_State>(0x10286ee0L));
                break;
            }
            case 0x10286ee0: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286f2fL : 0x10286eebL);
                break;
            }
            case 0x10286eeb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286f2fL : 0x10286f0aL);
                break;
            }
            case 0x10286f0a: {
                current = static_cast<FUN_10285dc0_State>(0x10286f38L);
                break;
            }
            case 0x10286f2f: {
                current = static_cast<FUN_10285dc0_State>(0x10286f32L);
                break;
            }
            case 0x10286f32: {
                current = static_cast<FUN_10285dc0_State>(0x10286f38L);
                break;
            }
            case 0x10286f38: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286e60L : 0x10286f48L);
                break;
            }
            case 0x10286f48: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286f90L : 0x10286f60L);
                break;
            }
            case 0x10286f60: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286f93L : 0x10286f83L);
                break;
            }
            case 0x10286f83: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286f93L : 0x10286f8bL);
                break;
            }
            case 0x10286f8b: {
                current = static_cast<FUN_10285dc0_State>(0x10286d04L);
                break;
            }
            case 0x10286f90: {
                current = static_cast<FUN_10285dc0_State>(0x10286f93L);
                break;
            }
            case 0x10286f93: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287017L : 0x10286fb5L);
                break;
            }
            case 0x10286fb5: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286fc7L : 0x10286fc3L);
                break;
            }
            case 0x10286fc3: {
                current = static_cast<FUN_10285dc0_State>(0x1028701aL);
                break;
            }
            case 0x10286fc7: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286fd3L : 0x10286fccL);
                break;
            }
            case 0x10286fcc: {
                current = static_cast<FUN_10285dc0_State>(0x1028701aL);
                break;
            }
            case 0x10286fd3: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286febL : 0x10286fd8L);
                break;
            }
            case 0x10286fd8: {
                current = static_cast<FUN_10285dc0_State>(0x1028701aL);
                break;
            }
            case 0x10286feb: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286fffL : 0x10286ff0L);
                break;
            }
            case 0x10286ff0: {
                current = static_cast<FUN_10285dc0_State>(0x1028701aL);
                break;
            }
            case 0x10286fff: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028700bL : 0x10287004L);
                break;
            }
            case 0x10287004: {
                current = static_cast<FUN_10285dc0_State>(0x1028701aL);
                break;
            }
            case 0x1028700b: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287017L : 0x10287010L);
                break;
            }
            case 0x10287010: {
                current = static_cast<FUN_10285dc0_State>(0x1028701aL);
                break;
            }
            case 0x10287017: {
                current = static_cast<FUN_10285dc0_State>(0x1028701aL);
                break;
            }
            case 0x1028701a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287038L : 0x10287021L);
                break;
            }
            case 0x10287021: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287038L : 0x10287025L);
                break;
            }
            case 0x10287025: {
                current = static_cast<FUN_10285dc0_State>(0x10287038L);
                break;
            }
            case 0x10287038: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287054L : 0x10287050L);
                break;
            }
            case 0x10287050: {
                current = static_cast<FUN_10285dc0_State>(0x102870b8L);
                break;
            }
            case 0x10287054: {
                current = static_cast<FUN_10285dc0_State>(0x102870b8L);
                break;
            }
            case 0x102870b8: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102870dbL : 0x102870d6L);
                break;
            }
            case 0x102870d6: {
                current = static_cast<FUN_10285dc0_State>(0x1028712aL);
                break;
            }
            case 0x102870db: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102870faL : 0x102870e3L);
                break;
            }
            case 0x102870e3: {
                current = static_cast<FUN_10285dc0_State>(0x1028712aL);
                break;
            }
            case 0x102870fa: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287110L : 0x10287102L);
                break;
            }
            case 0x10287102: {
                current = static_cast<FUN_10285dc0_State>(0x1028712aL);
                break;
            }
            case 0x10287110: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028711fL : 0x10287118L);
                break;
            }
            case 0x10287118: {
                current = static_cast<FUN_10285dc0_State>(0x1028712aL);
                break;
            }
            case 0x1028711f: {
                current = static_cast<FUN_10285dc0_State>(0x1028712aL);
                break;
            }
            case 0x1028712a: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287137L : 0x1028712fL);
                break;
            }
            case 0x1028712f: {
                current = static_cast<FUN_10285dc0_State>(0x10287171L);
                break;
            }
            case 0x10287137: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287156L : 0x1028713fL);
                break;
            }
            case 0x1028713f: {
                current = static_cast<FUN_10285dc0_State>(0x10287171L);
                break;
            }
            case 0x10287156: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028716cL : 0x1028715eL);
                break;
            }
            case 0x1028715e: {
                current = static_cast<FUN_10285dc0_State>(0x10287171L);
                break;
            }
            case 0x1028716c: {
                current = static_cast<FUN_10285dc0_State>(0x10287171L);
                break;
            }
            case 0x10287171: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102871a9L : 0x10287188L);
                break;
            }
            case 0x10287188: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102871a9L : 0x1028718eL);
                break;
            }
            case 0x1028718e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102871a9L : 0x10287194L);
                break;
            }
            case 0x10287194: {
                current = static_cast<FUN_10285dc0_State>(0x102871d6L);
                break;
            }
            case 0x102871a9: {
                current = static_cast<FUN_10285dc0_State>(0x102871d6L);
                break;
            }
            case 0x102871d6: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028722eL : 0x10287210L);
                break;
            }
            case 0x10287210: {
                current = static_cast<FUN_10285dc0_State>(0x1028722eL);
                break;
            }
            case 0x1028722e: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x1028726eL : 0x10287232L);
                break;
            }
            case 0x10287232: {
                current = static_cast<FUN_10285dc0_State>(0x10287235L);
                break;
            }
            case 0x10287235: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028726bL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028726b: {
                current = static_cast<FUN_10285dc0_State>(0x1028726eL);
                break;
            }
            case 0x1028726e: {
                current = static_cast<FUN_10285dc0_State>(0x1028735bL);
                break;
            }
            case 0x10287276: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287361L : 0x1028728cL);
                break;
            }
            case 0x1028728c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x102872fdL : 0x1028729cL);
                break;
            }
            case 0x1028729c: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287361L : 0x102872acL);
                break;
            }
            case 0x102872ac: {
                current = static_cast<FUN_10285dc0_State>(0x102872c0L);
                break;
            }
            case 0x102872c0: {
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
                        current = static_cast<FUN_10285dc0_State>(0x102872fbL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x102872fb: {
                current = static_cast<FUN_10285dc0_State>(0x1028735bL);
                break;
            }
            case 0x102872fd: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10287361L : 0x10287309L);
                break;
            }
            case 0x10287309: {
                current = static_cast<FUN_10285dc0_State>(0x10287320L);
                break;
            }
            case 0x10287320: {
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
                        current = static_cast<FUN_10285dc0_State>(0x1028735bL);
                        keep_looping = false;
                    }
                }
                if (max_iters == 0 && keep_looping) {
                    ctx.has_overflow = true;
                    current = FUN_10285dc0_State::ERROR;
                }
                break;
            }
            case 0x1028735b: {
                current = static_cast<FUN_10285dc0_State>(0x10287361L);
                break;
            }
            case 0x10287361: {
                uint8_t b = read_byte(ctx);
                current = static_cast<FUN_10285dc0_State>((b & 1) ? 0x10286ab5L : 0x10287372L);
                break;
            }
            case 0x10287372: {
                return { current, false, false };
            }
            default:
                return { FUN_10285dc0_State::ERROR, false, true };
        }
    }
}

} // namespace DoogEngine1
