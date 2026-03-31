#include "main.h"

/**
 * print_unsigned - prints an unsigned long integer
 * @n: number to print
 *
 * Return: number of printed characters
 */
int print_unsigned(unsigned long n)
{
    int count;
    char c;

    count = 0;
    if (n / 10)
        count += print_unsigned(n / 10);

    c = (n % 10) + '0';
    write(1, &c, 1);
    count++;

    return (count);
}

/**
 * print_int - prints a signed integer (%d or %i)
 * @args: variadic arguments list
 *
 * Return: number of printed characters
 */
int print_int(va_list args)
{
    long n;
    int count;

    n = va_arg(args, int);
    count = 0;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        n = -n;
    }

    count += print_unsigned((unsigned long)n);
    return (count);
}
