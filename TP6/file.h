//
// Created by oswald on 17/01/24.
//

#ifndef TP6_FILE_H
#define TP6_FILE_H

#include "nodeList.h"

typedef struct {
    NodeList *tete;
    NodeList *queue;
    int taille;
} File;

File *creerFile();

void enfiler(File *file, NodeList *node);

NodeList *defiler(File *file);

void supprimerFile(File *file);

#endif //TP6_FILE_H
