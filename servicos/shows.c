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
    int parar;
    Cabecalho *cabecalho;
    cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
    cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));
    cabecalho ->DHD = NULL;
    cabecalho ->persona = NULL;
    
    parar = ler_nome_show(cabecalho ->dados ->nome); 
    if(parar){
        do{ 
        parar = ler_data(cabecalho);
        if(parar == 1){
            parar = ler_hora(cabecalho);
            if(!parar)break;
            parar = ler_duracao(cabecalho);
            if(!parar)break;
        }
        }while(parar && !(parar == 2));
    }
    if(parar == 2)parar = ler_persona(cabecalho);

    if(parar && escolha_cad_show(cabecalho)){
        cabecalho ->dados ->tam_personagem = strlen(cabecalho ->persona) + 1;
        cabecalho ->dados ->tam_DHD = strlen(cabecalho ->DHD) + 1;
        cabecalho ->dados ->id = id_show();
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
        printf("\n\n");
        printf("SHOW CADASTRADO\n");
    }
    else{
        printf("\n\n");
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
    printf("╔═════════════════════════════════╗\n");
    printf("║     INSIRA O CÓDIGO DO SHOW:      ║\n");
    printf("╚═════════════════════════════════╝\n");
    printf("--> ");
    scanf("%d",&id_lido);
    getchar();
    
    encontrado = True;
    arq_shows = fopen("arq_shows.dat","r+b");
    if(arq_shows == NULL)return;
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
    pausar();  
}

void atualizar_Show(){
    Cabecalho *cabecalho;
    cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
    cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));
    cabecalho ->DHD = NULL;
    cabecalho ->persona = NULL;
    cabecalho ->DHD = listaChar(cabecalho ->DHD,"");
    cabecalho ->persona = listaChar(cabecalho ->persona,"");
    
    ler_id(&cabecalho ->id_lido);
    if(valida_show(cabecalho ->id_lido)){
        cabecalho ->arq_shows = fopen("arq_shows.dat","r+b");
        if(cabecalho ->arq_shows == NULL)return;
        while(fread(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows) == 1){
            if(cabecalho ->id_lido == cabecalho ->dados ->id){
                ler_nome_show(cabecalho ->dados ->nome); 
                ler_data(cabecalho);
                ler_hora(cabecalho);
                ler_duracao(cabecalho);
                ler_persona(cabecalho);
                fseek(cabecalho ->arq_shows,-sizeof(Dados_S),SEEK_CUR);
                fwrite(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows);
                fwrite(cabecalho ->DHD,cabecalho ->dados ->tam_DHD,1,cabecalho ->arq_shows);
                fwrite(cabecalho ->persona,cabecalho ->dados ->tam_personagem,1,cabecalho ->arq_shows);
                fclose(cabecalho ->arq_shows);
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