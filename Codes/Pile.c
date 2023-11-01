#include "Pile.h"

Pile *creerPile() {
    Pile *pile = (Pile *) malloc(sizeof(pile));

    if (pile) {
        pile->tete = NULL;
        return pile;
    }
    exit(EXIT_FAILURE);
}

void empiler(Pile *pile, int nombre) {
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

void depiler(Pile *pile, int *resultat) {
    Element *aDepiler;

    if (pile && pile->tete) {
        aDepiler = pile->tete;
        if (resultat)
	        *resultat = aDepiler->nombre;
        pile->tete = aDepiler->suivant;
        free(aDepiler);
    }
}
