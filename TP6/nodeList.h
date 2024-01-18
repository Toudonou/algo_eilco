//
// Created by oswald on 17/01/24.
//

#ifndef TP6_NODELIST_H
#define TP6_NODELIST_H

#include "graphe.h"

typedef struct nodeList {
    Sommet *element;
    struct nodeList *suivant;
} NodeList;

NodeList *creerNodeList(Sommet *element);

void printNodeList(NodeList *node);

void supprimerNodeList(NodeList *node);

#endif //TP6_NODELIST_H
