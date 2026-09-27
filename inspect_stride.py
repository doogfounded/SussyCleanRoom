with open('GameAssembly.dll', 'rb') as f:
    # Seek to the first entry of the 96-byte stride
    start = 0x02958FBF
    f.seek(start)
    elem1 = f.read(96)
    elem2 = f.read(96)

def print_element(label, offset, data):
    print(f"\n--- {label} at file offset {hex(offset)} (96 bytes) ---")
    for i in range(0, len(data), 16):
        hex_part = " ".join(f"{b:02x}" for b in data[i:i+16])
        ascii_part = "".join(chr(b) if 32 <= b <= 126 else "." for b in data[i:i+16])
        print(f"{hex(offset + i)}: {hex_part:<48} | {ascii_part}")

print_element("Element 1", start, elem1)
print_element("Element 2", start + 96, elem2)
