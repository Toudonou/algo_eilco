//
// Created by oswald on 13/01/24.
//

#include "graphe.h"

Graphe *graphe1(int taille);

Graphe *graphe2(int taille);

Graphe *graphe3(int taille);

int main() {
    const int taille = 9;
    Graphe *graphe = NULL;

    graphe = graphe1(taille);
    printf("Parcour en largeur du graphe 1: ");
    parcoursLargeur(graphe, 'a');
    supprimerGraphe(graphe);


    graphe = graphe2(8);
    printf("Parcour en profondeur du graphe 2: ");
    parcoursProfondeur(graphe, 'a');
    supprimerGraphe(graphe);

    graphe = graphe3(5);
    printf("Dijkstra du graphe 3: ");
    //dijkstra(graphe, 'a');
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

Graphe *graphe2(const int taille) {
    Graphe *graphe = creerGraphe(taille);

    for (int i = 0; i < taille; i++) {
        ajoutSommet(graphe, (char) ('a' + i));
    }

    ajoutArc(graphe, 'a', 'g', 1);
    ajoutArc(graphe, 'a', 'b', 1);

    ajoutArc(graphe, 'b', 'f', 1);
    ajoutArc(graphe, 'b', 'e', 1);
    ajoutArc(graphe, 'b', 'c', 1);

    ajoutArc(graphe, 'c', 'e', 1);
    ajoutArc(graphe, 'c', 'd', 1);

    ajoutArc(graphe, 'd', 'c', 1);

    ajoutArc(graphe, 'e', 'h', 1);
    ajoutArc(graphe, 'e', 'd', 1);
    ajoutArc(graphe, 'e', 'b', 1);

    ajoutArc(graphe, 'f', 'h', 1);
    ajoutArc(graphe, 'f', 'a', 1);

    ajoutArc(graphe, 'g', 'f', 1);

    ajoutArc(graphe, 'h', 'e', 1);
    return graphe;
}

Graphe *graphe3(const int taille) {
    Graphe *graphe = creerGraphe(taille);

    for (int i = 0; i < taille; i++) {
        ajoutSommet(graphe, (char) ('a' + i));
    }

    ajoutArc(graphe, 'a', 'e', 5);
    ajoutArc(graphe, 'a', 'b', 3);

    ajoutArc(graphe, 'b', 'e', 1);
    ajoutArc(graphe, 'b', 'c', 6);

    ajoutArc(graphe, 'c', 'd', 2);

    ajoutArc(graphe, 'd', 'c', 7);
    ajoutArc(graphe, 'd', 'a', 3);

    ajoutArc(graphe, 'e', 'd', 6);
    ajoutArc(graphe, 'e', 'c', 3);
    ajoutArc(graphe, 'e', 'b', 1);

    return graphe;
}
