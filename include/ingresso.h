#ifndef INGRESSO_H
#define INGRESSO_H

void ingresso();

void vender_Ingresso();

void excluir_Ingresso();  

void atualizar_Ingresso();

void pesquisar_Ingresso();

typedef struct vender_Ingresso Dados_I;

struct vender_Ingresso{
    
    char cpf[20];
    char codigo_Show[5];
    char cadeira[5];
    char status;

};

#endif
