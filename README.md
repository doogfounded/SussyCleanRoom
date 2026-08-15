# SussyCleanRoom - Reverse Engineering & Architecture Notes

## Overview
This repository contains reverse-engineering artifacts, decompiled sources, and dynamic testing harnesses from when decompiling Among Us's GameAssembly.dll file with us discovering a bytecode interpreter kernel (`FUN_10285dc0`) that we have nicknamed **DoogEngine1** for the current moment.

Rather than attempting a top-down static decompilation of the entire binary, this project applies **empirical black-box probing, differential single-byte mutation testing, and dynamic execution telemetry** to map the virtual machine's internal finite state machine (FSM) and framing protocols from the inside out.

---

## 🧭 Methodology & Analysis Approach

When analyzing large, undocumented native binaries and flattened state machines:
1. **Isolate Subsystems:** Break monolithic dispatch loops into modular, testable functional regions rather than analyzing the entire binary at once.
2. **Dynamic Instrumentation:** Wrap target functions in isolated C++ test harnesses with controlled input buffers and execution boundaries.
3. **Differential Single-Byte Sweeps:** Hold a baseline payload constant and mutate exactly one byte at a time across candidate values (`0x00`, `0x01`, `0x02`, `0x7F`, `0xFF`, etc.) to isolate control bytes from passive arguments.
4. **Telemetry Logging:** Output cycle-by-cycle metrics (`bytes_consumed`, `cursor`, `state_hex`, `overflow`) to CSV to detect mathematical cadence, framing boundaries, and phase shifts.

---

## 🏗️ Architectural Findings

### 1. The Stream-Processor / Tick-Pump Model
The execution engine operates as an iterative stream pump. Calling core handlers repeatedly against a persistent `BufferContext` yields discrete consumption cycles rather than unconstrained parsing loops:
* **Frame Alignment:** When encountering padding or frame delimiters, the stream self-synchronizes across iterations.
* **Yield State (`0x103282d0`):** Indicates a clean frame completion or scheduler yield back to the host loop.

### 2. Region 1: 25-Byte Frame Format (`0x10286a40`)
Region 1 processes streaming command frames structured into distinct functional zones:

| Byte Offset | Purpose | Identified Behavior |
| :--- | :--- | :--- |
| **Byte 0** | **Magic / Region Enable** | `0x01` enters active parsing; other values cause early 3-byte bailout. |
| **Byte 1** | **Bitmask / Branch Flag** | Evaluates `byte[1] & 1`. Bit 0 set $\rightarrow$ 2-byte path; Bit 0 clear $\rightarrow$ 3-byte path. |
| **Byte 2** | **Length Modifier** | Controls payload consumption depth (`0x00` = 3B, `0x01` = 16B, `0x02+` = 23B). |
| **Bytes 3–24** | **Instruction Payload** | Passive arguments and data payload processed during active state passes. |

### 3. Region Survey & Subsystem Sizing
* **Region 0 (`0x10285dc0`):** Entry evaluation & header guard.
* **Region 1 (`0x10286a40`):** 23/25-byte stream command processor.
* **Region 2 (`0x10287390`):** Active 38-byte block consumer subsystem.
* **Regions 3–12 (`0x10287e00`+):** Specialized state-dependent compute/ALU blocks requiring explicit entry keys.

---

## 🛠️ Building and Running the Test Harness

The harness requires a clean C++20 environment targeting MinGW-w64.

### Direct Build via `g++` (PowerShell)
```powershell
g++ -std=c++20 -I./clean_src (Get-ChildItem clean_src/*.cpp | Where-Object { $_.Name -ne "FUN_102b23f0.cpp" }) -o test_harness.exe

./test_harness.exe
```

### Analyzing Telemetry Logs
To inspect anomalies and non-standard byte consumption in PowerShell:
```powershell
Import-Csv diff_trace.csv | Where-Object { [int]$_.bytes_consumed -ne 23 } | Format-Table -AutoSize
```
