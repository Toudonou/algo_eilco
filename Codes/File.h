#ifndef FILES_H
#define FILES_H

#include "Listes.h"

typedef struct File {
    Element* tete;
    Element* queue;
}File;


File* creerFile();

void enfiler(File* file, int nombre);

void defiler(File* file, int* resultat);

#endif // FILES_H
