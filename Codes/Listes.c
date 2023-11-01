#include "Listes.h"

Element* creerElement(int valeur) {
    Element* elt = (Element*) malloc(sizeof(Element));
    if (elt != NULL) {
        elt->nombre = valeur;
        elt->suivant = NULL;
        return elt;
    }
    exit(0);
}

int rechercher(Element* liste, int valeur) {
    Element* curseur = liste;
    while (curseur) {
        if (curseur->nombre == valeur) return 1;
        curseur = curseur->suivant;
    }
    return 0;
}

Element* insererDebut(Element* liste, int valeur) {
    Element* elt = creerElement(valeur);
    elt->suivant = liste;
    return elt;
}

void insererEntre(Element* p, int valeur) {
    Element* elt = creerElement(valeur);
    elt->suivant = p->suivant;
    p->suivant = elt;
}

Element* insertionCroissante(Element* liste, int valeur) {
    Element* curseur = liste;

    if(rechercher(liste, valeur) == 1) return liste;

    if (curseur) {
        if (curseur->nombre > valeur) return insererDebut(liste, valeur);

        while (curseur->suivant) {
            if (curseur->suivant->nombre > valeur) {
                insererEntre(curseur, valeur);
                return liste;
            }
            curseur = curseur->suivant;
        }
        insererEntre(curseur, valeur);
        return liste;
    }
    return insererDebut(liste, valeur);
}

void afficher(Element* liste) {
    if (liste) {
        Element* curseur = liste;
        while (curseur != NULL){
            printf("%d --> ", curseur->nombre);
            curseur = curseur->suivant;
        }
        printf("NULL\n");
        return;
    }
    printf("VIDE!!! \n");
}

Element* supprimerElement(Element* liste, int valeur) {

    Element* curseur;

    if (liste) {
        curseur = liste;
        // debut
        if (curseur->nombre == valeur) {
            curseur = curseur->suivant;
            free(liste);
            return curseur;
        }

        while (curseur->suivant){
            if (curseur->suivant->nombre == valeur) {
                Element* aSupprimer = curseur->suivant;
                curseur->suivant = aSupprimer->suivant;
                free(aSupprimer);
                return liste;
            }
            else curseur = curseur->suivant;
        }
    }
    return liste;
}

int tailleListe(Element* liste) {
    Element* curseur = liste;
    int taille = 0;
    while (curseur) {
        taille++;
        curseur = curseur->suivant;
    }
    return taille;
}


