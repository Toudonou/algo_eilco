#include "file.h"

int main() {
    srand(time(NULL));
    float tempsMoyen = 0;
    File *file = creerFile();

    for(int i = 0; i < 10; i++){
        enfiler(file, i + 1, (float )i,  (float ) (rand()%11));
    }
    return 0;
}
