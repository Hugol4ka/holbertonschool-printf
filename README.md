# 0x11. C - printf

## Description
This project is a custom implementation of the standard C library function `printf`. It formats and prints data to the standard output according to a format string. 

This is a group project developed by Pierre Rouvellat and Hugo Lacassagne.

## Compilation
All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`:
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c

graph TD
    A[Start _printf] --> B{format[i] == '\0'?}
    B -- Yes --> C[Return Total Count]
    B -- No --> D{format[i] == '%'}
    
    D -- No --> E[Write char to stdout]
    E --> F[Total Count++]
    F --> G[i++]
    G --> B

    D -- Yes --> H{Check format[i+1]}
    H -- 'c' --> I[Call print_char]
    H -- 's' --> J[Call print_string]
    H -- '%' --> K[Write '%']
    H -- '\0' --> L[Return -1]
    
    I --> M[Total Count += return value]
    J --> M
    K --> M
    M --> N[i += 2]
    N --> B