#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "anima.h"
#include "ingresso.h"
#include "utils.h"
#include "leitura.h"

int tempo_Ingresso = 100;


void menu_Ingresso(){
    limparTela();
    printf("\n");
    func_Ani(tempo_Ingresso);
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_Ingresso);
    printf("║                MÓDULO INGRESSOS                  ║\n");
    func_Ani(tempo_Ingresso);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_Ingresso);
    printf("║                                                  ║\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 1. Vender Ingresso                             ║\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 2. Pesquisar Ingresso                          ║\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 3. Atualizar Ingresso                          ║\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 4. Excluir Ingresso                            ║\n");
    func_Ani(tempo_Ingresso);
    printf("║                                                  ║\n");
    func_Ani(tempo_Ingresso);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
    func_Ani(tempo_Ingresso);
    printf("╚══════════════════════════════════════════════════╝\n");
    func_Ani(tempo_Ingresso);
    printf("--> Digite a opção desejada: ");
}



void vender_Ingresso(){
    int parar;
    FILE *arq_Ingresso;
    Dados_I *dados;
    dados = (Dados_I*) malloc(sizeof(Dados_I));
    
    parar = ler_cpf_show(dados);
    if(parar){
        parar = ler_codigo(dados);
    }
    if(parar){
    
    }
       


        // printf("V----------------------------------\n");
        // printf("|  ESCOLHA SUA CADEIRA: ");
        // ler_string(dados->cadeira,5);
        // printf("V----------------------------------\n");

        // dados->status = 'V';
        // arq_Ingresso = fopen("arq_ingresso.dat","ab");
        // fwrite(dados,sizeof(Dados_I),1,arq_Ingresso);
        // fclose(arq_Ingresso);
        // free(dados);
    
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
    pausar();
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
    pausar();
}



void pesquisar_Ingresso(){
    char id[6];
    char titulo[19] = "PESQUISAR INGRESSO";
    func_Ani_Left(titulo);


    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO INGRESSO: ");
    ler_string(id,6);
    printf("-----------------------------------\n");
    limparTela();
    pausar();
}



void ingresso(){
    int executar_I;

    do {
        menu_Ingresso();
        scanf("%d", &executar_I);
        limparBuffer();
        
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
                break;

            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                pausar();
                break;
            
        }
    } while (executar_I != 0);
}

