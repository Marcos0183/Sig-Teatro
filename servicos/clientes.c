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
        printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
        func_Ani(tempo_cliente);
        printf("║                                                  ║\n");
        func_Ani(tempo_cliente);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_cliente);
        printf("--> Digite a opção desejada: ");
}   



void exibir_cliente(Cliente* clt) {
    printf("cpf: %s\n", clt->cpf);
    printf("Nome: %s\n", clt->nome);
    printf("Email: %s\n", clt->email);
    printf("Telefone: %s\n", clt->telefone);
}



void cadastrar_cliente() { 
    
    Cliente *clt;
    FILE *arq_clientes;
    clt = (Cliente*) malloc(sizeof(Cliente));
    
    char titulo[19] = "CADASTRAR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");
    
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");  
    ler_string(clt->cpf, 20);

    
    ler_nome(clt->nome);

    printf("-----------------------------------\n");
    printf("|  INSIRA O EMAIL DO CLIENTE: ");
    ler_string(clt->email, 40);

    printf("-----------------------------------\n");
    printf("|  INSIRA O TELEFONE: ");
    ler_string(clt->telefone, 16);

    printf("-----------------------------------\n");

    clt->status = true;

    arq_clientes = fopen("clientes.dat", "ab");
    if (arq_clientes == NULL) {
        limparBuffer();
        fclose(arq_clientes);
        return;
    }
    fwrite(clt, sizeof(Cliente), 1, arq_clientes);

    exibir_cliente(clt);
    printf("Cliente cadastrado com sucesso!\n");

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
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");
    ler_string(cpf_lido1, 15);
    printf("-----------------------------------\n");

    arq_clientes = fopen("clientes.dat", "r+b");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
       
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1 && (!encontrado)) {
        if (strcmp(clt->cpf, cpf_lido1) == 0) {
            encontrado = 1;

            printf("Cliente encontrado. Insira os novos dados:\n");

            printf("-----------------------------------\n");
            printf("|  INSIRA O CPF DO CLIENTE: ");
            ler_string(clt->cpf, 15);

            printf("-----------------------------------\n");
            printf("|  INSIRA O NOME DO CLIENTE: ");
            ler_string(clt->nome, 50);

            printf("-----------------------------------\n");
            printf("|  INSIRA O EMAIL DO CLIENTE: ");
            ler_string(clt->email, 40);

            printf("-----------------------------------\n");
            printf("|  INSIRA O TELEFONE: ");
            ler_string(clt->telefone, 16);
            printf("-----------------------------------\n");

            clt->status = true;
            fseek(arq_clientes, -sizeof(Cliente), SEEK_CUR);
            fwrite(clt, sizeof(Cliente), 1, arq_clientes);

        } 
    }

   
    

    fclose(arq_clientes);
    free(clt);


    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf_lido1);
        remove("clientestemp.csv");
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
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");
    ler_string(cpf_lido, 20);
    printf("-----------------------------------\n");

    arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    
    }
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if ((strcmp(clt->cpf, cpf_lido) == 0) && (clt->status == true)) {
            printf("Cliente encontrado:\n");
            printf("CPF: %s\n", clt->cpf);
            printf("Nome: %s\n", clt->nome);
            printf("Email: %s\n", clt->email);
            printf("Telefone: %s\n", clt->telefone);
        }
    }

    fclose(arq_clientes);
    free(clt);
    pausar();   

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

    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");  
    ler_string(cpf_lido, 15);
    printf("-----------------------------------\n");

    arq_clientes = fopen("clientes.dat", "r+b");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        free(clt);
        return;
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1 && (!encontrado)) {
        if ((strcmp(clt->cpf, cpf_lido) == 0) && (clt->status == true)) {
            exibir_cliente(clt);
            printf("Tem certeza que deseja excluir este técnico? (s/n): ");
            scanf(" %c", &confirm);
            limparBuffer();
            if (confirm == 's' || confirm == 'S') {
                encontrado = 1;
                clt->status = false;
                fseek(arq_clientes, -sizeof(Cliente), SEEK_CUR);
                fwrite(clt, sizeof(Cliente), 1, arq_clientes);
                printf("Técnico com CPF %s encontrado e excluido.\n", cpf_lido);
            } else {
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

    FILE *arq_clientes;
    Cliente *clt;
    clt = (Cliente*) malloc(sizeof(Cliente));
    arq_clientes = fopen("clientes.dat", "rb");
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
        printf("CPF: %s\n", clt->cpf);
        printf("Nome: %s\n", clt->nome);
        printf("Email: %s\n", clt->email);
        printf("Telefone: %s\n", clt->telefone);
        printf("-------------------------\n");
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