#ifndef INGRESSO_H
#define INGRESSO_H

typedef struct vender_Ingresso Dados_I;
typedef struct mapeia_cadeira Mapeia;
struct vender_Ingresso{
    
    char cpf[20];
    int id_show;
    char cadeira[6];
    int cord_i;
    int cord_j;
    int status;
    
};
struct mapeia_cadeira{
    int i;
    int j;
};

void ingresso();

void vender_Ingresso();

void excluir_Ingresso();  

void atualizar_Ingresso();

void pesquisar_Ingresso();

void altera_cadeira(char *,int);

void procura_cad(char *,Mapeia *);

int cadeira_usada(char *,int);

void exibir_cadeiras(int);

#endif
