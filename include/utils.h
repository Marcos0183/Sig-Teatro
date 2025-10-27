#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>

void limparBuffer();

void pausar();

void limparTela();

char* ler_string(char* destino, int tamanho);

void abrir_arquivo(FILE *);

int pot(int,int);

int converte_numero(char *);

void copia_carac_D3(char [][20][6],char [][20][6]);

#endif