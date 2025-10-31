#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "leitura.h"
#include "utils.h"
#include "valida.h"
#include "listachar.h"
#include "shows.h"
#include "ingresso.h"
#include "clientes.h"
#include "anima.h"


int id_ingresso(void){
    int idRetorna; 
    int *id;
    id = &idRetorna;
    FILE *arq_id;
    arq_id = fopen("id_i.dat","rb");

    if(arq_id == NULL){
       arq_id = fopen("id_i.dat","w+");
       idRetorna = 0;
       fwrite(id,sizeof(int),1,arq_id);
       rewind(arq_id);
    }
    fread(id,sizeof(int),1,arq_id);
    fclose(arq_id);
    if(idRetorna == 2000){
        idRetorna = 0;
    }
    arq_id = fopen("id_i.dat","wb");
    idRetorna++;
    fwrite(id,sizeof(int),1,arq_id);
    fclose(arq_id);
    return idRetorna;
}


int id_show(void){
    int idRetorna; 
    int *id;
    id = &idRetorna;
    FILE *arq_id;
    arq_id = fopen("id.dat","rb");

    if(arq_id == NULL){
       arq_id = fopen("id.dat","w+");
       idRetorna = 0;
       fwrite(id,sizeof(int),1,arq_id);
       rewind(arq_id);
    }
    fread(id,sizeof(int),1,arq_id);
    fclose(arq_id);
    if(idRetorna == 100){
        idRetorna = 0;
    }
    arq_id = fopen("id.dat","wb");
    idRetorna++;
    fwrite(id,sizeof(int),1,arq_id);
    fclose(arq_id);
    return idRetorna;
}

//1. Passe o endereço da variável
//Ex: ler_id(&id_lido)
void ler_id(int *id_lido){
    printf("\n \n");
    printf("====================================\n"); 
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",id_lido);
    getchar();
    printf("====================================\n"); 
}



int ler_codigo(Dados_I *dados){
    char id_lido[5];
    printf("====================================\n"); 
    printf("|  INSIRA O CÓDIGO DO SHOW: ");
    ler_string(id_lido,5);

    dados ->id_show = converte_numero(id_lido);
    if(valida_show(dados ->id_show)){
        return True;
    }
    else{
        printf("SHOW NÃO ENCONTRADO\n\n");
        system("pause");
        return False;
    }
}



int ler_cadeira(Dados_I *dados){ 
    exibir_cadeiras(dados ->id_show);
    printf("====================================\n"); 
    printf("|  ESCOLHA SUA CADEIRA: ");
    ler_string(dados->cadeira,5);
    printf("====================================\n"); 
    if(valida_cadeira(dados ->cadeira,dados ->id_show)){
        Mapeia *coord;
        coord = (Mapeia *) malloc(sizeof(Mapeia));
        procura_cad(dados ->cadeira,coord);
        dados ->cord_i = coord ->i;
        dados ->cord_j = coord ->j;
        free(coord);
        system("pause");
        return True;
    }
    else{
        system("pause");
        return False;
    }

}



void ler_nomeShow(char *nome){
    printf("\n \n");
    printf("====================================\n"); 
    printf("|  INSIRA O NOME DO SHOW: ");
    ler_string(nome,32);
}



void ler_DHD(Cabecalho *cabecalho){
    Dados_Temp *inf;
    inf = (Dados_Temp *) malloc(sizeof(Dados_Temp));
    int parar;
    parar = True;
    printf("====================================\n"); 
    while(parar){
        printf("|  INSIRA A DATA DO SHOW - DIGITE (S) PARA ENCERRAR: ");
        ler_string(inf ->data,12);

        printf("====================================\n"); 
        if(strcmp(inf ->data,"S") == 0 || strcmp(inf ->data,"s") == 0) parar = False;
        else{
            cabecalho ->DHD = listaChar(cabecalho ->DHD,inf ->data);

            printf("|  INSIRA A HORA DE INÍCIO DO SHOW: ");
            ler_string(inf ->hora,6);
            printf("====================================\n"); 
            listaChar(cabecalho ->DHD,inf ->hora);

            printf("|  INSIRA A DURAÇÃO DO SHOW: ");
            ler_string(inf ->duracao,5);
            printf("====================================\n"); 
            listaChar(cabecalho ->DHD,inf ->duracao);
        }
    }
    cabecalho ->dados ->tam_DHD = strlen(cabecalho ->DHD) + 1;
    free(inf);
}



void ler_persona(Cabecalho *cabecalho){
    Dados_Temp *inf;
    inf = (Dados_Temp *) malloc(sizeof(Dados_Temp));
    int parar;
    parar = True;
    while(parar){
        printf("|  INSIRA OS PERSONAGENS DO SHOW - DIGITE (S) PARA ENCERRAR: ");
        ler_string(inf ->personagem,32);
        printf("====================================\n"); 
        if(strcmp(inf ->personagem,"S") == 0 || strcmp(inf ->personagem,"s") == 0) parar = False;
        else{
            cabecalho ->persona = listaChar(cabecalho ->persona,inf ->personagem);
        }
    }
    cabecalho ->dados ->tam_personagem = strlen(cabecalho ->persona) + 1;
    free(inf);

}



void ler_nome(char *nome) {
    do {
    printf("====================================\n"); 
    printf("|  INSIRA O NOME: ");
    ler_string(nome, 50);
    } while (!valida_nome(nome));
}



void ler_cpf(char *cpf) {
    do {
    printf("====================================\n"); 
    printf("|  INSIRA O CPF: ");
    ler_string(cpf, 15);
    } while (!valida_cpf(cpf));
}



int ler_cpf_show(Dados_I *dados){
    int saida;
    SEP  *controle;
    controle = (SEP *) malloc(sizeof(SEP));
    controle ->valida = False;
    do{ 
        limparTela();
        char titulo[16] = "VENDER INGRESSO";
        func_Ani_Left(titulo);
        printf("\n \n");
        printf("=====================================================================\n"); 
        printf("|  INSIRA SEU CPF DE CADASTRO - SEM CPF DIGITE (C) PARA CADASTRAR-SE: ");
        ler_string(dados ->cpf, 20);
        valida_cpf_show(controle,dados);

        switch (controle ->error){
            case 1:
            printf("\n");
            printf("CLIENTE NÃO CADASTRADO");
            pausar();
            break;
            case 2:
            printf("\n");
            printf("CPF INSERIDO INCORRETO OU NÃO VÁLIDO\n");
            pausar();
        }
        
    }while(!controle ->valida && !converte_numero(dados ->cpf) == SAIR);
    saida = controle ->valida;
    free(controle);
    return saida;
}



void ler_telefone(char *telefone) {
    do {
    printf("====================================\n"); 
    printf("|  INSIRA O TELEFONE: ");
    ler_string(telefone, 16);
    } while (!valida_telefone(telefone));
}



void ler_email(char *email) {
    do {
    printf("====================================\n");
    printf("|  INSIRA O EMAIL: ");
    ler_string(email, 40);
    } while (!valida_email(email));
}



void ler_funcao(char *funcao) {
    do
    {
    printf("====================================\n");
    printf("|  INSIRA A FUNÇÃO: ");
    ler_string(funcao, 16);
    } while (!valida_funcao(funcao));
}