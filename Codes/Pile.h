#ifndef PILES_H
#define PILES_H

#include "Listes.h"

typedef struct Pile {
    Element* tete;
}Pile;

Pile* creerPile();

void empiler(Pile* Pile, int nombre);
void depiler(Pile* Pile, int* resultat);

#endif // PILES_H
