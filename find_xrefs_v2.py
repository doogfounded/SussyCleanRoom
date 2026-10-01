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

# 1. Search for table pointer references: both RVA and absolute VA
patterns = [
    (struct.pack("<I", target_rva), "32-bit RVA (0x00285dc0)"),
    (struct.pack("<I", target_va & 0xFFFFFFFF), "32-bit Absolute VA (0x10285dc0)"),
    (struct.pack("<Q", target_va), "64-bit Absolute VA")
]

print("[1] Pointer & Table References:")
for pattern, label in patterns:
    idx = 0
    found = 0
    while True:
        idx = data.find(pattern, idx)
        if idx == -1:
            break
        try:
            rva = pe.get_rva_from_offset(idx)
            sec = pe.get_section_by_rva(rva)
            sec_name = sec.Name.rstrip(b'\x00').decode('latin1') if sec else "unknown"
            print(f"  Found {label} at file offset {hex(idx)} (RVA: {hex(rva)} in {sec_name})")
        except Exception:
            print(f"  Found {label} at file offset {hex(idx)}")
        idx += len(pattern)
        found += 1
    if found == 0:
        print(f"  No {label} references found.")

# 2. Search ALL executable sections for relative CALL (E8) and JMP (E9)
print("\n[2] Relative Call (E8) & JMP (E9) References across all code sections:")
IMAGE_SCN_MEM_EXECUTE = 0x20000000
total_calls = 0

for sec in pe.sections:
    sec_name = sec.Name.rstrip(b'\x00').decode('latin1')
    is_exec = (sec.Characteristics & IMAGE_SCN_MEM_EXECUTE) != 0 or sec_name in ('.text', 'il2cpp')
    if not is_exec:
        continue

    sec_data = sec.get_data()
    sec_rva = sec.VirtualAddress

    for i in range(len(sec_data) - 5):
        if sec_data[i] in (0xE8, 0xE9):
            disp = struct.unpack("<i", sec_data[i+1:i+5])[0]
            caller_rva = sec_rva + i
            dest_rva = (caller_rva + 5 + disp) & 0xFFFFFFFF
            if dest_rva == target_rva:
                op_type = "CALL" if sec_data[i] == 0xE8 else "JMP"
                print(f"  {op_type} in [{sec_name}] at RVA {hex(caller_rva)} -> {hex(target_rva)}")
                total_calls += 1

if total_calls == 0:
    print("  No direct relative CALL or JMP opcodes found targeting this RVA.")
