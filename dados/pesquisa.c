#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "anima.h"
#include "shows.h"
#include "ingresso.h"
#include "clientes.h"
#include "pesquisa.h"


char cadeira_copia[5][20][6] = { // Modelo de bancos
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

//########################################## FUNÇÕES DE PROCURA DO MÓDULO RELATÓRIO ################################################

void exibir_rel_ingresso(Dados_I *dados_I){ // Exibe dados dos ingressos comprados e válidos somente no módulo relatório
    int parar;
    FILE *arq_cliente;
    FILE *arq_show;
    Dados_S *dados_S;
    Cliente *dados_C;
    dados_S = (Dados_S *) malloc(sizeof(Dados_S));
    dados_C = (Cliente *) malloc(sizeof(Cliente));
    
    arq_cliente = fopen("clientes.dat","rb");
    if(arq_cliente == NULL)return;
    arq_show = fopen("arq_shows.dat","rb");
    if(arq_show == NULL)return;

    parar = True;
    while(parar && fread(dados_C,sizeof(Cliente),1,arq_cliente) == 1){
        if(strcmp(dados_C ->cpf, dados_I ->cpf) == 0){
            parar = False;
        } 
    }

    parar = True;
    while( parar && fread(dados_S,sizeof(Dados_S),1,arq_show) == 1){ 
        if(dados_S ->id == dados_I ->id_show){
            parar = False;
        }
        else fseek(arq_show,dados_S ->tam_DHD + dados_S ->tam_personagem,SEEK_CUR);
    }
    
    printf("|%-16s|%-47s|%-3.3d - %-37s|%-9s|%.4d|\n",dados_I ->cpf,dados_C ->nome,dados_S ->id,dados_S ->nome,dados_I ->cadeira,dados_I ->id);
    printf("|---------------------------------------------------------------------------------------------------------------------------|\n");
   
    
    fclose(arq_cliente);
    fclose(arq_show);
    free(dados_C);
    free(dados_S);
}
    

//######################################### FUNÇÕES DE PROCURA DO MÓDULO INGRESSO #################################################

void exibir_ingresso(Dados_I *dados_I,int revelar){ // Exibe os dados do ingresso somente no CRUD de ingresso
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
    printf("| Nome-Id Show : %.4d - %-40s  |\n",dados_S ->id,dados_S ->nome);
    printf("| Cadeira      : %-46s |\n",dados_I->cadeira);
    if(revelar)printf("| Id_Ingresso  : %-46.4d |\n",dados_I->id);
    printf("+---------------------------------------------------------------+\n");
    
    free(dados_C);
    free(dados_S);
}

void pesquisar_ingresso(Dados_I *dados,char *cpf_lido){ // Procura os dados de um ingresso a partir de um CPF
    limparTela();
    FILE *arq_ingresso;
    arq_ingresso = fopen("arq_ingresso.dat","rb");
    if(arq_ingresso == NULL){
        printf("ERRO AO ABRIR ARQUIVO DE INGRESSOS\n");
        pausar();
        exit(1);
    }

    while(fread(dados,sizeof(Dados_I),1,arq_ingresso) == 1){
        if(strcmp(dados ->cpf,cpf_lido) == 0 && dados ->status == True){
            exibir_ingresso(dados,True);
        }
    }
    fclose(arq_ingresso);
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
            parar = False;
            for(int i = 0; i < 5; i++){
                printf("\n");
                for(int p = 0;p < 110;p++){
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
            cadeira ->cont --;
            fseek(arq_cadeira,-sizeof(Cadeiras),SEEK_CUR);
            fwrite(cadeira,sizeof(Cadeiras),1,arq_cadeira);
            parar = False;
        }
    }
    fclose(arq_cadeira);
    free(cadeira);
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

void altera_cadeira(char *assento,int id_parametro){
    int parar;
    Cadeiras *cadeira;
    Mapeia *coord;
    FILE *arq_cadeiras;
    cadeira = (Cadeiras *) malloc(sizeof(Cadeiras));
    coord = (Mapeia *) malloc(sizeof(Mapeia));

    arq_cadeiras = fopen("arq_cadeiras.dat","r+b");
    if(arq_cadeiras == NULL)return;

    parar = True;
    while(fread(cadeira,sizeof(Cadeiras),1,arq_cadeiras) == 1 && parar){
        if(cadeira ->id == id_parametro){
            procura_cad(assento,coord);
            strcat(cadeira ->cad[coord ->i][coord ->j],"!");
            cadeira ->cont++;
            fseek(arq_cadeiras,-sizeof(Cadeiras),SEEK_CUR);
            fwrite(cadeira,sizeof(Cadeiras),1,arq_cadeiras);
            parar = False;
        }
    }
    fclose(arq_cadeiras);
    free(cadeira);
    free(coord);
}


//######################################## FUNÇÕES DE PROCURA/CRIAÇÃO DO MÓDULO SHOWS #############################################

void exibir_inf_cadastro(Cabecalho *cabecalho,int revelar){
    printf("+---------------------------------------------------------------+\n");
    printf("|                     DADOS DO SHOW                             |\n");
    printf("+---------------------------------------------------------------+\n");   
    if(revelar)printf("| ID       : %-50.3d |\n", cabecalho ->dados ->id);
    printf("| Nome     : %-50s |\n", cabecalho ->dados ->nome);
    printf("| DHD      : %-50s |\n", cabecalho ->DHD);
    printf("| Personagem : %-48s |\n", cabecalho ->persona);
    printf("+---------------------------------------------------------------+\n");
}

int escolha_cad_show(Cabecalho *cabecalho){ 
    char escolha[50];
    int saida;
    int parar;
    parar = True;
    while(parar){ 
        limparTela();
        exibir_inf_cadastro(cabecalho,False);
        printf("CADASTRAR - EXCLUIR SHOW - SIM(S)/NAO(N): ");
        ler_string(escolha,50);
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
        if(cabecalho ->id_lido == cabecalho ->dados ->id && cabecalho ->dados ->status == True){
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
    pausar();
}

void cria_cadeiras(int id_parametro){
    FILE *arq_cadeiras;
    Cadeiras *cadeiras;
    cadeiras = (Cadeiras *) malloc(sizeof(Cadeiras));
    
    copia_carac_D3(cadeira_copia,cadeiras ->cad );
    cadeiras ->id = id_parametro;
    cadeiras ->cont = 0;
    cadeiras ->status = True;

    arq_cadeiras = fopen("arq_cadeiras.dat","ab");
    abrir_arquivo(arq_cadeiras);
    fwrite(cadeiras,sizeof(Cadeiras),1,arq_cadeiras);
    fclose(arq_cadeiras);
    free(cadeiras);
}

void apaga_cadeiras(int id_parametro){ // Apaga determido grupo de assentos do show pelo id especificado no parâmetro
    Cadeiras *cadeira;
    FILE *arq_cadeiras;
    cadeira = (Cadeiras *) malloc(sizeof(Cadeiras));
    
    arq_cadeiras = fopen("arq_cadeiras.dat","r+b");
    if(arq_cadeiras == NULL){
        printf("PROBLEMAS AO ABRIR O ARQUIVO DE ASSENTOS, POR FAVOR TENTAR NOVAMENTE\n");
        pausar();
        exit(1);
    }
     
    while(fread(cadeira,sizeof(Cadeiras),1,arq_cadeiras) == 1){
        if(cadeira ->id == id_parametro && cadeira ->status == True){
            fseek(arq_cadeiras,-sizeof(Cadeiras),SEEK_CUR);
            cadeira ->status = False;
            fwrite(cadeira,sizeof(Cadeiras),1,arq_cadeiras);
            break;
        }
    }
    fclose(arq_cadeiras);
    free(cadeira);
}

void apaga_ingressos(int id_parametro){
    Dados_I *dados;
    FILE *arq_ingresso;
    dados = (Dados_I *) malloc(sizeof(Dados_I));
    arq_ingresso = fopen("arq_ingresso.dat","r+b");
    if(arq_ingresso == NULL){
        printf("ERRO AO ABRIR ARQUIVO DE INGRESSOS/n");
        pausar();
        exit(1);
    }

    while(fread(dados,sizeof(Dados_I),1,arq_ingresso) == 1){
        if(dados ->id_show  == id_parametro && dados ->status == True){
            dados ->status = False;
            fseek(arq_ingresso,-sizeof(Dados_I),SEEK_CUR);
            fwrite(dados,sizeof(Dados_I),1,arq_ingresso);
            fseek(arq_ingresso, 0, SEEK_CUR);
        }
    }
    fclose(arq_ingresso);
    free(dados);
}








