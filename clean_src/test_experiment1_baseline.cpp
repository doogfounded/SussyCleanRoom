#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>
#include <iomanip>

#include "vm_context.h"
#include "vm_kernel.h"
#include "set_buffer.h"
#include "FUN_1033f53a.h"
#include "FUN_10343870.h"

namespace DoogEngine1 {
    void ExecuteBytecodeKernel(VMContext &vm);
}

struct RunObservation {
    std::string test_name;
    std::string file_path;
    uint32_t file_size;
    uint8_t byte_at_200;
    uint8_t byte_at_201;
    uint32_t pc_offset_before;
    uint32_t pc_offset_after;
    int32_t pc_bytes_advanced;
    bool any_register_modified;
    int32_t registers_after[16];
    uint32_t sp_before;
    uint32_t sp_after;
    bool has_error;
    uint32_t error_code;
    bool is_running;
};

RunObservation run_unbiased_test(const std::string& test_name, const std::string& file_path, bool invoke_handwritten_vm_kernel = false) {
    RunObservation obs = {};
    obs.test_name = test_name;
    obs.file_path = file_path;

    std::ifstream file(file_path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "[-] Error opening: " << file_path << std::endl;
        return obs;
    }
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<uint8_t> buffer(static_cast<size_t>(size));
    file.read(reinterpret_cast<char*>(buffer.data()), size);
    obs.file_size = static_cast<uint32_t>(buffer.size());

    if (buffer.size() > 0x201) {
        obs.byte_at_200 = buffer[0x200];
        obs.byte_at_201 = buffer[0x201];
    }

    // Initialize clean VMContext: NO manufactured register writes, NO injected stack values
    DoogEngine1::VMContext vm;
    for (int i = 0; i < 16; ++i) {
        vm.write_reg(i, 0);
    }
    vm.sp = 0;
    vm.has_error = false;
    vm.error_code = 0;
    vm.is_running = true;
    vm.trace_execution = false;
    vm.instruction_count = 0;

    if (buffer.size() > 0x200) {
        vm.pc = buffer.data() + 0x200;
        vm.code_base = buffer.data();
        vm.code_end = buffer.data() + buffer.size();
        vm.arena_base = buffer.data();
        vm.arena_size = buffer.size();
    } else {
        vm.pc = nullptr;
    }

    obs.pc_offset_before = (vm.pc != nullptr && vm.code_base != nullptr) ? static_cast<uint32_t>(vm.pc - vm.code_base) : 0;
    obs.sp_before = vm.sp;

    // 1. Run pipeline setup routines from clean_src
    DoogEngine1::set_buffer();
    DoogEngine1::FUN_1033f53a();
    DoogEngine1::FUN_10343870();

    // 2. Execute target state machine from FUN_1032a1f0.dot (ExecuteBytecodeKernel)
    // NOTE: We do NOT write simulated registers R0..R4 or push values to stack.
    DoogEngine1::ExecuteBytecodeKernel(vm);

    // 3. Optional: invoke handwritten interpreter if requested to observe its isolated effect
    if (invoke_handwritten_vm_kernel) {
        if (vm.pc != nullptr && (obs.byte_at_200 != 0x00 || obs.byte_at_201 != 0x00)) {
            DoogEngine1::execute_bytecode_kernel(vm);
        }
    }

    obs.pc_offset_after = (vm.pc != nullptr && vm.code_base != nullptr) ? static_cast<uint32_t>(vm.pc - vm.code_base) : 0;
    obs.pc_bytes_advanced = static_cast<int32_t>(obs.pc_offset_after) - static_cast<int32_t>(obs.pc_offset_before);
    obs.sp_after = vm.sp;
    obs.has_error = vm.has_error;
    obs.error_code = vm.error_code;
    obs.is_running = vm.is_running;

    obs.any_register_modified = false;
    for (int i = 0; i < 16; ++i) {
        obs.registers_after[i] = vm.read_reg(static_cast<uint8_t>(i));
        if (obs.registers_after[i] != 0) {
            obs.any_register_modified = true;
        }
    }

    return obs;
}

void print_observation(const RunObservation& obs) {
    std::cout << "=================================================================" << std::endl;
    std::cout << "TEST: " << obs.test_name << std::endl;
    std::cout << "File: " << obs.file_path << " (" << obs.file_size << " bytes)" << std::endl;
    std::cout << "Bytes at 0x200..0x201: [0x" << std::hex << std::setw(2) << std::setfill('0') << (int)obs.byte_at_200
              << ", 0x" << std::setw(2) << std::setfill('0') << (int)obs.byte_at_201 << "]" << std::dec << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "PC before: 0x" << std::hex << obs.pc_offset_before
              << " | PC after: 0x" << obs.pc_offset_after
              << " | Delta: " << std::dec << obs.pc_bytes_advanced << " bytes" << std::endl;
    std::cout << "SP before: " << obs.sp_before << " | SP after: " << obs.sp_after << std::endl;
    std::cout << "Kernel Error: " << (obs.has_error ? "YES" : "NO")
              << " (Code: 0x" << std::hex << obs.error_code << std::dec << ")"
              << " | is_running: " << (obs.is_running ? "true" : "false") << std::endl;

    std::cout << "Registers Modified by Target: " << (obs.any_register_modified ? "YES" : "NONE (ALL ZERO)") << std::endl;
    std::cout << "Register Dump (R0..R15):" << std::endl;
    for (int i = 0; i < 16; ++i) {
        std::cout << "  R" << std::setw(2) << std::setfill(' ') << i << " = 0x"
                  << std::hex << std::setw(8) << std::setfill('0') << obs.registers_after[i] << std::dec;
        if ((i + 1) % 4 == 0) std::cout << std::endl;
    }
    std::cout << "=================================================================\n" << std::endl;
}

int main() {
    std::cout << "\n=================================================================" << std::endl;
    std::cout << "   EXPERIMENT 1: UNBIASED BASELINE RUN (NO INJECTED REGISTERS)   " << std::endl;
    std::cout << "=================================================================\n" << std::endl;

    // Test 1: Original testfile (zeros) through target ExecuteBytecodeKernel alone
    RunObservation obs1 = run_unbiased_test("1. Target ExecuteBytecodeKernel against 'testfile' (all zeros)", "testfile", false);
    print_observation(obs1);

    // Test 2: Mutated file 1 (byte 0x200 = 0xA5) through target ExecuteBytecodeKernel alone
    RunObservation obs2 = run_unbiased_test("2. Target ExecuteBytecodeKernel against 'testfile_mutated1' (0x200 = 0xA5)", "testfile_mutated1", false);
    print_observation(obs2);

    // Test 3: Mutated file 2 (byte 0x200 = 0xA5, 0x201 = 0x3C) through target ExecuteBytecodeKernel alone
    RunObservation obs3 = run_unbiased_test("3. Target ExecuteBytecodeKernel against 'testfile_mutated2' (0x200 = 0xA5, 0x201 = 0x3C)", "testfile_mutated2", false);
    print_observation(obs3);

    // Test 4: Real Unity asset file 'level2' through target ExecuteBytecodeKernel alone
    RunObservation obs4 = run_unbiased_test("4. Target ExecuteBytecodeKernel against 'level2' (Unity asset)", "level2", false);
    print_observation(obs4);

    // Test 5: Hand-written interpreter in vm_kernel.cpp against 'testfile_mutated1' (WITHOUT hardcoded register writes)
    RunObservation obs5 = run_unbiased_test("5. Hand-written interpreter (vm_kernel.cpp) against 'testfile_mutated1' (no harness writes)", "testfile_mutated1", true);
    print_observation(obs5);

    // Test 6: Hand-written interpreter in vm_kernel.cpp against 'testfile_mutated2' (WITHOUT hardcoded register writes)
    RunObservation obs6 = run_unbiased_test("6. Hand-written interpreter (vm_kernel.cpp) against 'testfile_mutated2' (no harness writes)", "testfile_mutated2", true);
    print_observation(obs6);

    return 0;
}
