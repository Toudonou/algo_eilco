#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define fichier "fichier.txt"

typedef struct client{
    int numero;
    char nom[50];
    float solde;
}client;

void ajouterClient(){
    FILE *file = fopen(fichier, "a");
    client clt;
    if(file){
        printf("Entrer le numero client : ");
        scanf("%d", &clt.numero);
        getchar();
        
        printf("Entrer le nom du client (50 caractères au plus) : ");
        fgets(clt.nom, 50, stdin);
        for (int i = 0; i < strlen(clt.nom); i++) if (clt.nom[i + 1] == '\0') clt.nom[i] = '\0';
        
        do{
            printf("Entrer son solde (>= 0) : ");
            scanf("%f", &clt.solde);
        } while (clt.solde < 0);
        
        fprintf(file, "%d %s %f\n", clt.numero, clt.nom, clt.solde);
        printf("Client ajouter avec succes\n\n");
        fclose(file);
    }
}

void listerClients() {
    FILE *file = NULL; 
    file = fopen(fichier, "r");
    client clt;
    int i = 1;

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    while (fscanf(file, "%d %s %f\n", &clt.numero, clt.nom, &clt.solde) != EOF) {
        if (i == 1) printf("Liste de(s) client(s) : \n");
        fprintf(stdout, "\t%d-) %s\n", i++, clt.nom);
    }

    if (i == 1) {
        printf("Il n'y a pas de clients\n");
    }

    fclose(file);
}

void afficherCompteClient(){
    FILE *file = NULL; 
    file = fopen(fichier, "r");
    client clt;
    int numeroClient;

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    printf("Entrer le numero du client : ");
    scanf("%d", &numeroClient);

    while(fscanf(file, "%d %s %f", &clt.numero, clt.nom, &clt.solde) != EOF){
        if(clt.numero == numeroClient){
            printf("Informations client : \n\tNumero : %d\n\tNom : %s\n\tSolde : %f\n", clt.numero, clt.nom, clt.solde);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("Client non trouvé\n");
}

void virementRetrait(){
    FILE *file = NULL; 
    file = fopen(fichier, "r");
    client clt, *tabClients;
    int i = 0, nbrLignes = 0, clientManup;
    char ch;

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    // compter le nombre de lignes
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') nbrLignes++;
    }

    rewind(file);
    // copie du fichier
    tabClients = malloc(nbrLignes*sizeof(client));
    while(fscanf(file, "%d %s %f\n", &tabClients[i].numero, tabClients[i].nom, &tabClients[i].solde) != EOF) i++;
    fclose(file);

    // reouverture du fichier et modification du solde
    file = fopen(fichier, "w+");
    i = 0;
    printf("Entrer le numero du client : ");
    scanf("%d", &clientManup);
    while(i < nbrLignes){
        if(tabClients[i].numero == clientManup){
            printf("1 - Retrait\n2 - Virement\n>> ");
            scanf("%d", &clientManup);
            if(clientManup == 1) {
                printf("Solde : ");
                scanf("%d", &clientManup);
                tabClients[i].solde -= clientManup;
            }
            else{
                printf("Solde : ");
                scanf("%d", &clientManup);
                tabClients[i].solde += clientManup;
            }
            fprintf(file, "%d %s %f\n", tabClients[i].numero, tabClients[i].nom, tabClients[i].solde);
        }
        else fprintf(file, "%d %s %f\n", tabClients[i].numero, tabClients[i].nom, tabClients[i].solde);
        i++;
    }


    fclose(file);
}

int main(int argc, char *argv[]){
    int ops;

    while (1)
    {
        printf("\nQue vous-voulez faire ???\n1 - Ajouter un client\n2 - Lister les clients\n3 - Afficher un compte client\n4 - Effectuer un virement ou un retrait\n0 - Stop\n>> ");
        scanf("%d", &ops);

        switch (ops)
        {
        case 0:
            printf("Sortie du programme\n");
            return 0;
        case 1:
            ajouterClient();
            break;
        case 2:
            listerClients();
            break;
        case 3:
            afficherCompteClient();
            break;
        case 4:
            virementRetrait();
            break;
        default:
            break;
        }
    }
    
}
