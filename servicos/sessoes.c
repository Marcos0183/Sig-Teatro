#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sessoes.h"
#include "anima.h"
#include "utils.h"

void menu_Sessao(){
    limparTela();
        printf("╔══════════════════════════════════════════════════╗\n");
        func_Ani(100);
        printf("║             SISTEMA DE TEATRO                    ║\n");
        func_Ani(100);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(100);
        printf("║                                                  ║\n");
        func_Ani(100);
        printf("║ ► 1. Cadastrar Sessão                            ║\n");
        func_Ani(100);
        printf("║ ► 2. Pesquisar Sessão                            ║\n");
        func_Ani(100);
        printf("║ ► 3. Atualizar Sessão                            ║\n");
        func_Ani(100);
        printf("║ ► 4. Excluir Sessão                              ║\n");
        func_Ani(100);
        printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
        func_Ani(100);
        printf("║                                                  ║\n");
        func_Ani(100);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(100);
        printf("--> Digite a opção desejada: ");
}



void cadastrar_Sessao(){
    int codigo_show;

    char nome_show[50];
    //char data[32]; //até o momento, nao há nenhuma comparação de data e hora
    //char hora[16]; //pesquisar
    float preco;
    //mostrar_data_hora(data, hora); //funcao adicionada para hora e data atuais


    char titulo[19]= "CADASTRAR SESSÃO";
    func_Ani_Left(titulo);
    printf("\n \n");

    printf("-----------------------------------\n");
    printf("|  INSIRA O CÓDIGO DA SESSÃO: ");  
    scanf("%d", &codigo_show);
    limparBuffer();

    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME DO SHOW: ");
    lerstring(nome_show, 50);

    printf("-----------------------------------\n");
    printf("|  INSIRA O PREÇO DO SHOW: ");
    scanf("%f", &preco);
    limparBuffer();

    // printf("-----------------------------------\n");
    // printf("|  DATA DA SESSÃO: %s\n  ", data);

    // printf("-----------------------------------\n");
    // printf("|  HORA DA SESSÃO: %s\n  ", hora);


    printf("\nRESUMO DA SESSÃO:\n");
    printf("Codigo: %d\n", codigo_show);
    printf("Show: %s\n", nome_show);
    //printf("Data: %s\n", data);
    //printf("Hora: %s\n", hora);
    printf("Preço: R$ %.2f\n", preco);
    system("pause");
}

void pesquisar_Sessao(){
    int codigo_show;

    char titulo[19]= "PROCURAR SESSÃO";
    func_Ani_Left(titulo);
    printf("\n \n");

    printf("-----------------------------------\n");
    printf("|  INSIRA O CÓDIGO DA SESSÃO: "); 
    scanf("%d", &codigo_show);
    getchar();

}

void atualizar_Sessao(){
    int codigo_show;

    char titulo[19]= "ATUALIZAR SESSÃO";
    func_Ani_Left(titulo);
    printf("\n \n");

    printf("-----------------------------------\n");
    printf("|  INSIRA O CÓDIGO DA SESSÃO: "); 
    scanf("%d", &codigo_show);
    getchar();

}

void excluir_Sessao(){
    int codigo_show;

    char titulo[19]= "EXCLUIR SESSÃO";
    func_Ani_Left(titulo);
    printf("\n \n");

    printf("-----------------------------------\n");
    printf("|  INSIRA O CÓDIGO DA SESSÃO: "); 
    scanf(" %d", &codigo_show);
    getchar();

}



void sessoes(){
    int executar_se;
    do {
        void menu_Sessao();
        scanf(" %d", &executar_se);
        getchar();

        switch (executar_se) {
            case 1:
                cadastrar_Sessao();
                break;
            case 2:
                pesquisar_Sessao();
                break;
            case 3:
                atualizar_Sessao();
                break;
            case 4:
                excluir_Sessao();
                break;
            case 0:
                break;
            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                system("pause");
                break;
        }
    } while (executar_se != 0);
}