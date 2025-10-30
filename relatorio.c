#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"
#include "anima.h"
#include "utils.h"
#include "clientes.h"
#include "leitura.h"
#define true 1
#define false 0

int tempo_cliente = 100;

void menu_relatorio(){
    limparTela();
        printf("╔══════════════════════════════════════════════════╗\n");
        func_Ani(tempo_cliente);
        printf("║                MODULO RELATÓRIO                  ║\n");
        func_Ani(tempo_cliente);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_cliente);
        printf("║                                                  ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 1. Relatório de Clientes                       ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 2. Relatório de Técnicos                      ║\n");
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
                listar_tecnico();
                break;

            case 0:
                break;
        }
    } while (executar_R != 0);
}