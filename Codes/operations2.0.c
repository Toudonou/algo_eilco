//
// Created by oswald on 10/15/23.
//

#include "operations2.0.h"

int caracteresEntier(const char *chaine, int taille) {
    int resulatat = 0;
    for (int i = 0; i < taille; i++) resulatat += (chaine[i] - '0') * (int) pow(10, taille - i - 1);
    return resulatat;
}

ElementPileOps *elementIndicePileOps(PileOps *pileOps, int indice) {
    ElementPileOps *curseur = NULL;
    if (pileOps) {
        curseur = pileOps->tete;
        while (curseur) {
            if (indice == 0) return curseur;
            curseur = curseur->suivant;
            indice--;
        }
    }
    return NULL;
}

void echangePileOps(ElementPileOps *element1, ElementPileOps *element2) {
    ElementPileOps stock1 = *element1, stock2 = *element2;
    element1->contenu = stock2.contenu;
    element1->estOperateur = stock2.estOperateur;

    element2->contenu = stock1.contenu;
    element2->estOperateur = stock1.estOperateur;
}

PileOps *chainePileOps(char *chaine) {
    PileOps *pileOps = creerPileOps();
    char tmp[50]; // 10145+3+2
    for (int i = 0, j = 0; i <= strlen(chaine); i++) {
        if (i < strlen(chaine) && chaine[i] != '+' && chaine[i] != '*' && chaine[i] != '-' && chaine[i] != '/') {
            tmp[j] = chaine[i];
            tmp[++j] = '\0';
        } else if (i == strlen(chaine)) {
            empilerPileOps(pileOps, caracteresEntier(tmp, (int) strlen(tmp)), 0);
        } else {
            empilerPileOps(pileOps, caracteresEntier(tmp, (int) strlen(tmp)), 0);
            empilerPileOps(pileOps, chaine[i], 1);
            j = 0;
        }
    }
    return pileOps;
}

void inversePileOps(PileOps *pileOps) {
    int taille = taillePileOps(pileOps);
    if (pileOps) {
        for (int i = 0; i < taille / 2; i++) {
            if (elementIndicePileOps(pileOps, i) && elementIndicePileOps(pileOps, taille - i - 1)) {
                echangePileOps(elementIndicePileOps(pileOps, i), elementIndicePileOps(pileOps, taille - i - 1));
            }
        }
    }
}

void ecriturePostfixePileOps(PileOps *pileOps) {
    if (pileOps && !pileOps->tete) return;

    ElementPileOps stock;
    int taille = taillePileOps(pileOps);

    // Postfixé * && /
    for (int i = 0; i < taille;) {
        stock = *elementIndicePileOps(pileOps, i);
        if (stock.estOperateur) {
            if (stock.contenu == '*' || stock.contenu == '/') {
                echangePileOps(elementIndicePileOps(pileOps, i), elementIndicePileOps(pileOps, i + 1));
                i += 2;
            } else i++;
        } else i++;
    }

    // Postfixé + && -
    for (int i = 0, j; i < taille;) {
        stock = *elementIndicePileOps(pileOps, i);
        if (stock.estOperateur) {
            if (stock.contenu == '+' || stock.contenu == '-') {
                j = i;
                while (j < taille - 1) {
                    elementIndicePileOps(pileOps, j)->contenu = elementIndicePileOps(pileOps, j + 1)->contenu;
                    elementIndicePileOps(pileOps, j)->estOperateur = elementIndicePileOps(pileOps, j + 1)->estOperateur;
                    j++;
                    if (elementIndicePileOps(pileOps, j)->estOperateur &&
                        (elementIndicePileOps(pileOps, j)->contenu == '+' ||
                         elementIndicePileOps(pileOps, j)->contenu == '-'))
                        break;
                }

                if (j == taille - 1) {
                    elementIndicePileOps(pileOps, j)->contenu = stock.contenu;
                    elementIndicePileOps(pileOps, j)->estOperateur = stock.estOperateur;
                    i = ++j;
                } else {
                    elementIndicePileOps(pileOps, j - 1)->contenu = stock.contenu;
                    elementIndicePileOps(pileOps, j - 1)->estOperateur = stock.estOperateur;
                    i = j;
                }
            } else i++;
        } else i++;
    }
}

int operationPostfixePileOps(char *chaine) {
    PileOps *pileOps = NULL, *pileCalcul = creerPileOps();
    ElementPileOps *a = NULL, *b = NULL, *stock = NULL;
    int taille, resultat;

    pileOps = chainePileOps(chaine);
    inversePileOps(pileOps);
    ecriturePostfixePileOps(pileOps);
    taille = taillePileOps(pileOps);

    for (int i = 0; i < taille; i++) {
        stock = depilerPileOps(pileOps);
        if (!stock->estOperateur) {
            empilerPileOps(pileCalcul, stock->contenu, stock->estOperateur);
        } else {
            b = depilerPileOps(pileCalcul);
            a = depilerPileOps(pileCalcul);

            if (stock->contenu == '+') empilerPileOps(pileCalcul, a->contenu + b->contenu, 0);
            else if (stock->contenu == '-') empilerPileOps(pileCalcul, a->contenu - b->contenu, 0);
            else if (stock->contenu == '*') empilerPileOps(pileCalcul, a->contenu * b->contenu, 0);
            else if (stock->contenu == '/') empilerPileOps(pileCalcul, a->contenu / b->contenu, 0);
        }
    }


    resultat = depilerPileOps(pileCalcul)->contenu;
    supprimerPileOps(&pileOps);
    supprimerPileOps(&pileCalcul);
    return resultat;
}
