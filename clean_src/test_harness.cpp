#include <iostream>
#include <vector>
#include <cstdint>
#include <iomanip>
#include "FUN_10285dc0.h"
#include "FUN_10285dc0_regions.h"

using namespace DoogEngine1;

void probe_r2_table() {
    std::cout << "========================================================\n";
    std::cout << "       DOOG ENGINE: REGION 2 TABLE INDEX PROBE          \n";
    std::cout << "========================================================\n";
    std::cout << "BytePos | TestedVal | Consumed | NewState     | Result\n";
    std::cout << "--------------------------------------------------------\n";

    uint8_t test_vals[] = { 0x00, 0x01, 0x02, 0x03, 0x08, 0x0F, 0x10, 0x1F, 0x7F, 0x80, 0xFF };

    for (int byte_pos = 0; byte_pos < 2; ++byte_pos) {
        for (uint8_t val : test_vals) {
            BufferContext ctx;
          std::vector<uint8_t> data(64, 0x00);   // owns the memory, lives for the whole function/scope
          data[byte_pos] = val;                  // mutate the actual storage
          ctx.cursor = 0;
          ctx.buffer = data;                     // span now safely views `data`
            ctx.has_overflow = false;

            FUN_10285dc0_State current_state = static_cast<FUN_10285dc0_State>(0x10287390);

            // Execute Region 2
            RegionResult res = ProcessCoreLoopRegion_Case2(ctx, current_state);

            size_t consumed = ctx.cursor;

            std::cout << "Byte " << byte_pos << "  | 0x" 
                      << std::hex << std::setw(2) << std::setfill('0') << (int)val << "    | "
                      << std::dec << std::setw(8) << consumed << " | 0x"
                      << std::hex << static_cast<uint32_t>(current_state) << "   | ";

            if (consumed == 38) {
                std::cout << "Full 38B Block\n";
            } else if (consumed == 0) {
                std::cout << "Yield / 0B\n";
            } else {
                std::cout << "Branch Shift (" << consumed << "B)\n";
            }
        }
        std::cout << "--------------------------------------------------------\n";
    }
}

int main() {
    probe_r2_table();
    return 0;
}