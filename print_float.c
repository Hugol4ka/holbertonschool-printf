#include "main.h"

/**
 * print_unsigned_long - prints an unsigned long int
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_unsigned_long(unsigned long n)
{
    int count;
    char c;

    count = 0;
    if (n >= 10)
        count += print_unsigned_long(n / 10);

    c = (n % 10) + '0';
    write(1, &c, 1);
    count++;

    return (count);
}

/**
 * print_frac_6 - prints fractional part on exactly 6 digits
 * @n: fractional part (0 to 999999)
 *
 * Return: number of characters printed (6)
 */
int print_frac_6(unsigned long n)
{
    unsigned long div;
    char c;
    int count;

    div = 100000;
    count = 0;
    while (div > 0)
    {
        c = ((n / div) % 10) + '0';
        write(1, &c, 1);
        count++;
        div /= 10;
    }
    return (count);
}

/**
 * print_float - prints a float/double as %f (fixed 6 decimals)
 * @args: variadic arguments list
 *
 * Return: number of characters printed
 */
int print_float(va_list args)
{
    double n;
    double scaled;
    unsigned long all;
    unsigned long int_part;
    unsigned long frac_part;
    int count;

    n = va_arg(args, double);
    count = 0;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        n = -n;
    }

    scaled = (n * 1000000.0) + 0.5;
    all = (unsigned long)scaled;
    int_part = all / 1000000;
    frac_part = all % 1000000;

    count += print_unsigned_long(int_part);
    write(1, ".", 1);
    count++;
    count += print_frac_6(frac_part);

    return (count);
}
