//
// Created by oswald on 13/01/24.
//

#include "graphe.h"

Graphe *graphe1(int taille);

int main() {
    const int taille = 9;
    Graphe *graphe = graphe1(taille);


    parcoursLargeur(graphe, 'a');

    supprimerGraphe(graphe);
    return 0;
}

Graphe *graphe1(const int taille) {
    Graphe *graphe = creerGraphe(taille);

    for (int i = 0; i < taille; i++) {
        ajoutSommet(graphe, (char) ('a' + i));
    }

    ajoutArc(graphe, 'a', 'g', 1);
    ajoutArc(graphe, 'a', 'b', 1);

    ajoutArc(graphe, 'b', 'g', 1);
    ajoutArc(graphe, 'b', 'e', 1);
    ajoutArc(graphe, 'b', 'c', 1);
    ajoutArc(graphe, 'b', 'a', 1);

    ajoutArc(graphe, 'c', 'f', 1);
    ajoutArc(graphe, 'c', 'd', 1);
    ajoutArc(graphe, 'c', 'b', 1);

    ajoutArc(graphe, 'd', 'c', 1);

    ajoutArc(graphe, 'e', 'h', 1);
    ajoutArc(graphe, 'e', 'f', 1);
    ajoutArc(graphe, 'e', 'b', 1);

    ajoutArc(graphe, 'f', 'i', 1);
    ajoutArc(graphe, 'f', 'e', 1);
    ajoutArc(graphe, 'f', 'c', 1);

    ajoutArc(graphe, 'g', 'h', 1);
    ajoutArc(graphe, 'g', 'b', 1);
    ajoutArc(graphe, 'g', 'a', 1);

    ajoutArc(graphe, 'h', 'i', 1);
    ajoutArc(graphe, 'h', 'e', 1);
    ajoutArc(graphe, 'h', 'g', 1);

    ajoutArc(graphe, 'i', 'h', 1);
    ajoutArc(graphe, 'i', 'f', 1);

    return graphe;
}
