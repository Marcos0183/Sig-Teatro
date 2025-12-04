#ifndef PESQUISA_H
#define PESQUISA_H
#include "shows.h"
#include "ingresso.h"

void exibir_rel_ingresso(Dados_I *);

int escolha_cad_show(Cabecalho *);

void exibir_ingresso(Dados_I *,int);

void exibir_inf_cadastro(Cabecalho *,int);

void pesquisa_show(Cabecalho *);

void pesquisar_ingresso(Dados_I *,char *);

void cria_cadeiras(int);

void vagar_cadeira(Dados_I *);

void exibir_cadeiras(int);

int cadeira_usada(char *,int);

void procura_cad(char *,Mapeia *);

void altera_cadeira(char *,int);

void apaga_cadeiras(int id_parametro);

void apaga_ingressos(int id_parametro);

ListaID *listaI_id_show();

void exibir_rel_show(ListaID *);

ListaID *listaD_id_show();

#endif

