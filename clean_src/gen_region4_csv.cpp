#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdio>
#include "FUN_10285dc0.h"
#include "FUN_10285dc0_regions.h"

using namespace DoogEngine1;

int main() {
    const char* filename = "region4_engine.csv";
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        std::cerr << "Failed to open " << filename << "\n";
        return 1;
    }

    // 4MB buffered I/O for speed
    std::vector<char> io_buf(4 * 1024 * 1024);
    setvbuf(fp, io_buf.data(), _IOFBF, io_buf.size());
    fputs("b0,b1,b2,consumed,destination\n", fp);

    std::vector<uint8_t> buffer_payload(64, 0x00);
    for (size_t i = 3; i < buffer_payload.size(); ++i) {
        buffer_payload[i] = static_cast<uint8_t>(i);
    }

    BufferContext ctx;
    ctx.buffer = buffer_payload;
    char line[64];

    std::cout << "[1/2] Generating 16.7M permutations from engine binary...\n";

    for (int b0 = 0; b0 <= 0xFF; ++b0) {
        for (int b1 = 0; b1 <= 0xFF; ++b1) {
            for (int b2 = 0; b2 <= 0xFF; ++b2) {
                ctx.cursor = 0;
                ctx.has_overflow = false;
                buffer_payload[0] = static_cast<uint8_t>(b0);
                buffer_payload[1] = static_cast<uint8_t>(b1);
                buffer_payload[2] = static_cast<uint8_t>(b2);

                FUN_10285dc0_State state = static_cast<FUN_10285dc0_State>(0x10287fc0);
                RegionResult res = ProcessCoreLoopRegion_Case3(ctx, state);

                int len = snprintf(line, sizeof(line), "%02X,%02X,%02X,%u,%08X\n",
                                   b0, b1, b2, static_cast<unsigned int>(ctx.cursor), static_cast<uint32_t>(res.next));
                fwrite(line, 1, len, fp);
            }
        }
    }

    fclose(fp);
    std::cout << "Done! Output written to " << filename << "\n";
    return 0;
}

