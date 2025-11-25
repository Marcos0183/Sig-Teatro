#ifndef TECNICOS_H
#define TECNICOS_H

typedef struct {
    char cpf[20];
    char nome[50];
    char funcao[16];
    char email[40];
    char telefone[16];
    int status;
} Tecnico;

typedef struct no_tecnico {
    Tecnico tecnico;
    struct no_tecnico *prox;
} NoTecnico;

void tecnicos();

void menu_Tecnicos();

void cadastro_Tecnico();

void atualizar_Tecnico();

void pesquisar_Tecnico();

void excluir_Tecnico();

void listar_tecnicos();

void exibir_tecnico(Tecnico* tec);

int cpf_existente_tec(char *cpf);

#endif