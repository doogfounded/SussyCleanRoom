import pefile
import struct

pe = pefile.PE("GameAssembly.dll")
image_base = pe.OPTIONAL_HEADER.ImageBase
target_rva = 0x285DC0
target_va = image_base + target_rva

print(f"Target VA:  {hex(target_va)}")
print(f"Target RVA: {hex(target_rva)}\n")

with open("GameAssembly.dll", "rb") as f:
    data = f.read()

# 1. Search for direct pointer references (data/vtable references)
ptr_pattern_32 = struct.pack("<I", target_va & 0xFFFFFFFF)
ptr_pattern_64 = struct.pack("<Q", target_va)

print("[1] Pointer References in File:")
for pattern, label in [(ptr_pattern_32, "32-bit pointer"), (ptr_pattern_64, "64-bit pointer")]:
    idx = 0
    found = 0
    while True:
        idx = data.find(pattern, idx)
        if idx == -1:
            break
        rva = pe.get_rva_from_offset(idx)
        print(f"  Found {label} at raw offset {hex(idx)} (RVA: {hex(rva)})")
        idx += len(pattern)
        found += 1
    if found == 0:
        print(f"  No {label}s found.")

# 2. Search for x86/x64 relative CALL/JMP opcodes (E8 / E9 xx xx xx xx)
print("\n[2] Relative Call (E8) References in .text:")
text_sec = None
for sec in pe.sections:
    if b".text" in sec.Name:
        text_sec = sec
        break

if text_sec:
    sec_data = text_sec.get_data()
    sec_rva = text_sec.VirtualAddress
    for i in range(len(sec_data) - 5):
        if sec_data[i] in (0xE8, 0xE9):  # CALL or JMP relative
            disp = struct.unpack("<i", sec_data[i+1:i+5])[0]
            caller_rva = sec_rva + i
            dest_rva = caller_rva + 5 + disp
            if dest_rva == target_rva:
                op_type = "CALL" if sec_data[i] == 0xE8 else "JMP"
                print(f"  {op_type} at RVA {hex(caller_rva)} -> {hex(target_rva)}")
