#include "table_hachage.h"

int hash(char *mot){
    if(!mot) return 0;
    int size = (char) strlen(mot);
    int cmp = 0;
    for(int i = 0; i < size; i++) cmp += mot[i];
    
    return (int) cmp%size;
}

void initialiserTable(MOT **tableH){
    if(tableH){
        for(int i = 0; i < LONGUEUR_TABLE; i++) tableH[i] = NULL;
    }
}

void insererMot(MOT **tableH, char *mot){
    if(!tableH) return;
    int hash_mot = hash(mot);
    
    MOT* element = malloc(sizeof(MOT));
    if(!element){
        printf("Erreur lors de l'allocation\n");
        exit(EXIT_FAILURE);
    }
    strcpy(element->texte, mot);
    element->suivant = tableH[hash_mot];
    tableH[hash_mot] = element;

}

int existMot(MOT **tableH, char *mot){
    if(!tableH) return 0;

    int hash_mot = hash(mot);
    if(!tableH[hash_mot]) return 0;
    else{
        MOT* curseur = tableH[hash_mot];
        while (curseur){
            if(!strcmp(curseur->texte, mot)) return 1;
            curseur = curseur->suivant;
        }
    }
    return 0;
}

void insererFichier(MOT **tableH, char *nomFichier){
    FILE *f;
    char s[30];
    f = fopen(nomFichier, "r");
    while (fscanf(f, "%s", s) != EOF){
        insererMot(tableH, s);
    }
    fclose(f);
}

void afficher(MOT **tableH){
    int i = 0;

    for (i = 0; i < LONGUEUR_TABLE; i++){
        if (tableH[i]){
            MOT *liste = tableH[i];
            printf("\n");
            while (liste){
                printf("%s --> ", liste->texte);
                liste = liste->suivant;
            }
            printf("NULL");
        }
        else printf("\nNULL");
    }
}
