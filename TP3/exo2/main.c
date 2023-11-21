#include "file.h"

int main() {
    float tempsMoyen = 0;
    int taille = 10;
    File *file = creerFile();
    Client *curseur1 = NULL, *curseur2 = NULL;

    srand(time(NULL));
    for (int i = 0; i < taille; i++) {
        enfiler(file, i + 1, (float) i, (float) (5 + rand() % 6));
    }

    curseur1 = file->tete;
    while (curseur1) {
        printf("Client %d; temps d'arrivée : %.0f; durée de traitement : %.0f;\n", curseur1->id, curseur1->tempsArrive,
               curseur1->dureeTraitement);
        curseur1 = curseur1->suivant;
    }

    curseur1 = file->tete;
    for (int i = 0; i < taille; i++) {
        float dureeTraitementPrecedent = 0;
        curseur2 = file->tete;
        for (int j = 0; j < i && curseur2; j++) {
            dureeTraitementPrecedent += curseur2->dureeTraitement;
            curseur2 = curseur2->suivant;
        }
        tempsMoyen += dureeTraitementPrecedent - curseur1->tempsArrive;
        curseur1 = curseur1->suivant;
    }
    tempsMoyen /= (float) taille;

    printf("Temps d'attente moyen des clients dans cette file : %f", tempsMoyen);
    return 0;
}
