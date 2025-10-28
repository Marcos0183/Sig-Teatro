#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"
#include "anima.h"
#include "utils.h"
#include "leitura.h"
#define true 1
#define false 0


int tempo_cliente = 100;

void menu_cliente(){
    limparTela();
        printf("╔══════════════════════════════════════════════════╗\n");
        func_Ani(tempo_cliente);
        printf("║                MODULO CLIENTE                    ║\n");
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
        printf("║                                                  ║\n");
        func_Ani(tempo_cliente);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_cliente);
        printf("║ ► 0. Voltar ao Menu principal                    ║\n");
        func_Ani(tempo_cliente);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_cliente);
        printf("--> Digite a opção desejada: ");
}   



void exibir_cliente(Cliente* clt) {
    
    printf("\n+---------------------------------------------------------------+\n");
    printf("|                     DADOS DO CLIENTE                          |\n");
    printf("+---------------------------------------------------------------+\n");   
    printf("| CPF      : %-50s |\n", clt->cpf);
    printf("| Nome     : %-50s |\n", clt->nome);
    printf("| E-mail   : %-50s |\n", clt->email);
    printf("| Telefone : %-50s |\n", clt->telefone);
    printf("+---------------------------------------------------------------+\n");
}



int cpf_existente(char *cpf) {
    Cliente* clt;
    FILE *arq_clientes;
    clt = (Cliente*) malloc(sizeof(Cliente));
    if (clt == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return false;
    }

    arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        free(clt);
        return true;
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {        // Percorre o arquivo de clientes
        if ((strcmp(clt->cpf, cpf) == 0) && (clt->status == true)) {   // Compara o CPF lido com o CPF do cliente atual
            printf("======================================================\n");
            printf("CPF já cadastrado. Por favor, insira um CPF diferente.\n");
            printf("operação cancelada.\n");
            printf("======================================================\n");  
            fclose(arq_clientes);
            free(clt);
            return false;
        }
    } 

    fclose(arq_clientes);
    free(clt);
    return true;
}
  


void cadastrar_cliente() { 
    char confirm;
    Cliente* clt = (Cliente*) malloc(sizeof(Cliente));
    char titulo[19] = "CADASTRAR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");

    ler_cpf(clt->cpf);
     if (!cpf_existente(clt->cpf)) {               // Lê o CPF e verifica duplicidade antes de continuar                                   // CPF já existe → cancelar operação
         free(clt);                                // Libera memória alocada para o cliente
         pausar();
         return;
     }

    ler_nome(clt->nome);  
    ler_email(clt->email);
    ler_telefone(clt->telefone);
    clt->status = true;

    FILE *arq_clientes = fopen("clientes.dat", "ab");              // Abre o arquivo em modo anexar (append)
    if (arq_clientes == NULL) {
        free(clt);
        return;
    }

    fwrite(clt, sizeof(Cliente), 1, arq_clientes);

    limparTela();
    exibir_cliente(clt);
    printf("os dados do cliente estão corretos? (S/N): ");
    scanf(" %c", &confirm);
    limparBuffer();
    if (confirm == 'n' || confirm == 'N') {
        printf("\n Operação de cadastro cancelada pelo usuário.\n");
        fclose(arq_clientes);
        free(clt);
        pausar();
        return;
    }

    printf("\n Cliente cadastrado com sucesso!\n");

    fclose(arq_clientes);
    free(clt);
    pausar();
}



void atualizar_cliente(){

    Cliente* clt;
    char cpf_lido1[15];
    FILE *arq_clientes;
    int encontrado = 0;
    clt = (Cliente*) malloc(sizeof(Cliente));
    if (clt == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return;
    }   

    
        
    char titulo[19] = "ATUALIZAR CLIENTE";
    func_Ani_Left(titulo);

    printf("\n \n");
    ler_cpf(cpf_lido1);
    printf("-----------------------------------\n");

    arq_clientes = fopen("clientes.dat", "r+b");                          // Abre o arquivo em modo leitura e escrita
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
       
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1 && (!encontrado)) {        // Percorre o arquivo de clientes
        if (strcmp(clt->cpf, cpf_lido1) == 0) {                                         // Compara o CPF lido com o CPF do cliente atual
            encontrado = 1;

            printf("Cliente encontrado. Insira os novos dados:\n");

            ler_nome(clt->nome);
            ler_email(clt->email);
            ler_telefone(clt->telefone);
            clt->status = true;

            fseek(arq_clientes, -sizeof(Cliente), SEEK_CUR);
            fwrite(clt, sizeof(Cliente), 1, arq_clientes);

        } 
    }

   
   limparTela(); 
    exibir_cliente(clt);
    fclose(arq_clientes);
    free(clt);


    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf_lido1);
        pausar();
        return;
    }  
    printf("Cliente com CPF %s atualizado com sucesso.\n", cpf_lido1);
    pausar();
}



void pesquisar_cliente(){
    char cpf_lido[20];
    Cliente* clt;
    FILE *arq_clientes;
    clt = (Cliente*) malloc(sizeof(Cliente));
    if (clt == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return;
    }

    char titulo[19] = "PESQUISAR CLIENTE";
    func_Ani_Left(titulo);

    printf("\n \n");
    ler_cpf(cpf_lido);
    printf("-----------------------------------\n");

    arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if ((strcmp(clt->cpf, cpf_lido) == 0) && (clt->status == true)) {
            limparTela();
            exibir_cliente(clt);
            fclose(arq_clientes);
            free(clt);
            pausar();
            return;
        }
    } 

}



void excluir_cliente() {
    Cliente* clt;
    int encontrado = 0;
    FILE *arq_clientes;
    char cpf_lido[15];
    char confirm;
    clt = (Cliente*) malloc(sizeof(Cliente));
    if (clt == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return;
    }

    char titulo[19] = "EXCLUIR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");

    ler_cpf(cpf_lido);
    printf("-----------------------------------\n");

    arq_clientes = fopen("clientes.dat", "r+b");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        free(clt);
        return;
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1 && (!encontrado)) {
        if ((strcmp(clt->cpf, cpf_lido) == 0) && (clt->status == true)) {
            limparTela();
            exibir_cliente(clt);
            printf("Tem certeza que deseja excluir este técnico? (s/n): ");
            scanf(" %c", &confirm);                                             
            limparBuffer();
            if (confirm == 's' || confirm == 'S') {                               // Confirmação de exclusão
                encontrado = 1;
                clt->status = false;
                fseek(arq_clientes, -sizeof(Cliente), SEEK_CUR);                 // Move o ponteiro de arquivo de volta para o início do registro do cliente
                fwrite(clt, sizeof(Cliente), 1, arq_clientes);                   // Atualiza o registro do cliente no arquivo
                printf("Técnico com CPF %s encontrado e excluido.\n", cpf_lido);
            } else {                                                             // Cancelamento da exclusão
                printf("Operação de exclusão cancelada.\n");
                fclose(arq_clientes);
                free(clt);
                pausar();
                return;
            }
        }
    
    }
    fclose(arq_clientes);
    free(clt);

    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf_lido);
    }

    pausar();

}

    

void listar_cliente() {

    Cliente *clt = (Cliente*) malloc(sizeof(Cliente));
    FILE *arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return; 
    }
    
    char titulo[16] = "LISTAR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (clt -> status == true) {
            exibir_cliente(clt);
        }
    }
    fclose(arq_clientes);
    free(clt);
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