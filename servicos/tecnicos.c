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
        printf("║                                                  ║\n");
        func_Ani(tempo_Tecnicos);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_Tecnicos);
        printf("║ ► 0. Voltar ao Menu principal                    ║\n");
        func_Ani(tempo_Tecnicos);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_Tecnicos);
        printf("--> Digite a opção desejada: ");
}



void exibir_tecnico(Tecnico* tec) {
    
    printf("\n+---------------------------------------------------------------+\n");
    printf("|                     DADOS DO TÉCNICO                          |\n");
    printf("+---------------------------------------------------------------+\n");   
    printf("| CPF      : %-50s |\n", tec->cpf);
    printf("| Nome     : %-50s |\n", tec->nome);
    printf("| Função   : %-50s |\n", tec->funcao);
    printf("| E-mail   : %-50s |\n", tec->email);
    printf("| Telefone : %-50s |\n", tec->telefone);
    printf("+---------------------------------------------------------------+\n");

}  

    

int cpf_existente_tec(char *cpf) {
    Tecnico* tec;
    FILE *arq_clientes;
    tec = (Tecnico*) malloc(sizeof(Tecnico));
    if (tec == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return false;
    }

    arq_clientes = fopen("tecnicos.dat", "rb");
    if (arq_clientes == NULL) {
        free(tec);
        return true;
    }

    while (fread(tec, sizeof(Tecnico), 1, arq_clientes) == 1) {                 // Percorre todos os técnicos cadastrados
        if ((strcmp(tec->cpf, cpf) == 0) && (tec->status == true)) {            // Verifica se o CPF já existe
            printf("======================================================\n");
            printf("CPF já cadastrado. Por favor, insira um CPF diferente.\n");
            printf("operação cancelada.\n");
            printf("======================================================\n");
            fclose(arq_clientes);
            free(tec);
            return false;
        }
    } 

    fclose(arq_clientes);
    free(tec);
    return true;
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
    if (!cpf_existente_tec(tec->cpf)) {         // CPF já existe → cancelar operação
        free(tec);
        pausar();
        return;
    }

    ler_nome(tec->nome);
    ler_funcao(tec->funcao);
    ler_email(tec->email);
    ler_telefone(tec->telefone);

    tec->status = true; 

    arq_tecnicos = fopen("tecnicos.dat", "ab");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }
    exibir_tecnico(tec);
    printf("Técnico cadastrado com sucesso!\n");
    fwrite(tec, sizeof(Tecnico), 1, arq_tecnicos);
    fclose(arq_tecnicos);
    free(tec);
    pausar();
}



void atualizar_Tecnico() {
    char confirm;
    Tecnico* tec;
    tec = (Tecnico*) malloc(sizeof(Tecnico));
    char cpf_lido[15];
    FILE *arq_tecnicos;
    int encontrado = 0;
    
    

    char titulo[19] = "ATUALIZAR TÉCNICO";
    func_Ani_Left(titulo);
    printf("\n \n");
    
    ler_cpf(cpf_lido);

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
            
            printf("Insira os novos dados do técnico:\n");
            
            ler_nome(tec->nome);
            ler_funcao(tec->funcao);
            ler_email(tec->email);
            ler_telefone(tec->telefone);
            tec->status = true;

            fseek(arq_tecnicos, -sizeof(Tecnico), SEEK_CUR);
            fwrite(tec, sizeof(Tecnico), 1, arq_tecnicos);
        }
    }
    limparTela();
    exibir_tecnico(tec);
    printf("os dados do tecnico estão corretos? (s/n): ");
    scanf(" %c", &confirm);
    limparBuffer();
    if (confirm == 'n' || confirm == 'N') {
        printf("Operação de atualização cancelada.\n");
        fclose(arq_tecnicos);
        free(tec);
        pausar();
        return;
    }

    fclose(arq_tecnicos);
    free(tec);

    if (!encontrado) {
        printf("Técnico com CPF %s não encontrado.\n", cpf_lido);
        return;
    }

    printf("Técnico atualizado com sucesso!\n");
    pausar();

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
    
    ler_cpf(cpf_lido);
    printf("-----------------------------------\n");

    arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de tecnicos.\n");
        limparBuffer();
        return;   
    }
    while ((fread(tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) && (!encontrado)) {
        if ((strcmp(tec->cpf, cpf_lido) == 0) && (tec->status == true)) {
            exibir_tecnico(tec);
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

    
    ler_cpf(cpf_lido);
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
            exibir_tecnico(tec);
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
