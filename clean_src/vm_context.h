#pragma once

#include <cstddef>
#include <cstdint>

namespace DoogEngine1 {

struct VMContext {
  // =========================================================================
  // Core Execution State
  // =========================================================================
  const uint8_t *pc = nullptr;        // Program Counter (points to next bytecode byte)
  const uint8_t *code_base = nullptr; // Base pointer to start of bytecode buffer

  // =========================================================================
  // Virtual CPU Registers
  // =========================================================================
  static constexpr size_t NUM_REGISTERS = 16;
  int32_t registers[NUM_REGISTERS] = {0}; // r0 through r15

  // =========================================================================
  // Virtual Stack
  // =========================================================================
  static constexpr size_t STACK_SIZE = 512;
  int32_t stack[STACK_SIZE] = {0};
  size_t sp = 0; // Stack Pointer (index of next free slot)

  // =========================================================================
  // Engine Control & Status Flags
  // =========================================================================
  bool is_running = true;
  bool has_error = false;
  uint32_t error_code = 0;
  uint32_t rollingChecksum = 0;

  // =========================================================================
  // Inline Register Access Methods (With Array Bounds Masking)
  // =========================================================================

  inline int32_t read_reg(uint8_t idx) const {
    return registers[idx & 0x0F];
  }

  inline void write_reg(uint8_t idx, int32_t val) {
    registers[idx & 0x0F] = val;
  }

  // =========================================================================
  // Inline Bytecode Fetch Helpers (Little-Endian)
  // =========================================================================

  // Fetch 1 byte and advance PC
  inline uint8_t fetch_u8() { return *pc++; }

  // Fetch 16-bit little-endian integer and advance PC by 2
  inline uint16_t fetch_u16() {
    uint16_t val =
        static_cast<uint16_t>(pc[0]) | (static_cast<uint16_t>(pc[1]) << 8);
    pc += 2;
    return val;
  }

  // Fetch 32-bit little-endian integer and advance PC by 4
  inline uint32_t fetch_u32() {
    uint32_t val = static_cast<uint32_t>(pc[0]) |
                   (static_cast<uint32_t>(pc[1]) << 8) |
                   (static_cast<uint32_t>(pc[2]) << 16) |
                   (static_cast<uint32_t>(pc[3]) << 24);
    pc += 4;
    return val;
  }

  inline int32_t fetch_i32() { return static_cast<int32_t>(fetch_u32()); }

  // =========================================================================
  // Inline Stack Operations (With Overflow / Underflow Guards)
  // =========================================================================

  inline void push(uint32_t value) {
    if (sp < STACK_SIZE) {
      stack[sp++] = value;
    } else {
      has_error = true;
      is_running = false;
      error_code = 1; // Stack Overflow
    }
  }

  inline uint32_t pop() {
    if (sp > 0) {
      return stack[--sp];
    } else {
      has_error = true;
      is_running = false;
      error_code = 2; // Stack Underflow
      return 0;
    }
  }

  // Reads a value relative to the top of the stack without popping.
  inline uint32_t peek(size_t depth = 0) const {
    if (sp == 0 || depth >= sp) {
      return 0; // Underflow safety guard
    }
    return stack[sp - 1 - depth];
  }

  // New: Read value from stack relative to SP (e.g., for ADD Rdest, [SP+offset])
  inline int32_t read_stack_offset(int32_t offset) {
    if (sp >= offset && offset < STACK_SIZE) {
      return stack[sp - offset]; // Assuming 'offset' is the distance from the top of the stack
    } else {
      has_error = true;
      is_running = false;
      error_code = 3; // Stack Read Error
      return 0;
    }
  }

  // =========================================================================
  // Inline VM Instruction Helper Methods
  // =========================================================================

  inline void load_imm() {
    uint8_t dst = fetch_u8();
    int32_t val = fetch_i32();
    write_reg(dst, val);
  }

  inline void op_add() {
    int32_t b = pop();
    int32_t a = pop();
    push(a + b);
  }

  inline void op_and() {
    int32_t b = pop();
    int32_t a = pop();
    push(a & b);
  }

  inline void op_or() {
    int32_t b = pop();
    int32_t a = pop();
    push(a | b);
  }

  inline void op_xor_stream(uint8_t mask = 0xAA) {
    int32_t val = pop();
    push(val ^ mask);
  }
};

// Main entry declaration for the 87-state execution kernel
void ExecuteBytecodeKernel(VMContext &vm);

} // namespace DoogEngine1