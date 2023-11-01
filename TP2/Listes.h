#ifndef LISTES_H
#define LISTES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct client {
    int id;
    float x, y;
    int q;
    struct client *suivant;
} Client;


Client *creerClient(int id, float x, float y, int q);

Client *insertionClient(Client *liste, Client *c, int pos);

void afficher(Client *liste);

float distance(Client *c1, Client *c2);

float distanceDepot(Client *c);

float distanceTotale(Client *liste);

int meilleurePosition(Client *liste, Client *c);

Client *suprressionClient(Client *liste, int pos);

#endif // LISTES_H
