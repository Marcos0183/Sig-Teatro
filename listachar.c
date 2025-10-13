#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listachar.h"
// ##################FUNÇÃO PARA UM VETOR DINÂMICO DE CARACTERES######################
// MODELO RETIRADO DO LIVRO (Introdução a Estruturas de Dados com técnicas de programação em C SEGUNDA EDIÇÃO)
//com modificações do CHATGPT 4.0

void realoca(ListaCha *cr, int n){
    cr ->v = (char *) realloc(cr ->v,n+1);
    if(cr ->v == NULL){
        printf(stderr,"Erro ao Salvar Dados\n");
        exit(1);
    }
}


void atribui(ListaCha *cr, const char *s){
    realoca(cr,strlen(s));
    strcpy(cr ->v,s);
}


ListaCha *criacopia(const char *s){
    ListaCha *cr = (ListaCha *) malloc(sizeof(ListaCha));
    cr ->v = NULL;
    atribui(cr,s);
    return cr;
}


ListaCha *criavazia(void){
    return criacopia("");
}


void concatena(ListaCha *cr, const char *s){
    int tam = strlen(cr ->v) + strlen(s);
    realoca(cr,tam);
    strcat(cr->v,s);
}


const char *acessar(ListaCha *cr){
    return cr ->v;
}


void liberarM(ListaCha *cr){
    free(cr ->v);
    free(cr);
}

ListaCha *listaChar(void *cr, char *s){
    char virgula = ',';
    ListaCha *lista = (ListaCha *) cr;
    if(cr == NULL){
        lista = criavazia();
    } 
    concatena(lista,s);
    concatena(lista,virgula);
    return lista;
}

