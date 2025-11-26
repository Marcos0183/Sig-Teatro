#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "anima.h"
#include "ingresso.h"
#include "utils.h"
#include "leitura.h"
#include "valida.h"
#include "pesquisa.h"

int tempo_Ingresso = 100;

void menu_Ingresso(){
    limparTela();
    printf("\n");
    func_Ani(tempo_Ingresso);
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_Ingresso);
    printf("║                MÓDULO INGRESSOS                  ║\n");
    func_Ani(tempo_Ingresso);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_Ingresso);
    printf("║                                                  ║\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 1. Vender Ingresso                             ║\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 2. Pesquisar Ingresso                          ║\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 3. Atualizar Ingresso                          ║\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 4. Excluir Ingresso                            ║\n");
    func_Ani(tempo_Ingresso);
    printf("║                                                  ║\n");
    func_Ani(tempo_Ingresso);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_Ingresso);
    printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
    func_Ani(tempo_Ingresso);
    printf("╚══════════════════════════════════════════════════╝\n");
    func_Ani(tempo_Ingresso);
    printf("--> Digite a opção desejada: ");
}

void vender_Ingresso(){
    int parar;
    FILE *arq_ingresso;
    Dados_I *dados;
    dados = (Dados_I*) malloc(sizeof(Dados_I));
    
    parar = ler_cpf_show(dados);
    if(parar){
        parar = ler_codigo(dados);
    }
    if(parar){
        parar = ler_cadeira(dados);
    }
    
    arq_ingresso = fopen("arq_ingresso.dat","ab");
    if(arq_ingresso == NULL)return;

    char texto[] = "COMPRAR INGRESSO";
    limparTela();
    if(parar)exibir_ingresso(dados,False);
    if(parar && ler_escolha(texto)){
        dados ->id = id_ingresso();
        dados->status = True;
        fwrite(dados,sizeof(Dados_I),1,arq_ingresso);
        altera_cadeira(dados ->cadeira,dados ->id_show);
        printf("INGRESSO COMPRADO\n\n");
    }
    else printf("INGRESSO NÃO VENDIDO\n");
    fclose(arq_ingresso);
    free(dados);
    pausar();
}

void excluir_Ingresso(){
    int parar;
    char id_lido[50];
    FILE *arq_ingresso;
    Dados_I *dados;

    dados = (Dados_I *) malloc(sizeof(Dados_I));
    char titulo[19] = "EXCLUIR INGRESSO";
    func_Ani_Left(titulo);
    
    do{ 
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO INGRESSO: ");
    ler_string(id_lido,50);
    retira_char(id_lido,' ');
    printf("-----------------------------------\n");
    }while(!valida_id(id_lido) && !converte_numero(id_lido) == 0);

    arq_ingresso = fopen("arq_ingresso.dat","r+b");
    if(arq_ingresso == NULL)return;
   
    parar = True;
    while(fread(dados,sizeof(Dados_I),1,arq_ingresso) == 1 && parar){
        if(dados ->id == converte_numero(id_lido)){
            dados ->status = False;
            fseek(arq_ingresso,-sizeof(Dados_I),SEEK_CUR);
            fwrite(dados,sizeof(Dados_I),1,arq_ingresso);
            vagar_cadeira(dados);
            printf("INGRESSO EXCLUIDO\n\n");
            parar = False;
        }
    }
    if(parar)printf("INGRESSO NÃO ENCONTRADO\n\n");
    fclose(arq_ingresso);
    free(dados);
    pausar();
}

void atualizar_Ingresso(){
    int parar =  True;
    char id_lido[6];
    FILE *arq_ingresso;
    Dados_I *dados;

    dados = (Dados_I *) malloc(sizeof(Dados_I));
    char titulo[19] = "ATUALIZAR INGRESSO";
    func_Ani_Left(titulo);
    do{ 
        printf("\n \n");
        printf("-----------------------------------\n");
        printf("|  INSIRA O CODIGO DO INGRESSO: ");
        ler_string(id_lido,6);
        retira_char(id_lido,' ');
        printf("-----------------------------------\n");
        
        arq_ingresso = fopen("arq_ingresso.dat","r+b");
        if(arq_ingresso == NULL){
            free(dados);
            return;
        }    
        while(fread(dados,sizeof(Dados_I),1,arq_ingresso) == 1 && parar){
            if(converte_numero(id_lido) == dados ->id){
                exibir_ingresso(dados,True);  
                parar = False;
            }
        }
    }while(parar);
    
    char texto[] = "ATUALIZAR INGRESSO ";
    if(!parar && ler_escolha(texto)){
        parar = ler_cpf_show(dados);
        if(parar){
            parar = ler_codigo(dados);
        }
        if(parar){
            parar = ler_cadeira(dados);
        }
        if(parar){
            fwrite(dados,sizeof(Dados_I),1,arq_ingresso);
            vagar_cadeira(dados);
            altera_cadeira(dados ->cadeira,dados ->id_show);
            printf("INGRESSO ATUALIZADO\n");
        }
    }
    else{
        printf("\n\n");
        printf("SHOW NÃO ENCONTRADO\n");
        pausar();
    }
    fclose(arq_ingresso);
    free(dados);
}

void pesquisar_Ingresso(){
    char cpf_lido[20];
    Dados_I *dados;
    
    dados = (Dados_I *) malloc(sizeof(Dados_I));
    char titulo[19] = "PESQUISAR INGRESSO";
    func_Ani_Left(titulo);


    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O SEU CPF: ");
    ler_string(cpf_lido,20);
    retira_char(cpf_lido,' ');
    printf("-----------------------------------\n\n");

    if(valida_cliente(cpf_lido) && valida_cpf(cpf_lido)){
        pesquisar_ingresso(dados,cpf_lido);
    }
    else{
        printf("\n");
        printf("INGRESSO NÃO ENCONTARDO\n\n");
    }
    pausar();
    free(dados);
}

void ingresso(){
    char executar_I[2];

    do {
        menu_Ingresso();
        ler_string(executar_I,3);

        switch (executar_I[0]) {
            case '1':
                vender_Ingresso();
                break;

            case '2':
                pesquisar_Ingresso();
                break;

            case '3':
                atualizar_Ingresso();
                break;

            case '4':
                excluir_Ingresso();
                break;

            case '0':
                break;

            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                pausar();
                break;
            
        }
    } while (executar_I[0] != '0');
}








