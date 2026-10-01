import os

magic_signatures = [
    b"0x1QRH",
    b"1QRH",
    b"\x5a\x3c", # Opcode mask constants
]

targets = [f for f in os.listdir(".") if f.endswith((".dll", ".exe"))]

print(f"Scanning binaries in workspace: {targets}\n")

for target in targets:
    try:
        with open(target, "rb") as f:
            data = f.read()
            
        print(f"=== {target} (Size: {len(data):,} bytes) ===")
        found_any = False
        for sig in magic_signatures:
            pos = 0
            while True:
                pos = data.find(sig, pos)
                if pos == -1:
                    break
                print(f"  Found signature {sig} at file offset {hex(pos)}")
                pos += len(sig)
                found_any = True
        if not found_any:
            print("  No engine signatures found in this file.")
    except Exception as e:
        print(f"  Error reading {target}: {e}")
