//
// Created by oswald on 29/10/23.
//

#ifndef TP3_PILE_H
#define TP3_PILE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    float nombre;
    struct element *suivant;
}Element;

typedef struct {
    Element *tete;
}Pile;


Element *creerElement(float valeur);

void afficher(Element *liste);

Pile *creerPile();

void empiler(Pile *pile, float nombre);

void depiler(Pile *pile, float *resultat);

void supprimerPile(Pile **pile);

#endif //TP3_PILE_H
