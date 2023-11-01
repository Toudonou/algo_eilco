//
// Created by oswald on 10/15/23.
//

#ifndef CODES_PILEOPS_H
#define CODES_PILEOPS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ElementPileOps {
    int contenu;
    int estOperateur;
    struct ElementPileOps *suivant;
} ElementPileOps;

typedef struct PileOps {
    ElementPileOps *tete;
} PileOps;

ElementPileOps *creerElementPileOps(int contenu, int estOperateur);

PileOps *creerPileOps();

void empilerPileOps(PileOps *pileOps, int contenu, int estOperateur);

ElementPileOps *depilerPileOps(PileOps *pileOps);

int taillePileOps(PileOps *pileOps);

void supprimerPileOps(PileOps **pileOps);

#endif //CODES_PILEOPS_H
