# Power Quality Waveform Analyser

## Overview
This C program analyses power quality data from a CSV file. It computes RMS voltage, peak-to-peak voltage, DC offset, clipping count, and EN50160 compliance for three-phase AC waveforms.

The system processes waveform data and performs signal analysis to evaluate electrical power quality characteristics.

---

## Author
Pramodhi Rathnayake (25029679)

---

## GitHub Repository
https://github.com/PramodhiR/PQ-Analyser.git

---

## Features
- CSV file input processing
- RMS voltage calculation
- Peak-to-peak voltage calculation
- DC offset computation
- Clipping detection and counting
- Voltage validation
- EN50160 compliance checking
- File output generation

---

## Concepts Used
- Structures (structs) for waveform data organisation
- Pointers for efficient memory handling
- File handling (CSV read/write)
- Modular programming (multiple source files)
- Signal processing techniques
- Debugging and step-by-step testing

---

## Requirements
- Windows / Linux / macOS
- C compiler (gcc, clang, or CLion)
- CMake (if using CLion)

---

## Project Structure
- `main.c` → Main program logic
- `functions.c` → Processing functions
- `functions.h` → Function declarations
- `data.csv` → Input dataset
- `output.txt` → Processed results

---

## How to Run

1. Compile the program using a C compiler (e.g. GCC)
2. Run the executable file
3. Provide the input CSV file when prompted
4. View results in terminal or output file

### Example (GCC)
```bash
gcc -std=c99 main.c functions.c -o power_analyser
./power_analyser data.csv
