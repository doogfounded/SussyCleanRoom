// test_program.asm - Sample assembly program for DoogEngine1 VM
// Demonstrates immediate loading, stack operations, register math, and clean halt

// 1. Load test values into registers
LOAD_IMM32  R1, 0x12345678
LOAD_IMM32  R2, 0x0000002A      // 42
LOAD_IMM8   R3, 0x55

// 2. Perform register sliding shift & rotate
SHL_REG     R2, 2               // R2 = 42 << 2 = 168
ROR_REG     R1, 4

// 3. Stack push & pop sequence
PUSH_REG    R1
PUSH_IMM32  0x000000FF
POP_REG     R4
POP_REG     R5

// 4. Branching test with label
BRANCH_IF_ZERO R6, target_label
LOAD_IMM8   R7, 0x01

target_label:
HASH_ACC    R2
HALT
