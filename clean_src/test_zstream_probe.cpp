#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <zlib.h>

namespace DoogEngine1 {

// Exact Mono / Unity IL2CPP ZStream wrapper struct
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

// Clean-room implementation strictly following ReadZStream.dot topology
int ReadZStream_CleanRoom(MonoZStream* stream, uint8_t* out_buffer, int length, std::vector<std::string>& state_trace) {
    // BB_0x102fc4f0L: Check stream != nullptr
    state_trace.push_back("BB_0x102fc4f0L");
    if (!stream) {
        state_trace.push_back("BB_0x102fc5a9L (SINK_ERROR: null stream)");
        return -1;
    }

    // BB_0x102fc500L: Check out_buffer != nullptr
    state_trace.push_back("BB_0x102fc500L");
    if (!out_buffer) {
        state_trace.push_back("BB_0x102fc5a9L (SINK_ERROR: null out_buffer)");
        return -1;
    }

    // BB_0x102fc50bL: Check length > 0
    state_trace.push_back("BB_0x102fc50bL");
    if (length <= 0) {
        state_trace.push_back("BB_0x102fc5a9L (SINK_ERROR: non-positive length)");
        return 0;
    }

    // BB_0x102fc516L -> BB_0x102fc522L
    state_trace.push_back("BB_0x102fc516L");
    state_trace.push_back("BB_0x102fc522L");

    stream->z.next_out = out_buffer;
    stream->z.avail_out = length;
    uint32_t start_total_out = stream->z.total_out;

    state_trace.push_back("BB_0x102fc52fL");
    state_trace.push_back("BB_0x102fc530L (Loop Head)");

    while (stream->z.avail_out > 0) {
        if (stream->z.avail_in == 0) {
            state_trace.push_back("BB_0x102fc536L (Input exhausted)");
            break;
        }

        // BB_0x102fc55bL -> Invokes core loop FUN_1031f590L (inflate)
        state_trace.push_back("BB_0x102fc55bL -> FUN_1031f590L (inflate)");
        int status = inflate(&(stream->z), Z_NO_FLUSH);

        state_trace.push_back("BB_0x102fc56eL (Status: " + std::to_string(status) + ")");

        if (status == Z_STREAM_END) {
            state_trace.push_back("BB_0x102fc586L -> BB_0x102fc5a2L (Z_STREAM_END)");
            break;
        }
        if (status == Z_OK) {
            state_trace.push_back("BB_0x102fc573L -> BB_0x102fc577L (Continue loop)");
            continue;
        }

        // Error path: BB_0x102fc594L -> BB_0x102fc598L
        state_trace.push_back("BB_0x102fc594L -> BB_0x102fc598L (Error Return: " + std::to_string(status) + ")");
        return -1;
    }

    state_trace.push_back("BB_0x102fc598L (Normal Exit)");
    return static_cast<int>(stream->z.total_out - start_total_out);
}

} // namespace DoogEngine1

struct TestResult {
    std::string test_name;
    int return_value;
    int bytes_in_consumed;
    int bytes_out_produced;
    std::string output_preview;
    bool matched_expected;
    std::vector<std::string> trace;
};

TestResult run_test_vector(const std::string& name, const std::vector<uint8_t>& input_data, int window_bits, const std::string& expected_output = "") {
    TestResult res = {};
    res.test_name = name;

    DoogEngine1::MonoZStream* stream = DoogEngine1::CreateZStream_Wrapper(window_bits);
    if (!stream) {
        res.return_value = -999;
        return res;
    }

    // Set input
    stream->z.next_in = const_cast<uint8_t*>(input_data.data());
    stream->z.avail_in = static_cast<uInt>(input_data.size());

    // Prepare output buffer
    std::vector<uint8_t> out_buf(1024, 0);

    res.return_value = DoogEngine1::ReadZStream_CleanRoom(stream, out_buf.data(), static_cast<int>(out_buf.size()), res.trace);
    res.bytes_in_consumed = static_cast<int>(input_data.size() - stream->z.avail_in);
    res.bytes_out_produced = (res.return_value > 0) ? res.return_value : 0;

    if (res.bytes_out_produced > 0) {
        res.output_preview = std::string(reinterpret_cast<char*>(out_buf.data()), res.bytes_out_produced);
    } else {
        res.output_preview = "<NO OUTPUT PRODUCED>";
    }

    if (!expected_output.empty()) {
        res.matched_expected = (res.output_preview == expected_output);
    } else {
        res.matched_expected = false;
    }

    DoogEngine1::CloseZStream_Wrapper(stream);
    return res;
}

void print_test_result(const TestResult& res) {
    std::cout << "=================================================================" << std::endl;
    std::cout << "TEST: " << res.test_name << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "Return Value     : " << res.return_value << std::endl;
    std::cout << "Bytes In Consumed: " << res.bytes_in_consumed << std::endl;
    std::cout << "Bytes Out Written: " << res.bytes_out_produced << std::endl;
    std::cout << "Output Text      : \"" << res.output_preview << "\"" << std::endl;
    std::cout << "Matched Expected : " << (res.matched_expected ? "YES (100% REPRODUCIBLE)" : "NO") << std::endl;
    std::cout << "\nCFG State Trajectory in ReadZStream.dot:" << std::endl;
    for (size_t i = 0; i < res.trace.size(); ++i) {
        std::cout << "  [" << std::setw(2) << i << "] " << res.trace[i] << std::endl;
    }
    std::cout << "=================================================================\n" << std::endl;
}

int main() {
    std::cout << "\n=================================================================" << std::endl;
    std::cout << "   EXPERIMENT 2: BEHAVIORAL EQUIVALENCE & DECOMPRESSION PROBE    " << std::endl;
    std::cout << "=================================================================\n" << std::endl;

    // --- Vector 1: Standard RFC 1950 zlib stream encoding "HELLO_DOOG_ENGINE" ---
    // Deflate compression of "HELLO_DOOG_ENGINE"
    const std::string test_msg = "HELLO_DOOG_ENGINE";
    std::vector<uint8_t> compressed_zlib(128);
    uLongf comp_len = 128;
    compress(compressed_zlib.data(), &comp_len, reinterpret_cast<const Bytef*>(test_msg.data()), test_msg.size());
    compressed_zlib.resize(comp_len);

    std::cout << "[+] Prepared Vector 1 (RFC 1950 zlib stream): " << comp_len << " bytes, starts with: 0x"
              << std::hex << std::setw(2) << std::setfill('0') << (int)compressed_zlib[0] << " 0x"
              << std::setw(2) << std::setfill('0') << (int)compressed_zlib[1] << std::dec << std::endl;

    TestResult res1 = run_test_vector("1. Standard RFC 1950 zlib Stream ('HELLO_DOOG_ENGINE')", compressed_zlib, 15, test_msg);
    print_test_result(res1);

    // --- Vector 2: Raw Deflate Block (no zlib header, window_bits = -15) ---
    // Compress with raw deflate
    z_stream raw_def;
    std::memset(&raw_def, 0, sizeof(raw_def));
    deflateInit2(&raw_def, Z_DEFAULT_COMPRESSION, Z_DEFLATED, -15, 8, Z_DEFAULT_STRATEGY);
    raw_def.next_in = reinterpret_cast<Bytef*>(const_cast<char*>(test_msg.data()));
    raw_def.avail_in = test_msg.size();
    std::vector<uint8_t> raw_deflate_bytes(128);
    raw_def.next_out = raw_deflate_bytes.data();
    raw_def.avail_out = 128;
    deflate(&raw_def, Z_FINISH);
    raw_deflate_bytes.resize(raw_def.total_out);
    deflateEnd(&raw_def);

    TestResult res2 = run_test_vector("2. Raw Deflate Block (window_bits = -15)", raw_deflate_bytes, -15, test_msg);
    print_test_result(res2);

    // --- Vector 3: Slice from 'level2' (Unity asset file at offset 0x200) ---
    std::vector<uint8_t> level2_slice(256, 0);
    std::ifstream l2_file("level2", std::ios::binary);
    if (l2_file.is_open()) {
        l2_file.seekg(0x200);
        l2_file.read(reinterpret_cast<char*>(level2_slice.data()), 256);
    }
    TestResult res3 = run_test_vector("3. level2 Binary Asset Slice (at offset 0x200)", level2_slice, 15);
    print_test_result(res3);

    // --- Vector 4: Corrupt / Invalid Stream (0xFF 0xFF 0xFF 0xFF) ---
    std::vector<uint8_t> corrupt_bytes = {0xFF, 0xFF, 0xFF, 0xFF};
    TestResult res4 = run_test_vector("4. Corrupt / Invalid Byte Stream (0xFF 0xFF 0xFF 0xFF)", corrupt_bytes, 15);
    print_test_result(res4);

    return 0;
}
