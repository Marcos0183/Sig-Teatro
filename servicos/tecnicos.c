#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tecnicos.h"
#include "anima.h"
#include "utils.h"

int tempo_Tecnicos = 100;

void menu_Tecnicos(){
    limparTela();
        printf("╔══════════════════════════════════════════════════╗\n");
        func_Ani(tempo_Tecnicos);
        printf("║             SISTEMA DE TEATRO                    ║\n");
        func_Ani(tempo_Tecnicos);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_Tecnicos);
        printf("║                                                  ║\n");
        func_Ani(tempo_Tecnicos);
        printf("║ ► 1. Cadastrar Técnico                           ║\n");
        func_Ani(tempo_Tecnicos);
        printf("║ ► 2. Pesquisar Técnico                           ║\n");
        func_Ani(tempo_Tecnicos);
        printf("║ ► 3. Atualizar Técnico                           ║\n");
        func_Ani(tempo_Tecnicos);
        printf("║ ► 4. Excluir Técnico                             ║\n");
        func_Ani(tempo_Tecnicos);
        printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
        func_Ani(tempo_Tecnicos);
        printf("║                                                  ║\n");
        func_Ani(tempo_Tecnicos);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_Tecnicos);
        printf("--> Digite a opção desejada: ");
}

void cadastro_Tecnico(){
    char cpf[15];
    char nome[30];
    char funcao[16];
    char email[40];
    char telefone[16];
    
    char titulo[19] = "CADASTRAR TECNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TECNICO: ");  //** Deixarei assim por enquanto, sem validação
    fgets(cpf, 15, stdin);

    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME DO TECNICO: ");
    fgets(nome, 30, stdin);

    printf("-----------------------------------\n");
    printf("|  INSIRA A FUNÇÃO DO TECNICO: ");
    fgets(funcao, 15, stdin);

    printf("-----------------------------------\n");
    printf("|  INSIRA O EMAIL DO TECNICO: ");
    fgets(email, 40, stdin);
    printf("-----------------------------------\n");//
    
    printf("|  INSIRA O TELEFONE: ");
    fgets(telefone, 16, stdin);
    printf("-----------------------------------\n");

}

void atualizar_Tecnico(){
    char cpf[15];
    char titulo[19] = "ATUALIZAR TÉCNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TÉCNICO: ");  //** Deixarei assim por enquanto, sem validação
    fgets(cpf, 15, stdin);

    // procurar se há esse cpf
    // se sim, para alterar os dados tem que saber quais dados quer alterar
}

void pesquisar_Tecnico(){
    char cpf[15];
    
    char titulo[19] = "PESQUISAR TECNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TÉCNICO: ");  //** Deixarei assim por enquanto, sem validação
    fgets(cpf, 15, stdin);

}

void excluir_Tecnico(){
    char cpf[15];
    char titulo[19] = "EXCLUIR TÉCNICO";
    func_Ani_Left(titulo);
    printf("\n \n");

    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TÉCNICO: ");  //** Deixarei assim por enquanto, sem validação
    fgets(cpf, 15, stdin);

}



void tecnicos(){
    int executar_T;
    do {
        menu_Tecnicos();
        scanf(" %d",&executar_T);
        limparBuffer();
        
        
        switch (executar_T){
            case 1:
                cadastro_Tecnico();
                break;

            case 2:
                pesquisar_Tecnico();
                break;

            case 3:
                atualizar_Tecnico();
                break;

            case 4:
                excluir_Tecnico();
                break;

            case 0:
                break;
                
            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                pausar();
                break;
            }
    } while (executar_T != 0);
}
