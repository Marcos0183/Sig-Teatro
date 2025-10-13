#ifndef SHOWS_H
#define SHOWS_H
#define False 0
#define True 1

void shows();

void menu_Shows();

void cadastrar_Show();

void excluir_Show();

void atualizar_Show();

void pesquisar_Show();

typedef struct cadastro_Shows Dados;

struct cadastro_Shows{
    char id[3];
    char nome[32]; 
    void *DHD;
    void *personagens;
    char status;
};

#endif
