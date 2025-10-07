#ifndef SHOWS_H
#define SHOWS_H

void shows();

void menu_Shows();

void cadastrar_Show();

void excluir_Show();

void atualizar_Show();

void pesquisar_Show();

typedef struct cadastro_Shows Dados;

struct cadastro_Shows{
    char nome[32]; 
    char data[12];
    char hora[6];
    char duracao[6];
    char personagens[27];
    char status;
};

#endif
