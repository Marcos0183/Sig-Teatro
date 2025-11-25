#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define true 1
#define false 0
#define LIMITE 100

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

void abrir_arquivo(FILE *arq){
    if(arq == NULL){
        printf("ERRO AO ABRIR ARQUIVO DE DADOS");
        system("pause");        
        exit(1);
    }
}

int pot(int x,int rep){
    int soma = 1;
    if(rep == 0)return 1;
    else{ 
        for(int i = 1;i <= rep; i++){
            soma = soma * x;
        }
    }
    return soma;
}

int converte_numero(char *palavra){
    int x;
    int soma;
    int tam = strlen(palavra);
    x = tam - 1;
    soma = 0;
    for(int i = 0;i < tam;i++){
        soma = soma + (palavra[i] - '0') * (pot(10,x));
        x--;
    }
    return soma;
}

void copia_carac_D3(char copiar[5][20][6],char copiado[5][20][6]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 20; j++){
            strcpy(copiado[i][j],copiar[i][j]);
        }
    }
}

void ler_ate(char *palavra,char letra){
  for(int i = 0;i < strlen(palavra);i++){
    if(palavra[i] == letra){             //FUNÇÃO FEITA A PARTIR DO CHATGPT 4.0
       palavra[i] = '\0';
      break;
    }
  }
}

int conta_char(char *palavra, char letra){
    int tam = strlen(palavra);
    int cont = 0;
    for(int i = 0; i < tam; i++){
        if(palavra[i] == letra)cont++;
    }
    return cont;
}

void retira_char(char *palavra,char letra){
    int aparece = conta_char(palavra,letra);
    int tam = strlen(palavra);

    for(int i = 0; i < aparece; i++){
        char *x = strchr(palavra,letra);
        int indice = x - palavra; 
        for(int j = indice; j < tam; j++){
            palavra[j] = palavra[j + 1];     // FUNÇÃO FEITA A PARTIR DO AUXÍLIO DO CHATGPT
        }
    }
}