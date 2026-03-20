#ifndef MAIN_H
#define MAIN_H

/* --- Standard Libraries --- */
#include <stdarg.h> /* Pour les macros va_list, va_start, va_arg, va_end */
#include <unistd.h> /* Pour la fonction write() */

/* --- Main Function Prototype --- */
int _printf(const char *format, ...);

/* --- Helper Functions Prototypes --- */
/* Ces fonctions seront codees dans un autre fichier (ex: print_helpers.c) */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif
