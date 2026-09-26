#include <iostream>
#include <vector>
#include <cstdint>
#include <iomanip>
#include "FUN_10285dc0.h"
#include "FUN_10285dc0_regions.h"

using namespace DoogEngine1;

void sweep_r4_byte0() {
    std::cout << "B0   B1   B2   consumed   destination\n";
    std::cout << "-------------------------------------\n";

    const uint8_t b1 = 0x00;
    const uint8_t b2 = 0x01;

    uint32_t last_consumed = 0xFFFFFFFF;
    uint32_t last_dest = 0xFFFFFFFF;

    for (int b0_val = 0; b0_val <= 0xFF; ++b0_val) {
        uint8_t b0 = static_cast<uint8_t>(b0_val);

        std::vector<uint8_t> data(128, 0x00);
        data[0] = b0;
        data[1] = b1;
        data[2] = b2;

        for (int i = 3; i < 64; ++i) {
            data[i] = static_cast<uint8_t>(i);
        }

        BufferContext ctx;
        ctx.cursor = 0;
        ctx.has_overflow = false;
        ctx.buffer = data;

        FUN_10285dc0_State current_state = static_cast<FUN_10285dc0_State>(0x10287fc0);
        RegionResult res = ProcessCoreLoopRegion_Case3(ctx, current_state);

        uint32_t final_state_val = static_cast<uint32_t>(res.next);

        if (ctx.cursor != last_consumed || final_state_val != last_dest || b0_val <= 4 || b0_val == 0xFF) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << b0_val << "   "
                      << std::hex << std::setw(2) << std::setfill('0') << (int)b1 << "   "
                      << std::hex << std::setw(2) << std::setfill('0') << (int)b2 << "      "
                      << std::dec << std::setw(2) << std::setfill(' ') << ctx.cursor << "      "
                      << std::hex << std::setw(8) << std::setfill('0') << final_state_val << "\n";

            last_consumed = ctx.cursor;
            last_dest = final_state_val;
        }
    }
}

int main() {
    sweep_r4_byte0();
    return 0;
}