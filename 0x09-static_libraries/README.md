# 0x09. C - Static Libraries

## Learning Objectives
- Understand what static libraries are and why they are used
- Create a static library from existing object files
- Use `ar` (archiver) and `ranlib` to build and index libraries
- Link a program with a static library using `gcc`
- Write a script to automate library creation from all `.c` files

## Project Structure
- `main.h` – header with all function prototypes
- `*.c` – source files for each function
- `libmy.a` – static library containing all functions
- `create_static_lib.sh` – script to build `liball.a` from all `.c` files

## Functions Included
The library `libmy.a` contains the following functions:
- `_putchar` – write a character to stdout
- `_islower` – check if character is lowercase
- `_isalpha` – check if character is alphabetic
- `_abs` – compute absolute value
- `_isupper` – check if character is uppercase
- `_isdigit` – check if character is a digit
- `_strlen` – get string length
- `_puts` – print a string followed by newline
- `_strcpy` – copy a string
- `_atoi` – convert string to integer (placeholder)
- `_strcat` – concatenate two strings
- `_strncat` – concatenate with a byte limit
- `_strncpy` – copy a string with a limit
- `_strcmp` – compare two strings
- `_memset` – fill memory with constant byte
- `_memcpy` – copy memory area
- `_strchr` – locate a character in a string
- `_strspn` – get length of prefix substring
- `_strpbrk` – search for any of a set of bytes
- `_strstr` – locate a substring

## Compilation
All source files are compiled with:
gcc -std=gnu89 main.c -L. -lmy -o program

Script create_static_lib.sh
The script compiles all .c files in the current directory and creates a static library liball.a. Run it with:

bash
./create_static_lib.sh
