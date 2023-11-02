//
// Create by oswald at 01/09/23
//

#include "arbre.h"
#include <stdio.h>

Arbre *creerNoeud(int cle){
	Arbre *neoud = (Arbre *)malloc(sizeof(Arbre));
	
	if(neoud){
		neoud->cle = cle;
		neoud->gauche = NULL;
		neoud->droit = NULL;
		return neoud;
	}
	exit(EXIT_FAILURE);
}


Arbre *insertion(Arbre *arbre, int cle){
	if(cle < 0) return arbre;
	if(arbre){
		if(arbre->cle > cle) arbre->gauche = insertion(arbre->gauche, cle);
		else if(arbre->cle < cle) arbre->droit = insertion(arbre->droit, cle);
		return arbre;

	}
	return creerNoeud(cle);
}


void afficheArbre(Arbre *arbre){
	if(arbre){
		printf("{");
		afficheArbre(arbre->gauche);
		printf(",%d,", arbre->cle);
		afficheArbre(arbre->droit);
		printf("}");
		return;
	}
	printf("_");
}

void parcours(Arbre *arbre, int type){
	if(arbre){

		if(type == 1) printf(" %d ", arbre->cle);
		
		parcours(arbre->gauche, type);
		
		if(type == 3) printf(" %d ", arbre->cle);
		
		parcours(arbre->droit, type);
		
		if(type == 2) printf(" %d ", arbre->cle);
	}
}


int minArbre(Arbre *arbre){
	if(arbre){
		if(arbre->gauche) return minArbre(arbre->gauche);
		return arbre->cle;
	}
	return -1;
}


int maxArbre(Arbre *arbre){
	if(arbre){
		if(arbre->droit) return maxArbre(arbre->droit);
		return arbre->cle;
	}
	return -1;
}


int taille(Arbre *arbre){
	static int nombre = 0;
	if(arbre) nombre++;
	if(arbre && arbre->gauche) taille(arbre->gauche);
	if(arbre && arbre->droit) taille(arbre->droit);
	return nombre;
}


int max(int a, int b){
	return a > b ? a : b;
}

int hauteur(Arbre *arbre){
	if(arbre){
		return 1 + max(hauteur(arbre->gauche), hauteur(arbre->droit));
	}	
	return 0;
}


int nbrFeuilles(Arbre *arbre){
	static int nombre = 0;
	if(arbre && !arbre->gauche && !arbre->droit) nombre++;
	if(arbre && arbre->gauche) nbrFeuilles(arbre->gauche);
	if(arbre && arbre->droit) nbrFeuilles(arbre->droit);
	return nombre;
}


Arbre *recherche(Arbre *arbre, int cle){
	if(arbre){
		if(arbre->cle == cle) return arbre;
		else if (cle < arbre->cle) return recherche(arbre->gauche, cle);
		else if (arbre->cle < cle) return recherche(arbre->droit, cle);
	}
	return NULL;
}


Arbre *trouvePere(Arbre *racine, Arbre *arbre, int cle){
	if(arbre){
		if(racine->cle == cle) return NULL;
		if(arbre->cle > cle && arbre->gauche){
			if(arbre->gauche->cle == cle) return arbre;
			return trouvePere(racine, arbre->gauche, cle);
		}
		else if(arbre->cle < cle && arbre->droit){
			if(arbre->droit->cle == cle) return arbre;
			return trouvePere(racine, arbre->droit, cle);
		}
	}
	return NULL;
}
void suppressionFeuille(Arbre **racine, int cle){
	Arbre *pere = trouvePere(*racine, *racine, cle);
	
}
