#ifndef LISTES_H
#define LISTES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int nombre;
    struct element* suivant;
}Element;


Element* creerElement(int valeur);

int rechercher(Element* liste, int valeur);

Element* insererDebut(Element* liste, int valeur);

void insererEntre(Element* p, int valeur);

Element* insertionCroissante(Element* liste, int valeur);

void afficher(Element* liste);

Element* supprimerElement(Element* liste, int valeur);

int tailleListe(Element* liste);

#endif // LISTES_H
