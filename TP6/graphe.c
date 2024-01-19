//
// Created by oswald on 13/01/24.
//

#include "graphe.h"
#include "file.h"
#include "pile.h"

Graphe *creerGraphe(int nbrSommet) {
    Graphe *graphe = (Graphe *) malloc(sizeof(Graphe));
    if (!graphe) {
        fprintf(stderr, "Error during creation of the graph\n");
        exit(EXIT_FAILURE);
    }
    graphe->nbrSommet = nbrSommet;
    graphe->neouds = (Sommet **) calloc(nbrSommet, sizeof(Sommet *));
    if (!graphe->neouds) {
        fprintf(stderr, "Error during allocation of edges table\n");
        free(graphe);
        exit(EXIT_FAILURE);
    }
    graphe->cout = (int **) calloc(nbrSommet, sizeof(int *));
    if (!graphe->cout) {
        fprintf(stderr, "Error during allocation of cost matrix\n");
        free(graphe);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < nbrSommet; i++) {
        graphe->cout[i] = (int *) calloc(nbrSommet, sizeof(int));
        if (!graphe->cout[i]) {
            fprintf(stderr, "Error during allocation of cost matrix\n");
            for (int j = 0; j < i; j++) {
                free(graphe->cout[j]);
            }
            free(graphe->cout);
            free(graphe);
            exit(EXIT_FAILURE);
        }
    }
    return graphe;
}

Sommet *creerSommet(char libelle) {
    Sommet *sommet = (Sommet *) malloc(sizeof(Sommet));
    if (!sommet) {
        fprintf(stderr, "Error during nodeList allocation: %c\n", libelle);
        return NULL;
    }

    sommet->id = (int) (libelle - 'a');
    sommet->libelle = libelle;
    sommet->couleur = BLANC;
    sommet->arcs = NULL;
    return sommet;
}

Arc *creerArc(Sommet *sommet) {
    Arc *nouvelArc = (Arc *) calloc(1, sizeof(Arc));
    if (!nouvelArc) {
        fprintf(stderr, "Error during nodeList allocation: %c\n", sommet->libelle);
    } else {
        nouvelArc->sommet = sommet;
        nouvelArc->suivant = NULL;
    }
    return nouvelArc;
}

void ajoutSommet(Graphe *graphe, char libelle) {
    if (graphe) {
        Sommet *sommet = creerSommet(libelle);
        if (!sommet) {
            supprimerGraphe(graphe);
            exit(EXIT_FAILURE);
        }

        if (0 <= sommet->id && sommet->id < graphe->nbrSommet)
            graphe->neouds[sommet->id] = sommet;
        else {
            fprintf(stderr, "Out of bonds : %c", sommet->libelle);
            free(sommet);
            supprimerGraphe(graphe);
            exit(EXIT_FAILURE);
        }
    }
}

void ajoutArc(Graphe *graphe, char libelle1, char libelle2, int cout) {
    if (graphe) {
        if (!(0 <= libelle1 - 'a' && libelle1 - 'a' < graphe->nbrSommet) ||
            !(0 <= libelle2 - 'a' && libelle2 - 'a' < graphe->nbrSommet))
            return;

        int index1 = libelle1 - 'a', index2 = libelle2 - 'a';

        if (graphe->neouds[index1] != NULL) {
            Arc *curseur = graphe->neouds[index1]->arcs;
            Arc *nouvelArc = creerArc(graphe->neouds[index2]);
            if (!nouvelArc) {
                supprimerGraphe(graphe);
                exit(EXIT_FAILURE);
            }

            if (!curseur) {
                graphe->neouds[index1]->arcs = nouvelArc;
            } else {
                nouvelArc->suivant = graphe->neouds[index1]->arcs;
                graphe->neouds[index1]->arcs = nouvelArc;
            }

            graphe->cout[index1][index2] = cout;
        }
    }
}

void ajoutArete(Graphe *graphe, char libelle1, char libelle2, int cout) {
    ajoutArc(graphe, libelle1, libelle2, cout);
    ajoutArc(graphe, libelle2, libelle1, cout);
}

void reinitialiserGraphe(Graphe *graphe) {
    if (graphe) {
        for (int i = 0; i < graphe->nbrSommet; i++) {
            graphe->neouds[i]->couleur = BLANC;
        }
    }
}

void parcoursLargeur(Graphe *graphe, char libelle) {
    if (graphe) {
        if (0 <= (int) (libelle - 'a') && (int) (libelle - 'a') <= graphe->nbrSommet) {
            File *file = creerFile();
            NodeList *current = NULL;
            Arc *curseurArc = NULL;

            reinitialiserGraphe(graphe);
            graphe->neouds[(int) (libelle - 'a')]->couleur = GRIS;
            enfiler(file, creerNodeList(graphe->neouds[(int) (libelle - 'a')]));

            while (file->taille) {
                current = defiler(file);
                curseurArc = current->element->arcs;

                while (curseurArc) {
                    if (curseurArc->sommet->couleur == BLANC) {
                        curseurArc->sommet->couleur = GRIS;
                        enfiler(file, creerNodeList(curseurArc->sommet));
                    }
                    curseurArc = curseurArc->suivant;
                }
                current->element->couleur = NOIR;
                printNodeList(current);
                supprimerNodeList(current);
            }

            supprimerFile(file);
            printf("\n");
            reinitialiserGraphe(graphe);
            return;
        }
        printf("Sommet %c inexistant\n", libelle);
        return;
    }
    printf("Graphe vide\n");
}

void parcoursProfondeur(Graphe *graphe, char libelle) {
    if (graphe) {
        if (0 <= (int) (libelle - 'a') && (int) (libelle - 'a') <= graphe->nbrSommet) {
            Pile *pile = creerPile();
            NodeList *current = NULL;
            Arc *curseurArc = NULL;

            reinitialiserGraphe(graphe);
            graphe->neouds[(int) (libelle - 'a')]->couleur = GRIS;
            empiler(pile, creerNodeList(graphe->neouds[(int) (libelle - 'a')]));

            while (pile->taille) {
                current = pile->tete;
                curseurArc = current->element->arcs;

                if (current->element->couleur != NOIR) {
                    if (curseurArc) {
                        while (curseurArc) {
                            if (curseurArc->sommet->couleur == BLANC) {
                                curseurArc->sommet->couleur = GRIS;
                                empiler(pile, creerNodeList(curseurArc->sommet));
                            }
                            curseurArc = curseurArc->suivant;
                        }
                        current->element->couleur = NOIR;
                    } else {
                        traitement:
                        printNodeList(current);
                        supprimerNodeList(depiler(pile));
                    }
                } else {
                    goto traitement;
                }
            }

            printf("\n");
            supprimerPile(pile);
            reinitialiserGraphe(graphe);

            return;
        }
        printf("Sommet %c inexistant\n", libelle);
        return;
    }
    printf("Graphe vide\n");
}


void dijkstra(Graphe *graphe, char libelle, int *d, int *pi) {

}

void bellman(Graphe *graphe, char libelle, int *d, int *pi);

void afficherGraphe(Graphe *graphe) {
    if (graphe) {
        for (int i = 0; i < graphe->nbrSommet; i++) {
            printf("%c -> ", graphe->neouds[i]->libelle);
            Arc *curseur = graphe->neouds[i]->arcs;
            while (curseur) {
                printf("%c -> ", curseur->sommet->libelle);
                curseur = curseur->suivant;
            }
            printf("NULL\n");
        }
        return;
    }
    printf("Le graphe est vide\n");
}

void supprimerGraphe(Graphe *graphe) {
    if (graphe) {
        for (int i = graphe->nbrSommet - 1; i >= 0; i--) {
            if (graphe->cout[i])
                free(graphe->cout[i]);
            if (graphe->neouds[i]) {
                Arc *curseur = graphe->neouds[i]->arcs;
                Arc *aSupprimer = NULL;

                while (curseur) {
                    aSupprimer = curseur;
                    curseur = curseur->suivant;
                    free(aSupprimer);
                }

                free(graphe->neouds[i]);
            }
        }
        free(graphe->cout);
        free(graphe->neouds);
        free(graphe);
    }
}