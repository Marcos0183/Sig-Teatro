#ifndef TECNICOS_H
#define TECNICOS_H

typedef struct {
    char cpf[20];
    char nome[50];
    char funcao[16];
    char email[40];
    char telefone[16];
} Tecnico;

void tecnicos();

void menu_Tecnicos();

void cadastro_Tecnico();

void atualizar_Tecnico();

void pesquisar_Tecnico();

void excluir_Tecnico();

#endif