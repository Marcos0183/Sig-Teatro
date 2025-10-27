#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "anima.h"
#include "shows.h"

void exibir_inf_cadastro(Cabecalho *cabecalho){
    printf("Id: %d\n",cabecalho ->dados ->id);
    printf("Nome: %s\n",cabecalho ->dados ->nome);
    printf("Datas: %s\n",cabecalho ->DHD);
    printf("Personagens: %s\n",cabecalho ->persona);
}

int escolha_cad_show(Cabecalho *cabecalho){ 
    char escolha[2];
    int saida;
    int parar;
    parar = True;
    while(parar){ 
        exibir_inf_cadastro(cabecalho);
        printf("CADASTRAR SHOW - SIM(S)/NAO(N): ");
        ler_string(escolha,2);
        if(strcmp(escolha,"S") == 0 || strcmp(escolha,"s") == 0){
            saida = True;
            parar = False;
        }
        else if(strcmp(escolha,"N") == 0 || strcmp(escolha,"N") == 0){
            saida = False;
            parar = False;
        }
        else printf("ESCOLHA APENAS S PARA SIM E N PARA NÃO\n");
    }
    return saida;
}

void pesquisaShow(Cabecalho *cabecalho){
    cabecalho ->encontrado = True;
    cabecalho ->arq_shows = fopen("arq_shows.dat","rb");
    while(fread(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows) == 1){
        if(cabecalho ->id_lido == cabecalho ->dados ->id && cabecalho ->dados ->status == True ){
            cabecalho ->DHD = (char *) malloc(cabecalho ->dados ->tam_DHD);
            cabecalho ->persona = (char *) malloc(cabecalho ->dados ->tam_personagem);
            fread(cabecalho ->DHD,cabecalho ->dados ->tam_DHD,1,cabecalho ->arq_shows);
            fread(cabecalho ->persona,cabecalho ->dados ->tam_personagem,1,cabecalho ->arq_shows);
            exibir_inf_cadastro(cabecalho);
            fclose(cabecalho ->arq_shows);
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