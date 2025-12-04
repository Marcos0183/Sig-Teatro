#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "anima.h"
#include "ingresso.h"
#include "tecnicos.h"
#include "shows.h"
#include "clientes.h"
#include "utils.h"  
#include "relatorio.h"

int banner_mostrado = 0;
int tempo_Main = 100;


void menu_Principal() {
    limparTela();
    printf("\n");
    func_Ani(tempo_Main);
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_Main);
    printf("║             SISTEMA DE TEATRO                    ║\n");
    func_Ani(tempo_Main);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_Main);
    printf("║                                                  ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 1. Módulo Clientes                             ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 2. Módulo Ingressos                            ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 3. Módulo Espetáculos (Shows/Peças)            ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 4. Módulo Técnicos                             ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 5. Módulo Relatórios                           ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 6. Sobre o SIG-THEATER                         ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 7. Equipe SIG-THEATER                          ║\n");
    func_Ani(tempo_Main);
    printf("║                                                  ║\n");
    func_Ani(tempo_Main);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_Main);
    printf("║ ► 0. Encerrar o Programa                         ║\n");
    func_Ani(tempo_Main);
    printf("╚══════════════════════════════════════════════════╝\n");
    func_Ani(tempo_Main);
    printf("--> Digite a opção desejada: ");

}


void equipe(){
    limparTela();
    printf("\n \n");
    int tempo_Eq = 50;
    // Desenha a letra U 
    printf("     _   _ \n");
    func_Ani(tempo_Eq);
    printf("    | | | |\n");
    func_Ani(tempo_Eq);
    printf("    | | | |\n");
    func_Ani(tempo_Eq);
    printf("    | | | |\n");
    func_Ani(tempo_Eq);
    printf("    | |_| |\n");
    func_Ani(tempo_Eq);
    printf("     \\___/ \n");
    func_Ani(tempo_Eq);
    printf("           \n");
    func_Ani(tempo_Eq);

    printf("    ______ \n");
    func_Ani(tempo_Eq);
    printf("    |  ___|\n");
    func_Ani(tempo_Eq);
    printf("    | |_   \n");
    func_Ani(tempo_Eq);
    printf("    |  _|  \n");
    func_Ani(tempo_Eq);
    printf("    | |    \n");
    func_Ani(tempo_Eq);
    printf("    \\_|    \n");
    func_Ani(tempo_Eq);
    printf("           \n");
    func_Ani(tempo_Eq);

    printf("    ______ \n");
    func_Ani(tempo_Eq);
    printf("    | ___ \\\n");
    func_Ani(tempo_Eq);
    printf("    | |_/ /\n");
    func_Ani(tempo_Eq);
    printf("    |    / \n");
    func_Ani(tempo_Eq);
    printf("    | |\\ \\ \n");
    func_Ani(tempo_Eq);
    printf("    \\_| \\_|\n");
    func_Ani(tempo_Eq);
    printf("           \n");
    func_Ani(tempo_Eq);

    printf("     _   _ \n");
    func_Ani(tempo_Eq);
    printf("    | \\ | |\n");
    func_Ani(tempo_Eq);
    printf("    |  \\| |\n");
    func_Ani(tempo_Eq);
    printf("    | . ` |\n");
    func_Ani(tempo_Eq);
    printf("    | |\\  |\n");
    func_Ani(tempo_Eq);
    printf("    \\_| \\_/\n");
    func_Ani(tempo_Eq);


    printf("\n \n");
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    func_Ani(tempo_Eq);
    printf("║             Universidade Federal do Rio Grande do Norte                 ║\n");
    func_Ani(tempo_Eq);
    printf("║                 Disciplina DCT1106 -- Programacao                       ║\n");
    func_Ani(tempo_Eq);
    printf("║                   Professor: Flavius Gorgonio                           ║\n");
    func_Ani(tempo_Eq);
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
    func_Ani(tempo_Eq);
    printf("║               Sistema de Gestao de Teatro (SIG-THEATER)                 ║\n");
    func_Ani(tempo_Eq);
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
    func_Ani(tempo_Eq);
    printf("\n");
    printf("║             Projeto desenvolvido por:                                   ║\n");
    func_Ani(tempo_Eq);
    printf("║             Aluno 1: Emilly Elidia Andrade Macedo dos Santos            ║\n");
    func_Ani(tempo_Eq);
    printf("║             Aluno 2: Marcos Vinícius Dantas da Silva                    ║\n");
    func_Ani(tempo_Eq);
    printf("║             Aluno 3: Felipe Eduardo Silva Fernandes                     ║\n");
    func_Ani(tempo_Eq);
    printf("║             Aluno 4: Andriel Pereira Nogueira                           ║\n");
    func_Ani(tempo_Eq);
    printf("\n");
    func_Ani(tempo_Eq);
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
    func_Ani(tempo_Eq);
    pausar();
    printf("\n \n \n");
}


void proj_Descrit(){
    limparTela();
    printf("\n \n");
    printf("╔═══════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                   Universidade Federal do Rio Grande do Norte                           ║\n");
    printf("║                        Disciplina DCT1106 -- Programacao                                ║\n");
    printf("║                           Professor: Flavius Gorgonio                                   ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║   O Sistema de Gestao Teatral (SIG-THEATER) é um projeto para a disciplina de           ║\n");
    printf("║   Programação. O objetivo é gerenciar as operações de um teatro, como o cadastro        ║\n");
    printf("║   de clientes, técnicos e espetáculos, além da venda de ingressos e geração de          ║\n");
    printf("║   relatórios.                                                                           ║\n");
    printf("║                                                                                         ║\n");
    printf("║   A linguagem de programação utilizada é o C, restringindo-se apenas às suas            ║\n");
    printf("║   bibliotecas padrões.                                                                  ║\n");
    printf("║                                                                                         ║\n");
    printf("║   Módulos: Clientes, Ingressos, Shows, Técnicos e Relatórios.                           ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════════════╝\n");
    pausar();
    printf("\n \n");
}


int main(void) {
    int executar;
 
    do {
        limparTela();
        if (!banner_mostrado) {
            mostrar_banner();
            func_Ani(2);
            limparTela();
            banner_mostrado = 1; 
        }

        menu_Principal();
        
        scanf("%d", &executar);
        getchar();

        switch (executar) {
            case 1:
                cliente();
                break;

            case 2:
                ingresso();
                break;

            case 3:
                shows();
                break;

            case 4:
                tecnicos();
                break;

            case 5:
                relatorio();
                break;

            case 6:
                proj_Descrit();
                break;

            case 7:
                equipe();
                break;

            case 0:
                break;

            default:
                printf("\n \n");
                printf("Valor inválido! Digite uma das opções acima.\n");
                pausar();
                break;
        }
    } while (executar != 0);

    ani_Encerrar();
    return 0;            
} 


                                                                                                                                                                                                                                                                                                                                                                                        