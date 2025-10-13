#ifndef UTILS_H
#define UTILS_H

typedef struct guarda_id Id;
struct guarda_id{
    int ultimo_valor;
};


void limparBuffer();

void pausar();

void limparTela();

char* ler_string(char* destino, int tamanho);

#endif