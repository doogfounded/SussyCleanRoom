#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "FUN_10285dc0.h"
#include "FUN_10285dc0_regions.h"

struct RegionProbe {
    int region_id;
    std::string name;
    uint32_t entry_state;
    void (*handler)(DoogEngine1::BufferContext&, DoogEngine1::FUN_10285dc0_State);
};

// Wrapper dispatch table for all 13 core region handlers
void call_region_0(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case0(ctx, s); }
void call_region_1(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case1(ctx, s); }
void call_region_2(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case2(ctx, s); }
void call_region_3(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case3(ctx, s); }
void call_region_4(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case4(ctx, s); }
void call_region_5(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case5(ctx, s); }
void call_region_6(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case6(ctx, s); }
void call_region_7(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case7(ctx, s); }
void call_region_8(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case8(ctx, s); }
void call_region_9(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s)  { DoogEngine1::ProcessCoreLoopRegion_Case9(ctx, s); }
void call_region_10(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s) { DoogEngine1::ProcessCoreLoopRegion_Case10(ctx, s); }
void call_region_11(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s) { DoogEngine1::ProcessCoreLoopRegion_Case11(ctx, s); }
void call_region_12(DoogEngine1::BufferContext& ctx, DoogEngine1::FUN_10285dc0_State s) { DoogEngine1::ProcessCoreLoopRegion_Case2(ctx, s); }

void run_territory_blitz() {
    std::cout << "\n========================================================================\n";
    std::cout << "                 DOOG ENGINE: 13-REGION TERRITORY BLITZ                  \n";
    std::cout << "========================================================================\n";

    // Known / Representative entry states for each region
    std::vector<RegionProbe> probes = {
        { 0,  "Region 0  (Entry Guard)",   0x10285dc0, call_region_0 },
        { 1,  "Region 1  (Opcode Pump)",   0x10286a40, call_region_1 },
        { 2,  "Region 2  (Core Case 2)",   0x10287390, call_region_2 },
        { 3,  "Region 3  (Core Case 3)",   0x10287e00, call_region_3 },
        { 4,  "Region 4  (Core Case 4)",   0x10288800, call_region_4 },
        { 5,  "Region 5  (Core Case 5)",   0x10289200, call_region_5 },
        { 6,  "Region 6  (Core Case 6)",   0x10289c00, call_region_6 },
        { 7,  "Region 7  (Core Case 7)",   0x1028a600, call_region_7 },
        { 8,  "Region 8  (Core Case 8)",   0x1028b000, call_region_8 },
        { 9,  "Region 9  (Core Case 9)",   0x1028ba00, call_region_9 },
        { 10, "Region 10 (Core Case 10)",  0x1028c400, call_region_10 },
        { 11, "Region 11 (Core Case 11)",  0x1028ce00, call_region_11 },
        { 12, "Region 12 (Core Case 12)",  0x1028d800, call_region_12 },
    };

    std::cout << std::left 
              << std::setw(6)  << "ID" 
              << std::setw(26) << "Region Name" 
              << std::setw(14) << "Entry State" 
              << std::setw(12) << "Consumed" 
              << std::setw(10) << "Overflow" 
              << "Status\n";
    std::cout << std::string(72, '-') << "\n";

    for (const auto& p : probes) {
        // Prepare standard 64-byte active test payload
        std::vector<uint8_t> payload = { 0x01, 0x00, 0x02, 0x10, 0x20, 0x30, 0x40, 0x00 };
        payload.resize(64, 0x00);

        DoogEngine1::BufferContext ctx;
        ctx.buffer = payload;
        ctx.cursor = 0;
        ctx.has_overflow = false;

        auto state = static_cast<DoogEngine1::FUN_10285dc0_State>(p.entry_state);

        // Execute the region handler
        p.handler(ctx, state);

        std::string status = "Yield (0 bytes)";
        if (ctx.cursor > 0) status = "Active (" + std::to_string(ctx.cursor) + " bytes)";
        if (ctx.has_overflow) status = "OVERFLOW";

        std::cout << std::left 
                  << std::setw(6)  << p.region_id 
                  << std::setw(26) << p.name 
                  << "0x" << std::hex << std::setw(12) << p.entry_state << std::dec
                  << std::setw(12) << ctx.cursor 
                  << std::setw(10) << (ctx.has_overflow ? "TRUE" : "FALSE") 
                  << status << "\n";
    }

    std::cout << std::string(72, '-') << "\n";
    std::cout << "Territory Blitz complete.\n";
}

int main() {
    run_territory_blitz();
    return 0;
}