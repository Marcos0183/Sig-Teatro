#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "leitura.h"
#include "utils.h"
#include "valida.h"


void ler_nome(char *nome) {
    do {
    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME: "); 
    ler_string(nome, 50);
    } while (!valida_nome(nome));
}



void ler_cpf(char *cpf) {
    do {
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF: "); 
    ler_string(cpf, 15);
    } while (!valida_cpf(cpf));
}