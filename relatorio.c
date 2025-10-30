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
        printf("║ ► 1. Listar Clientes                             ║\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 2. Listar Técnicos                             ║\n");
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



void relatorio_cliente(){ 
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE CLIENTES              ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
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



void relatorio_tecnico(){ 
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE TÉCNICOS              ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
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

    do {
        menu_relatorio();
        scanf("%d", &executar_R);
        limparBuffer();

        switch (executar_R) {
            case 1:
                listar_cliente();
                break;
            case 2:
                listar_tecnicos();
                break;

            case 0:
                break;
        }
    } while (executar_R != 0);
}