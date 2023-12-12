#include "table_hachage.h"

int main(){
    MOT **tableH = malloc(sizeof(MOT*) * LONGUEUR_TABLE);
    initialiserTable(tableH);
    insererFichier(tableH, "dictionnaire.txt");
    afficher(tableH);

    printf("\n%d", existMot(tableH, "sfvbksjfbvk"));
    printf("\n%d", existMot(tableH, "ijk"));
    printf("\n%d", existMot(tableH, "aabcd"));
}

/*int main(){
    int tab[6] = {40, 10, 30, 20, 50, -70};
    triParTas(tab, 6);

    for(int i = 0; i < 6; i++) printf("%d ", tab[i]);

    return 0;
}*/