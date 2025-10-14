#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define LIMITE = 100;

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
    Id *id;
    id = (Id *) malloc(sizeof(Id));
    FILE *arq_id;
    arq_id = fopen("id.dat","ab");
    if(arq_id == NULL){
        printf("Erro ao abrir arquivo para salvar quais IDs foram usados");
        exit(1);
    }
    id ->ultimo_valor = 0;
    fwrite(id,sizeof(Id),1,arq_id);
    return id ->ultimo_valor;
}