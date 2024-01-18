//
// Created by oswald on 13/01/24.
//

#ifndef TP6_GRAPHE_H
#define TP6_GRAPHE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum couleur {
    BLANC, GRIS, NOIR
}COULEUR;

typedef struct arc Arc;

typedef struct sommet {
    int id;
    char libelle;
    int couleur;
    Arc *arcs;
} Sommet;

struct arc {
    Sommet *sommet;
    struct arc *suivant;
};

typedef struct graphe {
    Sommet **neouds;
    int **cout;
    int nbrSommet;
} Graphe;

Graphe *creerGraphe(int nbrSommet);

void ajoutSommet(Graphe *graphe, char libelle);

void ajoutArc(Graphe *graphe, char libelle1, char libelle2, int cout);

void ajoutArete(Graphe *graphe, char libelle1, char libelle2, int cout);

void parcoursProfondeur(Graphe *graphe, char libelle);

void parcoursLargeur(Graphe *graphe, char libelle);

Sommet *sommetMin(Graphe *graphe, int *d);

void dijkstra(Graphe *graphe, char libelle, int *d, int *pi);

void bellman(Graphe *graphe, char libelle, int *d, int *pi);

void afficherGraphe(Graphe *graphe);

void afficher(int *tab, int n);

void supprimerGraphe(Graphe *graphe);

#endif //TP6_GRAPHE_H
