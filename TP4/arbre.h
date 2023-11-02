//
// Create by oswald at 01/09/23
//

#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arbre{
	int cle;
	struct arbre *gauche;
	struct arbre *droit;
} Arbre;

Arbre *creerNoeud(int cle);

Arbre *insertion(Arbre *arbre, int cle);

void afficheArbre(Arbre *arbre);

void parcours(Arbre *arbre, int type);

int minArbre(Arbre *arbre);

int maxArbre(Arbre *arbre);

Arbre *recherche(Arbre *arbre, int cle);

Arbre *trouvePere(Arbre *racine, Arbre *arbre, int cle);

void suppression(Arbre **racine, int cle);

void suppressionFeuille(Arbre **racine, int cle);

void suppressionUnFils(Arbre **racine, int cle);

void suppressionDeuxFils(Arbre **racine, int cle);

int taille(Arbre *arbre);

int hauteur(Arbre *arbre);

int nbrFeuilles(Arbre *arbre);

#endif
