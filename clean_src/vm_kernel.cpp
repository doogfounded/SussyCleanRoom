#include "vm_kernel.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

namespace DoogEngine1 {

static void print_step_trace(const VMContext& vm, uint32_t pc_offset, const std::string& disassembly, int modified_reg = -1, const std::string& mem_effect = "") {
    std::cout << "  [" << std::right << std::dec << std::setw(3) << std::setfill(' ') << vm.instruction_count << "] "
              << "PC:0x" << std::right << std::hex << std::setw(4) << std::setfill('0') << pc_offset << " | "
              << std::left << std::setw(28) << std::setfill(' ') << disassembly << " | ";

    if (!mem_effect.empty()) {
        std::cout << std::left << std::setw(28) << std::setfill(' ') << mem_effect;
    } else if (modified_reg >= 0) {
        std::stringstream ss;
        ss << "R" << modified_reg << "=0x" << std::hex << vm.read_reg(static_cast<uint8_t>(modified_reg));
        std::cout << std::left << std::setw(28) << std::setfill(' ') << ss.str();
    } else {
        std::cout << std::string(28, ' ');
    }

    std::cout << " | SP:" << std::right << std::dec << vm.sp;
    if (vm.sp > 0) {
        std::cout << " [Top:0x" << std::hex << vm.peek(0);
        if (vm.sp > 1) {
            std::cout << ", 0x" << vm.peek(1);
        }
        std::cout << "]";
    }
    std::cout << std::right << std::dec << std::setfill(' ') << std::endl;
}

uint32_t execute_bytecode_kernel(VMContext& vm) {
    vm.is_running = true;

    if (vm.trace_execution) {
        std::cout << "\n=================== STEP DEBUGGER EXECUTION TRACE ===================" << std::endl;
        std::cout << "  STEP   PC       | INSTRUCTION                  | EFFECT / MEMORY EVENT        | STACK STATE" << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
    }

    while (vm.is_running && vm.pc != nullptr) {
        // Enforce code boundary if specified
        if (vm.code_end != nullptr && vm.pc >= vm.code_end) {
            break;
        }

        // Safety limit against infinite loops
        if (++vm.instruction_count > vm.max_instructions) {
            vm.has_error = true;
            vm.is_running = false;
            vm.error_code = 0xFF; // Execution limit exceeded
            break;
        }

        uint32_t cur_pc_offset = (vm.code_base != nullptr) ? static_cast<uint32_t>(vm.pc - vm.code_base) : 0;
        uint8_t opcode = vm.fetch_u8();

        switch (opcode) {
            // ================================================================
            // Family 1: Kernel Gateways & Context Setup
            // ================================================================
            case 0x00: { // NOP / INIT
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "NOP");
                break;
            }

            case 0x01: { // HALT
                vm.is_running = false;
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "HALT");
                break;
            }

            case 0x02: { // FETCH_TAG
                uint8_t dst = vm.fetch_u8();
                uint8_t tag = vm.fetch_u8();
                vm.write_reg(dst, tag);
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "FETCH_TAG R" + std::to_string(dst) + ", 0x" + std::to_string(tag), dst);
                break;
            }

            case 0x03: { // FETCH_WORD
                uint8_t dst = vm.fetch_u8();
                uint16_t val = vm.fetch_u16();
                vm.write_reg(dst, val);
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "FETCH_WORD R" + std::to_string(dst), dst);
                break;
            }

            case 0x04: { // FETCH_DWORD
                uint8_t dst = vm.fetch_u8();
                uint32_t val = vm.fetch_u32();
                vm.write_reg(dst, static_cast<int32_t>(val));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "FETCH_DWORD R" + std::to_string(dst), dst);
                break;
            }

            case 0x05: { // SET_BASE
                uint32_t imm32 = vm.fetch_u32();
                vm.write_reg(0, static_cast<int32_t>(imm32));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "SET_BASE", 0);
                break;
            }

            case 0x06: { // SYNC_CONTEXT
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "SYNC_CONTEXT");
                break;
            }

            case 0x07: { // BRANCH_REL
                int8_t offset = vm.fetch_i8();
                vm.pc += offset;
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "BRANCH_REL " + std::to_string(offset));
                break;
            }

            case 0x08: { // BRANCH_IF_ZERO
                uint8_t reg_idx = vm.fetch_u8();
                int8_t offset = vm.fetch_i8();
                bool taken = (vm.read_reg(reg_idx) == 0);
                if (taken) {
                    vm.pc += offset;
                }
                if (vm.trace_execution) {
                    print_step_trace(vm, cur_pc_offset, "BRANCH_IF_ZERO R" + std::to_string(reg_idx) + (taken ? " (TAKEN)" : " (NOT TAKEN)"));
                }
                break;
            }

            case 0x09: { // BRANCH_IF_NZ
                uint8_t reg_idx = vm.fetch_u8();
                int8_t offset = vm.fetch_i8();
                bool taken = (vm.read_reg(reg_idx) != 0);
                if (taken) {
                    vm.pc += offset;
                }
                if (vm.trace_execution) {
                    print_step_trace(vm, cur_pc_offset, "BRANCH_IF_NZ R" + std::to_string(reg_idx) + (taken ? " (TAKEN)" : " (NOT TAKEN)"));
                }
                break;
            }

            // ================================================================
            // Family 2: Register Load, Store & Move Operations
            // ================================================================
            case 0x0A: { // LOAD_IMM8
                uint8_t dst = vm.fetch_u8();
                uint8_t val = vm.fetch_u8();
                vm.write_reg(dst, val);
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "LOAD_IMM8 R" + std::to_string(dst) + ", 0x" + std::to_string(val), dst);
                break;
            }

            case 0x0B: { // LOAD_IMM16
                uint8_t dst = vm.fetch_u8();
                uint16_t val = vm.fetch_u16();
                vm.write_reg(dst, val);
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "LOAD_IMM16 R" + std::to_string(dst), dst);
                break;
            }

            case 0x0C: { // LOAD_IMM32
                uint8_t dst = vm.fetch_u8();
                uint32_t val = vm.fetch_u32();
                vm.write_reg(dst, static_cast<int32_t>(val));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "LOAD_IMM32 R" + std::to_string(dst), dst);
                break;
            }

            case 0x0D: { // MOV_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t src = vm.fetch_u8();
                vm.write_reg(dst, vm.read_reg(src));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "MOV_REG R" + std::to_string(dst) + ", R" + std::to_string(src), dst);
                break;
            }

            case 0x0E: { // LOAD_MEM8 dst, [src_off]
                uint8_t dst = vm.fetch_u8();
                uint8_t src_off = vm.fetch_u8();
                uint32_t addr = static_cast<uint32_t>(vm.read_reg(src_off));
                uint8_t val = vm.read_mem8(addr);
                vm.write_reg(dst, val);
                if (vm.trace_execution) {
                    std::stringstream ss;
                    ss << "MEM[0x" << std::hex << addr << "] => R" << std::dec << static_cast<int>(dst) << "=0x" << std::hex << static_cast<int>(val);
                    print_step_trace(vm, cur_pc_offset, "LOAD_MEM8 R" + std::to_string(dst) + ", [R" + std::to_string(src_off) + "]", -1, ss.str());
                }
                break;
            }

            case 0x0F: { // LOAD_MEM32 dst, [src_off]
                uint8_t dst = vm.fetch_u8();
                uint8_t src_off = vm.fetch_u8();
                uint32_t addr = static_cast<uint32_t>(vm.read_reg(src_off));
                uint32_t val = vm.read_mem32(addr);
                vm.write_reg(dst, static_cast<int32_t>(val));
                if (vm.trace_execution) {
                    std::stringstream ss;
                    ss << "MEM[0x" << std::hex << addr << "] => R" << std::dec << static_cast<int>(dst) << "=0x" << std::hex << val;
                    print_step_trace(vm, cur_pc_offset, "LOAD_MEM32 R" + std::to_string(dst) + ", [R" + std::to_string(src_off) + "]", -1, ss.str());
                }
                break;
            }

            case 0x10: { // STORE_MEM8 [dst_off], src
                uint8_t dst_off = vm.fetch_u8();
                uint8_t src = vm.fetch_u8();
                uint32_t addr = static_cast<uint32_t>(vm.read_reg(dst_off));
                uint8_t val = static_cast<uint8_t>(vm.read_reg(src) & 0xFF);
                vm.write_mem8(addr, val);
                if (vm.trace_execution) {
                    std::stringstream ss;
                    ss << "MEM[0x" << std::hex << addr << "] <= 0x" << std::hex << static_cast<int>(val);
                    print_step_trace(vm, cur_pc_offset, "STORE_MEM8 [R" + std::to_string(dst_off) + "], R" + std::to_string(src), -1, ss.str());
                }
                break;
            }

            case 0x11: { // STORE_MEM32 [dst_off], src
                uint8_t dst_off = vm.fetch_u8();
                uint8_t src = vm.fetch_u8();
                uint32_t addr = static_cast<uint32_t>(vm.read_reg(dst_off));
                uint32_t val = static_cast<uint32_t>(vm.read_reg(src));
                vm.write_mem32(addr, val);
                if (vm.trace_execution) {
                    std::stringstream ss;
                    ss << "MEM[0x" << std::hex << addr << "] <= 0x" << std::hex << val;
                    print_step_trace(vm, cur_pc_offset, "STORE_MEM32 [R" + std::to_string(dst_off) + "], R" + std::to_string(src), -1, ss.str());
                }
                break;
            }

            // ================================================================
            // Family 3: Stream XOR Operations
            // ================================================================
            case 0x19: { // XOR_BYTE_STREAM
                uint8_t src_reg = vm.fetch_u8();
                uint8_t mask = vm.fetch_u8();
                vm.write_reg(src_reg, vm.read_reg(src_reg) ^ mask);
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "XOR_BYTE_STREAM R" + std::to_string(src_reg), src_reg);
                break;
            }

            // ================================================================
            // Family 4: Arithmetic & Bitwise Logic
            // ================================================================
            case 0x28: { // ADD_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t src = vm.fetch_u8();
                vm.write_reg(dst, vm.read_reg(dst) + vm.read_reg(src));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "ADD_REG R" + std::to_string(dst) + ", R" + std::to_string(src), dst);
                break;
            }

            case 0x29: { // SUB_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t src = vm.fetch_u8();
                vm.write_reg(dst, vm.read_reg(dst) - vm.read_reg(src));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "SUB_REG R" + std::to_string(dst) + ", R" + std::to_string(src), dst);
                break;
            }

            case 0x2A: { // AND_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t src = vm.fetch_u8();
                vm.write_reg(dst, vm.read_reg(dst) & vm.read_reg(src));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "AND_REG R" + std::to_string(dst) + ", R" + std::to_string(src), dst);
                break;
            }

            case 0x2B: { // OR_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t src = vm.fetch_u8();
                vm.write_reg(dst, vm.read_reg(dst) | vm.read_reg(src));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "OR_REG R" + std::to_string(dst) + ", R" + std::to_string(src), dst);
                break;
            }

            case 0x2C: { // XOR_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t src = vm.fetch_u8();
                vm.write_reg(dst, vm.read_reg(dst) ^ vm.read_reg(src));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "XOR_REG R" + std::to_string(dst) + ", R" + std::to_string(src), dst);
                break;
            }

            // ================================================================
            // Family 5: Register Window Sliding Shifts
            // ================================================================
            case 0x37: { // SHL_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t shift = vm.fetch_u8();
                uint32_t val = static_cast<uint32_t>(vm.read_reg(dst));
                shift %= 32;
                vm.write_reg(dst, static_cast<int32_t>(val << shift));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "SHL_REG R" + std::to_string(dst) + ", " + std::to_string(shift), dst);
                break;
            }

            case 0x38: { // SHR_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t shift = vm.fetch_u8();
                uint32_t val = static_cast<uint32_t>(vm.read_reg(dst));
                shift %= 32;
                vm.write_reg(dst, static_cast<int32_t>(val >> shift));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "SHR_REG R" + std::to_string(dst) + ", " + std::to_string(shift), dst);
                break;
            }

            case 0x39: { // ROL_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t shift = vm.fetch_u8();
                uint32_t val = static_cast<uint32_t>(vm.read_reg(dst));
                shift %= 32;
                uint32_t res = (shift == 0) ? val : ((val << shift) | (val >> (32 - shift)));
                vm.write_reg(dst, static_cast<int32_t>(res));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "ROL_REG R" + std::to_string(dst) + ", " + std::to_string(shift), dst);
                break;
            }

            case 0x3A: { // ROR_REG
                uint8_t dst = vm.fetch_u8();
                uint8_t shift = vm.fetch_u8();
                uint32_t val = static_cast<uint32_t>(vm.read_reg(dst));
                shift %= 32;
                uint32_t res = (shift == 0) ? val : ((val >> shift) | (val << (32 - shift)));
                vm.write_reg(dst, static_cast<int32_t>(res));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "ROR_REG R" + std::to_string(dst) + ", " + std::to_string(shift), dst);
                break;
            }

            // ================================================================
            // Family 6: Memory Bounds & Pointer Alignment Guards
            // ================================================================
            case 0x46: { // CHK_BOUNDS8 offset_reg, count_reg
                uint8_t off_reg = vm.fetch_u8();
                uint8_t count_reg = vm.fetch_u8();
                uint32_t offset = static_cast<uint32_t>(vm.read_reg(off_reg));
                uint32_t count = static_cast<uint32_t>(vm.read_reg(count_reg));
                if (offset + count > vm.arena_size) {
                    vm.has_error = true;
                    vm.is_running = false;
                    vm.error_code = 0x46; // Bounds Check 8 Fault
                }
                if (vm.trace_execution) {
                    print_step_trace(vm, cur_pc_offset, "CHK_BOUNDS8 R" + std::to_string(off_reg) + ", R" + std::to_string(count_reg));
                }
                break;
            }

            case 0x47: { // CHK_BOUNDS32 offset_reg, count_reg
                uint8_t off_reg = vm.fetch_u8();
                uint8_t count_reg = vm.fetch_u8();
                uint32_t offset = static_cast<uint32_t>(vm.read_reg(off_reg));
                uint32_t count = static_cast<uint32_t>(vm.read_reg(count_reg));
                if (offset + count * 4 > vm.arena_size) {
                    vm.has_error = true;
                    vm.is_running = false;
                    vm.error_code = 0x47; // Bounds Check 32 Fault
                }
                if (vm.trace_execution) {
                    print_step_trace(vm, cur_pc_offset, "CHK_BOUNDS32 R" + std::to_string(off_reg) + ", R" + std::to_string(count_reg));
                }
                break;
            }

            case 0x48: { // ALIGN_WORD reg
                uint8_t reg = vm.fetch_u8();
                vm.write_reg(reg, vm.read_reg(reg) & ~1);
                if (vm.trace_execution) {
                    print_step_trace(vm, cur_pc_offset, "ALIGN_WORD R" + std::to_string(reg), reg);
                }
                break;
            }

            case 0x49: { // ALIGN_DWORD reg
                uint8_t reg = vm.fetch_u8();
                vm.write_reg(reg, vm.read_reg(reg) & ~3);
                if (vm.trace_execution) {
                    print_step_trace(vm, cur_pc_offset, "ALIGN_DWORD R" + std::to_string(reg), reg);
                }
                break;
            }

            // ================================================================
            // Family 7: Stack Operations & Checksum Hash Guards
            // ================================================================
            case 0x50: { // PUSH_REG
                uint8_t src = vm.fetch_u8();
                vm.push(vm.read_reg(src));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "PUSH_REG R" + std::to_string(src));
                break;
            }

            case 0x51: { // POP_REG
                uint8_t dst = vm.fetch_u8();
                vm.write_reg(dst, vm.pop());
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "POP_REG R" + std::to_string(dst), dst);
                break;
            }

            case 0x52: { // PUSH_IMM32
                uint32_t imm32 = vm.fetch_u32();
                vm.push(static_cast<int32_t>(imm32));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "PUSH_IMM32 0x" + std::to_string(imm32));
                break;
            }

            case 0x53: { // CHK_STACK
                if (vm.sp >= 256) {
                    vm.has_error = true;
                    vm.is_running = false;
                    vm.error_code = 1;
                }
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "CHK_STACK");
                break;
            }

            case 0x54: { // HASH_ACC
                uint8_t reg_idx = vm.fetch_u8();
                vm.rollingChecksum += static_cast<uint32_t>(vm.read_reg(reg_idx));
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "HASH_ACC R" + std::to_string(reg_idx));
                break;
            }

            case 0x56: { // EXIT_KERNEL
                vm.is_running = false;
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "EXIT_KERNEL");
                break;
            }

            default: {
                vm.is_running = false;
                if (vm.trace_execution) print_step_trace(vm, cur_pc_offset, "UNKNOWN_OP 0x" + std::to_string(opcode));
                break;
            }
        }
    }

    if (vm.trace_execution) {
        std::cout << "=====================================================================\n" << std::endl;
    }

    return vm.rollingChecksum;
}

} // namespace DoogEngine1
