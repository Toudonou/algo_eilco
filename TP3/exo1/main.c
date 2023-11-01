#include "operations.h"

int main() {
    char chaine[] = "5+5*((9+8)+(4*6)+7)";
    printf("%s = %f\n", chaine, evaluer(convertir_infixe_postfixe_generalisee(chaine)));
    return 0;
}
