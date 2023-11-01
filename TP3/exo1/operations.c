//
// Created by oswald on 29/10/23.
//

#include "operations.h"

float evaluer(char expression[]) {
    Pile *pile = creerPile();
    float a, b;
    for (int i = 0; i < strlen(expression); i++) {
        if ('0' <= expression[i] && expression[i] <= '9') {
            empiler(pile, (float) (expression[i] - '0'));
        } else {
            depiler(pile, &b);
            depiler(pile, &a);
            if (expression[i] == '+') empiler(pile, a + b);
            else if (expression[i] == '-') empiler(pile, a - b);
            else if (expression[i] == '*') empiler(pile, a * b);
            else if (expression[i] == '/') empiler(pile, a / b);
        }
    }
    depiler(pile, &a);
    supprimerPile(&pile);
    return a;
}

char *convertir_infixe_postfixe(char expression[]) {
    char *resultat = calloc(strlen(expression), sizeof(char));
    float c;
    Pile *pile = creerPile();

    for (int i = 0, j = 0; i < strlen(expression); i++) {
        c = expression[i];
        if ('0' <= c && c <= '9') resultat[j++] = (char) c;
        else if (c == '+' || c == '-' || c == '*' || c == '/') empiler(pile, (float) c);
        else if (c == ')') {
            depiler(pile, &c);
            resultat[j++] = (char) c;
        }
    }
    supprimerPile(&pile);
    return resultat;
}

char *convertir_infixe_postfixe_generalisee(char *expression) {
    char *resultat = calloc(strlen(expression), sizeof(char));
    float c;
    int j = 0;
    Pile *pile = creerPile();

    for (int i = 0; i < strlen(expression); i++) {
        c = expression[i];

        if ('0' <= c && c <= '9') resultat[j++] = (char) c;
        else if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/') {
            empiler(pile, c);
        } else if (c == ')') {
            while (pile->tete->nombre == '+' || pile->tete->nombre == '-' || pile->tete->nombre == '*' ||
                   pile->tete->nombre == '/') {
                depiler(pile, &c);
                resultat[j++] = (char) c;
            }
            depiler(pile, NULL);
        }
    }
    while (pile->tete != NULL && (pile->tete->nombre == '+' || pile->tete->nombre == '-' || pile->tete->nombre == '*' ||
                                  pile->tete->nombre == '/')) {
        depiler(pile, &c);
        resultat[j++] = (char) c;
    }
    depiler(pile, NULL);

    return resultat;
}
