# Project: _printf

## Description
This project is a custom implementation of the C standard library function `printf`.

## Supported Format Specifiers

| Specifier | Description | Function File |
| :---: | :--- | :--- |
| **`%c`** | Prints a single character | `print_char.c` |
| **`%s`** | Prints a string of characters | `print_string.c` |
| **`%%`** | Prints a percent sign | `print_percent.c`

## Flowchart
The following diagram describes the logic of the `_printf` function:

```mermaid
graph TD
    Start[Debut _printf] --> Condition{Fin de chaine?}
    Condition -- Oui --> Fin[Retourne le Compteur]
    Condition -- Non --> EstPourcent{Est-ce un % ?}

    EstPourcent -- No --> PrintChar[Ecrire le caractere]
    PrintChar --> Incr1[Compteur + 1]
    Incr1 --> Next1[i + 1]
    Next1 --> Condition

    EstPourcent -- Yes --> CheckNext{Lettre apres % ?}
    CheckNext -- c --> CallC[Appeler print_char]
    CheckNext -- s --> CallS[Appeler print_string]
    CheckNext -- % --> CallP[Ecrire %]
    
    CallC --> Sum[Ajouter au Compteur]
    CallS --> Sum
    CallP --> Sum
    Sum --> Next2[i + 2]
    Next2 --> Condition