#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>

void limparBuffer();

void pausar();

void limparTela();

char* ler_string(char* destino, int tamanho);

FILE* abrir_arquivo_leitura(const char *nome_arquivo);

FILE* abrir_arquivo_escrita(const char *nome_arquivo);

FILE* abrir_arquivo_leitura_escrita(const char *nome_arquivo);

#endif