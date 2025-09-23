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
        printf("║             SISTEMA DE TEATRO                    ║\n");
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
    char cpf[15];
    char nome[30];
    char email[40];
    char telefone[16];
    
    char titulo[19] = "CADASTRAR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");  
    fgets(cpf, 15, stdin);

    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME DO CLIENTE: ");
    fgets(nome, 30, stdin);

    printf("-----------------------------------\n");
    printf("|  INSIRA O EMAIL DO CLIENTE: ");
    fgets(email, 40, stdin);
    printf("-----------------------------------\n");//
    
    printf("|  INSIRA O TELEFONE: ");
    fgets(telefone, 16, stdin);
    printf("-----------------------------------\n");
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
    char cpf[15];
    char titulo[19] = "PESQUISAR CLIENTE";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");
    fgets(cpf, 15, stdin);
    printf("-----------------------------------\n");
    pausar();
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