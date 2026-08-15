import os
from pathlib import Path

def sort_files_by_size(target_directory, output_file_path):
    """
    Scans a directory, sorts files by size (largest first), 
    and saves the list to a text file.
    """
    dir_path = Path(target_directory)
    output_path = Path(output_file_path)
    
    # 1. Ensure target directory exists
    if not dir_path.is_dir():
        print(f"Error: The directory '{target_directory}' does not exist.")
        return

    file_list = []
    
    # 2. Gather all files and their sizes (excluding directories)
    for item in dir_path.iterdir():
        if item.is_file():
            try:
                file_size = item.stat().st_size  # Size in bytes
                file_list.append((item.name, file_size))
            except OSError as e:
                # Handle potential permission errors for specific files
                print(f"Skipping {item.name}: {e}")

    # 3. Sort files by size in descending order (largest first)
    # To sort smallest first, change reverse=True to reverse=False
    file_list.sort(key=lambda x: x[1], reverse=True)

    # 4. Save results to the output text file
    try:
        with open(output_path, mode='w', encoding='utf-8') as f:
            f.write(f"File Size Report for: {dir_path.resolve()}\n")
            f.write("=" * 60 + "\n")
            f.write(f"{'File Name':<40} | {'Size (Bytes)':<15}\n")
            f.write("=" * 60 + "\n")
            
            for file_name, size in file_list:
                f.write(f"{file_name:<40} | {size:<15,}\n")
                
        print(f"Successfully saved sorted file list to: {output_path.resolve()}")
        
    except IOError as e:
        print(f"Error writing to output file: {e}")

if __name__ == "__main__":
    # --- CONFIGURATION ---
    # Replace with the path to the folder you want to scan
    TARGET_FOLDER = "./clean_src" 
    
    # Replace with your desired output file destination
    OUTPUT_FILE = "./clean_src/sorted_files_report.txt" 
    # ---------------------
    
    sort_files_by_size(TARGET_FOLDER, OUTPUT_FILE)
