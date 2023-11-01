#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10


void afficher(int* tab){
    printf("tab = {");
    for (int i = 0; i < TAILLE - 1; i++) {
        printf("%d, ", tab[i]);
    }
    printf("%d}\n", tab[TAILLE - 1]);
}

float calculerMoyenne(int *tab){
    float moy = 0;
    for (int i = 0; i < TAILLE; i++) {
        moy += tab[i];
    }
    return moy / TAILLE;
}

int trouverMin(int *tab){
    int min = tab[0];
    for (int i = 0; i < TAILLE; i++) {
        if(min > tab[i]) min = tab[i];   
    }
    return min;
}

void inverserTableau(int *tab){
    int valeur;
    for (int i = 0; i < TAILLE / 2; i++) {
        valeur = tab[TAILLE - i - 1];
        tab[TAILLE - i - 1] = tab[i];
        tab[i] = valeur;
    }
}

int main(int argc, char *argv[]){
    srand(time(NULL));
    
    int tab[TAILLE];

    for (int i = 0; i < TAILLE; i++) {
        tab[i] = rand()%20;
    }
    
    afficher(tab);
    printf("Moyenne du tableau : %f\n", calculerMoyenne(tab));
    printf("Minimum du tableau : %d\n", trouverMin(tab));
    printf("Inversion du tableau : ");
    inverserTableau(tab);
    afficher(tab);

    return 0;
}
