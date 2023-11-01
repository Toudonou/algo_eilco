//
// Created by oswald on 10/15/23.
//

#include "operations1.0.h"
#include "string.h"

int caractereEntier(char caractere) {
    return caractere - '0';
}

int estOperateur(char caractere) {
    return caractere == '+' || caractere == '*' || caractere == '/' || caractere == '-' ? 1 : 0;
}

void ecriturePostfixe(char *chaine) {
    // Postfixé opérateur * && /
    for (int i = 0; i < strlen(chaine);) {
        if (chaine[i] == '*' || chaine[i] == '/') {
            char a = chaine[i + 1], b = chaine[i];
            chaine[i] = a;
            chaine[i + 1] = b;
            i += 2;
        } else i++;
    }

    // Postfixé opérateur + && -
    for (int i = 0, j; i < strlen(chaine);) {
        if (chaine[i] == '+' || chaine[i] == '-') {
            char b = chaine[i];
            j = i;
            while (j < strlen(chaine) - 1) {
                chaine[j] = chaine[j + 1];
                j++;
                if (chaine[j] == '+' || chaine[j] == '-') break;
            }
            if (j == strlen(chaine) - 1) {
                chaine[j] = b;
                i = ++j;
            } else {
                chaine[j - 1] = b;
                i = j;
            }
        } else i++;
    }
}

int operationPostfixe(char *chaine) {
    Pile *pile = creerPile();
    int a, b;
    ecriturePostfixe(chaine);

    for (int i = 0; i < strlen(chaine); i++) {
        if (!estOperateur(chaine[i])) {
            empiler(pile, caractereEntier(chaine[i]));
        } else {
            depiler(pile, &b);
            depiler(pile, &a);

            if (chaine[i] == '+') empiler(pile, a + b);
            else if (chaine[i] == '*') empiler(pile, a * b);
            else if (chaine[i] == '-') empiler(pile, a - b);
            else if (chaine[i] == '/') empiler(pile, a / b);
        }
    }

    depiler(pile, &a);
    return a;
}
