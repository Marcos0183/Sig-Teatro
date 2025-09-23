#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



void pausar() {
    printf("\n Pressione Enter para continuar...");
    limparBuffer();
}



void limparTela() {
    system("clear || cls");
}