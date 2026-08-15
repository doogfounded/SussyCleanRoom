# DoogEngine1 Opcode Specification Reference Table

This document provides a formal specification table for all **87 states** in the DoogEngine1 Bytecode Execution Kernel (`FUN_1032a1f0` / `ExecuteBytecodeKernel.cpp`).

All opcodes are categorized into **7 Functional Opcode Families** based on their instruction decoding logic, register mutations, and memory stream interactions.

---

## 1. Opcode Family 1: Kernel Gateways & Context Setup (States 0 – 9)

| Opcode ID | State Block ID | Mnemonic | Operands | Inline VMContext Method | Description & Instruction Behavior |
| :---: | :---: | :--- | :--- | :--- | :--- |
| **`0x00`** | `BB_0x1032a1f0L` | `NOP / INIT` | None | `fetch_u8()` | Entry gateway node; fetches first opcode byte and sets `is_running = true`. |
| **`0x01`** | `BB_0x1032a210L` | `HALT` | None | None | Graceful kernel termination node; sets `is_running = false`. |
| **`0x02`** | `BB_0x1032a225L` | `FETCH_TAG` | `[reg_idx]` | `fetch_u8()` | Reads opcode tag byte from `*pc++` into target virtual register. |
| **`0x03`** | `BB_0x1032a240L` | `FETCH_WORD` | `[reg_idx]` | `fetch_u16()` | Fetches 16-bit Little-Endian word from `*pc` into target register. |
| **`0x04`** | `BB_0x1032a260L` | `FETCH_DWORD`| `[reg_idx]` | `fetch_u32()` | Fetches 32-bit Little-Endian dword from `*pc` into target register. |
| **`0x05`** | `BB_0x1032a280L` | `SET_BASE` | `[imm32]` | `write_reg(0, imm32)` | Sets Program Counter (`R0`) stream base pointer to `imm32`. |
| **`0x06`** | `BB_0x1032a2a0L` | `SYNC_CONTEXT`| None | None | Flushes context pipeline registers prior to subsystem re-entry. |
| **`0x07`** | `BB_0x1032a2c0L` | `BRANCH_REL` | `[offset8]` | `pc += offset8` | Relative branch jump forward/backward by 8-bit signed offset. |
| **`0x08`** | `BB_0x1032a2e0L` | `BRANCH_IF_ZERO`| `[reg_idx, offset]`| `read_reg(reg_idx)` | Conditional branch jump if specified register value is `0`. |
| **`0x09`** | `BB_0x1032a300L` | `BRANCH_IF_NZ` | `[reg_idx, offset]`| `read_reg(reg_idx)` | Conditional branch jump if specified register value is non-zero. |

---

## 2. Opcode Family 2: Register Load, Store & Move Operations (States 10 – 24)

| Opcode ID | State Block ID | Mnemonic | Operands | Inline VMContext Method | Description & Instruction Behavior |
| :---: | :---: | :--- | :--- | :--- | :--- |
| **`0x0A`** | `BB_0x1032a320L` | `LOAD_IMM8` | `dst, imm8` | `load_imm(dst, imm8)` | Loads 8-bit immediate byte into register `dst`. |
| **`0x0B`** | `BB_0x1032a340L` | `LOAD_IMM16`| `dst, imm16`| `load_imm(dst, imm16)`| Loads 16-bit immediate word into register `dst`. |
| **`0x0C`** | `BB_0x1032a360L` | `LOAD_IMM32`| `dst, imm32`| `load_imm(dst, imm32)`| Loads 32-bit immediate dword into register `dst`. |
| **`0x0D`** | `BB_0x1032a380L` | `MOV_REG` | `dst, src` | `write_reg(dst, read_reg(src))` | Copies 32-bit value from register `src` to `dst`. |
| **`0x0E`** | `BB_0x1032a3a0L` | `LOAD_MEM8` | `dst, [src_off]`| `read_reg(src_off)` | Reads byte from memory arena offset into register `dst`. |
| **`0x0F`** | `BB_0x1032a3c0L` | `LOAD_MEM32`| `dst, [src_off]`| `read_reg(src_off)` | Reads 32-bit dword from memory arena offset into `dst`. |
| **`0x10`** | `BB_0x1032a3e0L` | `STORE_MEM8`| `[dst_off], src`| `read_reg(src)` | Writes byte from register `src` into memory arena offset. |
| **`0x11`** | `BB_0x1032a400L` | `STORE_MEM32`| `[dst_off], src`| `read_reg(src)` | Writes 32-bit dword from `src` into memory arena offset. |
| **`0x12` – `0x18`** | `BB_0x1032a420L..` | `REG_OP_X` | Various | `write_reg()` | Specialized register window transfer operations. |

---

## 3. Opcode Family 3: Data Stream XOR Operations (States 25 – 39)

| Opcode ID | State Block ID | Mnemonic | Operands | Inline VMContext Method | Description & Instruction Behavior |
| :---: | :---: | :--- | :--- | :--- | :--- |
| **`0x19`** | `BB_0x1032a500L` | `XOR_BYTE_STREAM`| `src_reg, key` | `op_xor_stream(src, key)`| XOR transforms byte stream in memory (`buffer[i] ^= R[src] ^ key`). |
| **`0x1A`** | `BB_0x1032a520L` | `XOR_WORD_STREAM`| `src_reg, key` | `op_xor_stream(src, key)`| XOR transforms 16-bit word stream in memory arena. |
| **`0x1B`** | `BB_0x1032a540L` | `XOR_DWORD_STREAM`|`src_reg, key`| `op_xor_stream(src, key)`| XOR transforms 32-bit dword stream in memory arena. |
| **`0x1C` – `0x27`** | `BB_0x1032a560L..` | `XOR_MASK_X` | `reg_a, reg_b` | `write_reg()` | Multi-pass stream obfuscation & decryption loop steps. |

---

## 4. Opcode Family 4: Arithmetic & Bitwise Logic (States 40 – 54)

| Opcode ID | State Block ID | Mnemonic | Operands | Inline VMContext Method | Description & Instruction Behavior |
| :---: | :---: | :--- | :--- | :--- | :--- |
| **`0x28`** | `BB_0x1032a680L` | `ADD_REG` | `dst, src` | `op_add(dst, src)` | Performs 32-bit addition (`R[dst] += R[src]`). |
| **`0x29`** | `BB_0x1032a6a0L` | `SUB_REG` | `dst, src` | `op_sub(dst, src)` | Performs 32-bit subtraction (`R[dst] -= R[src]`). |
| **`0x2A`** | `BB_0x1032a6c0L` | `AND_REG` | `dst, src` | `op_and(dst, src)` | Performs bitwise AND (`R[dst] &= R[src]`). |
| **`0x2B`** | `BB_0x1032a6e0L` | `OR_REG` | `dst, src` | `op_or(dst, src)` | Performs bitwise OR (`R[dst] \|= R[src]`). |
| **`0x2C`** | `BB_0x1032a700L` | `XOR_REG` | `dst, src` | `write_reg(dst, R[dst]^R[src])` | Performs bitwise XOR (`R[dst] ^= R[src]`). |
| **`0x2D` – `0x36`** | `BB_0x1032a720L..` | `ALU_ACC_X` | Various | `write_reg()` | Rolling accumulator & checksum calculation steps. |

---

## 5. Opcode Family 5: Register Window Sliding Shifts (States 55 – 69)

| Opcode ID | State Block ID | Mnemonic | Operands | Inline VMContext Method | Description & Instruction Behavior |
| :---: | :---: | :--- | :--- | :--- | :--- |
| **`0x37`** | `BB_0x1032a860L` | `SHL_REG` | `dst, shift` | `write_reg(dst, R[dst] << (shift%32))` | Logical shift left by `shift % 32` bits. |
| **`0x38`** | `BB_0x1032a880L` | `SHR_REG` | `dst, shift` | `write_reg(dst, R[dst] >> (shift%32))` | Logical shift right by `shift % 32` bits. |
| **`0x39`** | `BB_0x1032a8a0L` | `ROL_REG` | `dst, shift` | `write_reg()` | Bitwise rotate left by `shift % 32` bits. |
| **`0x3A`** | `BB_0x1032a8c0L` | `ROR_REG` | `dst, shift` | `write_reg()` | Bitwise rotate right by `shift % 32` bits. |
| **`0x3B` – `0x45`** | `BB_0x1032a8e0L..` | `WINDOW_SHIFT_X`| `window_idx` | `write_reg()` | Sliding register window base pointer adjustment. |

---

## 6. Opcode Family 6: Memory Bounds & Alignment Guards (States 70 – 79)

| Opcode ID | State Block ID | Mnemonic | Operands | Inline VMContext Method | Description & Instruction Behavior |
| :---: | :---: | :--- | :--- | :--- | :--- |
| **`0x46`** | `BB_0x1032aa40L` | `CHK_BOUNDS8` | `offset, count`| `read_reg()` | Checks `offset + count <= buffer_size` before byte read. |
| **`0x47`** | `BB_0x1032aa60L` | `CHK_BOUNDS32`| `offset, count`| `read_reg()` | Checks `offset + count*4 <= buffer_size` before dword read. |
| **`0x48`** | `BB_0x1032aa80L` | `ALIGN_WORD` | `offset` | `offset & ~1` | Aligns memory read offset to 2-byte boundary. |
| **`0x49`** | `BB_0x1032aaa0L` | `ALIGN_DWORD`| `offset` | `offset & ~3` | Aligns memory read offset to 4-byte boundary. |
| **`0x4A` – `0x4F`** | `BB_0x1032aac0L..` | `GUARD_MEM_X` | Various | Bounds Check | Emits status error code `1` if memory bounds exceeded. |

---

## 7. Opcode Family 7: Stack Operations & Checksum Hash Guards (States 80 – 86)

| Opcode ID | State Block ID | Mnemonic | Operands | Inline VMContext Method | Description & Instruction Behavior |
| :---: | :---: | :--- | :--- | :--- | :--- |
| **`0x50`** | `BB_0x1032ab80L` | `PUSH_REG` | `src` | `vm.push(read_reg(src))` | Pushes 32-bit register value onto internal VM stack. |
| **`0x51`** | `BB_0x1032aba0L` | `POP_REG` | `dst` | `vm.write_reg(dst, vm.pop())` | Pops 32-bit value from internal VM stack into register `dst`. |
| **`0x52`** | `BB_0x1032abc0L` | `PUSH_IMM32` | `imm32` | `vm.push(imm32)` | Pushes 32-bit immediate dword onto internal VM stack. |
| **`0x53`** | `BB_0x1032abe0L` | `CHK_STACK` | None | `vm.sp` | Checks stack pointer depth against bounds (`sp < 256`). |
| **`0x54`** | `BB_0x1032ac00L` | `HASH_ACC` | `reg_idx` | `rollingChecksum` | Accumulates register value into 32-bit rolling hash. |
| **`0x55`** | `BB_0x1032ac20L` | `VERIFY_HASH`| `expected_hash`| `FUN_1034798f()` | Compares computed hash against expected 32-bit checksum. |
| **`0x56`** | `BB_0x1032ac40L` | `EXIT_KERNEL` | None | `is_running = false`| Final state node; returns execution status code `0` or `1`. |
