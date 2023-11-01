//
// Created by oswald on 29/10/23.
//

#include "file.h"


Client *creerElement(int id, float tempsArrive, float dureeTraitement) {
    Client *elt = (Client *) malloc(sizeof(Client));
    if (elt != NULL) {
        elt->id = id;
        elt->tempsArrive = tempsArrive;
        elt->dureeTraitement = dureeTraitement;
        elt->suivant = NULL;
        return elt;
    }
    exit(0);
}

File *creerFile() {
    File *file = (File *) malloc(sizeof(file));

    if (file) {
        file->tete = NULL;
        file->queue = NULL;
        return file;
    }
    exit(0);
}

void enfiler(File *file, int id, float tempsArrive, float dureeTraitement) {
    Client *elt = creerElement(id, tempsArrive, dureeTraitement);

    if (file) {
        if (file->tete == NULL) {
            file->tete = elt;
            file->queue = elt;
        } else {
            file->queue->suivant = elt;
            file->queue = elt;
        }
    }
}

void defiler(File *file) {
    Client *aDefiler;

    if (file && file->tete) {
        if (file->tete == file->queue) {
            aDefiler = file->tete;
            file->tete = NULL;
            file->queue = NULL;
            free(aDefiler);
        } else {
            aDefiler = file->tete;
            file->tete = aDefiler->suivant;
            free(aDefiler);
        }
    }
}

void supprimerFile(File **file){
    while ((*file)->tete != NULL) defiler(*file);
    free(file);
}