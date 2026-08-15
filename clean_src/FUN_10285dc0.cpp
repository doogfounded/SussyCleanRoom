#include "FUN_10285dc0.h"
#include "FUN_10285dc0_regions.h"

namespace DoogEngine1 {

void FUN_10285dc0(BufferContext& ctx) {
    FUN_10285dc0_State current_state = FUN_10285dc0_State::ENTRY;

    while (current_state != FUN_10285dc0_State::EXIT && current_state != FUN_10285dc0_State::ERROR) {
        int region = classify_region(current_state);
        RegionResult res;
        switch (region) {
            case 0:  res = ProcessEntryRegion(ctx, current_state); break;
            case 1:  res = ProcessCoreLoopRegion_Case0(ctx, current_state); break;
            case 2:  res = ProcessCoreLoopRegion_Case1(ctx, current_state); break;
            case 3:  res = ProcessCoreLoopRegion_Case2(ctx, current_state); break;
            case 4:  res = ProcessCoreLoopRegion_Case3(ctx, current_state); break;
            case 5:  res = ProcessCoreLoopRegion_Case4(ctx, current_state); break;
            case 6:  res = ProcessCoreLoopRegion_Case5(ctx, current_state); break;
            case 7:  res = ProcessCoreLoopRegion_Case6(ctx, current_state); break;
            case 8:  res = ProcessCoreLoopRegion_Case7(ctx, current_state); break;
            case 9:  res = ProcessCoreLoopRegion_Case8(ctx, current_state); break;
            case 10: res = ProcessCoreLoopRegion_Case9(ctx, current_state); break;
            case 11: res = ProcessCoreLoopRegion_Case10(ctx, current_state); break;
            case 12: res = ProcessCoreLoopRegion_Case11(ctx, current_state); break;
            default:
                current_state = FUN_10285dc0_State::ERROR;
                goto loop_end;
        }
        current_state = res.next;
        if (res.finished) break;
        if (res.error) {
            current_state = FUN_10285dc0_State::ERROR;
            break;
        }
    }

loop_end:
    if (current_state == FUN_10285dc0_State::ERROR) {
        ctx.has_overflow = true;
    }
}

} // namespace DoogEngine1
