#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "anima.h"
#include "shows.h"


void pesquisaShow(Cabecalho *cabecalho){
    cabecalho ->encontrado = True;
    cabecalho ->arq_shows = fopen("arq_shows.dat","rb");
    while(fread(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows) == 1){
        if(cabecalho ->id_lido == cabecalho ->dados ->id && cabecalho ->dados ->status == True ){
            cabecalho ->DHD = (char *) malloc(cabecalho ->dados ->tam_DHD);
            cabecalho ->persona = (char *) malloc(cabecalho ->dados ->tam_personagem);
            fread(cabecalho ->DHD,cabecalho ->dados ->tam_DHD,1,cabecalho ->arq_shows);
            fread(cabecalho ->persona,cabecalho ->dados ->tam_personagem,1,cabecalho ->arq_shows);
            printf("Id: %d\n",cabecalho ->dados ->id);
            printf("Nome: %s\n",cabecalho ->dados ->nome);
            printf("Datas: %s\n",cabecalho ->DHD);
            printf("Personagens: %s\n",cabecalho ->persona);
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