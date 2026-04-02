# Project: _printf

## 📝 Description

This project is a custom implementation of the `printf` function from the C standard library. It was developed as a **collaborative project** at **Holberton School**, focusing on deep-level C programming, variadic functions, and memory management.

Our goal was to recreate the core logic of `printf`, allowing formatted output to the standard stream while handling various conversion specifiers and edge cases. This project highlights our ability to work as a team to build robust, modular, and well-documented software.

### 👥 Collaborative Work
This repository is the result of a joint effort, where we shared responsibilities for:
* Architecture and Flowchart design.
* Implementation of the core parser.
* Development of specific conversion handlers.
* Writing comprehensive manual pages and technical documentation.

## 📋 Requirements

### Environment
* **Operating System:** Ubuntu 20.04 LTS
* **Compiler:** `gcc`
* **C Standard:** `gnu89` (compiled with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`)

### Authorized Functions & Macros
The following functions and macros from the standard library are used in this project:

 | `write` | 
 | `malloc` | 
 | `free` |
 | `va_start` | 
 | `va_end` | 
 | `va_copy` |
 | `va_arg` |


## Supported Format Specifiers
    
| Specifier | Description | Function File |
| :---: | :--- | :--- |
| **`%i & %d`** | Prints a integer | `print_int.c` |
| **`%c`** | Prints a single character | `print_char.c` |
| **`%s`** | Prints a string of characters | `print_string.c` |
| **`%%`** | Prints a percent sign | `print_percent.c`|
| **`%f`** | Prints a float | `print_float.c`|
| **`%u`** | Prints a unsigned | `print_base.c`|
| **`Other`** | Not supported | :boom:



## Technologies used 
![C](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white) ![Makefile](https://img.shields.io/badge/Build-Makefile-00599C?style=for-the-badge&logo=gnu&logoColor=white) ![Git](https://img.shields.io/badge/Git-F05033?style=for-the-badge&logo=git&logoColor=white) ![Linux](https://img.shields.io/badge/OS-Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black) ![VS Code](https://img.shields.io/badge/Editor-VS%20Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white) ![Groff](https://img.shields.io/badge/Doc-Groff-131313?style=for-the-badge&logo=gnu&logoColor=white)

## 📂 Project Structure

| File | Description |
| :--- | :--- |
| `_printf.c` | Main function file containing the `_printf` engine and format parser |
| `get_print_func.c` | Logic to select the appropriate function for each conversion specifier |
| `main.h` | Header file with structures, function prototypes, and standard library inclusions |
| `_printf.3` | Custom manual page in Groff format for documentation |
| `Makefile` | Script to automate compilation and project management |
| `.gitignore` | Excludes binary files and temporary objects from the repository |
| `print_char.c` | Handles character output (`%c`) |
| `print_string.c` | Handles string output (`%s`) |
| `print_percent.c` | Handles the percent sign output (`%%`) |
| `print_int.c` | Handles decimal and integer specifiers (`%d`, `%i`) |
| `print_base.c` | Handles conversion for different bases (Binary, Octal, Hex...) |
| `print_float.c` | Handles floating-point numbers implementation |
| `print_pointer.c` | Handles memory address printing (`%p`) |.
  
## 🛠️ Installation & Compilation

This project uses a **Makefile** to automate the build process and create the static library.

### 1. Prerequisites
Ensure you have `gcc`, `make`, and standard C libraries installed on your **Linux (Ubuntu)** environment.

### 2. Build Instructions

Run the following commands in the root directory of the project:

| Command | Description |
| :--- | :--- |
| `make` | Compiles all source files and generates the `libftprintf.a` library |
| `make clean` | Removes all object files (`.o`) |
| `make fclean` | Removes object files AND the final library file |
| `make re` | Performs a full cleanup followed by a fresh compilation (`fclean` + `make`) |

### 3. Usage in your project

To test the function with your own `main.c` file, simply link the library during compilation:

```bash
gcc -Wall -Wextra -Werror -pedantic main.c libftprintf.a -o _printf_test 
```

## Flowchart
The following diagram describes the logic of the `_printf` function:

<img width="985" height="1601" alt="Final_flowchart_printf drawio" src="https://github.com/user-attachments/assets/755c1c92-fa44-43ac-bb35-17548b3c7da0" />

## 📖 Documentation

The project includes a custom manual page that follows the standard Linux programmer's manual format. It provides a detailed description of the function's syntax, return values, and supported conversion specifiers.

### How to access the manual
To view the manual page, use the following command from the root of the repository:

```bash
man ./_printf.3
```
## 🧪 Testing & Memory Check

To ensure the robustness of our `_printf` implementation, we conducted extensive testing, including memory leak detection.

### 💻 Usage Example
You can test the function with a `main.c` file like this:

```c
#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
    _printf("Hello %s\n", "world");
    _printf("Char: %c\n", 'A');
    _printf("Number: %d\n", 42);
    _printf("Negative: %i\n", -7);
    _printf("Percent: %%\n");
    return (0);
}
```
```c
Expected Output:

Hello world
Char: A
Number: 42
Negative: -7
Percent: %
```

### 🛡️ Memory Check (Valgrind)
Our implementation has been strictly tested with **Valgrind** to ensure zero memory leaks and no memory errors.

**Command:**
```bash
valgrind --leak-check=full --show-leak-kinds=all ./_printf_test
```
```c
==16779== HEAP SUMMARY:
==16779==     in use at exit: 0 bytes in 0 blocks
==16779==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==16779== 
==16779== All heap blocks were freed -- no leaks are possible
==16779== 
==16779== For lists of detected and suppressed errors, rerun with: -s
==16779== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## ✍️ Authors

* **Rouvellat Pierre** - [GitHub Profile](https://github.com/Pierre1200)
* **Lacassagne Hugo** - [GitHub Profile](https://github.com/Hugol4ka)




