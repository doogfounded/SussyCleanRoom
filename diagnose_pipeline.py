import pefile
import struct

pe = pefile.PE("GameAssembly.dll")
image_base = pe.OPTIONAL_HEADER.ImageBase

# 1. Inspect raw bytes at RVA 0x285dc0 (file offset 0x2851c0)
text_sec = None
for s in pe.sections:
    if b".text" in s.Name:
        text_sec = s
        break

if text_sec:
    target_rva = 0x285DC0
    target_file_offset = text_sec.PointerToRawData + (target_rva - text_sec.VirtualAddress)
    
    with open("GameAssembly.dll", "rb") as f:
        # Read 16 bytes before and 32 bytes at target
        f.seek(max(0, target_file_offset - 16))
        pre_bytes = f.read(16)
        code_bytes = f.read(32)
        
    print(f"=== [1] Machine Code at 0x10285dc0 (File Offset {hex(target_file_offset)}) ===")
    print("Preceding 16 bytes (epilogue/padding):", " ".join(f"{b:02x}" for b in pre_bytes))
    print("First 32 bytes at entry point:         ", " ".join(f"{b:02x}" for b in code_bytes))
    
    # Check for standard x86 function prologues (push ebp; mov ebp, esp -> 55 8b ec / sub esp -> 83 ec)
    if code_bytes[:3] == b"\x55\x8b\xec":
        print(">> Recognized standard x86 prologue: push ebp; mov ebp, esp")
    elif code_bytes[0] == 0x55:
        print(">> Recognized x86 prologue: push ebp")
    elif code_bytes[:2] == b"\x83\xec" or code_bytes[:2] == b"\x81\xec":
        print(">> Recognized stack reservation: sub esp, imm")
    else:
        print(f">> Non-standard prologue or basic block head (Starts with: {hex(code_bytes[0])})")

# 2. Scan for references to all known sibling functions in the pipeline
pipeline_functions = {
    "FUN_10285dc0 (Dispatch Loop)":   0x0285DC0,
    "FUN_1032a1f0 (Bytecode Kernel)": 0x032A1F0,
    "FUN_1033c5bf (State Engine)":    0x033C5BF,
    "FUN_1033f53a (Header Ingress)":  0x033F53A,
    "FUN_10342ebe (Sub-engine)":      0x0342EBE,
    "FUN_10343870 (Orchestrator)":    0x0343870,
    "FUN_1034798f (Egress Checksum)": 0x034798F,
}

print("\n=== [2] Scanning References for Entire Pipeline ===")
with open("GameAssembly.dll", "rb") as f:
    full_data = f.read()

for name, rva in pipeline_functions.items():
    va = image_base + rva
    rva_pat = struct.pack("<I", rva)
    va_pat = struct.pack("<I", va & 0xFFFFFFFF)
    
    # Search pointers
    rva_matches = full_data.count(rva_pat)
    va_matches = full_data.count(va_pat)
    
    # Search relative calls across all executable sections
    call_matches = []
    for s in pe.sections:
        if s.Characteristics & 0x20000000:
            s_data = s.get_data()
            s_rva = s.VirtualAddress
            s_name = s.Name.rstrip(b'\x00').decode('latin1')
            for i in range(len(s_data) - 5):
                if s_data[i] in (0xE8, 0xE9):
                    disp = struct.unpack("<i", s_data[i+1:i+5])[0]
                    dest = (s_rva + i + 5 + disp) & 0xFFFFFFFF
                    if dest == rva:
                        op = "CALL" if s_data[i] == 0xE8 else "JMP"
                        call_matches.append(f"{op} in [{s_name}] at {hex(s_rva + i)}")
                        
    print(f"\n{name} [RVA {hex(rva)}]:")
    print(f"  Pointers: {rva_matches} RVA refs, {va_matches} VA refs")
    if call_matches:
        for c in call_matches[:5]:
            print(f"  -> {c}")
    else:
        print("  -> No direct CALL/JMP opcodes")
