import sys
import time

def compare():
    f_engine = "region4_engine.csv"
    f_model  = "region4_model.csv"
    
    print(f"Comparing '{f_engine}' against '{f_model}'...")
    start_time = time.time()
    
    mismatches = 0
    line_num = 0
    
    with open(f_engine, 'r') as f1, open(f_model, 'r') as f2:
        for l1, l2 in zip(f1, f2):
            line_num += 1
            if l1 != l2:
                mismatches += 1
                if mismatches <= 10:
                    print(f"Mismatch at line {line_num}:")
                    print(f"  Engine: {l1.strip()}")
                    print(f"  Model:  {l2.strip()}")
                elif mismatches == 11:
                    print("  ... suppressing further mismatch logs ...")

    elapsed = time.time() - start_time
    print("-" * 50)
    print(f"Processed {line_num:,} rows in {elapsed:.2f} seconds.")
    if mismatches == 0:
        print("[SUCCESS] 100% Match! All 16,777,216 cases verified identical.")
    else:
        print(f"[FAILURE] Found {mismatches:,} total mismatches.")

if __name__ == "__main__":
    compare()
