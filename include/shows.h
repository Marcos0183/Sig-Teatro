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
    char DHD[1];
    char personagens[1];
    char status;
};

#endif
