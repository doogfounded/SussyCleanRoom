#include "vm_kernel.h"
#include <iostream>

namespace DoogEngine1 {

uint32_t execute_bytecode_kernel(VMContext& vm) {
    vm.is_running = true;

    while (vm.is_running && vm.pc != nullptr) {
        uint8_t opcode = vm.fetch_u8();

        switch (opcode) {
            case 0x00: { // NOP / INIT
                // Implied Entry point
                break;
            }

            case 0x01: { // HALT
                vm.is_running = false;
                break;
            }

            case 0x0A: { // LOAD_IMM8
                uint8_t dst = vm.fetch_u8();
                uint8_t val = vm.fetch_u8();
                vm.write_reg(dst, val);
                break;
            }

            case 0x0B: { // LOAD_IMM16
                uint8_t dst = vm.fetch_u8();
                uint16_t val = vm.fetch_u16();
                vm.write_reg(dst, val);
                break;
            }

            case 0x0C: { // LOAD_IMM32
                uint8_t dst = vm.fetch_u8();
                uint32_t val = vm.fetch_u32();
                vm.write_reg(dst, static_cast<int32_t>(val));
                break;
            }

            case 0x37: { // SHL_REG (Family 5)
                uint8_t dst = vm.fetch_u8();
                uint8_t shift = vm.fetch_u8();
                uint32_t val = static_cast<uint32_t>(vm.read_reg(dst));
                shift %= 32;
                vm.write_reg(dst, static_cast<int32_t>(val << shift));
                break;
            }

            case 0x38: { // SHR_REG (Family 5)
                uint8_t dst = vm.fetch_u8();
                uint8_t shift = vm.fetch_u8();
                uint32_t val = static_cast<uint32_t>(vm.read_reg(dst));
                shift %= 32;
                vm.write_reg(dst, static_cast<int32_t>(val >> shift));
                break;
            }

            case 0x39: { // ROL_REG (Family 5)
                uint8_t dst = vm.fetch_u8();
                uint8_t shift = vm.fetch_u8();
                uint32_t val = static_cast<uint32_t>(vm.read_reg(dst));
                shift %= 32;
                uint32_t res = (shift == 0) ? val : ((val << shift) | (val >> (32 - shift)));
                vm.write_reg(dst, static_cast<int32_t>(res));
                break;
            }

            case 0x3A: { // ROR_REG (Family 5)
                uint8_t dst = vm.fetch_u8();
                uint8_t shift = vm.fetch_u8();
                uint32_t val = static_cast<uint32_t>(vm.read_reg(dst));
                shift %= 32;
                uint32_t res = (shift == 0) ? val : ((val >> shift) | (val << (32 - shift)));
                vm.write_reg(dst, static_cast<int32_t>(res));
                break;
            }

            case 0x50: { // PUSH_REG (Family 7)
                uint8_t src = vm.fetch_u8();
                vm.push(vm.read_reg(src));
                break;
            }

            case 0x51: { // POP_REG (Family 7)
                uint8_t dst = vm.fetch_u8();
                vm.write_reg(dst, vm.pop());
                break;
            }

            case 0x52: { // PUSH_IMM32 (Family 7)
                uint32_t imm32 = vm.fetch_u32();
                vm.push(static_cast<int32_t>(imm32));
                break;
            }

            case 0x53: { // CHK_STACK (Family 7)
                if (vm.sp >= 256) {
                    vm.has_error = true;
                    vm.is_running = false;
                    vm.error_code = 1;
                }
                break;
            }

            case 0x54: { // HASH_ACC (Family 7)
                uint8_t reg_idx = vm.fetch_u8();
                vm.rollingChecksum += static_cast<uint32_t>(vm.read_reg(reg_idx));
                break;
            }

            case 0x56: { // EXIT_KERNEL (Family 7)
                vm.is_running = false;
                break;
            }

            default: {
                vm.is_running = false;
                break;
            }
        }
    }

    return vm.rollingChecksum;
}

} // namespace DoogEngine1
