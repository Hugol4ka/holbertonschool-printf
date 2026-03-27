#include"main.h"

/**
 * print_char - prints a single character
 * @bag: va_list containing the character to print
 * Return: number of characters printed (1)
 */

int print_char(va_list bag)
{
	char c;

	c = va_arg(bag, int);
	write(1, &c, 1);
	return (1);
}
