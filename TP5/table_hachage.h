#ifndef TABLE_HACHAGE_H
#define TABLE_HACHAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LONGUEUR_TABLE 10 // longueur de la table de hachage

typedef struct mot{
    char texte[30];
    struct mot *  suivant;
}MOT;



void insererFichier(MOT **tableH,  char *nomFichier);
void initialiserTable(MOT **tableH);
void insererMot(MOT **tableH , char * mot);
int existMot(MOT **tableH , char * mot);
int hash(char * mot);
void afficher(MOT **tableH);

#endif 
