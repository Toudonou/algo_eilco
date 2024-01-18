//
// Created by oswald on 17/01/24.
//

#include "file.h"

File *creerFile() {
    File *file = (File *) calloc(1, sizeof(File));
    if (!file) {
        fprintf(stderr, "Error during queue allocation\n");
        exit(EXIT_FAILURE);
    }
    file->taille = 0;
    file->tete = NULL;
    file->queue = NULL;
    return file;
}

void enfiler(File *file, NodeList *node) {
    if (file && node) {
        node->suivant = NULL;
        if (file->taille == 0) {
            file->tete = node;
            file->queue = node;
        } else {
            file->queue->suivant = node;
            file->queue = node;
        }
        file->taille++;
    }
}

NodeList *defiler(File *file) {
    NodeList *aDepiler = NULL;
    if (file && file->taille) {
        file->taille--;
        aDepiler = file->tete;
        file->tete = file->tete->suivant;
        if (file->taille == 0) {
            file->queue = NULL;
        }
    }
    return aDepiler;
}

void supprimerFile(File *file){
    if(file){
        while (file->taille){
            supprimerNodeList(defiler(file));
        }
        free(file);
    }
}