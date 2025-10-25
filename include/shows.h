#ifndef SHOWS_H
#define SHOWS_H
#define False 0
#define True 1
#include <stdio.h>

void shows();

void menu_Shows();

void cadastrar_Show();

void excluir_Show();

void atualizar_Show();

void pesquisar_Show();

typedef struct cadastro_Shows Dados_S;
typedef struct cadastro_Temp Dados_Temp;
typedef struct cabecalho_0 Cabecalho;


struct cadastro_Shows{
    int id;
    char nome[32]; 
    int tam_DHD;
    int tam_personagem;
    int status;
};

struct cadastro_Temp{
    char data[12];
    char hora[6];
    char duracao[5];
    char personagem[32];
};

struct cabecalho_0{
    int id_lido;
    int encontrado;
    char *DHD;
    char *persona;
    FILE *arq_shows;
    Dados_S *dados;
};

#endif
