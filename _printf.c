#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produit une sortie selon un format.
 * @format: Chaîne de caractères contenant le texte et les directives.
 * * Return: Le nombre total de caractères imprimés.
 */
int _printf(const char *format, ...)
{
    /* --- 1. DECLARATIONS --- */
    va_list bag; /* liste pour stocker les arguments (...) */
    int cpt = 0; /* compteur pour le retour final */
    int idx = 0; /* index pour parcourir la chaîne 'textInitial' */

    /* --- 2. INITIALISATION --- */
    if (format == NULL)
	return (-1); /* Sécurité */

	va_start (bag, format);

    /* --- 3. LA BOUCLE PRINCIPALE --- */
    while (format[idx] != '\0')
    {
        if (format[idx + 1] == '%') /* On regarde le suivant sans bouger idx */
    	{
        	write(1, &format[idx + 1], 1); /* On affiche le DEUXIÈME % */
        	cpt++;
        	idx++; /* On "saute" le deuxième % pour que la boucle ne le traite pas au prochain tour */
    	}
        /* CAS B : On a trouvé un '%' */
        /* -> Regarde le caractère juste après (format[i + 1]) */
        
        /* SOUS-CAS B.1 : C'est un 'c' */
        /* -> Appelle une fonction qui gère les caractères (Hugo s'en occupe) */
        
        /* SOUS-CAS B.2 : C'est un 's' */
        /* -> Appelle une fonction qui gère les strings (Hugo s'en occupe) */

        /* SOUS-CAS B.3 : C'est un autre '%' */
        /* -> Imprime simplement le caractère '%' avec write */

        /* SOUS-CAS B.4 : C'est fini ou inconnu ? */
        /* -> Gère les erreurs ou avance l'index */
    }

    /* --- 4. NETTOYAGE --- */
    /* INDICE : N'oublie jamais de fermer ta liste avec va_end */

    /* --- 5. RETOUR --- */
    /* INDICE : Renvoie le nombre total de caractères affichés */
}