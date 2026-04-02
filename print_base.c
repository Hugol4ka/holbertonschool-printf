#include "main.h"

/**
* print_base_u - print an unsigned integer in any base
* @n: number to print
* @digits: lookup table for symbols (ex: "0123456789abcdef")
* @base: base length (8, 10, 16)
*
* Return: number of characters printed
*
Principe:
* 1) On remonte récursivement jusqu'au chiffre le plus significatif.
* 2) Puis on affiche les chiffres de gauche à droite au retour.
* 3) On compte chaque caractère écrit.
*/
int print_base_u(unsigned int n, const char *digits, unsigned int base)
{
	int count;

	char c;

	count = 0;

	/* If n has more than one digit in this base, print higher digits first */
	if (n >= base)
		count += print_base_u(n / base, digits, base);

	/* Current digit = remainder in this base */
	c = digits[n % base];
	write(1, &c, 1);
	count++;

	return (count);
}

/**
* print_unsigned_dec - handle %u (unsigned decimal)

* @args: variadic list
*
* Return: number of characters printed
*/
int print_unsigned_dec(va_list args)
{
	unsigned int n;

	/* For %u, type must be unsigned int */
	n = va_arg(args, unsigned int);

	/* Decimal base */
	return (print_base_u(n, "0123456789", 10));
}

/**
* print_octal - handle %o (unsigned octal)

* @args: variadic list
*
* Return: number of characters printed
*/
int print_octal(va_list args)
{
	unsigned int n;

	n = va_arg(args, unsigned int);

	/* Octal base */
	return (print_base_u(n, "01234567", 8));
}

/**
* print_hex_lower - handle %x (unsigned hexadecimal lowercase)
* @args: variadic list
*
* Return: number of characters printed
*/
int print_hex_lower(va_list args)
{
	unsigned int n;

	n = va_arg(args, unsigned int);

	/* Hex base with lowercase letters */
	return (print_base_u(n, "0123456789abcdef", 16));
}

/**
* print_hex_upper - handle %X (unsigned hexadecimal uppercase)
* @args: variadic list
*
* Return: number of characters printed
*/
int print_hex_upper(va_list args)
{
	unsigned int n;

	n = va_arg(args, unsigned int);

	/* Hex base with uppercase letters */
	return (print_base_u(n, "0123456789ABCDEF", 16));
}
