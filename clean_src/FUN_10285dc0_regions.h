#pragma once
#include "FUN_10285dc0.h"

namespace DoogEngine1 {

inline int classify_region(FUN_10285dc0_State state) {
    uint32_t val = static_cast<uint32_t>(state);
    if (val >= 0x10285dc0 && val <= 0x10285e4b) return 0;
    if (val >= 0x10285ed0 && val <= 0x10286a19) return 1;
    if (val >= 0x10286a40 && val <= 0x10287372) return 2;
    if (val >= 0x10287390 && val <= 0x10287f9e) return 3;
    if (val >= 0x10287fc0 && val <= 0x10288d00) return 4;
    if (val >= 0x10288d10 && val <= 0x10289c99) return 5;
    if (val >= 0x10289cc0 && val <= 0x1028ac96) return 6;
    if (val >= 0x1028acc0 && val <= 0x1028bdc2) return 7;
    if (val >= 0x1028bdf0 && val <= 0x1028ccf8) return 8;
    if (val >= 0x1028cd20 && val <= 0x1028d720) return 9;
    if (val >= 0x1028d720 && val <= 0x1028e3e0) return 10;
    if (val >= 0x1028e3e0 && val <= 0x1028f3d7) return 11;
    if (val >= 0x1028f400 && val <= 0x10290664) return 12;
    return -1;
}

template<typename Fn>
inline FUN_10285dc0_State safe_copy_loop(
    BufferContext& ctx,
    size_t max_iterations,
    Fn&& body_fn,
    FUN_10285dc0_State exit_state)
{
    for (size_t i = 0; i < max_iterations; ++i) {
        if (!body_fn(ctx)) {
            return exit_state;
        }
    }
    ctx.has_overflow = true;
    return FUN_10285dc0_State::ERROR;
}

} // namespace DoogEngine1
