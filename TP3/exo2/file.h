//
// Created by oswald on 29/10/23.
//

#ifndef EXO2_FILE_H
#define EXO2_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct client {
    int id;
    float tempsArrive;
    float dureeTraitement;
    struct client *suivant;
} Client;

typedef struct File {
    Client *tete;
    Client *queue;
} File;

Client * creerElement(int id, float tempsArrive, float dureeTraitement);

File *creerFile();

void enfiler(File* file, int id, float tempsArrive, float dureeTraitement);

void defiler(File *file);

#endif //EXO2_FILE_H
