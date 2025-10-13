#ifndef LISTACHAR_H
#define LISTACHAR_H

typedef struct lista_str ListaCha;
struct lista_str{
    char *v;
};

ListaCha *listaChar(void *, char *);

#endif