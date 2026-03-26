#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* Pour les macros */
#include <unistd.h> /*fonction write()*/
#include<stddef.h> /*Null*/

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


int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int (*get_print_func(char s))(va_list);

#endif
