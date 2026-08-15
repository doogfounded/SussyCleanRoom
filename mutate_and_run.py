import sys
import subprocess
import shutil

def mutate_and_run(offset, new_bytes_hex):
    original_file = "testfile"
    mutated_file = "testfile_mutated"

    # Copy original file
    shutil.copyfile(original_file, mutated_file)

    # Convert hex string to bytes
    patch_bytes = bytes.fromhex(new_bytes_hex)

    # Apply byte patch at specified offset
    with open(mutated_file, "r+b") as f:
        f.seek(offset)
        old_bytes = f.read(len(patch_bytes))
        f.seek(offset)
        f.write(patch_bytes)

    print("=========================================================")
    print("        Byte Mutation & Payload Execution Tool          ")
    print("=========================================================")
    print(f"[+] Mutating '{original_file}' at offset 0x{offset:X} ({offset})")
    print(f"[+] Original bytes : {old_bytes.hex()}")
    print(f"[+] New bytes      : {patch_bytes.hex()}")
    print(f"[+] Saved mutated payload to '{mutated_file}'")
    print("---------------------------------------------------------")
    print("[+] Executing state engine on mutated payload...\n")

    # Run executable harness
    result = subprocess.run(["./clean_build/run_payload.exe", mutated_file], capture_output=True, text=True)
    print(result.stdout)
    if result.stderr:
        print("Stderr:", result.stderr)

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python mutate_and_run.py <offset_decimal_or_hex> <hex_bytes>")
        print("Example: python mutate_and_run.py 0x0 307831515248  # Patch '0x1QRH' at offset 0")
        sys.exit(1)

    raw_offset = sys.argv[1]
    offset = int(raw_offset, 16) if raw_offset.startswith("0x") else int(raw_offset)
    new_bytes_hex = sys.argv[2]

    mutate_and_run(offset, new_bytes_hex)
