#ifndef LEITURA_H
#define LEITURA_H
#include "shows.h"
#include "ingresso.h"

typedef struct sep SEP;
struct sep{
    int valida;
    int error;
};

int id_ingresso(void);

int id_show(void);

void ler_id(int *id_lido); 

int ler_codigo(Dados_I *);

int ler_cadeira(Dados_I *);

void ler_nomeShow(char *nome);

void ler_DHD(Cabecalho *);

void ler_persona(Cabecalho *);

void ler_nome(char *nome);

void ler_cpf(char *cpf);

int ler_cpf_show(Dados_I *);

void ler_telefone(char *telefone);

void ler_email(char *email);

void ler_funcao(char *funcao);

#endif
