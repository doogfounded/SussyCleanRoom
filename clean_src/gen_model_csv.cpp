#include <iostream>
#include <vector>
#include <cstdio>
#include "region4_model.hpp"

int main() {
    const char* filename = "region4_model.csv";
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        std::cerr << "Failed to open " << filename << "\n";
        return 1;
    }

    std::vector<char> io_buf(4 * 1024 * 1024);
    setvbuf(fp, io_buf.data(), _IOFBF, io_buf.size());
    fputs("b0,b1,b2,consumed,destination\n", fp);

    char line[64];

    std::cout << "[2/2] Generating 16.7M permutations from pure model...\n";

    for (int b0 = 0; b0 <= 0xFF; ++b0) {
        for (int b1 = 0; b1 <= 0xFF; ++b1) {
            for (int b2 = 0; b2 <= 0xFF; ++b2) {
                DecodeResult res = Decode_Region4_Model(b0, b1, b2);

                int len = snprintf(line, sizeof(line), "%02X,%02X,%02X,%u,%08X\n",
                                   b0, b1, b2, res.consumed, res.destination);
                fwrite(line, 1, len, fp);
            }
        }
    }

    fclose(fp);
    std::cout << "Done! Output written to " << filename << "\n";
    return 0;
}

