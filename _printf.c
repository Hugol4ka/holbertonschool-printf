#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h> /* Pour NULL */

/**
 * _printf - Produit une sortie selon un format.
 * @format: Chaîne de caractères contenant le texte et les directives.
 *
 * Return: Le nombre total de caractères imprimés, ou -1 en cas d'erreur.
 */
int _printf(const char *format, ...)
{
    /* --- 1. DECLARATIONS (Betty t'oblige à tout mettre ici) --- */
    va_list args;
    int count = 0; /* Ton score final */
    int i = 0;     /* Ton index pour parcourir 'format' */
    int (*pfunc)(va_list); /* Le pointeur pour stocker la fonction trouvée */

    /* --- 2. CAS LIMITES MORTELS (Edge Cases) --- */
    /* Que se passe-t-il si format est totalement NULL ? */
    if (/* À TOI DE JOUER : Condition si format n'existe pas */)
        return (-1);

    /* --- 3. INITIALISATION --- */
    /* Ouvre la valise d'arguments variadiques */
    /* À TOI DE JOUER : Utilise va_start */

    /* --- 4. LA BOUCLE PRINCIPALE --- */
    while (format != NULL && format[i] != '\0')
    {
        if (format[i] == '%')
        {
            /* ☠️ PIÈGE : Et si le % est le tout dernier caractère de la chaîne ? (ex: "Coucou %") */
            if (format[i + 1] == '\0')
                return (-1); /* Comportement standard de printf : erreur */

            /* On cherche si le caractère SUIVANT correspond à une fonction */
            pfunc = get_print_func(format[i + 1]);

            if (pfunc != NULL)
            {
                /* BINGO ! L'aiguilleur a trouvé la fonction ('c' ou 's') */
                /* À TOI DE JOUER :
                 * 1. Appelle pfunc en lui passant 'args'
                 * 2. Ajoute son résultat à 'count'
                 * 3. Avance 'i' de 1 pour "sauter" le spécificateur (ex: le 's')
                 */
                 
                 
                 
            }
            else
            {
                /* CAS : % inconnu (ex: "%z") ou double %% */
                /* On affiche le '%' puis le caractère inconnu */
                /* À TOI DE JOUER : Imprime le '%' et le format[i+1], puis met à jour 'count' et 'i' */
                
                
                
            }
        }
        else
        {
            /* C'est un caractère normal (ex: le 'H' de "Hello") */
            write(1, &format[i], 1);
            count++;
        }
        i++; /* On passe au caractère suivant de la chaîne */
    }

    /* --- 5. NETTOYAGE --- */
    /* Ferme la valise ! */
    /* À TOI DE JOUER : Utilise va_end */

    return (count);
}