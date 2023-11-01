#include "Listes.h"

Client *creerClient(int id, float x, float y, int q) {
    Client *client = (Client *) malloc(sizeof(Client));
    if (client) {
        client->id = id;
        client->x = x;
        client->y = y;
        client->q = q;
        client->suivant = NULL;
        return client;
    }
    exit(EXIT_FAILURE);
}

void afficher(Client *liste) {
    if (liste) {
        Client *curseur = liste;
        while (curseur) {
            printf("{Client: %d; x: %f; y: %f; q: %d}\n", curseur->id, curseur->x, curseur->y, curseur->q);
            curseur = curseur->suivant;
        }
        return;
    }
    printf("Liste vide\n");
}

float distance(Client *c1, Client *c2) {
    return (c1 && c2) ? (float) sqrtf(powf(c1->x - c2->x, 2) + powf(c1->y - c2->y, 2)) : 0;
}

float distanceDepot(Client *c) {
    return c ? (float) sqrtf(powf(c->x, 2) + powf(c->y, 2)) : 0;
}

float distanceTotale(Client *liste) {
    float distancTotale = 0;
    Client *curseur = liste;
    while (curseur && curseur->suivant) {
        distancTotale += distance(curseur, curseur->suivant);
        curseur = curseur->suivant;
    }
    distancTotale += distanceDepot(liste);
    distancTotale += distanceDepot(curseur);
    return distancTotale;
}

Client *insertionClient(Client *liste, Client *c, int pos) {
    int i = 0;
    Client *curseur = liste;

    if (liste) {
        if (pos == 0) {
            c->suivant = liste;
            return c;
        } else {
            while (i < pos && curseur->suivant) {
                curseur = curseur->suivant;
                i++;
            }
            c->suivant = curseur->suivant;
            curseur->suivant = c;
            return liste;
        }
    }
    return c;
}

int meilleurePosition(Client *liste, Client *c) {
    float delta = INFINITY;
    int pos = 0, i;
    Client *curseur = liste;

    if (curseur && curseur->suivant) {
        for (i = 0; curseur->suivant; i++) {
            if (delta > distance(curseur, c) + distance(c, curseur->suivant) - distance(curseur, curseur->suivant)) {
                delta = distance(curseur, c) + distance(c, curseur->suivant) - distance(curseur, curseur->suivant);
                pos = i;
            }
            curseur = curseur->suivant;
        }
        return pos ? pos : i + 1;
    } else if (curseur) return 1;
    else return 0;
}
