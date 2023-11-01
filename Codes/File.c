#include "File.h"

File* creerFile() {
    File* file = (File*)malloc(sizeof(file));
    
    if (file) {
        file->tete = NULL;
        file->queue = NULL;
        return file;
    }
    exit(0);
}

void enfiler(File* file, int nombre) {
    Element* elt = creerElement(nombre);
    
    if (file) {
        if (file->tete == NULL) {
            file->tete = elt;
            file->queue = elt;
        }
        else {
            file->queue->suivant = elt;
            file->queue = elt;
        }
    }
}

void defiler(File* file, int* resultat) {
    Element* aDefiler;

    if (file && file->tete) {
        if (file->tete == file->queue) {
            aDefiler = file->tete;
            file->tete = NULL;
            file->queue = NULL;
            *resultat = aDefiler->nombre;
            free(aDefiler);
        }
        else {
            aDefiler = file->tete;
            *resultat = aDefiler->nombre;
            file->tete = aDefiler->suivant;
            free(aDefiler);
        }
    }
}
