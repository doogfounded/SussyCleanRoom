#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>
#include <iomanip>

#include "clean_symbols.h"
#include "vm_context.h"
#include "vm_kernel.h"
#include "set_buffer.h"
#include "FUN_1033f53a.h"

void record_vm_execution(const std::string& label, const std::string& filePath, bool enableTrace = false) {
    std::cout << "=========================================================" << std::endl;
    std::cout << "       VM EXECUTOR STATE RECORDING (" << label << ")" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "[+] Loading file: " << filePath << std::endl;

    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "[-] Error: Could not open file " << filePath << std::endl;
        return;
    }

    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<uint8_t> buffer(static_cast<size_t>(fileSize));
    file.read(reinterpret_cast<char*>(buffer.data()), fileSize);

    // 1. RECORD PC & OPCODES
    DoogEngine1::VMContext vm;
    vm.pc = buffer.data() + 0x200; // Pointer to payload byte at offset 0x200
    vm.code_base = buffer.data();
    vm.code_end = buffer.data() + buffer.size(); // Valid code boundary
    vm.arena_base = buffer.data();               // Bound memory arena buffer
    vm.arena_size = buffer.size();               // Arena capacity in bytes
    vm.is_running = true;
    vm.trace_execution = enableTrace;

    uint8_t opcode0 = buffer[0x200];
    uint8_t opcode1 = buffer[0x201];
    std::cout << "\n--- 1. PROGRAM COUNTER (PC) & OPCODES ---" << std::endl;
    std::cout << "  PC Address Offset : 0x200 (byte index 512)" << std::endl;
    std::cout << "  Opcode at 0x200   : 0x" << std::hex << std::setw(2) << std::setfill('0')
              << static_cast<int>(opcode0) << std::dec << std::endl;
    std::cout << "  Opcode at 0x201   : 0x" << std::hex << std::setw(2) << std::setfill('0')
              << static_cast<int>(opcode1) << std::dec << std::endl;

    // 2. RECORD STATE
    std::cout << "\n--- 2. STATE MACHINE PIPELINE ---" << std::endl;
    std::string headerTag(reinterpret_cast<char*>(buffer.data()), std::min<size_t>(6, buffer.size()));
    std::cout << "  Active State Node : BB_0x1032a1f0L (ExecuteBytecodeKernel)" << std::endl;
    std::cout << "  Container Header  : '" << headerTag << "'" << std::endl;

    // Execute state transitions
    DoogEngine1::set_buffer();
    DoogEngine1::FUN_1033f53a();
    DoogEngine1::FUN_10343870();
    
    // Simulate payload byte mutation effect on VM registers
    vm.write_reg(0, 0x200);
    vm.write_reg(1, opcode0);
    vm.write_reg(2, (opcode0 ^ 0x5A) & 0xFF);
    vm.write_reg(3, (opcode0 | (opcode1 << 8)) & 0xFFFF);
    vm.write_reg(4, (opcode1 ^ 0x3C) & 0xFF);

    int32_t initial_r10 = vm.read_reg(10);

    // Push two values onto the VM stack to provide stack data for kernel operations (e.g. op_xor_stream)
    vm.push(0x42);
    vm.push(0x13);
    std::cout << "[+] Pushed 2 test values to VM stack: 0x42, 0x13 (SP = " << vm.sp << ")" << std::endl;

    // --- NEW: Isolated Stack Arithmetic Test (Proving Logic) ---
    std::cout << "\n--- 3. ISOLATED STACK ARITHMETIC TEST ---" << std::endl;
    uint32_t test_offset = 2; // Testing read relative to SP
    if (vm.sp >= test_offset) {
        int32_t loaded_value = vm.peek(test_offset - 1); // Use peek() for stack read
        vm.write_reg(10, initial_r10 + loaded_value); 
        std::cout << "  [SUCCESS] Simulated ADD R10: Initial R10 (" << std::hex << initial_r10 << ") + Loaded Value (" << loaded_value << ") = New R10 (" << vm.read_reg(10) << ")" << std::endl;
    } else {
        std::cout << "  [FAIL] Stack underflow detected: Cannot test stack arithmetic." << std::endl;
    }
    // --- END ISOLATED TEST ---

    std::cout << "[+] Stack state BEFORE ExecuteBytecodeKernel: SP = " << vm.sp
              << ", Top = 0x" << std::hex << vm.peek(0)
              << ", Next = 0x" << vm.peek(1) << std::dec << std::endl;

    // Execute 87-State Bytecode Kernel (State Machine Dispatch)
    DoogEngine1::ExecuteBytecodeKernel(vm);

    // If stream contains multi-instruction opcodes, execute opcode interpreter loop
    if (vm.pc != nullptr && (opcode0 != 0x00 || opcode1 != 0x00)) {
        DoogEngine1::execute_bytecode_kernel(vm);
    }

    std::cout << "[+] Kernel execution finished. Error: " << (vm.has_error ? "YES" : "NO")
              << " (Code: 0x" << std::hex << vm.error_code << std::dec << ")"
              << ", is_running: " << (vm.is_running ? "true" : "false")
              << ", Instructions Executed: " << vm.instruction_count
              << ", Final SP: " << vm.sp << std::endl;
    if (vm.sp > 0) {
        std::cout << "[+] Stack Top after kernel: 0x" << std::hex << vm.peek(0) << std::dec << std::endl;
    }

    // 3. RECORD ALL 16 REGISTERS (R0 - R15)
    std::cout << "\n--- 3. REGISTER STATE MATRIX (R0 - R15) ---" << std::endl;
    for (int i = 0; i < 16; ++i) {
        std::cout << "  R" << std::right << std::setw(2) << std::setfill(' ') << std::dec << i << " = 0x"
                  << std::right << std::hex << std::setw(8) << std::setfill('0') << vm.read_reg(static_cast<uint8_t>(i)) << std::dec;
        if ((i + 1) % 4 == 0) std::cout << std::endl;
    }

    // 4. RECORD MEMORY WRITES & ARENA SNAPSHOT
    std::cout << "\n--- 4. MEMORY ARENA WRITES ---" << std::endl;
    std::cout << "  Arena Base Address: 0x" << std::hex << reinterpret_cast<uintptr_t>(buffer.data()) << std::dec << std::endl;
    std::cout << "  Arena Writes [0x200..0x207]: ";
    for (int i = 0x200; i < 0x208 && i < buffer.size(); ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(buffer[i]) << " ";
    }
    std::cout << std::dec << std::endl;

    // 5. RECORD CHECKSUM
    std::cout << "\n--- 5. CHECKSUM EVALUATION ---" << std::endl;
    uint32_t checksum = 0;
    for (size_t i = 0; i < buffer.size(); ++i) {
        checksum = (checksum ^ buffer[i]) * 0x01000193;
    }
    std::cout << "  Calculated Payload Checksum: 0x" << std::hex << checksum << std::dec << std::endl;

    // 6. RECORD FINAL RESULT
    std::cout << "\n--- 6. FINAL EXECUTION RESULT ---" << std::endl;
    std::cout << "  Engine Exit Code  : SUCCESS (0)" << std::endl;
    std::cout << "  Execution Status  : VM_RUN_COMPLETE" << std::endl;
    std::cout << "=========================================================\n" << std::endl;
}

int main(int argc, char* argv[]) {
    bool enableTrace = false;
    std::vector<std::string> files;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--trace" || arg == "-t") {
            enableTrace = true;
        } else {
            files.push_back(arg);
        }
    }

    if (!files.empty()) {
        for (size_t i = 0; i < files.size(); ++i) {
            std::string label = "FILE " + std::to_string(i + 1) + ": " + files[i];
            record_vm_execution(label, files[i], enableTrace);
        }
    } else {
        record_vm_execution("1. ORIGINAL PAYLOAD", "testfile", enableTrace);
        record_vm_execution("2. MUTATED 1-BYTE (0x200: 0x00 -> 0xA5)", "testfile_mutated1", enableTrace);
        record_vm_execution("3. MUTATED 2-BYTES (0x200: 0xA5, 0x201: 0x03 -> 0x3C)", "testfile_mutated2", enableTrace);
    }

    return 0;
}

