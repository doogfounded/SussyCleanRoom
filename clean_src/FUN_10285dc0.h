#pragma once
#include <cstdint>
#include <span>

namespace DoogEngine1 {

struct BufferContext {
    std::span<const uint8_t> buffer;
    size_t cursor = 0;
    bool has_overflow = false;
};

enum class FUN_10285dc0_State : uint32_t {
    ENTRY = 0x10285dc0,
    EXIT = 0x103282d0,
    ERROR = 0x103281d0,
    
    // Core loop states
    S_10285dd1 = 0x10285dd1,
    S_10285dd8 = 0x10285dd8,
    S_10285ddf = 0x10285ddf,
    S_10285de8 = 0x10285de8,
    S_10285df1 = 0x10285df1,
    S_10285dfa = 0x10285dfa,
    S_10285e03 = 0x10285e03,
    S_10285e0c = 0x10285e0c,
    S_10285e15 = 0x10285e15,
    S_10285e1e = 0x10285e1e,
    S_10285e27 = 0x10285e27,
    S_10285e30 = 0x10285e30,
    S_10285e39 = 0x10285e39,
    S_10285e42 = 0x10285e42,
    S_10285e4b = 0x10285e4b,
};

struct RegionResult {
    FUN_10285dc0_State next;
    bool finished;
    bool error;
};

// Declaring FUN_10285dc0
void FUN_10285dc0(BufferContext& ctx);

// Region functions
RegionResult ProcessEntryRegion(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case0(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case1(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case2(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case3(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case4(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case5(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case6(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case7(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case8(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case9(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case10(BufferContext& ctx, FUN_10285dc0_State state);
RegionResult ProcessCoreLoopRegion_Case11(BufferContext& ctx, FUN_10285dc0_State state);

} // namespace DoogEngine1
