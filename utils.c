#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define true 1
#define false 0
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



FILE* abrir_arquivo_leitura(const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "rb"); // abre apenas para leitura binária
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nome_arquivo);
    }
    return arq;
}



FILE* abrir_arquivo_escrita(const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "ab"); // abre para escrita binária (append)
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nome_arquivo);
    }
    return arq;
}



FILE* abrir_arquivo_leitura_escrita(const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "r+b"); // abre para leitura e escrita binária
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nome_arquivo);
    }
    return arq;
}