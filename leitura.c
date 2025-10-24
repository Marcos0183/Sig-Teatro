#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "leitura.h"
#include "utils.h"
#include "valida.h"

int id_show(){
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

//1. Passe o endereço da variável
//Ex: ler_id(&id_lido)
void ler_id(int *id_lido){
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",id_lido);
    getchar();
    printf("-----------------------------------\n");
}

void ler_nome(char *nome) {
    do {
    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME: "); 
    ler_string(nome, 50);
    } while (!valida_nome(nome));
}

void ler_cpf(char *cpf) {
    do {
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF: "); 
    ler_string(cpf, 15);
    } while (!valida_cpf(cpf));
}

void ler_telefone(char *telefone) {
    do {
    printf("-----------------------------------\n");
    printf("|  INSIRA O TELEFONE: "); 
    ler_string(telefone, 16);
    } while (!valida_telefone(telefone));
}

void ler_email(char *email) {
    do {
    printf("-----------------------------------\n");
    printf("|  INSIRA O EMAIL: "); 
    ler_string(email, 40);
    } while (!valida_email(email));
}