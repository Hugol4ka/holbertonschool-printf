#include "main.h"

/**
* print_ptr_hex - Affiche une valeur non signée en hexadécimal minuscule
* @n: valeur à afficher
*
* Return: nombre de caractères écrits
*/
int print_ptr_hex(unsigned long n)
{
	int count;

	char c;

	char *digits;

	digits = "0123456789abcdef";
	count = 0;

	/* Affiche d'abord les chiffres de poids fort */
	if (n >= 16)
		count += print_ptr_hex(n / 16);

	/* Puis le chiffre courant */
	c = digits[n % 16];
	write(1, &c, 1);
	count++;

	return (count);
}

/**
* print_pointer - Gère le specifier %p
* @args: liste variadique
*
* Description:
* - Si pointeur NULL: affiche "(nil)" (comportement Linux courant)
* - Sinon: affiche "0x" + adresse en hexadécimal minuscule
*
* Return: nombre de caractères écrits
*/
int print_pointer(va_list args)
{
	void *ptr;

	unsigned long addr;

	int count;

	ptr = va_arg(args, void *);
	count = 0;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));

	addr = (unsigned long)ptr;

	count += write(1, "0x", 2);
	count += print_ptr_hex(addr);

	return (count);
}
