# Lab 12 – String Handling Functions  
This folder contains solved problems from Lab 12 of the "Programming Fundamentals" course.  

## Topics Covered  
- Character arrays and null-terminated strings  
- Pointers to `char` and dynamic memory allocation  
- Reading strings: `getc`, `getchar`, `fgets`  
- Writing strings: `putc`, `putchar`, `fputs`, `puts`  
- Character classification using `<ctype.h>` (`isalpha`, `isdigit`, etc.)  
- Core string operations from `<string.h>`:  
  - Length: `strlen`  
  - Copy: `strcpy`, `strncpy`  
  - Concatenation: `strcat`, `strncat`  
  - Comparison: `strcmp`, `strncmp`, `stricmp`  
  - Case conversion: `strlwr`, `strupr`, `strrev`  
  - Search: `strchr`, `strrchr`, `strstr`, `strpbrk`  
- String-to-number and number-to-string conversions from `<stdlib.h>`:  
  - `atoi`, `atol`, `atof`  
  - `itoa`, `ltoa`, `ultoa`  
- Memory block operations: `memset`, `memcpy`, `memmove`, `memcmp`, `memchr`  

## Problems  

### Part 1 – Character and String Input/Output  
#### Problem 1.1 – Count Character Occurrences  
- Read characters one by one from keyboard until EOF (CTRL+D)  
- Count occurrences of a specific character  

#### Problem 1.2 – Count Vowel Occurrences  
- Read characters from keyboard until EOF  
- Count individual vowel occurrences (a, e, i, o, u)  

#### Problem 1.3 – Word Lengths from File  
- Read a single-line text using `fgets` from a file  
- Print the length of each word (split by whitespace)  
- Do **not** use `strlen`  

#### Problem 1.4 – Convert Case from File  
- Read lines from file using `fgets`  
- Convert entire content to uppercase or lowercase using custom functions  
- Display a menu to choose conversion type  

### Part 2 – String Processing and Advanced Tasks  
#### Problem 2.1 – PERSONAL Structure  
- Define structure `PERSONAL` with:  
  - `char *nume`, `char *prenume`, `int varsta`  
- Dynamically allocate memory for `n` persons  
- Read input from file specified by user  
- Display in table format  
- Filter persons under 30 years  
- Sort alphabetically by `nume`  

#### Problem 2.2 – Convert Integer to Hexadecimal String  
- Implement function to convert `unsigned long` to hexadecimal (`0x` prefix)  
- Do not use built-in conversion functions  

#### Problem 2.3 – Remove Comments from C Source Code  
- Read content from file `p11.c`  
- Print code on screen, without comments  
- Preserve original line structure  

#### Problem 2.4 – Text Analysis from stdin  
- Read multi-line input until CTRL+D  
- Compute:  
  - Number of letters, digits, separators, words, sentences, paragraphs  
  - Total character count  
  - Percentage of letters and digits  

#### Problem 2.5 – Word-by-Word Syllable Separation  
- Read words from input until `.` is encountered  
- Print each word and its syllabified version  
- Basic rules:  
  - 1 consonant between vowels → goes to next syllable  
  - 2+ consonants between vowels → first stays, rest go to next  

## Build Instructions  
To compile and link programs using string manipulation functions:  
```bash
clang -Wall -c stringUtils.c    # Utility functions for string operations (if any)
clang -Wall -c main.c           # Main program
clang stringUtils.o main.o -o output
```
## Build with Makefile

- To build the project:
```bash
make
```
- To clean up build files:
```bash
make clean
```
