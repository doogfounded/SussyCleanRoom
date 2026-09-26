; ============================================================================
; MEMORY ARENA READ/WRITE & BOUNDS GUARD TEST PROGRAM
; ============================================================================

; Prologue: consumed by kernel entry
LOAD_IMM32 R1, 0x00000000

; --- 1. BOUNDS VERIFICATION & ALIGNMENT ---
LOAD_IMM32 R2, 0x00000300         ; R2 = Target memory offset 0x300
LOAD_IMM8  R3, 16                 ; R3 = Element count = 16
CHK_BOUNDS32 R2, R3               ; Verify 0x300 + 16*4 <= arena_size

LOAD_IMM8  R4, 7                  ; Unaligned offset
ALIGN_DWORD R4                    ; R4 = 7 & ~3 = 4

; --- 2. 32-BIT MEMORY STORE & LOAD ---
LOAD_IMM32 R5, 0x12345678
STORE_MEM32 [R2], R5              ; arena[0x300..0x303] = 0x12345678
LOAD_MEM32 R6, [R2]               ; R6 = arena[0x300..0x303] (verify 0x12345678)

; Store 0xDEADBEEF directly at offset 0x200 (visible in arena writes display)
LOAD_IMM32 R7, 0x00000200
LOAD_IMM32 R8, 0xDEADBEEF
STORE_MEM32 [R7], R8              ; arena[0x200..0x203] = 0xDEADBEEF

; --- 3. 8-BIT MEMORY STORE & LOAD ---
LOAD_IMM8  R9, 0x7F
LOAD_IMM32 R10, 0x00000204
STORE_MEM8 [R10], R9              ; arena[0x204] = 0x7F
LOAD_MEM8  R11, [R10]             ; R11 = arena[0x204] (verify 0x7F)

; --- 4. VALIDATION & EXIT FLAG ---
SUB_REG    R6, R5                 ; R6 = R6 - R5 (0 if read matches written)
BRANCH_IF_ZERO R6, mem_ok

LOAD_IMM32 R12, 0xBAD00BAD
HALT

mem_ok:
LOAD_IMM32 R12, 0x00C0FFEE        ; Success flag: 0xC0FFEE
HALT
