#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sessoes.h"
#include "anima.h"

int tempo_Sessoes = 100;
void sessoes(){
    bool parada_P = true;
    do {
        int executar_P;
        system("clear || cls");
        printf("#####################################################################################\n");
        func_Ani(tempo_Sessoes);
        printf("   +++                                 SESSAO                                    +++\n");
        func_Ani(tempo_Sessoes);
        printf("#####################################################################################\n");
        func_Ani(tempo_Sessoes);
        printf("###                             1 - CADASTRAR SESSAO                              ###\n");
        func_Ani(tempo_Sessoes);
        printf("###                                                                               ###\n");
        printf("###                             2 - PESQUISAR SESSAO                              ###\n");
        printf("###                                                                               ###\n");
        func_Ani(tempo_Sessoes);
        printf("###                             3 - ATUALIZAR SESSAO                              ###\n");
        printf("###                                                                               ###\n");
        func_Ani(tempo_Sessoes);
        printf("###                             4 - EXCLUIR SESSAO                                ###\n");
        printf("###                                                                               ###\n");
        func_Ani(tempo_Sessoes);
        printf("###                             0 - VOLTAR AO MENU ANTERIOR...                    ###\n");
        scanf(" %d", &executar_P);
        getchar();

        switch (executar_P) {
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
                parada_P = false;
                break;
            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                system("pause");
                break;
        }
    } while (parada_P);
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
    getchar();

    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME DO SHOW: ");
    fgets(nome_show, 50, stdin);

    printf("-----------------------------------\n");
    printf("|  INSIRA O PREÇO DO SHOW: ");
    scanf("%f", &preco);

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