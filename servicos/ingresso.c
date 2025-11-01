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
    char escolha[2];
    int parar;
    int saida;
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
    
    saida = False;
    while(parar){ 
        printf("COMPRAR INGRESS0 - SIM(S)/NAO(N): ");
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
       
    arq_ingresso = fopen("arq_ingresso.dat","ab");
    if(arq_ingresso == NULL)return;
    if(saida){
        dados ->id = id_ingresso();
        dados->status = True;
        printf("%s\n",dados ->cpf);
        printf("%d",dados ->status);
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
    char id_lido[6];
    FILE *arq_ingresso;
    Dados_I *dados;

    dados = (Dados_I *) malloc(sizeof(Dados_I));
    char titulo[19] = "EXCLUIR INGRESSO";
    func_Ani_Left(titulo);
    
    do{ 
    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO INGRESSO: ");
    ler_string(id_lido,6);
    printf("-----------------------------------\n");
    }while(!valida_id(id_lido));

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
    //int parar;
    //parar = True;
    // char id_lido[6];
    // FILE *arq_ingresso;
    // Dados_I *dados;

    // dados = (Dados_I *) malloc(sizeof(Dados_I));
    // char titulo[19] = "ATUALIZAR INGRESSO";
    // func_Ani_Left(titulo);
    
    // parar;
    // do{ 
    //     printf("\n \n");
    //     printf("-----------------------------------\n");
    //     printf("|  INSIRA O CODIGO DO INGRESSO: ");
    //     ler_string(id_lido,6);
    //     printf("-----------------------------------\n");
    //     pausar();
    // }while(parar);
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
    printf("-----------------------------------\n\n");

    if(valida_cliente(cpf_lido) && valida_cpf(cpf_lido)){
        pesquisar_ingresso(dados,cpf_lido);
    }
    else{
        printf("\n");
        printf("INGRESSO NÃO ENCONTARDO\n\n");
    }
    pausar();
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

void altera_cadeira(char *assento,int id_parametro){
    int parar;
    Cadeiras *cadeira;
    Mapeia *coord;
    FILE *arq_cadeiras;
    cadeira = (Cadeiras *) malloc(sizeof(Cadeiras));
    coord = (Mapeia *) malloc(sizeof(Mapeia));

    arq_cadeiras = fopen("arq_cadeiras.dat","r+b");
    abrir_arquivo(arq_cadeiras);
    parar = 1;
    while(fread(cadeira,sizeof(Cadeiras),1,arq_cadeiras) == 1 && parar){
        if(cadeira ->id == id_parametro){
            procura_cad(assento,coord);
            strcat(cadeira ->cad[coord ->i][coord ->j],"!");
            cadeira ->cont++;
            fseek(arq_cadeiras,-sizeof(Cadeiras),SEEK_CUR);
            fwrite(cadeira,sizeof(Cadeiras),1,arq_cadeiras);
            parar = 0;
        }
    }
    fclose(arq_cadeiras);
    free(cadeira);
    free(coord);
}

void procura_cad(char *assento,Mapeia *cordenadas){ 
    char converte[5] = "";
    switch(assento[0]){
        case 'A':
            cordenadas ->i = 0;
        break;
        case 'B':
            cordenadas ->i = 1;
        break;
        case 'C':
            cordenadas ->i = 2;
        break;
        case 'D':
            cordenadas ->i = 3;
        break;
        case 'E':
            cordenadas ->i = 4;
        break;
    }
    strcat(converte,&assento[1]);
    cordenadas ->j = converte_numero(converte) - 1;
}

int cadeira_usada(char *cad,int id_show){
    int saida = False;
    int parar = True;
    Cadeiras *assento;
    Mapeia *cord;
    FILE *arq_cadeira;
    cord = (Mapeia *) malloc(sizeof(Mapeia));
    assento = (Cadeiras *) malloc(sizeof(Cadeiras));
    arq_cadeira = fopen("arq_cadeiras.dat","rb");
    if(arq_cadeira == NULL)return False;
    

    procura_cad(cad,cord);
    while(fread(assento,sizeof(Cadeiras),1,arq_cadeira) == 1 && parar){
        if(assento ->id == id_show){
            parar = False;
            if(!(strchr(assento ->cad[cord ->i][cord ->j],'!') != NULL))saida = True;
        }
    }
    fclose(arq_cadeira);
    free(assento);
    free(cord);
    return saida;
}

void exibir_cadeiras(int id_show){
    int parar = True;
    Cadeiras *assento;
    FILE *arq_cadeira;
    assento = (Cadeiras *) malloc(sizeof(Cadeiras));
    arq_cadeira = fopen("arq_cadeiras.dat","rb");
    abrir_arquivo(arq_cadeira);

     while(fread(assento,sizeof(Cadeiras),1,arq_cadeira) == 1 && parar){
        if(assento ->id == id_show){
            for(int i = 0; i < 5; i++){
                printf("\n");
                for(int p = 0;p < 70;p++){
                    printf("-");
                }
                printf("\n\n");

                for(int j = 0; j < 20; j++){
                    if(strchr(assento ->cad[i][j],'!') == NULL ){
                        printf(" %s ",assento ->cad[i][j]);
                        printf("|");   
                    } 
                    else{
                        printf("    ");
                        printf("|");  
                    }    
                }          
            }   
        }
    }
    fclose(arq_cadeira);
    free(assento);
    printf("\n\n");
}

void vagar_cadeira(Dados_I *dados){
    int parar;
    FILE *arq_cadeira;
    Cadeiras *cadeira;
    cadeira = (Cadeiras *) malloc(sizeof(Cadeiras));

    arq_cadeira = fopen("arq_cadeiras.dat","r+b");
    if(arq_cadeira == NULL)return;
 
    parar = True;
    while(fread(cadeira,sizeof(Cadeiras),1,arq_cadeira) == 1 && parar){
        if(dados ->id_show == cadeira ->id){
            ler_ate(cadeira ->cad[dados ->cord_i][dados ->cord_j],'!');
            printf("%s",cadeira ->cad[dados ->cord_i][dados ->cord_j]);
            pausar();
            fseek(arq_cadeira,-sizeof(Cadeiras),SEEK_CUR);
            fwrite(cadeira,sizeof(Cadeiras),1,arq_cadeira);
            parar = False;
        }
    }
    fclose(arq_cadeira);
    free(cadeira);
}