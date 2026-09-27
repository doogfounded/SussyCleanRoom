import struct

target_offset = 0x028C32C0

with open('GameAssembly.dll', 'rb') as f:
    f.seek(0x3C)
    pe_offset = struct.unpack('<I', f.read(4))[0]
    
    f.seek(pe_offset)
    if f.read(4) != b'PE\x00\x00':
        print('Not a valid PE file!')
        exit(1)
        
    num_sections, opt_hdr_size = struct.unpack('<2x H 12x H 2x', f.read(20))
    f.seek(pe_offset + 24 + opt_hdr_size)
    
    print(f"Checking target raw file offset: {hex(target_offset)}\n")
    print(f"{'Section':<10} | {'Raw Offset':<12} | {'Raw Size':<12} | {'Virtual Addr':<14} | Status")
    print('-' * 65)
    
    matched = False
    for _ in range(num_sections):
        sec_data = f.read(40)
        name = sec_data[:8].rstrip(b'\x00').decode('latin1')
        virt_size, virt_addr, raw_size, raw_ptr = struct.unpack('<IIII', sec_data[8:24])
        
        status = ''
        if raw_ptr <= target_offset < raw_ptr + raw_size:
            status = '<<< TARGET LOCATED HERE'
            matched = True
            
        print(f"{name:<10} | {hex(raw_ptr):<12} | {hex(raw_size):<12} | {hex(virt_addr):<14} | {status}")
        
    if not matched:
        print('\nTarget offset not found in any standard mapped section.')
