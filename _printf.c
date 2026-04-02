#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - Produces output according to a format.
 * @format: Character string containing text and format specifiers.
 *
 * Return: The total number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
    /* --- 1. DECLARATIONS --- */
    va_list args;
    int count = 0;         /* Total number of printed characters */
    int i = 0;             /* Iterator for the 'format' string */
    int (*pfunc)(va_list); /* Function pointer to hold the matching print function */

    /* --- 2. EDGE CASES --- */
    if (format == NULL)
        return (-1);

    /* --- 3. INITIALIZATION --- */
    va_start(args, format);

    /* --- 4. MAIN LOOP --- */
    while (format != NULL && format[i] != '\0')
    {
        if (format[i] == '%')
        {
            /* EDGE CASE: '%' is the very last character of the string */
            if (format[i + 1] == '\0')    
            {
                va_end(args);
                return (-1);
            }

            /* Check if the NEXT character matches a valid format specifier */
            pfunc = get_print_func(format[i + 1]);

            if (pfunc != NULL)
            {
                count += pfunc(args); /* Execute the matched function */
                i++;
            }
            else
            {
                /* CASE: Double %% */
                if (format[i + 1] == '%')
                {
                    write(1, "%", 1);
                    count++;
                }
                /* CASE: Unknown format specifier (e.g., "%z") */
                else
                {
                    write(1, "%", 1);            /* Print the '%' */
                    write(1, &format[i + 1], 1); /* Print the unknown character */
                    count += 2;
                }
                i++; /* Skip the evaluated character for the next iteration */
            }
        }
        else
        {
            /* CASE: Regular character */
            write(1, &format[i], 1);
            count++;
        }
        i++; /* Move to the next character in the string */
    }

    /* --- 5. CLEANUP --- */
    va_end(args);

    return (count);
}