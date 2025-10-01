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
        printf("║                MODULO TÉCNICO                    ║\n");
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
    FILE *arq_tecnicos;
    char cpf[20];   
    char nome[50];
    char funcao[16];
    char email[40];
    char telefone[16];
    
    char titulo[19] = "CADASTRAR TECNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TECNICO: ");  //** Deixarei assim por enquanto, sem validação
    ler_string(cpf, 20);

    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME DO TECNICO: ");
    ler_string(nome, 50);

    printf("-----------------------------------\n");
    printf("|  INSIRA A FUNÇÃO DO TECNICO: ");
    ler_string(funcao, 16);

    printf("-----------------------------------\n");
    printf("|  INSIRA O EMAIL DO TECNICO: ");
    ler_string(email, 40);
    printf("-----------------------------------\n");//
    
    printf("|  INSIRA O TELEFONE: ");
    ler_string(telefone, 16);
    printf("-----------------------------------\n");

    arq_tecnicos = fopen("tecnicos.csv", "at");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }
    fprintf(arq_tecnicos, "%s;%s;%s;%s;%s\n", cpf, nome, funcao, email, telefone);
    fclose(arq_tecnicos);
    printf("Técnico cadastrado com sucesso!\n");
    pausar();
}



void atualizar_Tecnico(){

    char cpf [15];
    char cpf_lido[15];
    char nome[50];
    char funcao[16];
    char email[40];
    char telefone[16];
    FILE *arq_tecnicos;
    FILE *arq_temptecnicos;
    int encontrado = 0;
    
    arq_tecnicos = fopen("tecnicos.csv", "rt");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }
    arq_temptecnicos = fopen("tecnicostemp.csv", "wt");
    if (arq_temptecnicos == NULL) {
        printf("Erro ao abrir o arquivo temporario de tecnicos.\n");
        fclose(arq_tecnicos);
        limparBuffer();
        return;
    }

    char titulo[19] = "ATUALIZAR TÉCNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TÉCNICO: ");  //** Deixarei assim por enquanto, sem validação
    ler_string(cpf_lido, 15);
    printf("-----------------------------------\n");

    while (fscanf(arq_tecnicos, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n",cpf, nome, funcao, email, telefone) == 5) {
        if (strcmp(cpf, cpf_lido) == 0) {
            encontrado = 1;
            printf("Técnico encontrado. Insira os novos dados:\n");

            printf("-----------------------------------\n");
            printf("|  INSIRA O CPF DO TECNICO: ");
            ler_string(cpf, 15);

            printf("-----------------------------------\n");
            printf("|  INSIRA O NOME DO TECNICO: ");
            ler_string(nome, 50);

            printf("-----------------------------------\n");
            printf("|  INSIRA A FUNÇÃO DO TECNICO: ");
            ler_string(funcao, 16);

            printf("-----------------------------------\n");

            printf("|  INSIRA O EMAIL DO TECNICO: ");
            ler_string(email, 40);
            printf("-----------------------------------\n");

            printf("|  INSIRA O TELEFONE: ");
            ler_string(telefone, 16);
            printf("-----------------------------------\n");

            fprintf(arq_temptecnicos, "%s;%s;%s;%s;%s\n", cpf, nome, funcao, email, telefone);
        } else {
            fprintf(arq_temptecnicos, "%s;%s;%s;%s;%s\n", cpf, nome, funcao, email, telefone);
        }
    }

    fclose(arq_tecnicos);
    fclose(arq_temptecnicos);

    if (!encontrado) {
        printf("Técnico com CPF %s não encontrado.\n", cpf);
        remove("tecnicostemp.csv");
        pausar();
        return;
    } else {
    
        if (remove("tecnicos.csv") != 0) {
            printf("Erro ao remover tecnicos.csv\n");
        }
        if (rename("tecnicostemp.csv", "tecnicos.csv") != 0) {
            printf("Erro ao renomear tecnicostemp.csv\n");
        }
    }

    printf("Técnico atualizado com sucesso!\n");
    pausar();

    // procurar se há esse cpf
    // se sim, para alterar os dados tem que saber quais dados quer alterar
}



void pesquisar_Tecnico(){
    char cpf_lido[15];
    char cpf[15];
    char nome[50];
    char funcao[16];
    char email[40];
    char telefone[16];
    FILE *arq_tecnicos;
    
    char titulo[19] = "PESQUISAR TECNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TÉCNICO: ");  //** Deixarei assim por enquanto, sem validação
    ler_string(cpf_lido, 15);

    arq_tecnicos = fopen("tecnicos.csv", "rt");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }
    while (!feof(arq_tecnicos)) {
        fscanf(arq_tecnicos, "%[^;]" ,cpf);
        fgetc(arq_tecnicos);
        fscanf(arq_tecnicos, "%[^;]", nome);
        fgetc(arq_tecnicos);
        fscanf(arq_tecnicos, "%[^;]", funcao);
        fgetc(arq_tecnicos);
        fscanf(arq_tecnicos, "%[^;]", email);
        fgetc(arq_tecnicos);
        fscanf(arq_tecnicos, "%[^\n]", telefone);
        fgetc(arq_tecnicos);
        if (strcmp(cpf, cpf_lido) == 0) {
            printf("\tTécnico encontrado:\n");
            printf("\tCPF: %s\n", cpf);
            printf("\tNome: %s\n", nome);
            printf("\tFunção: %s\n", funcao);
            printf("\tEmail: %s\n", email);
            printf("\tTelefone: %s\n", telefone);
            pausar();
            fclose(arq_tecnicos);
            return;
        }
    }
    printf("Técnico não encontrado.\n");
    pausar();


}



void excluir_Tecnico(){

    FILE *arq_tecnicos;
    FILE *arq_temptecnicos;
    int encontrado = 0; 
    char cpf_lido[15];
    char cpf[15];
    char nome[50];
    char funcao[16];
    char email[40];
    char telefone[16];

    arq_tecnicos = fopen("tecnicos.csv", "rt");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }

    arq_temptecnicos = fopen("tecnicostemp.csv", "wt");
    if (arq_temptecnicos == NULL) {
        printf("Erro ao abrir o arquivo temporario de tecnicos.\n");
        fclose(arq_tecnicos);
        limparBuffer();
        return;
    }



    char titulo[19] = "EXCLUIR TÉCNICO";
    func_Ani_Left(titulo);
    printf("\n \n");

    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TÉCNICO: ");  
    ler_string(cpf_lido, 15);
    printf("-----------------------------------\n");

    while (fscanf(arq_tecnicos, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n",cpf, nome, funcao, email, telefone) == 5) {
        if (strcmp(cpf, cpf_lido) != 0) {
            fprintf(arq_temptecnicos, "%s;%s;%s;%s;%s\n", cpf, nome, funcao, email, telefone);
        } else {
            encontrado = 1;
        }
    }
    fclose(arq_tecnicos);
    fclose(arq_temptecnicos);

    if (!encontrado) {
        printf("Técnico com CPF %s não encontrado.\n", cpf_lido);
        remove("tecnicostemp.csv");
        pausar();
        return;
    } else {
        printf("Técnico com CPF %s encontrado e excluido.\n", cpf_lido);
    
        if (remove("tecnicos.csv") != 0) {
            printf("Erro ao remover tecnicos.csv\n");
        }
        if (rename("tecnicostemp.csv", "tecnicos.csv") != 0) {
            printf("Erro ao renomear tecnicostemp.csv\n");
        }
    }

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
