#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#define SAIR 00

void limparBuffer();

void pausar();

void limparTela();

char* ler_string(char* destino, int tamanho);

void abrir_arquivo(FILE *);

int pot(int,int);

int converte_numero(char *);

void copia_carac_D3(char [5][20][6],char [5][20][6]);

void ler_ate(char *,char);

int conta_char(char *, char);

void retira_char(char *,char);

#endif