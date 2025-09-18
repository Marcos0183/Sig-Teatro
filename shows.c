#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shows.h"
#include "anima.h"

int tempo_Shows = 100;
void shows(){  
    bool parada_S = true;
    do {  
        int executar_S;
        system("clear||cls");
        printf("#####################################################################################\n");
        func_Ani(tempo_Shows);
        printf("   +++                                  SHOWS                                 +++\n");
        func_Ani(tempo_Shows);
        printf("#####################################################################################\n");
        func_Ani(tempo_Shows);
        printf("###                             1 - CADASTRAR SHOW                                ###\n");
        func_Ani(tempo_Shows);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Shows);
        printf("###                             2 - PESQUISAR SHOW                                ###\n");
        func_Ani(tempo_Shows);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Shows);
        printf("###                             3 - ATUALIZAR SHOW                                ###\n");
        func_Ani(tempo_Shows);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Shows);
        printf("###                             4 - EXCLUIR SHOW                                  ###\n");
        func_Ani(tempo_Shows);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Shows);
        printf("##                              0 - VOLTAR AO MENU ANTERIOR... ");
        
        scanf(" %d",&executar_S);
        getchar();

        switch (executar_S) {
            case 1:
                cadastrar_Show();
                break;
            case 2:
                pesquisar_Show();
                break;
            case 3:
                atualizar_Show();
                break;
            case 4:
                excluir_Show();
                break;
            case 0:
                parada_S = false;
                break;
            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                system("pause");
                break;
        }
    } while (parada_S);
}

void cadastrar_Show(){
    char nome[30]; 
    char data[10];
    char duracao[4];
    char personagens[100];
    char titulo[16] = "CADASTRAR SHOW";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME DO SHOW: ");
    fgets(nome,30,stdin);
    printf("V----------------------------------\n");
    printf("|  INSIRA A/AS DATAS DO SHOW: ");
    fgets(data,10,stdin);
    printf("V----------------------------------\n");
    printf("|  INSIRA A/AS DURACAOS DO SHOW: ");
    fgets(duracao,4,stdin);;
    printf("V----------------------------------\n");
    printf("|  INSIRA O/OS PERSONAGENS DO SHOW: ");
    fgets(personagens,100,stdin);
    printf("V----------------------------------\n");
    system("pause");

}

void excluir_Show(){
    int codigo;
    char titulo[16] = "EXCLUIR SHOW";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",&codigo);
    printf("V----------------------------------\n");
}

void atualizar_Show(){
    int codigo;
    char titulo[16] = "ATUALIZAR SHOW";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",&codigo);
    printf("V----------------------------------\n");
}

void pesquisar_Show(){
    int codigo;
    char titulo[16] = "PESQUISAR SHOW";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",&codigo);
    getchar();
    printf("-----------------------------------\n");
}
