//
// Created by oswald on 10/15/23.
//

#include "PileOps.h"

ElementPileOps* creerElementPileOps(int contenu, int estOperateur){
    ElementPileOps* element = (ElementPileOps*) malloc(sizeof(ElementPileOps));
    if(element){
        element->contenu = contenu;
        element->estOperateur = estOperateur;
        element->suivant = NULL;
        return element;
    }
    exit(EXIT_FAILURE);
}

PileOps* creerPileOps(){
    PileOps* pileOps = (PileOps*) malloc(sizeof(PileOps));
    if(pileOps){
        pileOps->tete = NULL;
        return pileOps;
    }
    exit(EXIT_FAILURE);
}

void empilerPileOps(PileOps* pileOps, int contenu, int estOperateur){
    ElementPileOps* elementPileOps = creerElementPileOps(contenu, estOperateur);
    if(pileOps){
        elementPileOps->suivant = pileOps->tete;
        pileOps->tete = elementPileOps;
    }
}

ElementPileOps* depilerPileOps(PileOps* pileOps){
    ElementPileOps* aDepiler = NULL;
    if(pileOps && pileOps->tete){
        aDepiler = pileOps->tete;
        pileOps->tete = aDepiler->suivant;
        aDepiler->suivant = NULL;
    }
    return aDepiler;
}

int taillePileOps(PileOps *pileOps){
    int taille = 0;
    ElementPileOps* curseur = NULL;
    if(pileOps){
        curseur = pileOps->tete;
        while (curseur){
            taille++;
            curseur = curseur->suivant;
        }
    }
    return taille;
}

void supprimerPileOps(PileOps **pileOps){
    ElementPileOps *curseur = NULL;
    if(*pileOps){
        curseur = (*pileOps)->tete;
        while (curseur){
            curseur = curseur->suivant;
            free(depilerPileOps(*pileOps));
        }
        free(*pileOps);
    }
}
