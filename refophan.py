class VMContext:
    def __init__(self):
        # 32-bit registers (Assuming 32 registers based on typical VM designs, 
        # though count isn't explicitly in snippet, indices are used)
        self.registers = [0] * 32 
        
        # Internal VM stack
        self.stack = []
        self.sp = 0  # Stack pointer
        
        # Rolling hash accumulator
        self.rollingChecksum = 0
        
        # Execution state
        self.is_running = False
        
        # Program counter
        self.pc = 0
        
        # Bytecode stream (to be loaded)
        self.bytecode = []

    def read_reg(self, src):
        return self.registers[src]

    def write_reg(self, dst, value):
        self.registers[dst] = value & 0xFFFFFFFF  # Ensure 32-bit

    def push(self, value):
        if self.sp >= 256:
            raise Exception("Stack overflow: sp >= 256")
        self.stack.append(value & 0xFFFFFFFF)
        self.sp += 1

    def pop(self):
        if self.sp <= 0:
            raise Exception("Stack underflow")
        self.sp -= 1
        return self.stack.pop()

    def halt(self):
        self.is_running = False
        return 0  # Success status code

# Main Execution Loop
def execute_bytecode_kernel(bytecode):
    vm = VMContext()
    vm.bytecode = bytecode
    
    # Initialize kernel
    # Opcode 0x00: NOP / INIT (implied by context as entry point)
    vm.is_running = True
    vm.pc = 0
    
    print("Kernel initialized. is_running = True")

    while vm.is_running:
        if vm.pc >= len(vm.bytecode):
            print("End of bytecode stream.")
            break
            
        opcode = vm.bytecode[vm.pc]
        vm.pc += 1
        
        # Dispatch based on Opcode Family
        if opcode == 0x50: # PUSH_REG (Family 7)
            src = vm.bytecode[vm.pc]
            vm.pc += 1
            vm.push(vm.read_reg(src))
            
        elif opcode == 0x51: # POP_REG (Family 7)
            dst = vm.bytecode[vm.pc]
            vm.pc += 1
            vm.write_reg(dst, vm.pop())
            
        elif opcode == 0x52: # PUSH_IMM32 (Family 7)
            # Assuming 4 bytes for imm32
            imm32 = (vm.bytecode[vm.pc] | 
                     (vm.bytecode[vm.pc+1] << 8) | 
                     (vm.bytecode[vm.pc+2] << 16) | 
                     (vm.bytecode[vm.pc+3] << 24))
            vm.pc += 4
            vm.push(imm32)
            
        elif opcode == 0x53: # CHK_STACK (Family 7)
            # Checks sp < 256, implicit in push method, but can be explicit check here
            if vm.sp >= 256:
                raise Exception("CHK_STACK failed: sp >= 256")
                
        elif opcode == 0x54: # HASH_ACC (Family 7)
            reg_idx = vm.bytecode[vm.pc]
            vm.pc += 1
            # Accumulate register value into rollingChecksum
            vm.rollingChecksum = (vm.rollingChecksum + vm.read_reg(reg_idx)) & 0xFFFFFFFF
            
        elif opcode == 0x56: # EXIT_KERNEL (Family 7)
            # Final state node; returns execution status code 0 or 1
            vm.halt()
            
        elif opcode == 0x37: # SHL_REG (Family 5)
            dst = vm.bytecode[vm.pc]
            shift = vm.bytecode[vm.pc+1]
            vm.pc += 2
            vm.write_reg(dst, (vm.read_reg(dst) << (shift % 32)) & 0xFFFFFFFF)
            
        elif opcode == 0x38: # SHR_REG (Family 5)
            dst = vm.bytecode[vm.pc]
            shift = vm.bytecode[vm.pc+1]
            vm.pc += 2
            vm.write_reg(dst, (vm.read_reg(dst) >> (shift % 32)) & 0xFFFFFFFF)
            
        elif opcode == 0x39: # ROL_REG (Family 5)
            dst = vm.bytecode[vm.pc]
            shift = vm.bytecode[vm.pc+1]
            vm.pc += 2
            # Rotate Left 32-bit
            val = vm.read_reg(dst)
            shift = shift % 32
            vm.write_reg(dst, ((val << shift) | (val >> (32 - shift))) & 0xFFFFFFFF)
            
        elif opcode == 0x3A: # ROR_REG (Family 5)
            dst = vm.bytecode[vm.pc]
            shift = vm.bytecode[vm.pc+1]
            vm.pc += 2
            # Rotate Right 32-bit
            val = vm.read_reg(dst)
            shift = shift % 32
            vm.write_reg(dst, ((val >> shift) | (val << (32 - shift))) & 0xFFFFFFFF)
            
        elif opcode == 0x00: # NOP / INIT (Implied Entry)
            pass # is_running already True
            
        elif opcode == 0x01: # HALT (Implied Termination)
            vm.halt()
            
        else:
            print(f"Unknown opcode: 0x{opcode:02X}")
            vm.halt()

    return vm.rollingChecksum

# Example Usage
# Simple program: Load 10 into R0, Push R0, Pop into R1, Hash R1, Exit
# LOAD_IMM32 R0, 10 (Opcode 0x0C, not in Family 5/7, but needed for test)
# PUSH_REG R0
# POP_REG R1
# HASH_ACC R1
# EXIT_KERNEL

sample_bytecode = [
    0x0C, 0x00, 0x00, 0x00, 0x0A, # LOAD_IMM32 R0, 10 (assuming R0=0, imm=10)
    0x50, 0x00,                  # PUSH_REG R0
    0x51, 0x01,                  # POP_REG R1
    0x54, 0x01,                  # HASH_ACC R1
    0x56                        # EXIT_KERNEL
]

result = execute_bytecode_kernel(sample_bytecode)
print(f"Final Hash: {result}")