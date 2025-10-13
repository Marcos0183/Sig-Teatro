#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



void pausar() {
    printf("\n Pressione Enter para continuar...");
    limparBuffer();
}



char* ler_string(char* destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) != NULL) {
        int len = strcspn(destino, "\n"); 

        if (destino[len] == '\n') {
            destino[len] = '\0';
        } else {
            limparBuffer();      
        }
        return destino;
    }
    return NULL; 
}


void limparTela() {
    system("clear || cls");
}


int id(){
    #define LIMITE = 1000;
    Id *id;
    FILE *arq_id;
    id = (Id *) malloc(sizeof(Id));
    arq_id = fopen("id.dat","ab");
    id ->ultimo_valor = 0;
    fwrite(id,sizeof(Id),1,arq_id);
    return id ->ultimo_valor;
}