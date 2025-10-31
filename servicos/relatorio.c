#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"
#include "anima.h"
#include "utils.h"
#include "tecnicos.h"
#include "leitura.h"
#define true 1
#define false 0

int tempo_relatorio = 100;

void menu_relatorio(){
    limparTela();
        printf("╔══════════════════════════════════════════════════╗\n");
        func_Ani(tempo_relatorio);
        printf("║               MODULO RELATÓRIO                   ║\n");
        func_Ani(tempo_relatorio);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_relatorio);
        printf("║                                                  ║\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 1. relatorio clientes                          ║\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 2. relatorio Técnicos                          ║\n");
        func_Ani(tempo_relatorio);
        printf("║                                                  ║\n");
        func_Ani(tempo_relatorio);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 0. Voltar ao Menu principal                    ║\n");
        func_Ani(tempo_relatorio);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_relatorio);
        printf("--> Digite a opção desejada: ");
}



void listar_clientes_ativos() {
    limparTela();
    char titulo[28] = "LISTANDO CLIENTES ATIVOS";
    func_Ani_Left(titulo);
    printf("\n \n");
    Cliente* clt = (Cliente*) malloc(sizeof(Cliente));
    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (clt -> status == true) {
            exibir_cliente(clt);
        }
    }
    fclose(arq_clientes);
    free(clt);
    pausar();
}



void listar_clientes_inativos() {
    limparTela();
    char titulo[30] = "LISTANDO CLIENTES INATIVOS";
    func_Ani_Left(titulo);
    printf("\n \n");
    Cliente* clt = (Cliente*) malloc(sizeof(Cliente));
    FILE *arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (clt -> status == false) {
            exibir_cliente(clt);
        }
    }
    fclose(arq_clientes);
    free(clt);
    pausar();
}



void listar_clientes_por_nome() {

    limparTela();
    char nome_busca[50];
    char titulo[30] = "LISTANDO CLIENTES POR NOME";
    func_Ani_Left(titulo);
    printf("\n \n");
    Cliente* clt = (Cliente*) malloc(sizeof(Cliente));

    ler_nome(nome_busca);
    limparTela();

    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (strstr(clt->nome, nome_busca) != NULL) {
            exibir_cliente(clt);
        }
    }
    fclose(arq_clientes);
    free(clt);
    pausar();
}



void listar_todos_clientes() {
    limparTela();
    char titulo[28] = "LISTANDO TODOS OS CLIENTES";
    func_Ani_Left(titulo);
    printf("\n \n");
    Cliente* clt = (Cliente*) malloc(sizeof(Cliente));
    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        exibir_cliente(clt);
    }
    fclose(arq_clientes);
    free(clt);
    pausar();
}



void relatorio_cliente(){ 
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE CLIENTES              ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 1. Listar Clientes ativos                      ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 2. Listar Clientes inativos                    ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 3. Listar clientes por nome                    ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 4. listar todos os clientes                    ║\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 0. Voltar ao Menu Relatórios                   ║\n");
    func_Ani(tempo_relatorio);
    printf("╚══════════════════════════════════════════════════╝\n");
    func_Ani(tempo_relatorio);
    printf("--> Digite a opção desejada: ");
}



void listar_tecnicos_ativos() {
    limparTela();
    printf("Listando técnicos ativos...\n");
    // Aqui você pode adicionar o código para listar os técnicos ativos
    pausar();
}



void listar_tecnicos_inativos() {
    limparTela();
    printf("Listando técnicos inativos...\n");
    // Aqui você pode adicionar o código para listar os técnicos inativos
    pausar();
}



void listar_tecnicos_por_nome() {
    limparTela();
    printf("Listando técnicos por nome...\n");
    // Aqui você pode adicionar o código para listar os técnicos por nome
    pausar();
}



void listar_todos_tecnicos() {
    limparTela();
    printf("Listando todos os técnicos...\n");
    // Aqui você pode adicionar o código para listar todos os técnicos
    pausar();
}



void relatorio_tecnico(){ 
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE TÉCNICOS              ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 1. Listar Técnicos ativos                      ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 2. Listar Técnicos inativos                    ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 3. Listar Técnicos por nome                    ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 4. listar todos os Técnicos                    ║\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 0. Voltar ao Menu Relatórios                   ║\n");
    func_Ani(tempo_relatorio);
    printf("╚══════════════════════════════════════════════════╝\n");
    func_Ani(tempo_relatorio);
    printf("--> Digite a opção desejada: ");
}



void relatorio() {
    int executar_R;
    int opcao_tecnico;
    int opcao_cliente;

    do {
        menu_relatorio();
        scanf("%d", &executar_R);
        limparBuffer();

        switch (executar_R) {
            case 1:
                do {
                    relatorio_cliente();
                    scanf("%d", &opcao_cliente);
                    limparBuffer();
                    switch (opcao_cliente) {
                        case 1:
                            listar_clientes_ativos();
                            break;
                        case 2:
                            listar_clientes_inativos();
                            break;
                        case 3:
                            listar_clientes_por_nome();
                            break;
                        case 4:
                            listar_todos_clientes();
                            break;
                        case 0:
                            break;
                    }
                } while (opcao_cliente != 0);
                break;

            case 2:
                do {
                    relatorio_tecnico();
                    scanf("%d", &opcao_tecnico);
                    limparBuffer();
                    switch (opcao_tecnico) {
                        case 1:
                            listar_tecnicos_ativos();
                            break;
                        case 2:
                            listar_tecnicos_inativos();
                            break;
                        case 3:
                            listar_tecnicos_por_nome();
                            break;
                        case 4:
                            listar_todos_tecnicos();
                            break;
                        case 0:
                            break; 
                    }
                } while (opcao_tecnico != 0);
                break;

            case 0:
                break;

            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                pausar();
                break;
        }
    } while (executar_R != 0);
}