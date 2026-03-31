#include"main.h"

int (*get_print_func(char s))(va_list)
{
	print_t options[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"f", print_float},
		{NULL, NULL}
	};

	int i = 0;

	while (options[i].type != NULL)
	{
		if (s == options[i].type[0])
		{
			return (options[i].f);
		}
		i++;
	}
	return (NULL);
}