#include "tas.h"

void inserer(int tas[], int *n, int valeur){
    (*n)++;
    tas[*n] = valeur;
    for(int i = *n; i > 1 && tas[i] < tas[i/2]; i = i/2) echanger(tas, i, i/2);
}

void supprimerMinimum(int tas[], int *n){
    tas[1] = tas[*n];
    (*n)--;
    int i = 1, j;
    while(i <= *n/2){
        if((2*i == *n) || (tas[2 * i] < tas[2 * i + 1])) j = 2 * i;
        else j = 2 * i + 1;

        if(tas[i] > tas[j]){
            echanger(tas, i, j);
            i = j;
        }
        else break;
    }
}

void triParTas(int *tab, int n){
    int *tas = malloc(sizeof(int) * (n + 1));
    if(!tas) {
        printf("Erreur lors de l'allocation");
        exit(EXIT_FAILURE);
    }
    int tailleTas = 0;

    for(int i = 0; i < n; i++)
        inserer(tas, &tailleTas, tab[i]);


    for(int i = 0; i < n; i++){
        tab[i] = tas[1];
        supprimerMinimum(tas, &tailleTas);
    }

    free(tas);
}

void echanger(int *tas, int i, int j){
    int stock = tas[i];
    tas[i] = tas[j];
    tas[j] = stock;
}
