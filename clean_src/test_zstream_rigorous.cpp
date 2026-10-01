#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <random>
#include <zlib.h>

namespace DoogEngine1 {

struct MonoZStream {
    z_stream z;
    bool is_deflate;
    int window_bits;
};

MonoZStream* CreateZStream_Wrapper(int window_bits) {
    MonoZStream* stream = new MonoZStream();
    std::memset(&(stream->z), 0, sizeof(z_stream));
    stream->window_bits = window_bits;
    int ret = inflateInit2(&(stream->z), window_bits);
    if (ret != Z_OK) {
        delete stream;
        return nullptr;
    }
    return stream;
}

void CloseZStream_Wrapper(MonoZStream* stream) {
    if (stream) {
        inflateEnd(&(stream->z));
        delete stream;
    }
}

// Emulates ReadZStream wrapping FUN_1031f590 (inflate)
int ReadZStream_CleanRoom(MonoZStream* stream, uint8_t* out_buffer, int length, int& z_err) {
    if (!stream || !out_buffer || length <= 0) {
        return -1;
    }
    stream->z.next_out = out_buffer;
    stream->z.avail_out = length;
    uint32_t start_total_out = stream->z.total_out;

    z_err = inflate(&(stream->z), Z_NO_FLUSH);

    int bytes_produced = static_cast<int>(stream->z.total_out - start_total_out);
    return bytes_produced;
}

} // namespace DoogEngine1

// Independent reference zlib decompression
int IndependentZlibInflate(const uint8_t* in_data, size_t in_len, uint8_t* out_data, size_t out_cap, int window_bits, int& z_err) {
    z_stream strm;
    std::memset(&strm, 0, sizeof(strm));
    z_err = inflateInit2(&strm, window_bits);
    if (z_err != Z_OK) return -1;

    strm.next_in = const_cast<Bytef*>(in_data);
    strm.avail_in = in_len;
    strm.next_out = out_data;
    strm.avail_out = out_cap;

    z_err = inflate(&strm, Z_FINISH);
    int produced = strm.total_out;
    inflateEnd(&strm);
    return produced;
}

void RunComparison(const std::string& test_name, const std::vector<uint8_t>& compressed, size_t expected_orig_size, int window_bits) {
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "TEST: " << test_name << " (Compressed len: " << compressed.size() << ")" << std::endl;

    // 1. Run through ReadZStream wrapper
    auto* mz = DoogEngine1::CreateZStream_Wrapper(window_bits);
    mz->z.next_in = const_cast<Bytef*>(compressed.data());
    mz->z.avail_in = compressed.size();

    std::vector<uint8_t> out1(expected_orig_size + 1024, 0);
    int z_err1 = 0;
    int prod1 = DoogEngine1::ReadZStream_CleanRoom(mz, out1.data(), out1.size(), z_err1);
    DoogEngine1::CloseZStream_Wrapper(mz);

    // 2. Run through independent zlib
    std::vector<uint8_t> out2(expected_orig_size + 1024, 0);
    int z_err2 = 0;
    int prod2 = IndependentZlibInflate(compressed.data(), compressed.size(), out2.data(), out2.size(), window_bits, z_err2);

    std::cout << "  ReadZStream  -> Produced: " << prod1 << " bytes | z_err: " << z_err1 << std::endl;
    std::cout << "  ReferenceZlib -> Produced: " << prod2 << " bytes | z_err: " << z_err2 << std::endl;

    bool match = (prod1 == prod2) && (z_err1 == z_err2 || (z_err1 == Z_STREAM_END && z_err2 == Z_STREAM_END));
    if (prod1 > 0 && prod2 > 0) {
        match = match && (std::memcmp(out1.data(), out2.data(), prod1) == 0);
    }
    std::cout << "  MATCH EQUIVALENCE: " << (match ? "PASS (100% IDENTICAL)" : "FAIL") << std::endl;
}

std::vector<uint8_t> CompressZlib(const std::vector<uint8_t>& src, int level, int window_bits) {
    z_stream strm;
    std::memset(&strm, 0, sizeof(strm));
    deflateInit2(&strm, level, Z_DEFLATED, window_bits, 8, Z_DEFAULT_STRATEGY);
    strm.next_in = const_cast<Bytef*>(src.data());
    strm.avail_in = src.size();
    std::vector<uint8_t> out(src.size() + 1024);
    strm.next_out = out.data();
    strm.avail_out = out.size();
    deflate(&strm, Z_FINISH);
    out.resize(strm.total_out);
    deflateEnd(&strm);
    return out;
}

int main() {
    std::cout << "========================================================\n";
    std::cout << "   STRICT CONTROLLED EXPERIMENTATION: ZLIB / READZSTREAM\n";
    std::cout << "========================================================\n";

    // 1. Small payload (17 bytes)
    std::string s1 = "HELLO_DOOG_ENGINE";
    std::vector<uint8_t> b1(s1.begin(), s1.end());
    RunComparison("1. Small Payload (17B, level 6)", CompressZlib(b1, 6, 15), b1.size(), 15);

    // 2. Medium payload (4096 bytes repetitive pattern)
    std::vector<uint8_t> b2(4096);
    for (size_t i = 0; i < b2.size(); ++i) b2[i] = static_cast<uint8_t>(i % 37);
    RunComparison("2. Medium Payload (4KB, level 1 fast)", CompressZlib(b2, 1, 15), b2.size(), 15);
    RunComparison("3. Medium Payload (4KB, level 9 best)", CompressZlib(b2, 9, 15), b2.size(), 15);

    // 3. Incompressible data (4096 random bytes, uncompressible)
    std::mt19937 rng(1337);
    std::vector<uint8_t> b3(4096);
    for (size_t i = 0; i < b3.size(); ++i) b3[i] = static_cast<uint8_t>(rng() & 0xFF);
    RunComparison("4. Incompressible Random Data (4KB)", CompressZlib(b3, 6, 15), b3.size(), 15);

    // 4. Truncated data (valid compressed data cut in half)
    auto comp1 = CompressZlib(b2, 6, 15);
    comp1.resize(comp1.size() / 2); // Cut off!
    RunComparison("5. Truncated Compressed Stream", comp1, b2.size(), 15);

    // 5. Malformed data (bad header bytes 0x00 0x00)
    std::vector<uint8_t> bad_hdr = {0x00, 0x00, 0x12, 0x34, 0x56};
    RunComparison("6. Malformed Header Bytes (0x00 0x00)", bad_hdr, 100, 15);

    // 6. Completely corrupted stream (0xFF 0xFF 0xFF 0xFF)
    std::vector<uint8_t> bad_bytes = {0xFF, 0xFF, 0xFF, 0xFF};
    RunComparison("7. Corrupted Bytes (0xFF 0xFF 0xFF 0xFF)", bad_bytes, 100, 15);

    std::cout << "========================================================\n";
    return 0;
}
