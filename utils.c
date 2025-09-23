#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



void pausar() {
    printf("\n Pressione Enter para continuar...");
    limparBuffer();
}



char* lerString(char* destino, int tamanho) {
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