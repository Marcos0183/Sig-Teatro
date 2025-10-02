#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "shows.h"
#include "anima.h"
#include "utils.h"

int tempo_Shows = 100;


void menu_Shows(){
    limparTela();
        printf("╔══════════════════════════════════════════════════╗\n");
        func_Ani(tempo_Shows);
        printf("║                   MODULO SHOWS                   ║\n");
        func_Ani(tempo_Shows);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_Shows);
        printf("║                                                  ║\n");
        func_Ani(tempo_Shows);
        printf("║ ► 1. Cadastrar Show                              ║\n");
        func_Ani(tempo_Shows);
        printf("║ ► 2. Pesquisar Show                              ║\n");
        func_Ani(tempo_Shows);
        printf("║ ► 3. Atualizar Show                              ║\n");
        func_Ani(tempo_Shows);
        printf("║ ► 4. Excluir Show                                ║\n");
        func_Ani(tempo_Shows);
        printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
        func_Ani(tempo_Shows);
        printf("║                                                  ║\n");
        func_Ani(tempo_Shows);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_Shows);
        printf("--> Digite a opção desejada: ");
}



void cadastrar_Show(){
    char *comp_1 = "S";
    char *comp_2 = "s";
    char *comp_3;
    char lista[150];
    char nome[32]; 
    char data[12];
    char hora[6];
    char duracao[6];
    char personagens[27];
    char titulo[16] = "CADASTRAR SHOW";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O NOME DO SHOW: ");
    ler_string(nome,32);
    

    int parar = 1;
    FILE *arq_Temp_data;
    arq_Temp_data = fopen("arq_Temp_Data.csv","wt");
    while(parar){
        printf("V----------------------------------\n");
        printf("|  INSIRA A DATA DO SHOW - DIGITE (S) PARA ENCERRAR: ");
        ler_string(data,12);
        char *comp_3 = data;
        if(strcmp(comp_3,comp_1) == 0 || strcmp(comp_3,comp_2) == 0) parar = 0;
        else{
            printf("V----------------------------------\n");
            printf("|  INSIRA A HORA DE INÍCO DO SHOW: ");
            ler_string(hora,6);
            printf("V----------------------------------\n");
            printf("|  INSIRA A/AS DURACAOS DO SHOW: ");
            ler_string(duracao,6);
            arq_Temp_data = fopen("arq_Temp_Data.csv","at");
            fprintf(arq_Temp_data,"%s,",data);
            fprintf(arq_Temp_data,"%s,",hora);
            fprintf(arq_Temp_data,"%s,\n",duracao);
            fclose(arq_Temp_data);
        } 
    }


    parar = 1;
    FILE *arq_Temp_pers;
    arq_Temp_pers = fopen("arq_Temp_Pers.csv","wt");
    arq_Temp_pers = fopen("arq_Temp_Pers.csv","at");
    printf("V----------------------------------\n");
    while(parar){
        printf("|  INSIRA OS PERSONAGENS DO SHOW - DIGITE (S) PARA ENCERRAR: ");
        ler_string(personagens,27);
        printf("V----------------------------------\n");
        comp_3 = personagens;
        if(strcmp(comp_3,comp_1) == 0 || strcmp(comp_3,comp_2) == 0) parar = 0;
        else{
            fprintf(arq_Temp_pers,"%s,",personagens);
        }
    }
    fprintf(arq_Temp_pers,"\n");
    fclose(arq_Temp_pers);

    
    FILE *arq_Shows;
    arq_Shows = fopen("arq_shows.csv","at");
    fprintf(arq_Shows,"%s;",nome);
    arq_Temp_data = fopen("arq_Temp_Data.csv","rt");
    fprintf(arq_Shows,"[");
    while(fscanf(arq_Temp_data,"%[^\n]",lista) == 1){
        fprintf(arq_Shows,"%s",lista);
        fgetc(arq_Temp_data);
    }
    fclose(arq_Temp_data);
    fprintf(arq_Shows,"];");

    
    arq_Temp_pers = fopen("arq_Temp_Pers.csv","rt");
    fprintf(arq_Shows,"[");
    while(fscanf(arq_Temp_pers,"%[^\n]",lista) == 1){
        fprintf(arq_Shows,"%s",lista);
        fgetc(arq_Temp_data);
    }
    fprintf(arq_Shows,"]\n");
    fclose(arq_Temp_pers);
    fclose(arq_Shows);
    system("pauser");
}

void excluir_Show(){
    int codigo;
    char titulo[16] = "EXCLUIR SHOW";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",&codigo);
    printf("V----------------------------------\n");
}

void atualizar_Show(){
    int codigo;
    char titulo[16] = "ATUALIZAR SHOW";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",&codigo);
    printf("V----------------------------------\n");
}

void pesquisar_Show(){
    int codigo;
    char titulo[16] = "PESQUISAR SHOW";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",&codigo);
    getchar();
    printf("-----------------------------------\n");
}



void shows(){ 
    int executar_S; 

    do {  
        menu_Shows();
        scanf(" %d",&executar_S);
        limparBuffer();

        switch (executar_S) {
            case 1:
                cadastrar_Show();
                break;

            case 2:
                pesquisar_Show();
                break;

            case 3:
                atualizar_Show();
                break;

            case 4:
                excluir_Show();
                break;
                 
            case 0:
                break;
            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                pausar();
                break;
        }
    } while (executar_S != 0);
}
