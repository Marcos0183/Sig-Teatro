#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "leitura.h"
#include "utils.h"
#include "valida.h"
#include "listachar.h"
#include "shows.h"

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



void ler_nomeShow(char *nome){
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME DO SHOW: ");
    ler_string(nome,32);
}



void ler_DHD(Cabecalho *cabecalho){
    Dados_Temp *inf;
    inf = (Dados_Temp *) malloc(sizeof(Dados_Temp));
    int parar;
    parar = True;
    printf("-----------------------------------\n");
    while(parar){
        printf("|  INSIRA A DATA DO SHOW - DIGITE (S) PARA ENCERRAR: ");
        ler_string(inf ->data,12);

        printf("-----------------------------------\n");
        if(strcmp(inf ->data,"S") == 0 || strcmp(inf ->data,"s") == 0) parar = False;
        else{
            cabecalho ->DHD = listaChar(cabecalho ->DHD,inf ->data);

            printf("|  INSIRA A HORA DE INÍCIO DO SHOW: ");
            ler_string(inf ->hora,6);
            printf("-----------------------------------\n");
            listaChar(cabecalho ->DHD,inf ->hora);

            printf("|  INSIRA A DURAÇÃO DO SHOW: ");
            ler_string(inf ->duracao,5);
            printf("-----------------------------------\n");
            listaChar(cabecalho ->DHD,inf ->duracao);
        }
    }
    cabecalho ->dados ->tam_DHD = strlen(cabecalho ->DHD) + 1;
    free(inf);
}



void ler_persona(Cabecalho *cabecalho){
    Dados_Temp *inf;
    inf = (Dados_Temp *) malloc(sizeof(Dados_Temp));
    int parar;
    parar = True;
    while(parar){
        printf("|  INSIRA OS PERSONAGENS DO SHOW - DIGITE (S) PARA ENCERRAR: ");
        ler_string(inf ->personagem,32);
        printf("-----------------------------------\n");
        if(strcmp(inf ->personagem,"S") == 0 || strcmp(inf ->personagem,"s") == 0) parar = False;
        else{
            cabecalho ->persona = listaChar(cabecalho ->persona,inf ->personagem);
        }
    }
    cabecalho ->dados ->tam_personagem = strlen(cabecalho ->persona) + 1;
    free(inf);

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