#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct {
    char cpf[20];
    char nome[50];
    char email[40];
    char telefone[16];
    int status;
} Cliente; 

typedef struct no_cliente {
    Cliente cliente;
    struct no_cliente *prox;
} NoCliente;

void cliente();

void cadastrar_cliente();

void atualizar_cliente();

void pesquisar_cliente();

void excluir_cliente();

int cpf_existente(char *cpf);

void listar_cliente();

void exibir_cliente(Cliente* clt);

#endif