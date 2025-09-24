#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anima.h"
#define TAM_LINHA 60
#define TAM_INTERNO (TAM_LINHA - 2)
#ifdef _WIN64 // Caso windows 64, use:
    #include <windows.h>  //Trecho de código tirado do ChatGPT
#else // Se não, Linux,Mcos, use:
    #include <unistd.h>
#endif

void ani_Encerrar(){
    printf("\n \n");
    
    int i;
    int j;
    for (i = 0; i < 4; i++){
        system("clear||cls");
        printf("ENCERRAR PROGRAMA ");
        for (j = 0; j < 5; j++){
            func_Ani(300);
            printf(". ");
            fflush(stdout); 
        }
    }
    system("clear||cls");
    printf("PROGRAMA ENCERRADO\n");
}

void func_Ani(int tempo){  //Função retirada do ChatGPT 4.0
    #ifdef _WIN64
        Sleep(tempo);
    #else
        usleep(tempo * 1000); 
        //struct timespec ts;
        //ts.tv_sec = tempo / 1000;                 
        //ts.tv_nsec = (tempo % 1000) * 1000000L;   
        //nanosleep(&ts, NULL);
    #endif
}

void func_Ani_Left(const char titulo[]) {
    system("clear||cls");

    int i;

    // Linha superior
    printf("╔");
    for (i = 0; i < TAM_INTERNO; i++) printf("═");
    printf("╗\n");

    // Linha do título centralizado
    int titulo_len = strlen(titulo);  // cuidado: conta bytes!
    int espacos = (TAM_INTERNO - titulo_len) / 2;
    
    printf("║");
    for (i = 0; i < espacos; i++) printf(" ");
    printf("%s", titulo);
    for (i = 0; i < TAM_INTERNO - espacos - titulo_len; i++) printf(" ");
    printf("║\n");  // removido espaço antes do ║

    // Linha inferior
    printf("╚");
    for (i = 0; i < TAM_INTERNO; i++) printf("═");
    printf("╝\n");

}
