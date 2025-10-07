#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct {
    char cpf[20];
    char nome[50];
    char email[40];
    char telefone[16];
    int status;
} Cliente; 

void cliente();

void cadastrar_cliente();

void atualizar_cliente();

void pesquisar_cliente();

void excluir_cliente();

void listar_cliente();





#endif