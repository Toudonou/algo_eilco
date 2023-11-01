//
// Created by oswald on 17/10/23.
//
#include "Listes.h"

int main(){
    int pos, i;
    Client *tab[4], *liste = NULL;
    tab[0] = creerClient(0, 5,2,20);
    tab[1] = creerClient(1, -1,9,5);
    tab[2] = creerClient(2, 1,1,10);
    tab[3] = creerClient(3, 2,2,15);

    for(i = 0; i < 4; i++){
        pos = meilleurePosition(liste, tab[i]);
        liste = insertionClient(liste, tab[i], pos);
        afficher(liste);
        printf("Distance parcourue : %f\n", distanceTotale(liste));
    }

    return 0;
}
