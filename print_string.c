#include"main.h"
#include<unistd.h>
#include<stdarg.h>
#include<stddef.h>

/**
 * print_string - Prints a string from a va_list argument
 * @bag: va_list containing the string argument
 *
 * Return: The number of characters printed
 */

int print_string(va_list bag)
{
char *str;
int i = 0;

str = va_arg(bag, char *);

if (str == NULL)
str = "(null)";

while (str[i] != '\0')
	{
	write(1, &str[i], 1);
	i++;
	}

return (i);
}
