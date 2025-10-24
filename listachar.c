#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listachar.h"
// ##################FUNÇÃO PARA UM VETOR DINÂMICO DE CARACTERES######################
// MODELO RETIRADO DO LIVRO (Introdução a Estruturas de Dados com técnicas de programação em C SEGUNDA EDIÇÃO)
//com modificações do CHATGPT 4.0

void realoca(char **cr, int n){
    *cr = (char *) realloc(*cr,n+1);
    if(cr == NULL){
        printf("Erro ao Salvar Dados\n");
        exit(1);
    }
}


void atribui(char **cr, const char *s){
    realoca(cr,strlen(s));
    strcpy(*cr,s);
}


char *criacopia(const char *s){
    char *cr = (char *) malloc(sizeof(char));
    cr = NULL;
    atribui(&cr,s);
    return cr;
}

 char *criavazia(void){
    return criacopia("");
}


void concatena(char **cr, const char *s){
    int tam = strlen(*cr) + strlen(s);
    realoca(cr,tam);
    strcat(*cr,s);
}


const char *acessar(char *cr){
    return cr;
}


void liberarM(char *cr){
    free(cr);
}

//Sempre que usar essa função lembre:
//1. De iniciar a variavel do tipo char ponteiro com NULL a primeira vez que for usala-la
//Ex: cr = NULL;
char *listaChar(char *cr,const char *s){ 
    char *virgula = ",";
    if(cr == NULL){
        cr = criavazia();
    } 
    concatena(&cr,s);
    concatena(&cr,virgula); 
    return cr;
}

