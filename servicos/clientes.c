#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"
#include "anima.h"
#include "utils.h"

int tempo_cliente = 100;

void menu_cliente(){
    limparTela();
        printf("╔══════════════════════════════════════════════════╗\n");
        func_Ani(tempo_cliente);
        printf("║                MODULO CLIENTE                    ║\n");
        func_Ani(tempo_cliente);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_cliente);
        printf("║                                                  ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 1. cadastrar Cliente                           ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 2. Pesquisar Cliente                           ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 3. Atualizar Cliente                           ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 4. Excluir Cliente                             ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 5. listar cliente                              ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
        func_Ani(tempo_cliente);
        printf("║                                                  ║\n");
        func_Ani(tempo_cliente);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_cliente);
        printf("--> Digite a opção desejada: ");
}   



void cadastrar_cliente() {
    char cpf[20];
    char nome[50];
    char email[40];
    char telefone[16];
    FILE *arq_clientes;
    
    char titulo[19] = "CADASTRAR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");
    
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");  
    ler_string(cpf, 20);

    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME DO CLIENTE: ");
    ler_string(nome, 50);

    printf("-----------------------------------\n");
    printf("|  INSIRA O EMAIL DO CLIENTE: ");
    ler_string(email, 40);

    printf("-----------------------------------\n");
    printf("|  INSIRA O TELEFONE: ");
    ler_string(telefone, 16);

    printf("-----------------------------------\n");

    arq_clientes = fopen("clientes.csv", "at");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;   
    }
    fprintf(arq_clientes, "%s;%s;%s;%s\n", cpf, nome, email, telefone);
    fclose(arq_clientes);
    printf("Cliente cadastrado com sucesso!\n");
    pausar();
}



void atualizar_cliente(){
    char cpf[15];
    char titulo[19] = "ATUALIZAR CLIENTE";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");
    fgets(cpf, 15, stdin);
    printf("-----------------------------------\n");
    pausar();
}



void pesquisar_cliente(){
    char cpf_lido[20];
    char cpf[20];
    char nome[50];
    char email[40];
    char telefone[16];
    FILE *arq_clientes;

    arq_clientes = fopen("clientes.csv", "rt");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;   
    }

    char titulo[19] = "PESQUISAR CLIENTE";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");
    ler_string(cpf_lido, 20);
    printf("-----------------------------------\n");

    while (!feof(arq_clientes)) {
        fscanf(arq_clientes, "%[^;]" ,cpf);
        fgetc(arq_clientes);
        fscanf(arq_clientes, "%[^;]", nome);
        fgetc(arq_clientes);
        fscanf(arq_clientes, "%[^;]", email);
        fgetc(arq_clientes);
        fscanf(arq_clientes, "%[^\n]", telefone);
        fgetc(arq_clientes);
        if (strcmp(cpf, cpf_lido) == 0) {
            printf("\tCliente encontrado:\n");
            printf("\tCPF: %s\n", cpf);
            printf("\tNome: %s\n", nome);
            printf("\tEmail: %s\n", email);
            printf("\tTelefone: %s\n", telefone);
            pausar();
            fclose(arq_clientes);
            return;
        }
    }
}



void excluir_cliente(){
    char cpf[15];
    char titulo[19] = "EXCLUIR CLIENTE";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");
    fgets(cpf, 15, stdin);
    printf("-----------------------------------\n");
    pausar();
}



void listar_cliente(){
    char titulo[16] = "LISTAR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("Listando todos os clientes...\n");
    pausar();
}



void cliente(){
    int executar_C;

    do {
        menu_cliente();
        scanf("%d", &executar_C);
        limparBuffer();

        switch (executar_C) {
            case 1:
                cadastrar_cliente();
                break;
            case 2:
                pesquisar_cliente();
                break;
            case 3:
                atualizar_cliente();
                break;
            case 4:
                excluir_cliente();
                break;
            case 5:
                listar_cliente();
                break;

            case 0:
                break;
            
            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                pausar();
                break;
        }
    } while (executar_C != 0);        
}