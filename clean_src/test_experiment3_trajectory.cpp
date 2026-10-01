#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <iomanip>
#include <fstream>

#include "FUN_10285dc0.h"
#include "FUN_10285dc0_regions.h"

struct TrajectoryResult {
    std::string test_name;
    size_t input_size;
    size_t bytes_consumed;
    bool has_overflow;
    uint32_t final_state;
    std::string exit_label;
    std::vector<int> regions_visited;
};

TrajectoryResult run_trajectory_test(const std::string& name, const std::vector<uint8_t>& data) {
    TrajectoryResult res = {};
    res.test_name = name;
    res.input_size = data.size();

    DoogEngine1::BufferContext ctx;
    ctx.buffer = std::span<const uint8_t>(data.data(), data.size());
    ctx.cursor = 0;
    ctx.has_overflow = false;

    DoogEngine1::FUN_10285dc0_State current = DoogEngine1::FUN_10285dc0_State::ENTRY;

    while (current != DoogEngine1::FUN_10285dc0_State::EXIT && current != DoogEngine1::FUN_10285dc0_State::ERROR) {
        int reg = DoogEngine1::classify_region(current);
        if (res.regions_visited.empty() || res.regions_visited.back() != reg) {
            res.regions_visited.push_back(reg);
        }

        DoogEngine1::RegionResult r;
        switch (reg) {
            case 0:  r = DoogEngine1::ProcessEntryRegion(ctx, current); break;
            case 1:  r = DoogEngine1::ProcessCoreLoopRegion_Case0(ctx, current); break;
            case 2:  r = DoogEngine1::ProcessCoreLoopRegion_Case1(ctx, current); break;
            case 3:  r = DoogEngine1::ProcessCoreLoopRegion_Case2(ctx, current); break;
            case 4:  r = DoogEngine1::ProcessCoreLoopRegion_Case3(ctx, current); break;
            case 5:  r = DoogEngine1::ProcessCoreLoopRegion_Case4(ctx, current); break;
            case 6:  r = DoogEngine1::ProcessCoreLoopRegion_Case5(ctx, current); break;
            case 7:  r = DoogEngine1::ProcessCoreLoopRegion_Case6(ctx, current); break;
            case 8:  r = DoogEngine1::ProcessCoreLoopRegion_Case7(ctx, current); break;
            case 9:  r = DoogEngine1::ProcessCoreLoopRegion_Case8(ctx, current); break;
            case 10: r = DoogEngine1::ProcessCoreLoopRegion_Case9(ctx, current); break;
            case 11: r = DoogEngine1::ProcessCoreLoopRegion_Case10(ctx, current); break;
            case 12: r = DoogEngine1::ProcessCoreLoopRegion_Case11(ctx, current); break;
            default:
                current = DoogEngine1::FUN_10285dc0_State::ERROR;
                goto done;
        }

        current = r.next;
        if (r.finished || r.error || ctx.has_overflow) break;
    }

done:
    res.bytes_consumed = ctx.cursor;
    res.has_overflow = ctx.has_overflow;
    res.final_state = static_cast<uint32_t>(current);

    if (current == DoogEngine1::FUN_10285dc0_State::EXIT) {
        res.exit_label = "CLEAN_EXIT (0x103282d0)";
    } else if (current == DoogEngine1::FUN_10285dc0_State::ERROR) {
        res.exit_label = "ERROR_SINK (0x103281d0)";
    } else {
        std::stringstream ss;
        ss << "STATE_0x" << std::hex << res.final_state;
        res.exit_label = ss.str();
    }

    return res;
}

void print_result(const TrajectoryResult& res) {
    std::cout << "=================================================================" << std::endl;
    std::cout << "TEST: " << res.test_name << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "Input Size      : " << res.input_size << " bytes" << std::endl;
    std::cout << "Bytes Consumed  : " << res.bytes_consumed << " bytes" << std::endl;
    std::cout << "Buffer Overflow : " << (res.has_overflow ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Final Terminal  : " << res.exit_label << std::endl;
    std::cout << "Regions Visited : [";
    for (size_t i = 0; i < res.regions_visited.size(); ++i) {
        std::cout << "Region " << res.regions_visited[i];
        if (i + 1 < res.regions_visited.size()) std::cout << " -> ";
    }
    std::cout << "]" << std::endl;
    std::cout << "=================================================================\n" << std::endl;
}

int main() {
    std::cout << "\n=================================================================" << std::endl;
    std::cout << "    EXPERIMENT 3: FUN_10285dc0 TRAJECTORY & EXECUTION PROBE      " << std::endl;
    std::cout << "=================================================================\n" << std::endl;

    // Test 1: testfile (pure zeros)
    std::vector<uint8_t> testfile_data(1024, 0);
    std::ifstream tf("testfile", std::ios::binary);
    if (tf.is_open()) {
        testfile_data.resize(65536);
        tf.read(reinterpret_cast<char*>(testfile_data.data()), testfile_data.size());
    }
    TrajectoryResult r1 = run_trajectory_test("1. Zero Buffer ('testfile' slice)", testfile_data);
    print_result(r1);

    // Test 2: level2 (Unity asset file)
    std::vector<uint8_t> level2_data(65536, 0);
    std::ifstream l2("level2", std::ios::binary);
    if (l2.is_open()) {
        l2.read(reinterpret_cast<char*>(level2_data.data()), level2_data.size());
    }
    TrajectoryResult r2 = run_trajectory_test("2. Unity Asset File ('level2' header slice)", level2_data);
    print_result(r2);

    // Test 3: Synthetic discriminator tags 0..12 to probe individual case regions
    for (int tag = 0; tag < 13; ++tag) {
        std::vector<uint8_t> tag_buf(65536, 0);
        tag_buf[0] = static_cast<uint8_t>(tag);
        // Fill subsequent bytes with test pattern
        for (size_t i = 1; i < 256; ++i) tag_buf[i] = static_cast<uint8_t>(i & 0xFF);

        std::string test_name = "3." + std::to_string(tag) + ". Discriminator Tag " + std::to_string(tag);
        TrajectoryResult rt = run_trajectory_test(test_name, tag_buf);
        std::cout << "  Tag " << std::setw(2) << tag << " -> Consumed: " << std::setw(3) << rt.bytes_consumed
                  << " bytes | Overflow: " << (rt.has_overflow ? "T" : "F")
                  << " | Terminal: " << rt.exit_label
                  << " | Path: Region " << rt.regions_visited[0] << " -> Region " << (rt.regions_visited.size() > 1 ? std::to_string(rt.regions_visited[1]) : "None")
                  << std::endl;
    }
    std::cout << "\n=================================================================\n" << std::endl;

    return 0;
}
