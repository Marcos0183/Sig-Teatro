#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"
#include "anima.h"
#include "utils.h"



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



void cadastrar_cliente(Cliente* clt) { 
    
   
    
    
    FILE *arq_clientes;
    
    char titulo[19] = "CADASTRAR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");
    
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");  
    ler_string(clt->cpf, 20);

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

    arq_clientes = fopen("clientes.csv", "at");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;   
    }
    fprintf(arq_clientes, "%s;%s;%s;%s\n", clt->cpf, clt->nome, clt->email, clt->telefone);
    fclose(arq_clientes);
    printf("Cliente cadastrado com sucesso!\n");
    pausar();
}



void atualizar_cliente(Cliente* clt){
    char cpf_lido1[15];
    FILE *arq_clientes;
    FILE *arq_tempclientes;
    int encontrado = 0;

    arq_clientes = fopen("clientes.csv", "rt");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }

    arq_tempclientes = fopen("clientestemp.csv", "wt");
    if (arq_tempclientes == NULL) {
        printf("Erro ao abrir o arquivo temporario de clientes.\n");
        limparBuffer();
        fclose(arq_clientes);
        return;
    }

        

    char titulo[19] = "ATUALIZAR CLIENTE";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");
    ler_string(cpf_lido1, 15);
    printf("-----------------------------------\n");

    Cliente buffer;

    while (fscanf(arq_clientes, "%[^;];%[^;];%[^;];%[^\n]\n",clt->cpf, clt->nome, clt->email, clt->telefone ) == 4) {
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

            fprintf(arq_tempclientes, "%s;%s;%s;%s\n", clt->cpf, clt->nome, clt->email, clt->telefone);
        } else {
            fprintf(arq_tempclientes, "%s;%s;%s;%s\n", clt->cpf, clt->nome, clt->email, clt->telefone);
        }
    }

   
    

    fclose(arq_clientes);
    fclose(arq_tempclientes);


    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf_lido1);
        remove("clientestemp.csv");
        pausar();
        return;
    } else {
        printf("Cliente com CPF %s atualizado com sucesso.\n", cpf_lido1);
        if (remove("clientes.csv") != 0) {
            printf("Erro ao remover clientes.csv\n");
        }
        if (rename("clientestemp.csv", "clientes.csv") != 0) {
            printf("Erro ao renomear clientestemp.csv\n");
        }  
    }
    pausar();
}



void pesquisar_cliente(){
    char cpf_lido[20];
    Cliente clt;
    FILE *arq_clientes;

    arq_clientes = fopen("clientes.csv", "rt");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;   
    }

    char titulo[19] = "PESQUISAR CLIENTE";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");
    ler_string(cpf_lido, 20);
    printf("-----------------------------------\n");

    while (fscanf(arq_clientes, "%[^;];%[^;];%[^;];%[^\n]\n", clt.cpf, clt.nome, clt.email, clt.telefone) == 4) {    
        if (strcmp(clt.cpf, cpf_lido) == 0) {
            printf("\tCliente encontrado:\n");
            printf("\tCPF: %s\n", clt.cpf); 
            printf("\tNome: %s\n", clt.nome);
            printf("\tEmail: %s\n", clt.email);
            printf("\tTelefone: %s\n", clt.telefone);
            pausar();
            fclose(arq_clientes);
            return;
        }
    }
}



void excluir_cliente(){
    int encontrado = 0;
    FILE *arq_clientes;
    FILE *arq_tempclientes;
    char cpf[15];
    char cpf_lido[15];
    char nome[50];
    char email[40];
    char telefone[16];
    char titulo[19] = "EXCLUIR CLIENTE";
    func_Ani_Left(titulo);

    arq_clientes = fopen("clientes.csv", "rt");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }

    arq_tempclientes = fopen("clientestemp.csv", "wt");
    if (arq_tempclientes == NULL) {
        printf("Erro ao abrir o arquivo temporario de clientes.\n");
        fclose(arq_clientes);
        limparBuffer();
        return;
    }

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CPF DO CLIENTE: ");
    ler_string(cpf_lido, 15);
    printf("-----------------------------------\n");

    while (fscanf(arq_clientes, "%[^;];%[^;];%[^;];%[^\n]\n",cpf, nome, email, telefone) == 4) {
        if (strcmp(cpf, cpf_lido) != 0) {
            fprintf(arq_tempclientes, "%s;%s;%s;%s\n", cpf, nome, email, telefone);
        } else {
            encontrado = 1;
        }
}

fclose(arq_clientes);
fclose(arq_tempclientes);
    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf_lido);
        remove("clientestemp.csv");
        pausar();
        return;
    } else {
        printf("Cliente com CPF %s encontrado e excluido.\n", cpf_lido);
    
        if (remove("clientes.csv") != 0) {
            printf("Erro ao remover clientes.csv\n");
        }
        if (rename("clientestemp.csv", "clientes.csv") != 0) {
            printf("Erro ao renomear clientestemp.csv\n");
        }
    }
     
    printf("Cliente excluido com sucesso!\n");
    pausar();

}

    

    
    





void listar_cliente(){
    char titulo[16] = "LISTAR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("Listando todos os clientes...\n");
    pausar();
}



void cliente(){
    Cliente clt;
    int executar_C;

    do {
        menu_cliente();
        scanf("%d", &executar_C);
        limparBuffer();

        switch (executar_C) {
            case 1:
                cadastrar_cliente(&clt);
                break;
            case 2:
                pesquisar_cliente(clt);
                break;
            case 3:
                atualizar_cliente(&clt);
                break;
            case 4:
                excluir_cliente(&clt);
                break;
            case 5:
                listar_cliente(clt);
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