#include "main.h"

/**
 * _printf - Produit une sortie selon un format.
 * @format: Chaîne de caractères contenant le texte et les directives.
 * * Return: Le nombre total de caractères imprimés.
 */
int _printf(const char *textInitial, ...)
{
    /* --- 1. DECLARATIONS --- */
    va_list bag; /* liste pour stocker les arguments (...) */
    int cpt = 0; /* compteur pour le retour final */
    int idx = 0; /* index pour parcourir la chaîne 'textInitial' */

    /* --- 2. INITIALISATION --- */
    if (textInitial == NULL)
	return (-1); /* Sécurité */

	va_start (bag, textInitial);

    /* --- 3. LA BOUCLE PRINCIPALE --- */
    while (textInitial != '\0')
    {
        if (textInitial[idx] != '%')
			write (1, &textInitial[idx], 1);/* -> Imprime le caractère directement avec write */
        	idx++;

        /* CAS B : On a trouvé un '%' */
        /* -> Regarde le caractère juste après (format[i + 1]) */
        
        /* SOUS-CAS B.1 : C'est un 'c' */
        /* -> Appelle une fonction qui gère les caractères (Hugo s'en occupe) */
        
        /* SOUS-CAS B.2 : C'est un 's' */
        /* -> Appelle une fonction qui gère les strings (Hugo s'en occupe) */  int print_string(va_list bag)

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