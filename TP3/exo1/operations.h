//
// Created by oswald on 29/10/23.
//

#ifndef TP3_OPERATIONS_H
#define TP3_OPERATIONS_H

#include "pile.h"
#include <string.h>

float evaluer(char expression[]);

char *convertir_infixe_postfixe(char expression[]);
char * convertir_infixe_postfixe_generalisee(char expression[]);
#endif //TP3_OPERATIONS_H
