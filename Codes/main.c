#include "operations2.0.h"


int main() {
    char chaine[] = "20*20+150";
    printf("%s = %d\n", chaine, operationPostfixePileOps(chaine));


    return 0;
}
