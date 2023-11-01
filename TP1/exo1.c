#include <stdio.h>

void testCaractere(char c){
    if('0' <= c && c <= '9'){
        printf("%c est un chiffre\n", c);
    }
    else if ('A' <= c  && c <= 'Z') {
        printf("%c est une lettre majuscule\n", c);
    }
    else if ('a' <= c && c <= 'z') {
        printf("%c est une lettre miniscule\n", c);
    }
    else {
        printf("%c n'est ni un chiffre, ni une lettre miniscule, ni une lettre majuscule\n", c);
    }
}

void tableMultiplication(){
    char nombre;
    do{
        printf("Quelle table de multiplication voulez-vous, tapez 0 (zéro) pour sortir ? : ");
        scanf("%c", &nombre);
        getchar();
        if('1' <= nombre && nombre <= '9'){
            for (int i = 1; i <= 10; i++){
                printf("%c x %d = %d\n", nombre, i, (nombre - '0') * i);
            }
        }
        else if (nombre != '0'){
            printf("Ce n'est pas dans les possibilités du programme, recommencez\n");
        }
    } while (nombre != '0');
    
}

int main(){
    
    char c;
    printf("Entrer un caractère : ");
    scanf("%c", &c);
    testCaractere(c);

    tableMultiplication();
    
    return 0;
}
