#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"
#include "anima.h"
#include "utils.h"
#include "tecnicos.h"
#include "leitura.h"
#include "shows.h"
#include "ingresso.h"
#include "pesquisa.h"
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
        printf("║ ► 3. relatorio Shows/Espetaculos                 ║\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 4. relatorio Ingressos                         ║\n");
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
    printf("\n\n");
    Cliente clt;
    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(&clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (clt.status == true) {
            exibir_cliente(&clt);
        }
    }
    fclose(arq_clientes);
    pausar();
}



void listar_clientes_inativos() {
    limparTela();
    char titulo[30] = "LISTANDO CLIENTES INATIVOS";
    func_Ani_Left(titulo);
    printf("\n\n");
    Cliente clt;
    FILE *arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(&clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (clt.status == false) {
            exibir_cliente(&clt);
        }
    }
    fclose(arq_clientes);
    pausar();
}



void listar_clientes_por_nome() {

    limparTela();
    char nome_busca[50];
    char titulo[30] = "LISTANDO CLIENTES POR NOME";
    func_Ani_Left(titulo);
    printf("\n\n");
    Cliente clt;

    ler_nome(nome_busca);
    limparTela();

    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(&clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (strstr(clt.nome, nome_busca) != NULL) {
            exibir_cliente(&clt);
        }
    }
    fclose(arq_clientes);
    pausar();
}



void listar_todos_clientes() {
    limparTela();
    char titulo[28] = "LISTANDO TODOS OS CLIENTES";
    func_Ani_Left(titulo);
    printf("\n\n");
    Cliente clt;
    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(&clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        exibir_cliente(&clt);
    }
    fclose(arq_clientes);
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
    char titulo[28] = "LISTANDO TÉCNICOS ATIVOS";
    func_Ani_Left(titulo);
    printf("\n");
    Tecnico* tec = (Tecnico*) malloc(sizeof(Tecnico));
    FILE* arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de técnicos.\n");
        limparBuffer();
        return;
    }
    while (fread(tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) {
        if (tec -> status == true) {
            exibir_tecnico(tec);
        }
    }
    fclose(arq_tecnicos);
    free(tec);
    pausar();
}



void listar_tecnicos_inativos() {
    limparTela();
    char titulo[30] = "LISTANDO TÉCNICOS INATIVOS";
    func_Ani_Left(titulo);
    printf("\n");
    Tecnico* tec = (Tecnico*) malloc(sizeof(Tecnico));
    FILE *arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de técnicos.\n");
        limparBuffer();
        return;
    }
    while (fread(tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) {
        if (tec -> status == false) {
            exibir_tecnico(tec);
        }
    }
    fclose(arq_tecnicos);
    free(tec);
    pausar();
}



void listar_tecnicos_por_nome() {
    limparTela();
    char nome_busca[50];
    char titulo[30] = "LISTANDO TÉCNICOS POR NOME";
    func_Ani_Left(titulo);
    printf("\n");
    Tecnico* tec = (Tecnico*) malloc(sizeof(Tecnico));

    ler_nome(nome_busca);
    limparTela();

    FILE* arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de técnicos.\n");
        limparBuffer();
        return;
    }
    while (fread(tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) {
        if (strstr(tec->nome, nome_busca) != NULL) {
            exibir_tecnico(tec);
        }
    }
    fclose(arq_tecnicos);
    free(tec);
    pausar();
}



void listar_todos_tecnicos() {
    limparTela();
    char titulo[28] = "LISTANDO TODOS OS TÉCNICOS";
    func_Ani_Left(titulo);
    printf("\n");
    Tecnico* tec = (Tecnico*) malloc(sizeof(Tecnico));
    FILE* arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de técnicos.\n");
        limparBuffer();
        return;
    }
    while (fread(tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) {
        exibir_tecnico(tec);
    }
    fclose(arq_tecnicos);
    free(tec);
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



void listar_shows_ativos(){
    Cabecalho *cabecalho;
    cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
    cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));
    char titulo[16] = "SHOWS AGENDADOS";
    func_Ani_Left(titulo);

    cabecalho ->encontrado = True;
    cabecalho ->arq_shows = fopen("arq_shows.dat","rb");
    while(fread(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows) == 1){
        if(cabecalho ->dados ->status == True ){
            cabecalho ->DHD = (char *) malloc(cabecalho ->dados ->tam_DHD);
            cabecalho ->persona = (char *) malloc(cabecalho ->dados ->tam_personagem);
            fread(cabecalho ->DHD,cabecalho ->dados ->tam_DHD,1,cabecalho ->arq_shows);
            fread(cabecalho ->persona,cabecalho ->dados ->tam_personagem,1,cabecalho ->arq_shows);
            exibir_inf_cadastro(cabecalho,1);
            free(cabecalho ->DHD);
            free(cabecalho ->persona);
            cabecalho ->encontrado = False;
        }
        else{
            fseek(cabecalho ->arq_shows,cabecalho ->dados ->tam_DHD + cabecalho ->dados ->tam_personagem,SEEK_CUR);
        }
    }
    if(cabecalho ->encontrado)printf("SEM SHOWS AGENDADOS\n");
    fclose(cabecalho ->arq_shows);
    free(cabecalho ->dados);
    free(cabecalho);
    pausar();
}



void listar_shows_inativos(){
    Cabecalho *cabecalho;
    cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
    cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));
    char titulo[20] = "SHOWS APRESENTADOS";
    func_Ani_Left(titulo);

    cabecalho ->encontrado = True;
    cabecalho ->arq_shows = fopen("arq_shows.dat","rb");
    while(fread(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows) == 1){
        if(cabecalho ->dados ->status == False){
            cabecalho ->DHD = (char *) malloc(cabecalho ->dados ->tam_DHD);
            cabecalho ->persona = (char *) malloc(cabecalho ->dados ->tam_personagem);
            fread(cabecalho ->DHD,cabecalho ->dados ->tam_DHD,1,cabecalho ->arq_shows);
            fread(cabecalho ->persona,cabecalho ->dados ->tam_personagem,1,cabecalho ->arq_shows);
            exibir_inf_cadastro(cabecalho,1);
            free(cabecalho ->DHD);
            free(cabecalho ->persona);
            cabecalho ->encontrado = False;
        }
        else{
            fseek(cabecalho ->arq_shows,cabecalho ->dados ->tam_DHD + cabecalho ->dados ->tam_personagem,SEEK_CUR);
        }
    }
    if(cabecalho ->encontrado)printf("SEM SHOWS APRESENTADOS\n");
    fclose(cabecalho ->arq_shows);
    free(cabecalho ->dados);
    free(cabecalho);
    pausar();
}



void relatorio_shows(){ 
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE SHOWS                 ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 1. Listar Shows Agendados                      ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 2. Listar Shows Apresentados                   ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 3. Listar Shows por Nome                       ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 4. listar todos os Shows                       ║\n");
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



void listar_ingressos_ativos(){
    int achado;
    Dados_I *dados;
    dados = (Dados_I *) malloc(sizeof(Dados_I));
    char titulo[19] = "INGRESSOS ATIVOS";
    func_Ani_Left(titulo);


    FILE *arq_ingresso;
    arq_ingresso = fopen("arq_ingresso.dat","rb");
    achado = True;
    while(fread(dados,sizeof(Dados_I),1,arq_ingresso) == 1){
        if(dados ->status == True){
            exibir_ingresso(dados,True);
            achado = False;
        }
    }
    if(achado)printf("SEM INGRESSOS COMPRADOS\n");
    free(dados);
}



void listar_ingressos_inativos(){
    int achado;
    Dados_I *dados;
    dados = (Dados_I *) malloc(sizeof(Dados_I));
    char titulo[19] = "INGRESSOS ATIVOS";
    func_Ani_Left(titulo);


    FILE *arq_ingresso;
    arq_ingresso = fopen("arq_ingresso.dat","rb");
    achado = True;
    while(fread(dados,sizeof(Dados_I),1,arq_ingresso) == 1){
        if(dados ->status == False){
            exibir_ingresso(dados,True);
            achado = False;
        }
    }
    if(achado)printf("SEM INGRESSOS RASGADOS\n");
    free(dados);

}



void relatorio_ingressos(){
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE INGRESSOS             ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 1. Listar Igressos Comprados                   ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 2. Listar Ingressos Rasgados                   ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 3. Listar Ingressos por Show                   ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 4. listar Todos Ingresso Vendidos              ║\n");
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
    int opcao_show;
    int opcao_ingresso;

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
            
            case 3:
                do{
                    relatorio_shows();
                    scanf(" %d", &opcao_show);
                    limparBuffer();
                    switch (opcao_show) {
                        case 1:
                            listar_shows_ativos();
                            break;
                        case 2:
                            listar_shows_inativos();
                            break;
                        case 3:
                            printf("Não Finalizado");
                            pausar();
                            break;
                        case 4:
                            printf("Não Finalizado");
                            pausar();
                            break;
                        case 0:
                            break; 
                    }
                }while(opcao_show != 0);
            
            case 4:
                do{
                    relatorio_ingressos();
                    scanf(" %d", &opcao_ingresso);
                    limparBuffer();
                    switch (opcao_ingresso) {
                        case 1:
                            listar_ingressos_ativos();
                            pausar();
                            break;
                        case 2:
                            listar_ingressos_inativos();
                            pausar();
                            break;
                        case 3:
                            printf("Não Finalizado");
                            pausar();
                            break;
                        case 4:
                            printf("Não Finalizado");
                            pausar();
                            break;
                        case 0:
                            break; 
                    }
                }while(opcao_ingresso != 0);
                
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