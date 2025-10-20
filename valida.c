#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
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

    int digitos = 0;

    for (int i = 0; telefone[i] != '\0'; i++) {
        char c = telefone[i];

        // Aceita apenas números, espaço, parêntese e hífen
        if (!isdigit(c) && c != ' ' && c != '(' && c != ')' && c != '-') {
            return false;
        }
        if (isdigit(c)) {
            digitos++;
        }
    }

    // Telefones brasileiros têm 10 ou 11 dígitos (com DDD)
    if (digitos < 10 || digitos > 11) {
        return false;
    }

    return true;
    }





int valida_email(char *email) {
    // Implementar a validação de email aqui
    return true; // Placeholder
}