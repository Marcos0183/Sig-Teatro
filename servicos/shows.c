#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "shows.h"
#include "anima.h"
#include "utils.h"
#include "listachar.h"
#include "leitura.h"
#include "pesquisa.h"
#include "valida.h"


char cadeira_copia[5][20][6] = {
        { "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10",
          "A11", "A12", "A13", "A14", "A15", "A16", "A17", "A18", "A19", "A20" },

        { "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10",
          "B11", "B12", "B13", "B14", "B15", "B16", "B17", "B18", "B19", "B20" },

        { "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10",
          "C11", "C12", "C13", "C14", "C15", "C16", "C17", "C18", "C19", "C20" },

        { "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10",
          "D11", "D12", "D13", "D14", "D15", "D16", "D17", "D18", "D19", "D20" },

        { "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10",
          "E11", "E12", "E13", "E14", "E15", "E16", "E17", "E18", "E19", "E20" }
    };
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
        printf("║                                                  ║\n");
        func_Ani(tempo_Shows);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_Shows);
        printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
        func_Ani(tempo_Shows);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_Shows);
        printf("--> Digite a opção desejada: ");
}

void cadastrar_Show(){
    Cabecalho *cabecalho;
    cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
    cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));
    cabecalho ->DHD = NULL;
    cabecalho ->persona = NULL;
    char titulo[16] = "CADASTRAR SHOW";
    func_Ani_Left(titulo);

    ler_nomeShow(cabecalho ->dados ->nome); 
    ler_DHD(cabecalho);
    ler_persona(cabecalho);
    cabecalho ->dados ->id = id_show();
    if(escolha_cad_show(cabecalho)){
        cabecalho ->arq_shows = fopen("arq_shows.dat","ab");
        cabecalho ->dados ->status = True;      
        cria_cadeiras(cabecalho ->dados ->id);
        fwrite(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows);
        fwrite(cabecalho ->DHD,cabecalho ->dados ->tam_DHD,1,cabecalho ->arq_shows);
        fwrite(cabecalho ->persona,cabecalho ->dados ->tam_personagem,1,cabecalho ->arq_shows);
        fclose(cabecalho ->arq_shows);
        free(cabecalho ->DHD);
        free(cabecalho ->persona);
        free(cabecalho ->dados);
        free(cabecalho);
        printf("SHOW CADASTRADO\n");
    }
    else{
        printf("SHOW NÃO CADASTRADO\n");
    }     
    pausar();
}

void excluir_Show(){
    int id_lido;
    int encontrado;
    Dados_S *dados;
    dados = (Dados_S *) malloc(sizeof(Dados_S));
    FILE *arq_shows;
    char titulo[16] = "EXCLUIR SHOW";
    func_Ani_Left(titulo);


    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",&id_lido);
    getchar();
    printf("V----------------------------------\n");

    
    encontrado = True;
    arq_shows = fopen("arq_shows.dat","r+b");
    while(fread(dados,sizeof(Dados_S),1,arq_shows) == 1){
        if(id_lido == dados ->id && dados ->status == True){
            dados ->status = False;
            fseek(arq_shows,-1*sizeof(Dados_S),SEEK_CUR);
            fwrite(dados,sizeof(Dados_S),1,arq_shows);
            encontrado = False;
            printf("SHOW EXCLUÍDO!\n");
        }
        else fseek(arq_shows,dados ->tam_DHD + dados ->tam_personagem,SEEK_CUR);
    }

    if(encontrado) printf("SHOW NÃO ENCONTRADO!\n");
    fclose(arq_shows);
    free(dados);
    system("pause");  
}

void atualizar_Show(){
    Cabecalho *cabecalho;
    cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
    cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));
    cabecalho ->DHD = NULL;
    cabecalho ->persona = NULL;
    char titulo[16] = "ATUALIZAR SHOW";
    func_Ani_Left(titulo);
    
    ler_id(&cabecalho ->id_lido);
    if(valida_show(cabecalho ->id_lido)){
        cabecalho ->arq_shows = fopen("arq_shows.dat","r+b");
        if(cabecalho ->arq_shows == NULL)return;
        while(fread(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows) == 1){
            if(cabecalho ->id_lido == cabecalho ->dados ->id){
                ler_nomeShow(cabecalho ->dados ->nome); 
                ler_DHD(cabecalho);
                ler_persona(cabecalho);
                fseek(cabecalho ->arq_shows,-sizeof(Dados_S),SEEK_CUR);
                fwrite(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows);
                fwrite(cabecalho ->DHD,cabecalho ->dados ->tam_DHD,1,cabecalho ->arq_shows);
                fwrite(cabecalho ->persona,cabecalho ->dados ->tam_personagem,1,cabecalho ->arq_shows);
                free(cabecalho ->DHD);
                free(cabecalho ->persona);
                printf("DADOS DE SHOW ALTERADO\n\n");
                pausar();
            }
            else{
                fseek(cabecalho ->arq_shows,cabecalho ->dados ->tam_DHD + cabecalho ->dados ->tam_personagem,SEEK_CUR);
            }
        }
    }
    else{
        printf("SHOW NÃO ENCONTRADO\n\n");
        system("pause");
    } 
    fclose(cabecalho ->arq_shows);
    free(cabecalho ->dados);
    free(cabecalho);
}

void pesquisar_Show(){
    Cabecalho *cabecalho;
    cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
    cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));
    char titulo[16] = "PESQUISAR SHOW";
    func_Ani_Left(titulo);
    ler_id(&cabecalho ->id_lido);
    pesquisa_show(cabecalho);
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

void cria_cadeiras(int id_parametro){
    FILE *arq_cadeiras;
    Cadeiras *cadeiras;
    cadeiras = (Cadeiras *) malloc(sizeof(Cadeiras));
    
    copia_carac_D3(cadeira_copia,cadeiras ->cad );
    cadeiras ->id = id_parametro;
    cadeiras ->cont = 0;

    arq_cadeiras = fopen("arq_cadeiras.dat","ab");
    abrir_arquivo(arq_cadeiras);
    fwrite(cadeiras,sizeof(Cadeiras),1,arq_cadeiras);
    fclose(arq_cadeiras);
    free(cadeiras);
}
