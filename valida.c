#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"
#include "leitura.h"
#define true 1
#define false 0


int valida_nome(char *nome) {
    int i;
    int tamanho = strlen(nome);
    if (tamanho < 3) {
        printf("Nome muito curto. Deve ter pelo menos 3 caracteres.\n");
        return false;
    }
    for (i = 0; i < tamanho; i++) {
        if (!((nome[i] >= 'A' && nome[i] <= 'Z') || (nome[i] >= 'a' && nome[i] <= 'z') || nome[i] == ' ')) {
            printf("Nome inválido. Use apenas letras e espaços.\n");
            return false;
        }
    }
    return true;
}



int valida_cpf(char *cpf) {
    // Implementar a validação de CPF aqui
    return true; // Placeholder
}



int valida_telefone(char *telefone) {
    // Implementar a validação de telefone aqui
    return true; // Placeholder
}