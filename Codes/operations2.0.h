//
// Created by oswald on 10/15/23.
//

#ifndef CODES_OPERATIONS2_0_H
#define CODES_OPERATIONS2_0_H

#include <string.h>
#include <math.h>
#include "PileOps.h"

PileOps *chainePileOps(char *chaine);

void echangePileOps(ElementPileOps *element1, ElementPileOps *element2);

void inversePileOps(PileOps *pileOps);

ElementPileOps *elementIndicePileOps(PileOps *pileOps, int indice);

int caracteresEntier(const char *chaine, int taille);

void ecriturePostfixePileOps(PileOps *pileOps);

int operationPostfixePileOps(char *chaine);

#endif //CODES_OPERATIONS2_0_H
