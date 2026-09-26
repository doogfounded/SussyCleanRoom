; ============================================================================
; HIGH-LEVEL VM TEST PROGRAM: Fibonacci, Stack Reduction, Bitwise & Hash Acc
; ============================================================================

; Prologue: Consumed by kernel entry
LOAD_IMM32 R1, 8                  ; R1 = Loop Counter N = 8

; --- 1. FIBONACCI SEQUENCE CALCULATION ---
LOAD_IMM8  R2, 0                  ; R2 = F0 = 0
LOAD_IMM8  R3, 1                  ; R3 = F1 = 1
LOAD_IMM8  R4, 1                  ; R4 = Decrement constant 1

fib_loop:
PUSH_REG   R3                     ; Save old F1 to stack
ADD_REG    R3, R2                 ; F_next = F1 + F0
POP_REG    R2                     ; F0 = old F1
SUB_REG    R1, R4                 ; N = N - 1
BRANCH_IF_NZ R1, fib_loop         ; Loop until N == 0

; --- 2. STACK ARRAY BUFFER REDUCTION ---
PUSH_IMM32 10
PUSH_IMM32 20
PUSH_IMM32 30
PUSH_IMM32 40
LOAD_IMM8  R5, 0                  ; R5 = Sum accumulator = 0
POP_REG    R6                     ; Pop 40
ADD_REG    R5, R6                 ; Sum = 40
POP_REG    R6                     ; Pop 30
ADD_REG    R5, R6                 ; Sum = 70
POP_REG    R6                     ; Pop 20
ADD_REG    R5, R6                 ; Sum = 90
POP_REG    R6                     ; Pop 10
ADD_REG    R5, R6                 ; Sum = 100 (0x64)

; --- 3. BITWISE TRANSFORMATIONS & ROLLING HASH ACCUMULATION ---
MOV_REG    R7, R5                 ; R7 = 100
ADD_REG    R7, R3                 ; R7 = 100 + Fib(8)
SHL_REG    R7, 4                  ; R7 <<= 4
ROR_REG    R7, 2                  ; Rotate right 2 bits
XOR_BYTE_STREAM R7, 0xA5          ; Stream XOR transformation
HASH_ACC   R7                     ; Accumulate into VM rolling checksum

; --- 4. CONDITIONAL VALIDATION & SUCCESS FLAG ---
LOAD_IMM8  R8, 100
SUB_REG    R8, R5                 ; R8 = 100 - R5 == 0 ?
BRANCH_IF_ZERO R8, success_exit

; Failure path
LOAD_IMM32 R9, 0xDEADDEAD         ; Error marker
HALT

success_exit:
LOAD_IMM32 R9, 0xCAFEBABE         ; Success marker: 0xCAFEBABE
HALT
