#include <stdio.h>
#include <stdlib.h>
#include "anima.h"
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

void func_Ani_Left(char titulo[30]){
    system("clear||cls");
    int i;
     //Primeira Linha
    for(i = 0; i<70; i++){  
        printf("#");
        func_Ani(1);
    }
    printf("\n");

    //Segunda Linha
    for(i = 0;i<27; i++){
        if (i > 3 && i < 7){ 
            printf("+");
            func_Ani(15);
        } 
        else{
            printf(" ");
            func_Ani(15);
        }
    }
    printf("%s",titulo);
    
    for(i = 0;i<31;i++){
        if (i > 19 && i < 24){
            printf("+");
            func_Ani(15);
        }
        else{
            printf(" ");
            func_Ani(1);
        }
    }
    printf("\n");

    // Terceira Linha   
    for(i = 0; i<70; i++){  
        printf("#");
        func_Ani(1);
    }
 
}