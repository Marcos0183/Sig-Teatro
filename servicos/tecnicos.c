#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tecnicos.h"
#include "anima.h"
#include "utils.h"
#include "leitura.h"
#define true 1
#define false 0

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
        printf("║ ► 5. Listar Técnico                              ║\n");
        func_Ani(tempo_Tecnicos);
        printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
        func_Ani(tempo_Tecnicos);
        printf("║                                                  ║\n");
        func_Ani(tempo_Tecnicos);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_Tecnicos);
        printf("--> Digite a opção desejada: ");
}



void exibir_tecnico(Tecnico* tec) {
    
    printf("\n+-----------------------------------+\n");
    printf("|         DADOS DO TÉCNICO          |\n");
    printf("+-----------------------------------+\n");
    printf("| CPF      : %-50s |\n", tec->cpf);
    printf("| Nome     : %-50s |\n", tec->nome);
    printf("| Função   : %-50s |\n", tec->funcao);
    printf("| E-mail   : %-50s |\n", tec->email);
    printf("| Telefone : %-50s |\n", tec->telefone);
    printf("+-----------------------------------+\n");

}  

    

void cadastro_Tecnico() {
    FILE *arq_tecnicos;
    Tecnico* tec;
    tec = (Tecnico*) malloc(sizeof(Tecnico));
    if (tec == NULL) {
        printf("Erro ao alocar memoria para o tecnico.\n");
        return;
    }

    
    
    char titulo[19] = "CADASTRAR TECNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    ler_cpf(tec->cpf);
    
    ler_nome(tec->nome);

    printf("-----------------------------------\n");
    printf("|  INSIRA A FUNÇÃO DO TECNICO: ");
    ler_string(tec->funcao, 16);

    ler_email(tec->email);
    
    ler_cpf(tec->cpf);

    tec->status = true; 

    arq_tecnicos = fopen("tecnicos.dat", "ab");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }
    fwrite(tec, sizeof(Tecnico), 1, arq_tecnicos);
    fclose(arq_tecnicos);
    free(tec);
    printf("Técnico cadastrado com sucesso!\n");
    pausar();
}



void atualizar_Tecnico() {

    Tecnico* tec;
    tec = (Tecnico*) malloc(sizeof(Tecnico));
    char cpf_lido[15];
    FILE *arq_tecnicos;
    int encontrado = 0;
    
    

    char titulo[19] = "ATUALIZAR TÉCNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TÉCNICO: ");  //** Deixarei assim por enquanto, sem validação
    ler_string(cpf_lido, 15);
    printf("-----------------------------------\n");

    arq_tecnicos = fopen("tecnicos.dat", "r+b");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }

    while (fread(tec, sizeof(Tecnico) , 1, arq_tecnicos)==1 && (!encontrado)) {  
        if ((strcmp(tec->cpf, cpf_lido) == 0) && (tec->status == true)) {
            encontrado = 1;
            printf("Técnico encontrado. Insira os novos dados:\n");

            printf("-----------------------------------\n");
            printf("|  INSIRA O CPF DO TECNICO: ");
            ler_string(tec->cpf, 15);

            printf("-----------------------------------\n");
            printf("|  INSIRA O NOME DO TECNICO: ");
            ler_string(tec->nome, 50);

            printf("-----------------------------------\n");
            printf("|  INSIRA A FUNÇÃO DO TECNICO: ");
            ler_string(tec->funcao, 16);

            printf("-----------------------------------\n");

            printf("|  INSIRA O EMAIL DO TECNICO: ");
            ler_string(tec->email, 40);

            printf("-----------------------------------\n");
            printf("|  INSIRA O TELEFONE: ");
            ler_string(tec->telefone, 16);
            printf("-----------------------------------\n");

            tec->status = true;
            fseek(arq_tecnicos, -sizeof(Tecnico), SEEK_CUR);
            fwrite(tec, sizeof(Tecnico), 1, arq_tecnicos);
        }
    }


    fclose(arq_tecnicos);

    if (!encontrado) {
        printf("Técnico com CPF %s não encontrado.\n", cpf_lido);
        remove("tecnicostemp.csv");
        pausar();
        return;
    }

    printf("Técnico atualizado com sucesso!\n");
    pausar();

    // procurar se há esse cpf
    // se sim, para alterar os dados tem que saber quais dados quer alterar
}



void pesquisar_Tecnico(){
    Tecnico* tec;
    char cpf_lido[15];
    int encontrado = 0;
    FILE *arq_tecnicos;
    tec = (Tecnico*) malloc(sizeof(Tecnico));
    if (tec == NULL) { 
        printf("Erro ao alocar memoria para o tecnico.\n");
        return;
    }
    
    char titulo[19] = "PESQUISAR TECNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TÉCNICO: ");  //** Deixarei assim por enquanto, sem validação
    ler_string(cpf_lido, 15);
    printf("-----------------------------------\n");

    arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }
    while ((fread(tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) && (!encontrado)) {
        if ((strcmp(tec->cpf, cpf_lido) == 0) && (tec->status == true)) {
            printf("Técnico encontrado:\n");
            printf("CPF: %s\n", tec->cpf);
            printf("Nome: %s\n", tec->nome);
            printf("Função: %s\n", tec->funcao);
            printf("Email: %s\n", tec->email);
            printf("Telefone: %s\n", tec->telefone);
            printf("--------------------------------\n");
            pausar();
            encontrado = 1;
        }
    }
    fclose(arq_tecnicos);
    free(tec);

    if (!encontrado)        {
    printf("\tTécnico não encontrado.\n");
    pausar();
    return;
    }


}



void excluir_Tecnico(){
    
    Tecnico* tec;
    tec = (Tecnico*) malloc(sizeof(Tecnico));
    FILE *arq_tecnicos;
    int encontrado = 0; 
    char cpf_lido[15];
    char confirm;
    

    char titulo[19] = "EXCLUIR TÉCNICO";
    func_Ani_Left(titulo);
    printf("\n \n");

    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO TÉCNICO: ");  
    ler_string(cpf_lido, 15);
    printf("-----------------------------------\n");

    arq_tecnicos = fopen("tecnicos.dat", "r+b");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }

    while (fread(tec, sizeof(Tecnico) , 1, arq_tecnicos)==1 && (!encontrado)) {  
        if ((strcmp(tec->cpf, cpf_lido) == 0) && (tec->status == true)) {
            exibir_tecnico(tec);
            printf("Tem certeza que deseja excluir este técnico? (s/n): ");
            scanf(" %c", &confirm);
            limparBuffer();
            if (confirm == 's' || confirm == 'S') {
                encontrado = 1;
                tec->status = false;
                fseek(arq_tecnicos, -sizeof(Tecnico), SEEK_CUR);
                fwrite(tec, sizeof(Tecnico), 1, arq_tecnicos);
                printf("Técnico com CPF %s encontrado e excluido.\n", cpf_lido);
            } else {
                printf("Operação de exclusão cancelada.\n");
                fclose(arq_tecnicos);
                free(tec);
                pausar();
                return;
            }
        }        
    }

    fclose(arq_tecnicos);
    

    if (!encontrado) {
        printf("Técnico com CPF %s não encontrado.\n", cpf_lido);
        pausar();
        return;
    }

    pausar();
    
}



void listar_tecnicos() {
    FILE *arq_tecnicos;
    Tecnico* tec;
    tec = (Tecnico*) malloc(sizeof(Tecnico));
    if (tec == NULL) {
        printf("Erro ao alocar memoria para o tecnico.\n");
        return;
    }
    arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }
    char titulo[16] = "LISTAR TECNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    while (fread(tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) {
        if (tec -> status == true) {
        printf("CPF: %s\n", tec->cpf);
        printf("Nome: %s\n", tec->nome);
        printf("Função: %s\n", tec->funcao);
        printf("Email: %s\n", tec->email);
        printf("Telefone: %s\n", tec->telefone);
        printf("-------------------------\n");
        }
    }
    fclose(arq_tecnicos);
    free(tec);
    
    pausar();
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

            case 5:
                listar_tecnicos();
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
