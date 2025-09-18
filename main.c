#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "anima.h"
#include "ingresso.h"
#include "sessoes.h"
#include "tecnicos.h"
#include "shows.h"

//INFO
void proj_Descrit();
void equipe();

//DATA E HORA
//void mostrar_data_hora();

void equipe(){
    int tempo_Eq = 50; 
    printf(" _    _ \n");
    func_Ani(tempo_Eq);
    printf("| |  | |\n");
    func_Ani(tempo_Eq);
    printf("| |  | |\n");
    func_Ani(tempo_Eq);
    printf("| |  | |\n");
    func_Ani(tempo_Eq);
    printf("| |  | |\n");
    func_Ani(tempo_Eq);
    printf("| |__| |\n");
    func_Ani(tempo_Eq);
    printf(" \\____/ \n\n");
    func_Ani(tempo_Eq);

    // Desenha a letra F
    printf(" ______ \n");
    func_Ani(tempo_Eq);
    printf("|  ____|\n");
    func_Ani(tempo_Eq);
    printf("| |__   \n");
    func_Ani(tempo_Eq);
    printf("|  __|  \n");
    func_Ani(tempo_Eq);
    printf("| |     \n");
    func_Ani(tempo_Eq);
    printf("|_|     \n\n");
    func_Ani(tempo_Eq);
                                         // A palavra UFRN foi feita pelo GEMINI
    // Desenha a letra R
    printf(" ______ \n");
    func_Ani(tempo_Eq);
    printf("|  _  \\\n");
    func_Ani(tempo_Eq);
    printf("| | | |\n");
    func_Ani(tempo_Eq);
    printf("| | | |\n");
    func_Ani(tempo_Eq);
    printf("| |_| |\n");
    func_Ani(tempo_Eq);
    printf("|  _  /\n");
    func_Ani(tempo_Eq);
    printf("|_| \\_\\\n\n");
    func_Ani(tempo_Eq);

    // Desenha a letra N
    printf(" _    _ \n");
    func_Ani(tempo_Eq);
    printf("| \\  / |\n");
    func_Ani(tempo_Eq);
    printf("|  \\/  |\n");
    func_Ani(tempo_Eq);
    printf("| |\\/| |\n");
    func_Ani(tempo_Eq);
    printf("| |  | |\n");
    func_Ani(tempo_Eq);
    printf("|_|  |_|\n");
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
    printf("\n");
    func_Ani(tempo_Eq);
    printf("#########################################################################\n");
    func_Ani(tempo_Eq);
    printf("\n \n \n");
}
void proj_Descrit(){
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
    printf("\n \n");
}

int tempo_Main = 100;
int main() {
    
    bool parada = true;
    do { 
        system("clear||cls");
        int executar;
        
        //proj_Descrit();
        //equipe();

        printf("#####################################################################################\n");
        func_Ani(tempo_Main);
        printf("   +++                           SISTEMA DE TEATRO                             +++\n");
        func_Ani(tempo_Main);
        printf("#####################################################################################\n");
        func_Ani(tempo_Main);
        printf("###                             1 - ENTRAR NO MODULO INGRESSO                     ###\n");
        func_Ani(tempo_Main);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Main);
        printf("###                             2 - ENTRAR NO MODULO SHOWS/PECAS                  ###\n");
        func_Ani(tempo_Main);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Main);
        printf("###                             3 - ENTRAR NO MODULO SESSOES                      ###\n");
        func_Ani(tempo_Main);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Main);
        printf("###                             4 - ENTRAR NO MODULO TECNICOS                     ###\n");
        func_Ani(tempo_Main);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Main);
        printf("###                             5 - ENTRAR NO MODULO RELATORIO                    ###\n");
        func_Ani(tempo_Main);
        printf("###                                                                               ###\n");
        func_Ani(tempo_Main);
        printf("##                              0 - ENCERRAR PROGRAMA : ");
        
        scanf("%d",&executar);
        getchar();

        switch (executar) {
            case 1:
                ingresso();
                break;
            case 2:
                shows();
                break;
            case 3:
                sessoes();
                break;
            case 4:
                tecnicos();
                break;        
            case 0:
                parada = false;
                break;
            
            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                system("pause");
                break;
        }
    } while (parada);
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


                                                                                                                                                                                                                                                                                                                                                                                        