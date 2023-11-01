//
// Created by oswald on 29/10/23.
//

#include "pile.h"


Element *creerElement(float valeur) {
    Element *elt = (Element *) malloc(sizeof(Element));
    if (elt != NULL) {
        elt->nombre = valeur;
        elt->suivant = NULL;
        return elt;
    }
    exit(0);
}

void afficher(Element *liste) {
    if (liste) {
        Element *curseur = liste;
        while (curseur != NULL) {
            printf("%f --> ", curseur->nombre);
            curseur = curseur->suivant;
        }
        printf("NULL\n");
        return;
    }
    printf("VIDE!!! \n");
}

Pile *creerPile() {
    Pile *pile = (Pile *) malloc(sizeof(pile));

    if (pile) {
        pile->tete = NULL;
        return pile;
    }
    exit(EXIT_FAILURE);
}

void empiler(Pile *pile, float nombre) {
    Element *elt = creerElement(nombre);

    if (pile) {
        if (pile->tete == NULL) {
            pile->tete = elt;
        } else {
            elt->suivant = pile->tete;
            pile->tete = elt;
        }
    }
}

void depiler(Pile *pile, float *resultat) {
    Element *aDepiler;

    if (pile && pile->tete) {
        aDepiler = pile->tete;
        if (resultat)
            *resultat = aDepiler->nombre;
        pile->tete = aDepiler->suivant;
        free(aDepiler);
    }
}

void supprimerPile(Pile **pile) {
    while ((*pile)->tete){
        depiler(*pile, NULL);
    }
    free(*pile);
}
