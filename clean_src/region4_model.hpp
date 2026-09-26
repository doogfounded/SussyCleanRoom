#pragma once
#include <cstdint>
struct DecodeResult {
    uint32_t consumed;
    uint32_t destination;
};

// Analytical model of Region 4 (ProcessCoreLoopRegion_Case3)
inline DecodeResult Decode_Region4_Model(uint8_t b0, uint8_t b1, uint8_t b2) {
    (void)b0; // b0 is passive payload data

    if (b1 & 1) {
        return { 2, 0x10288bed }; // Fast-path token (odd parity)
    }

    if (b2 == 0) {
        return { 3, 0x103282d0 }; // Error / sink trap
    }
    if (b2 == 1) {
        return { 29, 0x10288bed }; // Short parameterized block
    }
    return { 31, 0x10288bed }; // Full parameterized block (b2 >= 2)
}
