#include <stdio.h>

#define TAILLE 100

void rechercherRemplacer(char *chaine, char c, char r){
    for (int i = 0; i < TAILLE; i++) {
        if(chaine[i] == c) chaine[i] = r;
    }
}

void majusculeMot(char *chaine){
    if('a' <= chaine[0] && chaine[0] <= 'z')
        chaine[0] -= 32;
    for (int i = 1; i < TAILLE; i++) {
        if(chaine[i - 1] == ' ' && 'a' <= chaine[i] && chaine[i] <= 'z'){
            chaine[i] -= 32;
        } 
    }
}

int main(int argc, char *argv[]){
    char chaine[TAILLE], c, r;

    printf("Entrer une chaîne de caractères(moins de %d caractères) : ", TAILLE);
    fgets(chaine, TAILLE, stdin);

    printf("Entrer le caractère à remplacer : ");
    scanf("%c", &c);
    getchar();

    printf("Entrer le caractère de remplacement : ");
    scanf("%c", &r);

    rechercherRemplacer(chaine, c, r);
    printf("Résultat : %s\n", chaine);

    majusculeMot(chaine); 
    printf("Résultat : %s\n", chaine);

    return 0;
}

