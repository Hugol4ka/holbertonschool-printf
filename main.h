#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/**
 * struct print_t - Structure for format specifiers and their handlers
 * @type: Format specifier character
 * @f: Function pointer to handle the format specifier
 */

typedef struct print_t
{
	char *type;
	int (*f)(va_list);
} print_t;

int print_pointer(va_list args);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int (*get_print_func(char s))(va_list);
int print_int(va_list args);
int print_unsigned(unsigned long n);
int print_float(va_list args);
int print_unsigned_long(unsigned long n);
int print_frac_6(unsigned long n);
int print_base_u(unsigned int n, const char *digits, unsigned int base);
int print_unsigned_dec(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);

#endif
