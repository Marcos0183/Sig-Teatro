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
        printf("║ ► 0. Voltar ao Menu Anterior...                  ║\n");
        func_Ani(tempo_Shows);
        printf("║                                                  ║\n");
        func_Ani(tempo_Shows);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_Shows);
        printf("--> Digite a opção desejada: ");
}



// void cadastrar_Show(){
//     Cabecalho *cabecalho;
//     Dados_Temp *inf;
//     cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
//     cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));
//     inf = (Dados_Temp *) malloc(sizeof(Dados_Temp));
//     int parar;
//     cabecalho ->DHD = NULL;
//     cabecalho ->persona = NULL;
//     char titulo[16] = "CADASTRAR SHOW";
//     func_Ani_Left(titulo);

    
//     cabecalho ->dados ->id = id_show();
//     printf("\n \n");
//     printf("-----------------------------------\n");
//     printf("|  INSIRA O NOME DO SHOW: ");
//     ler_string(cabecalho ->dados->nome,32);     

    
//     parar = True;
//     printf("-----------------------------------\n");
//     while(parar){ 
//         printf("|  INSIRA A DATA DO SHOW - DIGITE (S) PARA ENCERRAR: ");
//         ler_string(inf ->data,12);
        
//         printf("-----------------------------------\n");
//         if(strcmp(inf ->data,"S") == 0 || strcmp(inf ->data,"s") == 0) parar = False;
//         else{ 
//             DHD = listaChar(DHD,inf ->data);

//             printf("|  INSIRA A HORA DE INÍCIO DO SHOW: "); 
//             ler_string(inf ->hora,6);
//             printf("-----------------------------------\n");
//             listaChar(DHD,inf ->hora);
           
//             printf("|  INSIRA A DURAÇÃO DO SHOW: ");        
//             ler_string(inf ->duracao,5);
//             printf("-----------------------------------\n");
//             listaChar(DHD,inf ->hora);           
//         }
//     }
    

//     parar = True;
//     while(parar){
//         printf("|  INSIRA OS PERSONAGENS DO SHOW - DIGITE (S) PARA ENCERRAR: ");
//         ler_string(inf ->personagem,32);
//         printf("-----------------------------------\n");
//         if(strcmp(inf ->personagem,"S") == 0 || strcmp(inf ->personagem,"s") == 0) parar = False;
//         else{
//             persona = listaChar(persona,inf ->personagem);
//         }
//     }

//     dados ->tam_DHD = strlen(DHD) + 1;
//     dados ->tam_personagem = strlen(persona) + 1;
//     arq_Shows = fopen("arq_shows.dat","ab");
//     dados ->status = True;
//     fwrite(dados,sizeof(Dados_S),1,arq_Shows);
//     fwrite(DHD,dados ->tam_DHD,1,arq_Shows);
//     fwrite(persona,dados ->tam_personagem,1,arq_Shows);
//     fclose(arq_Shows);
//     free(dados);
//     free(inf);
//     free(DHD);
//     free(persona);
// }


void excluir_Show(){
    int id_lido;
    int encontrado;
    Dados_S *dados;
    dados = (Dados_S *) malloc(sizeof(Dados_S));
    FILE *arq_shows;
    char titulo[16] = "EXCLUIR SHOW";
    func_Ani_Left(titulo);


    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",&id_lido);
    getchar();
    printf("V----------------------------------\n");

    
    encontrado = True;
    arq_shows = fopen("arq_shows.dat","r+b");
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
    system("pause");  
}

void atualizar_Show(){
    int id_lido;
    int encontrado;
    char *DHD;
    char *persona;
    int parar;
    Dados_S *dados;
    Dados_Temp *inf;
    inf = (Dados_Temp *) malloc(sizeof(Dados_Temp));
    dados = (Dados_S *) malloc(sizeof(Dados_S));
    FILE *arq_shows;
    char titulo[16] = "ATUALIZAR SHOW";
    func_Ani_Left(titulo);

    printf("\n \n");
    printf("-----------------------------------\n");
    printf("|  INSIRA O CODIGO DO SHOW: ");
    scanf("%d",&id_lido);
    printf("V----------------------------------\n");


    encontrado = True;
    arq_shows = fopen("arq_shows","r+b");
    while(fread(dados,sizeof(Dados_S),1,arq_shows) == 1){
        if(id_lido == dados ->id && dados ->status == True){
            printf("\n \n");
            printf("-----------------------------------\n");
            printf("|  INSIRA O NOME DO SHOW: ");
            ler_string(dados->nome,32);


            parar = True;
    printf("-----------------------------------\n");
    while(parar){ 
        printf("|  INSIRA A DATA DO SHOW - DIGITE (S) PARA ENCERRAR: ");
        ler_string(inf ->data,12);
        
        printf("-----------------------------------\n");
        if(strcmp(inf ->data,"S") == 0 || strcmp(inf ->data,"s") == 0) parar = False;
        else{ 
            DHD = listaChar(DHD,inf ->data);

            printf("|  INSIRA A HORA DE INÍCIO DO SHOW: "); 
            ler_string(inf ->hora,6);
            printf("-----------------------------------\n");
            listaChar(DHD,inf ->hora);
           
            printf("|  INSIRA A DURAÇÃO DO SHOW: ");        
            ler_string(inf ->duracao,5);
            printf("-----------------------------------\n");
            listaChar(DHD,inf ->hora);           
        }
    }
    

    parar = True;
    while(parar){
        printf("|  INSIRA OS PERSONAGENS DO SHOW - DIGITE (S) PARA ENCERRAR: ");
        ler_string(inf ->personagem,32);
        printf("-----------------------------------\n");
        if(strcmp(inf ->personagem,"S") == 0 || strcmp(inf ->personagem,"s") == 0) parar = False;
        else{
            persona = listaChar(persona,inf ->personagem);
        }
    }

        }
    }
}

void pesquisar_Show(){
    Cabecalho *cabecalho;
    cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
    cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));
    char titulo[16] = "PESQUISAR SHOW";
    func_Ani_Left(titulo);
    ler_id(&cabecalho ->id_lido);
    pesquisaShow(cabecalho);
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
