//
// Create by oswald at 01/09/23
//

#include "arbre.h"
#include <stdio.h>

void func(Arbre *arbre){

	printf("\nAffichage : ");
	afficheArbre(arbre);

	printf("\nInfixé : ");
	parcours(arbre, 3);

	printf("\nMin : %d\n", minArbre(arbre));
	printf("Max : %d\n", maxArbre(arbre));

	printf("Taille : ");
	printf("%d\n", taille(arbre));

	printf("Hauteur : ");
	printf("%d\n", hauteur(arbre));

	printf("Nombre de feuilles : ");
	printf("%d\n", nbrFeuilles(arbre));
}

int main(void){
	Arbre *arbre = NULL;

	arbre = insertion(arbre, -90);
	arbre = insertion(arbre, 20);
	arbre = insertion(arbre, 6);
	arbre = insertion(arbre, 31);
	arbre = insertion(arbre, 5);
	arbre = insertion(arbre, 10);
	arbre = insertion(arbre, 25);
	arbre = insertion(arbre, 38);
	arbre = insertion(arbre, 2);
	arbre = insertion(arbre, 9);
	arbre = insertion(arbre, 12);
	arbre = insertion(arbre, 54);
	arbre = insertion(arbre, 7);
	arbre = insertion(arbre, 11);
	arbre = insertion(arbre, 18);

	func(arbre);
	arbre = suppression(arbre, 20);
	func(arbre);

	return 0;
}
