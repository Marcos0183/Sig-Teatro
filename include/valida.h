#ifndef VALIDA_H
#define VALIDA_H
#include "leitura.h"
#include "ingresso.h"

int valida_nome(char *nome);

int valida_cpf(char *cpf);

int valida_telefone(char *telefone);

int valida_email(char *email);

int valida_cliente(char *);

int valida_show(int);

void valida_cadeira(char *,int,SEP *);

int valida_id(char *);

int valida_funcao(char *funcao);

void valida_cpf_show(SEP *,Dados_I *);

void valida_ler_codigo(SEP *,char *);

#endif