#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - Produit une sortie selon un format.
 * @format: Chaîne de caractères contenant le texte et les directives.
 *
 * Return: Le nombre total de caractères imprimés, ou -1 en cas d'erreur.
 */

int _printf(const char *format, ...)
{
    /* --- 1. DECLARATIONS --- */
    va_list args;
    int count = 0; /* score final */
    int i = 0;     /* index pour parcourir 'format' */
    int (*pfunc)(va_list); /* pointeur pour stocker la fonction trouvée */

    /* --- 2. CAS LIMITES MORTELS (Edge Cases) --- */
    if (format == NULL)
        return (-1);

    /* --- 3. INITIALISATION --- */
    va_start(args, format);

    /* --- 4. LA BOUCLE PRINCIPALE --- */
    while (format != NULL && format[i] != '\0')
    {
        if (format[i] == '%')
        {
            /* PIÈGE : % est le tout dernier caractère de la chaîne */
            if (format[i + 1] == '\0')    
			{
				va_end (args);
				return (-1);
			}

            /* On cherche si le caractère SUIVANT correspond à une fonction */
            pfunc = get_print_func(format[i + 1]);

            if (pfunc != NULL)
            {
                count += pfunc(args); /* Appel de pfunc en lui passant args */
				i++;
            }
            else
            {
             	/* CAS : double %% */
                if (format[i + 1] == '%')
                {
                    write(1, "%", 1);
                    count++;
                }
                /* CAS : % inconnu (ex: "%z") */
                else
                {
                    write(1, "%", 1);     /* Imprime le '%' */
                    write(1, &format[i + 1], 1); /* Imprime le char inconnu */
                    count += 2;
                }
                i++; /* On saute le format[i+1] pour ne pas le relire à la boucle suivante */
            }
        }
        else
        {
            /* caractère normal */
            write(1, &format[i], 1);
            count++;
        }
        i++; /* caractère suivant de la chaîne */
    }

    /* --- 5. NETTOYAGE --- */
    va_end (args);

    return (count);
}