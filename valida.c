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



int valida_cpf(char *cpf_raw) {
    char cpf[20];
    int i, j, soma, resto, dig1, dig2;

    // Remove tudo que não for número
    j = 0;
    for (i = 0; cpf_raw[i] != '\0'; i++) {
        if (cpf_raw[i] >= '0' && cpf_raw[i] <= '9') {
            cpf[j++] = cpf_raw[i];
        }
    }
    cpf[j] = '\0';

    // Verifica se tem exatamente 11 dígitos
    if (strlen(cpf) != 11) {
        printf("CPF deve ter 11 dígitos.\n");
        return 0;
    }

    // Rejeita CPFs com todos os dígitos iguais (ex: 11111111111)
    // int iguais = 1;
    //for (i = 1; i < 11; i++) {
        // if (cpf[i] != cpf[0]) {
        //    iguais = 0;
        //  break;
       // }
    //}

    //if (iguais) {
        //printf("CPF com todos os dígitos iguais é inválido.\n");
        //return 0;
    //}

    // Calcula o primeiro dígito verificador
    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    dig1 = (resto < 2) ? 0 : 11 - resto;

    // Calcula o segundo dígito verificador
    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    soma += dig1 * 2;
    resto = soma % 11;
    dig2 = (resto < 2) ? 0 : 11 - resto;

    // Compara com os dígitos originais
    if (dig1 == (cpf[9] - '0') && dig2 == (cpf[10] - '0')) {
        return 1; 
    } else {
        printf("CPF inválido! Dígitos verificadores incorretos.\n");
        return 0; 
    }
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
    int tamanho = strlen(email);
    int i;
    int pos_arroba = -1;
    int pos_ponto = -1;

    // Verifica tamanho mínimo e máximo
    if (tamanho < 5 || tamanho > 254)
        return false;

    // Não pode começar ou terminar com ponto ou arroba
    if (email[0] == '.' || email[0] == '@' ||
        email[tamanho - 1] == '.' || email[tamanho - 1] == '@')
        return false;

    // Percorre cada caractere
    for (i = 0; i < tamanho; i++) {
        char c = email[i];

        // Não pode ter espaço ou caracteres especiais inválidos
        if (isspace(c)) {
            return false;
        }

        if (!isalnum(c) && c != '.' && c != '_' && c != '-' && c != '@') {
            return false;
        }

        if (c == '@') {
            // Já tem um @?
            if (pos_arroba != -1)
                return false;
            pos_arroba = i;
        }

        if (c == '.' && pos_arroba != -1){
            pos_ponto = i;
        }

    }

    // Verifica se há um @ e um . depois do @
    if (pos_arroba == -1 || pos_ponto == -1)
        return false;

    // Verifica se o ponto está depois do arroba e não colado
    if (pos_ponto < pos_arroba + 2)
        return false;

    // Verifica se o ponto não é o último caractere
    if (pos_ponto == tamanho - 1)
        return false;

    return true;
}



int valida_funcao(char *funcao) {
    int i;
    bool tem_letra = false;

    // Remove espaços do início
    while (*funcao == ' ') {
        funcao++;
    }

    if (strlen(funcao) == 0) {
        printf("Especialidade inválida! Campo vazio.\n");
        return false;
    }

    // Verifica se há pelo menos uma letra
    for (i = 0; funcao[i] != '\0'; i++) {
        if ((funcao[i] >= 'A' && funcao[i] <= 'Z') ||
            (funcao[i] >= 'a' && funcao[i] <= 'z')) {
            tem_letra = true;
        }
    }

    if (!tem_letra) {
        printf("Especialidade inválida! Deve conter letras.\n");
        return false;
    }

    return true;
}