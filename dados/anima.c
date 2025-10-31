#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anima.h"
#include "utils.h"
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
    limparTela();
    printf("\n╔═════════════════════════════════════════════════╗\n");
    printf("║ OBRIGADO POR USAR O SIG-THEATER                 ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║                                                 ║\n");
    printf("║ Sistema encerrado com sucesso!                  ║\n");
    printf("║                                                 ║\n");
    printf("║ Esperamos que o SIG-Theater tenha ajudado na    ║\n");
    printf("║ organização dos seus espetáculos.               ║\n");
    printf("║                                                 ║\n");
    printf("║ Continue levando a magia da arte e da cultura   ║\n");
    printf("║ ao seu público com excelência!                  ║\n");
    printf("║                                                 ║\n");
    printf("║ Até a próxima apresentação!                     ║\n");
    printf("║                                                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");

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
    int titulo_len = strlen(titulo);
    int espacos = (TAM_INTERNO - titulo_len) / 2;
    
    printf("║");
    for (i = 0; i < espacos; i++) printf(" ");
    printf("%s", titulo);
    for (i = 0; i < TAM_INTERNO - espacos - titulo_len; i++) printf(" ");
    printf("║\n");  

    // Linha inferior
    printf("╚");
    for (i = 0; i < TAM_INTERNO; i++) printf("═");
    printf("╝\n");

}

int tempo_Banner = 100;
void mostrar_banner() {
    printf("\n");
    func_Ani(tempo_Banner);
    printf("       /$$$$$$$                                /$$    /$$ /$$                 /$$                        \n");
    func_Ani(tempo_Banner);
    printf(" *    | $$__  $$                              | $$   | $$|__/                | $$                        \n");
    func_Ani(tempo_Banner);
    printf(" *    | $$  \\ $$  /$$$$$$  /$$$$$$/$$$$       | $$   | $$ /$$ /$$$$$$$   /$$$$$$$  /$$$$$$               \n");
    func_Ani(tempo_Banner);
    printf(" *    | $$$$$$$  /$$__  $$| $$_  $$_  $$      |  $$ / $$/| $$| $$__  $$ /$$__  $$ /$$__  $$              \n");
    func_Ani(tempo_Banner);
    printf(" *    | $$__  $$| $$$$$$$$| $$ \\ $$ \\ $$       \\  $$ $$/ | $$| $$  \\ $$| $$  | $$| $$  \\ $$              \n");
    func_Ani(tempo_Banner);
    printf(" *    | $$  \\ $$| $$_____/| $$ | $$ | $$        \\  $$$/  | $$| $$  | $$| $$  | $$| $$  | $$              \n");
    func_Ani(tempo_Banner);
    printf(" *    | $$$$$$$/|  $$$$$$$| $$ | $$ | $$         \\  $/   | $$| $$  | $$|  $$$$$$$|  $$$$$$/              \n");
    func_Ani(tempo_Banner);
    printf(" *    |_______/  \\_______/|__/ |__/ |__/          \\_/    |__/|__/  |__/ \\_______/ \\______/               \n");
    func_Ani(tempo_Banner);
    printf(" *                                                                                                        \n");
    func_Ani(tempo_Banner);
    printf(" *                                          /$$$$$$   /$$$$$$                                            \n");
    func_Ani(tempo_Banner);
    printf(" *                                         |____  $$ /$$__  $$                                           \n");
    func_Ani(tempo_Banner);
    printf(" *                                          /$$$$$$$| $$  \\ $$                                           \n");
    func_Ani(tempo_Banner);
    printf(" *                                         /$$__  $$| $$  | $$                                           \n");
    func_Ani(tempo_Banner);
    printf(" *                                        |  $$$$$$$|  $$$$$$/                                           \n");
    func_Ani(tempo_Banner);
    printf(" *                                         \\_______/ \\______/                                           \n");
    func_Ani(tempo_Banner);
    printf(" *                                                                                                        \n");
    func_Ani(tempo_Banner);
    printf(" *               /$$                /$$$$$$$$ /$$                             /$$                        \n");
    func_Ani(tempo_Banner);
    printf(" *              |__/               |__  $$__/| $$                            | $$                        \n");
    func_Ani(tempo_Banner);
    printf(" *      /$$$$$$$ /$$  /$$$$$$         | $$   | $$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ \n");
    func_Ani(tempo_Banner);
    printf(" *     /$$_____/| $$ /$$__  $$ /$$$$$$| $$   | $$__  $$ /$$__  $$ |____  $$|_  $$_/   /$$__  $$ /$$__  $$\n");
    func_Ani(tempo_Banner);
    printf(" *    |  $$$$$$ | $$| $$  \\ $$|______/| $$   | $$  \\ $$| $$$$$$$$  /$$$$$$$  | $$    | $$$$$$$$| $$  \\__/\n");
    func_Ani(tempo_Banner);
    printf(" *     \\____  $$| $$| $$  | $$        | $$   | $$  | $$| $$_____/ /$$__  $$  | $$ /$$| $$_____/| $$      \n");
    func_Ani(tempo_Banner);
    printf(" *     /$$$$$$$/| $$|  $$$$$$$        | $$   | $$  | $$|  $$$$$$$|  $$$$$$$  |  $$$$/|  $$$$$$$| $$      \n");
    func_Ani(tempo_Banner);
    printf(" *    |_______/ |__/ \\____  $$        |__/   |__/  |__/ \\_______/ \\_______/   \\___/   \\_______/|__/      \n");
    func_Ani(tempo_Banner);
    printf(" *                   /$$  \\ $$                                                                            \n");
    func_Ani(tempo_Banner);
    printf(" *                  |  $$$$$$/                                                                            \n");
    func_Ani(tempo_Banner);
    printf(" *                  \\______/                                                                             \n");
    func_Ani(tempo_Banner);  
}