# DNA Matching 🔬🧬💻

## Description 📝🔍✨

This project implements a **DNA Matching algorithm** that finds the longest common DNA subsequence between two given sequences. The program reads two DNA sequences from files, processes them, and outputs the longest matching sequence.

## Features 🚀📄🧪

- Reads DNA sequences from input files.
- Ignores invalid characters (only A, G, T, C are considered).
- Implements an efficient algorithm to find the **longest common subsequence**.
- Outputs the result to standard output.
- Handles large DNA sequences (up to **100,000 bases**).

## Technologies Used 🛠️💾🖥️

- **Language:** C
- **Memory Management:** Dynamic allocation for large sequences.
- **File Handling:** Reads DNA sequences from files.

## File Structure 📂📁🗂️

```
/DNA-Matching
 ├── src
 │   ├── dna.c            # Main C program
 │
 ├── test
 │   ├── input1.dna       # Example input file 1
 │   ├── input2.dna       # Example input file 2
 │   ├── output.dna       # Expected output file
 │
 ├── README.md            # This file
```

## How to Run 🏃‍♂️💡🖥️

### Compilation

Run the following command:

```sh
gcc -Wall -Wextra -std=c99 -o dna src/dna.c
```

### Execution

Run the program with two input DNA files:

```sh
./dna test/input1.dna test/input2.dna >output.dna
```

The output will be **the longest common DNA subsequence**.

### Example 📑📊🔬

#### Input (`test/input_example1.dna`):

```
CATTAGATATAGACG
```

#### Input (`test/input_example2.dna`):

```
CTATAGATATAGGGC
```

#### Output (`test/output.dna`):

```
TAGATATAG
```

## Edge Cases Considered ⚠️🧐✅

- Handling of **invalid characters** in input files.
- Very **short or long** DNA sequences.
- **Completely different** DNA sequences (should return an empty string).

## Future Improvements 🚧💡📈

- Optimize for **faster performance**.
- Extend to **multiple sequence comparison**.
- Add a **graphical visualization** of the matching sequences.

## License 📜⚖️✅

This project is licensed under the **MIT License**.

## Author 👨‍💻📧🔗

Giorgos Theodorou

