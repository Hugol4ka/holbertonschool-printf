#include "main.h"
#include <unistd.h> /* Très important pour pouvoir utiliser write() ! */

/**
 * print_char - Extrait un caractère de la liste et l'imprime.
 * @args: La liste variadique d'arguments (va_list).
 *
 * Return: Le nombre de caractères imprimés (toujours 1 pour un char).
 */
int print_char(va_list args)
{
    /* 1. DECLARATION */
    char c; /* Variable pour stocker notre caractère */

    /* * INDICE 1 - L'EXTRACTION : 
     * Utilise la macro va_arg(liste, type) pour sortir l'argument.
     * ⚠️ PIÈGE MORTEL EN C (Corner Case) ⚠️ : 
     * Quand un 'char' est passé dans les points de suspension (...), 
     * le compilateur C le "promeut" (le transforme) automatiquement en 'int'. 
     * Donc, quand tu le sors avec va_arg, tu dois demander un 'int', 
     * même si tu le stockes dans un 'char' !
     */
    c = va_arg(args, /* À TOI DE METTRE LE BON TYPE ICI */);

    /* * INDICE 2 - L'AFFICHAGE :
     * La fonction write(int fd, const void *buf, size_t count).
     * - fd = 1 (Sortie standard / écran)
     * - buf = L'ADRESSE de ce que tu veux imprimer (utilise le &)
     * - count = Combien d'octets/caractères ?
     */
    write(1, /* À TOI DE COMPLÉTER LES PARAMÈTRES */);

    /* * INDICE 3 - LE RETOUR :
     * Ton _printf a besoin de savoir combien de caractères ont été imprimés
     * pour tenir son score final (cpt). Un %c imprime combien de caractères ?
     */
    return (/* À TOI DE METTRE LE BON CHIFFRE */);
}