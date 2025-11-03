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
    int saida;
    char id_lido[5];
    SEP *controle;
    controle = (SEP *) malloc(sizeof(SEP));
    
    controle ->valida = False;
    do{ 
        limparTela();
        char titulo[16] = "VENDER INGRESSO";
        func_Ani_Left(titulo);
        printf("====================================\n"); 
        printf("|  INSIRA O CÓDIGO DO SHOW: ");
        ler_string(id_lido,5);
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
    }while( !controle ->valida && !converte_numero(id_lido) == 00);
    saida = controle ->valida;
    free(controle);
    return saida;
}



int ler_cadeira(Dados_I *dados){ 
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
    }while(!controle ->valida && !dados ->id_show == SAIR);
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



int ler_nome_show(char *nome){
    limparTela();
    char titulo[16] = "ATUALIZAR SHOW";
    func_Ani_Left(titulo);
    printf("\n \n");
    printf("====================================\n"); 
    printf("|  INSIRA O NOME DO SHOW: ");
    ler_string(nome,32);
    retira_char(nome,' ');
    if(converte_numero(nome) == SAIR)return False;
    return True;
}



void ler_DHD(Cabecalho *cabecalho){
    int parar;
    Dados_Temp *inf;
    inf = (Dados_Temp *) malloc(sizeof(Dados_Temp));
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
    saida = controle ->valida;
    if(controle ->valida)listaChar(cabecalho ->DHD,data);
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
    if(controle ->valida)listaChar(cabecalho ->DHD,hora);
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
        controle ->valida = False;
        if(converte_numero(duracao) != SAIR){
            valida_duracao(controle,duracao);
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
    if(controle ->valida)listaChar(cabecalho ->DHD,duracao);
    free(controle);
    return saida;
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



int ler_escolha(char *texto){
    int parar = False;
    int saida = False;
    int converte;
    char escolha[4];
    do{ 
        printf("%s - SIM(S)/NAO(N): ",texto);
        ler_string(escolha,4);
        retira_char(escolha,' ');
        converte = converte_numero(escolha);
        if(strcmp(escolha,"S") == 0 || strcmp(escolha,"s") == 0){
            saida = True;
            parar = True;
        }
        else if(strcmp(escolha,"N") == 0 || strcmp(escolha,"N") == 0){
            parar = True;
        }
        else if(converte == SAIR){
            parar = True;
        }
        else printf("ESCOLHA APENAS S-s PARA SIM E N-n PARA NÃO\n");
    }while(!parar);
    return saida;
}