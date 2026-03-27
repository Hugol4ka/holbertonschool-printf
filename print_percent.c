#include"main.h"

/**
 * print_percent - prints a percent sign
 * @bag: va_list of arguments (unused) because no arg for '%'
 * Return: number of characters printed (1)
 */

int print_percent(va_list bag)
{
	(void)bag;
	write(1, "%", 1);

	return (1);
}
