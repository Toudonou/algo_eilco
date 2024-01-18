//
// Created by oswald on 18/01/24.
//

#include "pile.h"


Pile *creerPile() {
    Pile *pile = (Pile *) calloc(1, sizeof(Pile));
    if (!pile) {
        fprintf(stderr, "Error during stack allocation\n");
        exit(EXIT_FAILURE);
    }
    pile->taille = 0;
    pile->tete = NULL;
    return pile;
}

void empiler(Pile *pile, NodeList *node) {
    if (pile && node) {
        node->suivant = pile->tete;
        pile->tete = node;
        pile->taille++;
    }
}

NodeList *depiler(Pile *pile) {
    NodeList *aDepiler = NULL;
    if (pile && pile->taille) {
        pile->taille--;
        aDepiler = pile->tete;
        pile->tete = pile->tete->suivant;
    }
    return aDepiler;
}

void supprimerPile(Pile *pile){
    if(pile){
        while (pile->taille){
            supprimerNodeList(depiler(pile));
        }
        free(pile);
    }
}