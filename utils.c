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
    int idRetorna;
    int *id;
    id = &idRetorna;
    FILE *arq_id;
    arq_id = fopen("id.dat","rb");

    if(arq_id == NULL){
       arq_id = fopen("id.dat","w+");
       idRetorna = 0;
       fwrite(id,sizeof(int),1,arq_id);
       rewind(arq_id);
    }
    fread(id,sizeof(int),1,arq_id);
    fclose(arq_id);

    arq_id = fopen("id.dat","wb");
    idRetorna++;
    fwrite(id,sizeof(int),1,arq_id);
    fclose(arq_id);
    free(id);
    return idRetorna;
}