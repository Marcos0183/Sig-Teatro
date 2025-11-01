#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "leitura.h"
#include "utils.h"
#include "shows.h"
#define true 1
#define false 0


int valida_nome(char *nome) {
    int i;
    int tamanho = strlen(nome);             //função para validar nome
    if (tamanho < 3) {
        return false;
    }
    for (i = 0; i < tamanho; i++) {
        if (!((nome[i] >= 'A' && nome[i] <= 'Z') || (nome[i] >= 'a' && nome[i] <= 'z') || nome[i] == ' ')) {
            return false;
        }
    }
    return true;
}



int valida_cpf(char *cpf_raw) {
    char cpf[20];
    int i, j, soma, resto, dig1, dig2,n;               //função para validar cpf desenvolvida com ajuda de chatgpt

    // Remove tudo que não for número
    j = 0;
    for (i = 0; cpf_raw[i] != '\0'; i++) {
        if (cpf_raw[i] >= '0' && cpf_raw[i] <= '9') {
            cpf[j++] = cpf_raw[i];
        }
    }
    cpf[j] = '\0';

    // Verifica se tem exatamente 11 dígitos
    if (strlen(cpf) != 11) {
        return 0;
    }

    for (n = 0; n < 11; n++) {
        if (cpf[n] < '0' || cpf[n] > '9') {
            return 0;
        }
    }
    // Rejeita CPFs com todos os dígitos iguais (ex: 11111111111)
    // int iguais = 1;
    //for (i = 1; i < 11; i++) {
        // if (cpf[i] != cpf[0]) {
        //    iguais = 0;
        //  break;
       // }
    //}

    //if (iguais) {
        //printf("CPF com todos os dígitos iguais é inválido.\n");
        //return 0;
    //}

    // Calcula o primeiro dígito verificador
    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    dig1 = (resto < 2) ? 0 : 11 - resto;

    // Calcula o segundo dígito verificador
    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    soma += dig1 * 2;
    resto = soma % 11;
    dig2 = (resto < 2) ? 0 : 11 - resto;

    // Compara com os dígitos originais
    if (dig1 == (cpf[9] - '0') && dig2 == (cpf[10] - '0')) {
        return 1; 
    } else {
        return 0; 
    }
}



int valida_telefone(char *telefone) {

    int digitos = 0;                        //função para validar telefone

    for (int i = 0; telefone[i] != '\0'; i++) {
        char c = telefone[i];

        // Aceita apenas números, espaço, parêntese e hífen
        if (!isdigit(c) && c != ' ' && c != '(' && c != ')' && c != '-') {
            return false;
        }
        if (isdigit(c)) {
            digitos++;
        }
    }

    // Telefones brasileiros têm 10 ou 11 dígitos (com DDD)
    if (digitos < 10 || digitos > 11) {
        return false;
    }

    return true;
    }



int valida_email(char *email) {
    int tamanho = strlen(email);
    int i;
    int pos_arroba = -1;
    int pos_ponto = -1;                             //funçao para validar email desenvolvida com ajuda de chatgpt

    // Verifica tamanho mínimo e máximo
    if (tamanho < 5 || tamanho > 254)
        return false;

    // Não pode começar ou terminar com ponto ou arroba
    if (email[0] == '.' || email[0] == '@' ||
        email[tamanho - 1] == '.' || email[tamanho - 1] == '@')
        return false;

    // Percorre cada caractere
    for (i = 0; i < tamanho; i++) {
        char c = email[i];

        // Não pode ter espaço ou caracteres especiais inválidos
        if (isspace(c)) {
            return false;
        }

        if (!isalnum(c) && c != '.' && c != '_' && c != '-' && c != '@') {
            return false;
        }

        if (c == '@') {
            // Já tem um @?
            if (pos_arroba != -1)
                return false;
            pos_arroba = i;
        }

        if (c == '.' && pos_arroba != -1){
            pos_ponto = i;
        }

    }

    // Verifica se há um @ e um . depois do @
    if (pos_arroba == -1 || pos_ponto == -1)
        return false;

    // Verifica se o ponto está depois do arroba e não colado
    if (pos_ponto < pos_arroba + 2)
        return false;

    // Verifica se o ponto não é o último caractere
    if (pos_ponto == tamanho - 1)
        return false;

    return true;
}



int valida_funcao(char *funcao) {
    int i;
    bool tem_letra = false;

    // Remove espaços do início                            //função para validar função
    while (*funcao == ' ') {
        funcao++;
    }

    if (strlen(funcao) == 0) {
        return false;
    }

    // Verifica se há pelo menos uma letra
    for (i = 0; funcao[i] != '\0'; i++) {
        if ((funcao[i] >= 'A' && funcao[i] <= 'Z') ||
            (funcao[i] >= 'a' && funcao[i] <= 'z')) {
            tem_letra = true;
        }
    }

    if (!tem_letra) {
        return false;
    }

    return true;
}



int valida_cliente(char *cliente){
    Cliente *clt;
    FILE *arq_clientes;
    clt = (Cliente*) malloc(sizeof(Cliente));
    
    arq_clientes = fopen("clientes.dat", "rb");
    if(arq_clientes == NULL)return False;
    
    while(fread(clt,sizeof(Cliente),1,arq_clientes) == 1){
        if(strcmp(clt ->cpf,cliente) == 0){
            fclose(arq_clientes);
            free(clt);
            return True;
        }
    }

    fclose(arq_clientes);
    free(clt);
    return False;

}



int valida_show(int id_show){
    int saida;
    int parar;
    Cabecalho *cabecalho;
    cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho));
    cabecalho ->dados = (Dados_S *) malloc(sizeof(Dados_S));

    cabecalho ->arq_shows = fopen("arq_shows.dat","rb");
    if(cabecalho ->arq_shows == NULL)return 0;
    
    saida = False;
    parar = True;
    while(fread(cabecalho ->dados,sizeof(Dados_S),1,cabecalho ->arq_shows) == 1 && parar){
        if(id_show == cabecalho ->dados ->id){
            saida = True;
            parar = False; 
        }
        else fseek(cabecalho ->arq_shows,cabecalho ->dados ->tam_DHD + cabecalho ->dados ->tam_personagem,SEEK_CUR);
    }
    fclose(cabecalho ->arq_shows);
    free(cabecalho ->dados);
    free(cabecalho);
    
    return saida;
}



void valida_cadeira(char *assento,int id_show,SEP *controle){
   char numero[3] = "";
   int convertido;
   
   controle ->valida = False;
    if(strlen(assento) <= 3 && strlen(assento) >= 2){
    
        if((assento[0] >= 65 && assento[0] <= 69)){
            strcat(numero,&assento[1]);
            convertido = converte_numero(numero);

            if(convertido >= 1 && convertido <= 20){

                if(cadeira_usada(assento,id_show)){
                    controle ->valida = True;
                    controle ->error = 0;
                }
                else controle ->error = 4; //Indicar que o assento escolhido está sendo usado
            }
            else{
                controle ->error = 3; //Indicar que foi usado carateres fora de (1 - 20)
            }
        }
        else{
            controle ->error = 2; //Indicar que foi usada caracteres fora de (A - E)   
        }
    }
    else{
        controle ->error = 1; //Indicar que o tamanho não bate
    }
}



int valida_id(char *id){
    for(int i = 0; i < strlen(id); i++){
        if(id[i] < 48 || id[i] > 57 ){
            return False;
        }
    }
    return True;
}



void valida_cpf_show(SEP *controle,Dados_I *dados){
    if(strcmp(dados ->cpf,"C") == 0 || strcmp(dados ->cpf, "c") == 0){
            cadastrar_cliente();
        }
        else if(valida_cpf(dados ->cpf)){
            if(valida_cliente(dados ->cpf)){
                controle ->valida = True;
                controle ->error = 0;
                //Dados corretos
            }
            else{
                controle ->error = 1; //indicar que cliente não é cadastrado
            }
        }
        else{
            controle ->error = 2; //indicar cpf inválido
        }
}



void valida_ler_codigo(SEP *controle,char *id_lido){
    int converte;
    converte = converte_numero(id_lido);
        if(valida_id(id_lido)){
            if(valida_show(converte)){
                controle ->valida = True;
                controle ->error = 0;
                //dados corretos
            }
            else{
                controle ->error = 1; //Indicar show não encontrado
       
            }
        }
        else{
            controle ->error = 2; //Id inválido
        }
}