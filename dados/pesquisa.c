#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "anima.h"
#include "shows.h"
#include "ingresso.h"
#include "clientes.h"

void exibir_ingresso(Dados_I *dados_I,int revelar){
    int parar;
    FILE *arq_cliente;
    FILE *arq_show;
    Dados_S *dados_S;
    Cliente *dados_C;
    dados_S = (Dados_S *) malloc(sizeof(Dados_S));
    dados_C = (Cliente *) malloc(sizeof(Cliente));
   
    arq_cliente = fopen("clientes.dat","rb");
    if(arq_cliente == NULL)return;
    
    parar = True;
    while(parar && fread(dados_C,sizeof(Cliente),1,arq_cliente) == 1){
        if(strcmp(dados_C ->cpf, dados_I ->cpf) == 0){
            parar = False;
        } 
    }
    fclose(arq_cliente);

    arq_show = fopen("arq_shows.dat","rb");
    if(arq_show == NULL)return;
    
    parar = True;
    while( parar && fread(dados_S,sizeof(Dados_S),1,arq_show) == 1){
        if(dados_S ->id == dados_I ->id_show){
            parar = False;
        }
        else fseek(arq_show,dados_S ->tam_DHD + dados_S ->tam_personagem,SEEK_CUR);
    }
    fclose(arq_show);
    
    printf("\n+---------------------------------------------------------------+\n");
    printf("|                     DADOS DO INGRESSO                         |\n");
    printf("+---------------------------------------------------------------+\n");   
    printf("| CPF          : %-46s |\n",dados_I->cpf);
    printf("| Cliente      : %-46s |\n",dados_C ->nome);
    printf("| Nome-Id Show : %s - %-28.3d  |\n",dados_S ->nome,dados_S ->id);
    printf("| Cadeira      : %-46s |\n",dados_I->cadeira);
    if(revelar)printf("| Id_Ingresso  : %-46d |\n",dados_I->id);
    printf("+---------------------------------------------------------------+\n");
    
    free(dados_C);
    free(dados_S);
}

void exibir_inf_cadastro(Cabecalho *cabecalho,int revelar){
    printf("\n+---------------------------------------------------------------+\n");
    printf("|                     DADOS SO SHOW                             |\n");
    printf("+---------------------------------------------------------------+\n");   
    if(revelar)printf("| ID       : %-50d |\n", cabecalho ->dados ->id);
    printf("| Nome     : %-50s |\n", cabecalho ->dados ->nome);
    printf("| DHD      : %-50s |\n", cabecalho ->DHD);
    printf("| Personagem : %-48s |\n", cabecalho ->persona);
    printf("+---------------------------------------------------------------+\n");
}

int escolha_cad_show(Cabecalho *cabecalho){ 
    char escolha[2];
    int saida;
    int parar;
    parar = True;
    while(parar){ 
        exibir_inf_cadastro(cabecalho,0);
        printf("CADASTRAR SHOW - SIM(S)/NAO(N): ");
        ler_string(escolha,2);
        if(strcmp(escolha,"S") == 0 || strcmp(escolha,"s") == 0){
            saida = True;
            parar = False;
        }
        else if(strcmp(escolha,"N") == 0 || strcmp(escolha,"n") == 0){
            saida = False;
            parar = False;
        }
        else printf("ESCOLHA APENAS (S) PARA SIM E (N) PARA NÃO\n");
    }
    return saida;
}

void pesquisa_show(Cabecalho *cabecalho){
    cabecalho ->encontrado = True;
    cabecalho ->arq_shows = fopen("arq_shows.dat","rb");
    while(fread(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows) == 1 && cabecalho ->encontrado){
        if(cabecalho ->id_lido == cabecalho ->dados ->id && cabecalho ->dados ->status == True ){
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
    if(cabecalho ->encontrado)printf("SHOW NÃO ENCONTRADO!\n");
    fclose(cabecalho ->arq_shows);
    free(cabecalho ->dados);
    free(cabecalho);
    pausar();
}

void pesquisar_ingresso(Dados_I *dados,char *cpf_lido){
    limparTela();
    FILE *arq_ingresso;
    arq_ingresso = fopen("arq_ingresso.dat","rb");

    while(fread(dados,sizeof(Dados_I),1,arq_ingresso) == 1){
        if(strcmp(dados ->cpf,cpf_lido) == 0 && dados ->status == True){
            exibir_ingresso(dados,True);
        }
    }
}