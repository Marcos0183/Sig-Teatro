#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "anima.h"
#include "ingresso.h"

int tempo_Ingresso = 100;
void ingresso() {  

    bool parada_I = true;
    do {  
        int executar_I;
        system("clear||cls");
        printf("#####################################################################################\n");
        func_Ani(tempo_Ingresso);
        printf("   +++                                INGRESSO                                 +++\n");
        func_Ani(tempo_Ingresso);
        printf("#####################################################################################\n");
        func_Ani(tempo_Ingresso);
        printf("###                             1 - VENDER INGRESSO                               ###\n");
        func_Ani(tempo_Ingresso);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Ingresso);
        printf("###                             2 - PESQUISAR INGRESSO                            ###\n");
        func_Ani(tempo_Ingresso);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Ingresso);
        printf("###                             3 - ATUALIZAR INGRESSO                            ###\n");
        func_Ani(tempo_Ingresso);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Ingresso);
        printf("###                             4 - EXCLUIR INGRESSO                              ###\n");
        func_Ani(tempo_Ingresso);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Ingresso);
        printf("##                              0 - VOLTAR AO MENU ANTERIOR...  ");
        
        scanf(" %d",&executar_I);
        getchar();
        
        switch (executar_I) {
            case 1:
                vender_Ingresso();
                break;
            case 2:
                pesquisar_Ingresso();
                break;
            case 3:
                atualizar_Ingresso();
                break;
            case 4:
                excluir_Ingresso();
                break;
            case 0:
                parada_I = false;
                break;
            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                system("pause");
            
        }
    } while (parada_I);
}

void vender_Ingresso(){
    char nome[30];
    int codigo_Show;
    char cadeira[3];
    char titulo[16] = "VENDER INGRESSO";
    
    func_Ani_Left(titulo);
    
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME: ");
    fgets(nome,30,stdin);
    printf("V----------------------------------\n");
    printf("|  INSIRA O CÓDIGO DO SHOW: ");
    scanf(" %d",&codigo_Show);
    getchar();
    printf("V----------------------------------\n");
    printf("|  ESCOLHA SUA CADEIRA: ");
    fgets(cadeira,3,stdin);
    printf("V----------------------------------\n");
    system("pause");
}

void excluir_Ingresso(){
    int codigo;
    char titulo[19] = "EXCLUIR INGRESSO";
    func_Ani_Left(titulo);
    
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO INGRESSO: ");
    scanf("%d",&codigo);
    printf("-----------------------------------\n");
    system("pause");
}

void atualizar_Ingresso(){
    int codigo;
    char titulo[19] = "ATUALIZAR INGRESSO";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO INGRESSO: ");
    scanf("%d",&codigo);
    printf("-----------------------------------\n");
    system("pause");
}

void pesquisar_Ingresso(){
    int codigo;
    char titulo[19] = "PESQUISAR INGRESSO";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO INGRESSO: ");
    scanf(" %d",&codigo);
    getchar();
    printf("-----------------------------------\n");
    system("pause");
}