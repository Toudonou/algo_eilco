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
	if(arbre) return 1 + taille(arbre->gauche) + taille(arbre->droit);
	return 0;
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
	if(!arbre) return 0;
	if(arbre){
		if(!arbre->gauche && !arbre->droit) return 1;
		return nbrFeuilles(arbre->gauche) + nbrFeuilles(arbre->droit); 
	}
}


Arbre *recherche(Arbre *arbre, int cle){
	if(arbre){
		if(arbre->cle == cle) return arbre;
		else if (cle < arbre->cle) return recherche(arbre->gauche, cle);
		else if (arbre->cle < cle) return recherche(arbre->droit, cle);
	}
	return NULL;
}


Arbre* suppression(Arbre *racine, int cle){
	if(racine == NULL) return racine;
	if(racine->cle == cle){
		if(racine->gauche == NULL){
			Arbre *filsDroit = racine->droit;
			free(racine);
			return filsDroit;
		}
		if(racine->droit == NULL){
			Arbre *filsGauche = racine->gauche;
			free(racine);
			return filsGauche;
		}

		Arbre* s = recherche(racine->droit, minArbre(racine->droit));
		
		racine->cle = s->cle;
		racine->droit = suppression(racine->droit, s->cle);
	}
	if(cle < racine->cle) racine->gauche = suppression(racine->gauche, cle);
	else racine->droit = suppression(racine->droit, cle);
	return racine;
}
