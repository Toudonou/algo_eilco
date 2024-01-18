//
// Created by oswald on 17/01/24.
//

#include "nodeList.h"


NodeList *creerNodeList(Sommet *element) {
    if (element) {
        NodeList *node = (NodeList *) calloc(1, sizeof(NodeList));
        if (!node) {
            fprintf(stderr, "Error during allocation of list nodeList: %c\n", element->libelle);
            exit(EXIT_FAILURE);
        }
        node->element = element;
        node->suivant = NULL;
        return node;
    }
    return NULL;
}

void printNodeList(NodeList *node) {
    if(node && node->element){
        printf("%c ", node->element->libelle);
    }
}

void supprimerNodeList(NodeList *node){
    if(node){
        free(node);
    }
}