# CSA02 – Assignment 5
## Modular, Memory-Aware and Persistent Program Engineering

**Course Code:** CSA02  
**Course Name:** C Programming  
**Course Outcome:** CO5  
**Assignment:** 5  
**Student Name:** [Enter Your Name]  
**Register Number:** 1914260115  
**Compiler:** OnlineGDB – C Compiler  
**Programming Language:** C

---

## 1. Introduction

This assignment focuses on modular programming, recursion, pointers, dynamic memory allocation, file handling, memory safety and performance analysis using C programming.

The case study is based on a District Blood Bank Network connecting multiple hospitals and managing donor and blood stock records.

## 2. Objectives

- Develop modular C programs using functions.
- Understand recursion and iterative approaches.
- Implement pointers and dynamic memory allocation.
- Manage donor records using files.
- Compare text and binary file operations.
- Measure memory usage and execution time.
- Apply memory safety techniques.

## 3. Repository Structure

```text
CSA02-1914260115-ASSIGNMENT-5/
│
├── README.md
│
├── A1/
│   ├── A1.c
│   └── A1_Analysis.md
│
├── A2/
│   ├── A2.c
│   └── A2_Analysis.md
│
├── A3/
│   ├── A3.c
│   └── A3_Analysis.md
│
├── A4/
│   ├── A4.c
│   └── A4_Analysis.md
│
├── A5/
│   ├── A5.c
│   ├── donors.txt
│   └── A5_Analysis.md
│
├── B1/
│   ├── B1.c
│   └── B1_Output.png
│
├── B2/
│   ├── B2.c
│   ├── B2_Analysis.md
│   └── B2_Output.png
│
├── B3/
│   ├── B3.c
│   ├── B3_Analysis.md
│   └── B3_Output.png
│
└── B4/
    ├── B4.c
    ├── donors.txt
    ├── B4_Analysis.md
    └── B4_Output.png
```

## 4. Part A – Design and Pseudocode

### A1 – Function Decomposition and Interfaces
Designed modular functions and studied function interfaces, return values and alternatives to global variables.

### A2 – Recursion and Iteration
Implemented recursive digital root and fast power operations. Studied recursion traces, termination and iterative alternatives.

### A3 – Pointers and Command-Line Arguments
Practised pointer expressions, pointer-based functions and command-line argument handling.

### A4 – Dynamic Memory Allocation
Designed a growable donor list using dynamic memory allocation and studied memory reallocation and allocation failures.

### A5 – Persistent File Storage
Designed donor and stock file storage using text and binary file operations. Studied file access and record updates.

## 5. Part B – Implementation and Testing

### B1 – Recursion Implementation and Testing
Implemented recursive functions, tested different input values and compared recursive and iterative approaches.

### B2 – Input Validation and Error Handling
Implemented input validation and tested donor details, invalid inputs and error-handling conditions.

### B3 – Text and Binary File Performance
Compared text and binary file operations using different record counts. Studied file size, execution time and record updates.

### B4 – Donor Eligibility Report
Implemented a donor eligibility report using a growable donor list loaded from a file. Measured allocated memory and execution time and released allocated memory using `free()`.

## 6. Software and Tools Used

- Programming Language: C
- Compiler: OnlineGDB C Compiler
- Repository Management: GitHub
- Code Execution: OnlineGDB
- Memory Management: `malloc()`, `realloc()`, `free()`
- File Handling: `fopen()`, `fscanf()`, `fread()`, `fwrite()`, `fseek()`

## 7. Compilation and Execution

Programs were developed and executed using OnlineGDB.

General GCC compilation command:

```bash
gcc filename.c -o program
```

Execution command:

```bash
./program
```

For Windows GCC:

```bash
program.exe
```

## 8. Testing and Results

Each program was compiled and tested with suitable inputs.

The outputs, observations and experimental results are maintained in their respective folders. Performance measurements should be recorded using actual program results.

## 9. Memory Management and Safety

Dynamic memory allocation was used where required. Allocated memory was released using `free()` after processing. Memory safety checks should be performed using AddressSanitizer or Valgrind where available.

## 10. Conclusion

This assignment provided practical experience in modular programming, recursion, pointers, dynamic memory allocation, persistent file storage and performance analysis. The programs demonstrate important C programming concepts through the District Blood Bank Network case study.

## 11. GitHub Repository

Repository:  
https://github.com/yukesh-1807/CSA02-1914260115-ASSIGNMENT-5.git
