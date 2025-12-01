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
#include "pesquisa.h"


//  ##############################       FUNÇÕES DE LEITURA GERAIS       ################################
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

int ler_escolha(char *texto){
    int parar = False;
    int saida = False;
    int converte;
    char escolha[50];
    do{ 
        printf("%s- SIM(S)/NAO(N): ",texto);
        ler_string(escolha,4);
        retira_char(escolha,' ');
        converte = converte_numero(escolha);
        if(strcmp(escolha,"S") == 0 || strcmp(escolha,"s") == 0){
            saida = True;
            parar = True;
        }
        else if(strcmp(escolha,"N") == 0 || strcmp(escolha,"n") == 0){
            parar = True;
        }
        else if(converte == SAIR){
            parar = True;
        }
        else printf("ESCOLHA APENAS S-s PARA SIM E N-n PARA NÃO\n");
    }while(!parar);
    return saida;
}


//  ##############################   FUNÇÕES DE LEITURA DO MÓDULO SHOWS   ################################

int id_show(void){  //Cria um id(codigo) para um show cadastrado
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

int ler_nome_show(char *nome){
    limparTela();
    char titulo[16] = "CADASTRAR SHOW";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("====================================\n"); 
    printf("|  INSIRA O NOME DO SHOW: ");
    ler_string(nome,32);
    if(converte_numero(nome) == SAIR)return False;
    return True;
}

int ler_data(Cabecalho *cabecalho){
    int saida;
    char data[50];
    SEP *controle;
    controle = (SEP *) malloc(sizeof(SEP));
    controle ->valida = False;

    do{
        limparTela();
        char titulo[16] = "CADASTRAR SHOW";
        func_Ani_Left(titulo);
        printf("==================================================\n");
        printf("|  INSIRA A DATA DO SHOW - DIGITE (S) PARA ENCERRAR: ");
        ler_string(data,50);
        retira_char(data,' ');
        if(converte_numero(data) != SAIR && !(strcmp(data,"S") == 0 || strcmp(data,"s") == 0)){
            valida_data(controle,data);
            switch (controle ->error){
                case 1:
                printf("\n");
                printf("FORMATO INVALIDO PARA DATA, INSIRA dia/mes/ano\n");
                pausar();
                break;
                case 2:
                printf("\n");
                printf("FORMATO INVALIDO, LEMBRE-SE DE ADICIONAR AS BARRAS\n");
                pausar();
                break;
                case 3:
                printf("\n");
                printf("DIGITE APENAS NUMEROS NO ANO\n");
                pausar();
                break;
                case 4:
                printf("\n");
                printf("DIGITE APENAS NUEMROS NO MES\n");
                pausar();
                break;
                case 5:
                printf("\n");
                printf("MES INVALIDO, DIGITE APENAS DE 01 A 12\n");
                pausar();
                break;
                case 6:
                printf("\n");
                printf("DIGITE APENAS NUMEROS NO DIA\n");
                pausar();
                break;
                case 7:
                printf("\n");
                printf("DIA INVALIDO, DIGITE APENAS O DIAS CONRRESPONDENTES AO MES\n");
                pausar();
                break;
                case 8:
                printf("\n");
                printf("LEMBRE QUE A ANO É BISSEXTO\n");
                pausar();
                break;
            }
        }
    }while(!(strcmp(data,"S") == 0 || strcmp(data,"s") == 0) && converte_numero(data) != SAIR && !controle ->valida);
    if(strcmp(data,"S") == 0 || strcmp(data,"s") == 0){
        saida = 2;
    }
    else saida = controle ->valida;
    if(controle ->valida)cabecalho ->DHD = listaChar(cabecalho ->DHD,data);
    free(controle);
    return saida;
}

int ler_hora(Cabecalho *cabecalho){ 
    int saida;
    char hora[50];
    SEP *controle;
    controle = (SEP *) malloc(sizeof(SEP));
    controle ->valida = False;
    do{ 
        limparTela();
        char titulo[16] = "CADASTRAR SHOW";
        func_Ani_Left(titulo);
        printf("==================================================\n");
        printf("|   INSIRA A HORA DE INÍCIO DO SHOW: ");
        ler_string(hora,50);
        retira_char(hora,' ');
        if(converte_numero(hora) != SAIR){
            valida_hora(controle,hora);
            switch(controle -> error){ 
                case 1:
                printf("\n");
                printf("FORMATO INVALIDO PARA HORA, INSIRA hora:minuto\n");
                pausar();
                break;
                case 2:
                printf("\n");
                printf("FORMATO INVALIDO PARA HORA, INSIRA O ':'\n");
                pausar();
                break;
                case 3:
                printf("\n");
                printf("DIGITE APENAS NUMEROS EM HORAS\n");
                pausar();
                break;
                case 4:
                printf("\n");
                printf("DIGITE APENAS DE 1 A 24 EM HORAS\n");
                pausar();
                break;
                case 5:
                printf("\n");
                printf("DIGITE APENAS NUMEROS EM MINUTOS\n");
                pausar();
                break;
                case 6:
                printf("\n");
                printf("DIGITE APENAS DE 1 A 59 EM MINUTOS\n");
                pausar();
                break;
            }
        }
    }while(!controle ->valida && !converte_numero(hora) == SAIR);
    saida = controle ->valida;
    if(controle ->valida)cabecalho ->DHD = listaChar(cabecalho ->DHD,hora);
    free(controle);
    return saida;
}

int ler_duracao(Cabecalho *cabecalho){
    int saida;
    char duracao[50];
    SEP *controle;
    controle = (SEP *) malloc(sizeof(SEP));
    controle ->valida = False;
    do{
        limparTela();
        char titulo[16] = "CADASTRAR SHOW";
        func_Ani_Left(titulo);
        printf("==================================================\n");
        printf("|  INSIRA A DURAÇÃO DO SHOW : ");
        ler_string(duracao,50);
        retira_char(duracao,' ');
        if(converte_numero(duracao) != SAIR){
            valida_duracao(controle,duracao);
             switch(controle ->error){ 
                case 1:
                printf("\n");
                printf("FORMATO INVALIDO PARA HORA, INSIRA hora:minuto\n");
                pausar();
                break;
                case 2:
                printf("\n");
                printf("FORMATO INVALIDO PARA HORA, INSIRA O ':'\n");
                pausar();
                break;
                case 3:
                printf("\n");
                printf("DIGITE APENAS NUMEROS EM HORAS\n");
                pausar();
                break;
                case 4:
                printf("\n");
                printf("DIGITE APENAS DE 1 A 5 EM HORAS\n");
                pausar();
                break;
                case 5:
                printf("\n");
                printf("DIGITE APENAS NUMEROS EM MINUTOS\n");
                pausar();
                break;
                case 6:
                printf("\n");
                printf("DIGITE APENAS DE 1 A 59 EM MINUTOS\n");
                pausar();
                break;
            }  
        }
    }while(!controle ->valida && !converte_numero(duracao) == SAIR);
    saida = controle ->valida;
    if(controle ->valida)cabecalho ->DHD = listaChar(cabecalho ->DHD,duracao);
    free(controle);
    return saida;
}

int ler_persona(Cabecalho *cabecalho){
    int saida;
    char nome[50];
    char nome_tratado[50];
    int parar;

    saida = True;
    parar = True;
    do{ 
    limparTela();
    char titulo[16] = "CADASTRAR SHOW";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("================================================================\n"); 
    printf("|  INSIRA O NOME DOS PERSONAGENS - DIGITE (S) PARA SAIR: ");
    ler_string(nome,50);
    
    strcpy(nome_tratado,nome);

    retira_char(nome_tratado,' ');
    if(converte_numero(nome) != SAIR && !(strcmp(nome,"S") == 0 || strcmp(nome,"s") == 0)){
        cabecalho ->persona = listaChar(cabecalho ->persona,nome);
    }
    else if(strcmp(nome,"S") == 0 || strcmp(nome,"s") == 0){
        if(strlen(cabecalho ->persona) < 2){
            saida = False;
            parar = False;
        }
        else{
            saida = True;
            parar = False;
        }
    }
    else{
        saida = False;
        parar = False;

    }
    }while(parar);
    return saida;
}



//  ##############################  FUNÇÕES DE LEITURA DO MÓDULO INGRESSO  ################################

int id_ingresso(void){  //Cria um id(codigo) para um ingresso vendido
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

int ler_cpf_show(Dados_I *dados){  //Ler o CPF do cliente que realiza a compra do ingresso
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
        retira_char(dados ->cpf,' ');
        if(converte_numero(dados ->cpf) != SAIR){ 
            valida_cpf_show(controle,dados);
            switch (controle ->error){
                case 1:
                printf("\n");
                printf("CLIENTE NÃO CADASTRADO\n");
                pausar();
                break;
                case 2:
                printf("\n");
                printf("CPF INSERIDO NÃO VÁLIDO\n");
                pausar();
            }
        }
        
    }while(!controle ->valida && !converte_numero(dados ->cpf) == SAIR);
    saida = controle ->valida;
    free(controle);
    return saida;
}

int ler_codigo(Dados_I *dados){  //Ler o id(codigo) do show que o cliente escolheu
    int saida;
    char id_lido[50];
    SEP *controle;
    controle = (SEP *) malloc(sizeof(SEP));
    
    controle ->valida = False;
    do{ 
        limparTela();
        char titulo[16] = "VENDER INGRESSO";
        func_Ani_Left(titulo);
        printf("====================================\n"); 
        printf("|  INSIRA O CÓDIGO DO SHOW: ");
        ler_string(id_lido,50);
        retira_char(id_lido,' ');
        if(converte_numero(id_lido) != SAIR){
            valida_ler_codigo(controle,id_lido);
            switch (controle ->error){
                case 1:
                printf("\n");
                printf("SHOW NÃO ENCONTRADO\n");
                pausar();
                break;

                case 2:
                printf("\n");
                printf("CÓDIGO DO SHOW INVALIDO, DIGITE APENAS NUMEROS\n");
                pausar();
                break;
            }
        }
       if(controle ->valida){
        dados ->id_show = converte_numero(id_lido);
       } 
    }while( !controle ->valida && !converte_numero(id_lido) == SAIR);
    saida = controle ->valida;
    free(controle);
    return saida;
}

int ler_cadeira(Dados_I *dados){ //Ler o assento do show que o cliente escolheu
    int saida;
    SEP *controle;
    controle = (SEP *) malloc(sizeof(SEP));
    
    controle ->valida = False;
    do{ 
        limparTela();
        char titulo[16] = "VENDER INGRESSO";
        func_Ani_Left(titulo);
        exibir_cadeiras(dados ->id_show);
        printf("====================================\n"); 
        printf("|  ESCOLHA SUA CADEIRA: ");
        ler_string(dados->cadeira,5);
        retira_char(dados ->cadeira,' ');
        if(converte_numero(dados ->cadeira) != SAIR){
            valida_cadeira(dados ->cadeira,dados ->id_show,controle);
            switch (controle ->error){
                case 1:
                printf("\n");
                printf("CADEIRA INSERIDA NAO VALIDA, ESCOLHA DE ACORDO COM O QUE ESTÁ SENDO EXIBIDO\n");
                pausar();
                break;
                case 2:
                printf("\n");
                printf("LINHA DE CADEIRAS NÃO EXISTENTE, DIGITE APENAS LETRAS (A - E)\n");
                pausar();
                break;
                case 3:
                printf("\n");
                printf("COLUNA DE CADEIRAS NÃO EXISTENTE, DIGITE APENAS NUMEROS (1 - 20)\n");
                pausar();
                break;
                case 4:
                printf("\n");
                printf("CADEIRA ESCOLHIDA JÁ OCUPADA, POR FAVOR ESCOLHER OUTRA\n");
                pausar();
                break;
            }
        }
    }while(!controle ->valida && !converte_numero(dados ->cadeira) == SAIR);
    if(controle ->valida){
        Mapeia *coord;
        coord = (Mapeia *) malloc(sizeof(Mapeia));
        procura_cad(dados ->cadeira,coord);
        dados ->cord_i = coord ->i;
        dados ->cord_j = coord ->j;
        free(coord);
    }
    saida = controle ->valida;
    free(controle);
    return saida;
}


//  ##############################  FUNÇÕES DE LEITURA DO MÓDULO CLIENTES E TECNICOS  ################################

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

