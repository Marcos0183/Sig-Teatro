#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "anima.h"
#include "ingresso.h"
#include "sessoes.h"
#include "tecnicos.h"
#include "shows.h"
#include "clientes.h"
#include "utils.h"

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
    printf("║ ► 1. Módulo clientes                             ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 2. Módulo Ingressos                            ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 3. Módulo Espetáculos (Shows/Peças)            ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 4. Módulo Sessões                              ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 5. Módulo Técnicos                             ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 6. Módulo Relatórios                           ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 7. sobre o SIG-THEATER                         ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 8. Equipe SIG-THEATER                          ║\n");
    func_Ani(tempo_Main);
    printf("║ ► 0. Encerrar o Programa                         ║\n");
    func_Ani(tempo_Main);
    printf("║                                                  ║\n");
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
    printf("#########################################################################\n");
    func_Ani(tempo_Eq);
    printf("             Universidade Federal do Rio Grande do Norte                 \n");
    func_Ani(tempo_Eq);
    printf("                 Disciplina DCT1106 -- Programacao                       \n");
    func_Ani(tempo_Eq);
    printf("                   Professor: Flavius Gorgonio                           \n");
    func_Ani(tempo_Eq);
    printf("#########################################################################\n");
    func_Ani(tempo_Eq);
    printf("-+-+-+-+-+-+-+-+-+- Sistema de Gestao de Teatro +-+-+-+-+-+-+-+-+-+-+-+-+\n");
    func_Ani(tempo_Eq);
    printf("#########################################################################\n");
    func_Ani(tempo_Eq);
    printf("\n");
    printf("             Projeto desenvolvido por:                                   \n");
    func_Ani(tempo_Eq);
    printf("             Aluno 1: Emilly Elidia Andrade Macedo dos Santos            \n");
    func_Ani(tempo_Eq);
    printf("             Aluno 2: Marcos Vinícius Dantas da Silva                    \n");
    func_Ani(tempo_Eq);
    printf("             Aluno 3: Felipe Eduardo Silva Fernandes                     \n");
    printf("\n");
    func_Ani(tempo_Eq);
    printf("#########################################################################\n");
    func_Ani(tempo_Eq);
    pausar();
    printf("\n \n \n");
}
void proj_Descrit(){
    limparTela();
    printf("\n \n");
    printf("=========================================================================================\n");
    printf("|                   Universidade Federal do Rio Grande do Norte                          |\n");
    printf("|                        Disciplina DCT1106 -- Programacao                               |\n");
    printf("|                           Professor: Flavius Gorgonio                                  |\n");
    printf("|                                                                                        |\n");
    printf("|   O Sistema de Gestao Teatral ou SGT, trata-se codigo produzido para fins pontuacao    |\n");
    printf("|   na disciplina de Programacao administrada pelo Professor Flavius Gorgonio.           |\n");
    printf("|                                                                                        |\n");
    printf("|   A linguagem de programacao utilizada e o C, se restrigindo apenas as suas bibliotecas|\n");
    printf("|   padroes.                                                                             |\n");
    printf("|                                                                                        |\n");
    printf("|   O sistema SGT e um software que gerencia e armazena dados referentes a uma casa de   |\n");
    printf("|   tetro, contanto com 4 modulos: Ingresso, Shows, Sessoes, Tecnicos e Relatorios.      |\n");               
    printf("|                                                                                        |\n");
    printf("|                                                                                        |\n");
    printf("=========================================================================================\n");
    pausar();
    printf("\n \n");
}


int main() {
    int executar;

    
        
    
    do {

        if (!banner_mostrado) {
            mostrar_banner();
            usleep(2000000);
            system("clear");
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
                sessoes();
                break;

            case 5:
                tecnicos();
                break;

            case 6:
                limparTela();
                printf("Módulo Relatórios em construção...\n");
                pausar();
                break;

            case 7:
                proj_Descrit();
                break;

            case 8:
                equipe();
                break;

            case 0:
                break;

            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                pausar();
                break;
        }
    } while (executar != 0);
    ani_Encerrar();
    return 0;            
} 


//############# FUNÇÕES DE DATA E HORA ##############################

// void mostrar_data_hora(char * data, char * hora){

//     time_t agora; //Função tirada do petbcc.ufscar.br/timefuncoes/#time e adaptada com auxílio de IA
//     time(&agora); //time_t => EPOCH / 01/01/1970

//     struct tm *t = localtime(&agora); //struct tm *t quebra o epoch e deixa legível e formatado

//     snprintf(data, 32, "%02d/%02d/%04d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
//     snprintf(hora, 16, "%02d:%02d", t->tm_hour, t-> tm_min); // formatação para data e hora
    
//     func_Ani(tempo);
// }


                                                                                                                                                                                                                                                                                                                                                                                        