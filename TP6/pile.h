//
// Created by oswald on 18/01/24.
//

#ifndef TP6_PILE_H
#define TP6_PILE_H

#include "nodeList.h"

typedef struct {
    NodeList *tete;
    int taille;
} Pile;

Pile *creerPile();

void empiler(Pile *file, NodeList *node);

NodeList *depiler(Pile *file);

void supprimerPile(Pile *file);

#endif //TP6_PILE_H
