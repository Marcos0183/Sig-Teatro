#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "anima.h"
#include "utils.h"
#include "leitura.h"
#define true 1
#define false 0


int tempo_cliente = 100;

void menu_cliente(){
    limparTela();
        printf("╔══════════════════════════════════════════════════╗\n");
        func_Ani(tempo_cliente);
        printf("║                MODULO CLIENTE                    ║\n");
        func_Ani(tempo_cliente);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_cliente);
        printf("║                                                  ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 1. cadastrar Cliente                           ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 2. Pesquisar Cliente                           ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 3. Atualizar Cliente                           ║\n");
        func_Ani(tempo_cliente);
        printf("║ ► 4. Excluir Cliente                             ║\n");
        func_Ani(tempo_cliente);
        printf("║                                                  ║\n");
        func_Ani(tempo_cliente);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_cliente);
        printf("║ ► 0. Voltar ao Menu principal                    ║\n");
        func_Ani(tempo_cliente);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_cliente);
        printf("--> Digite a opção desejada: ");
}   



void exibir_cliente(Cliente* clt) {
    
    printf("\n╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                     DADOS DO CLIENTE                        ║\n");
    printf("╠═════════════════════════════════════════════════════════════╣\n");
    printf("║ CPF      :%-50s║\n", clt->cpf);
    printf("║ Nome     :%-50s║\n", clt->nome);
    printf("║ E-mail   :%-50s║\n", clt->email);
    printf("║ Telefone :%-50s║\n", clt->telefone);
    printf("╚═════════════════════════════════════════════════════════════╝\n");
}



void gravar_cliente(Cliente* clt) {
    FILE *arq_clientes = fopen("clientes.dat", "ab");              // Abre o arquivo em modo anexar (append)
    if (arq_clientes == NULL) {
        return;
    }

    fwrite(clt, sizeof(Cliente), 1, arq_clientes);
    fclose(arq_clientes);
}



int confirma_dados_cliente(Cliente* clt) {
    char confirm;
    limparTela();
    exibir_cliente(clt);
    printf("Os dados do cliente estão corretos? (S/N): ");
    scanf(" %c", &confirm);
    limparBuffer();

    if (confirm == 'S' || confirm == 's') {
        return true;
    } else {
        return false;
    }
}



int cpf_existente(char *cpf) {
    Cliente* clt;
    FILE *arq_clientes;
    clt = (Cliente*) malloc(sizeof(Cliente));
    if (clt == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return false;
    }

    arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        free(clt);
        return true;            // arquivo vazio, CPF pode ser cadastrado
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {        // Percorre o arquivo de clientes
        if ((strcmp(clt->cpf, cpf) == 0) && (clt->status == true)) {   // Compara o CPF lido com o CPF do cliente atual
            printf("╔════════════════════════════════════════════════════════════╗\n");
            printf("║ CPF já cadastrado. Por favor, insira um CPF diferente.     ║\n");
            printf("║ Operação cancelada.                                        ║\n");
            printf("╚════════════════════════════════════════════════════════════╝\n");
            fclose(arq_clientes);
            free(clt);
            return false;
        }
    } 

    fclose(arq_clientes);
    free(clt);
    return true;
}
  


void cadastrar_cliente() { 

    Cliente* clt = (Cliente*) malloc(sizeof(Cliente));
    char titulo[19] = "CADASTRAR CLIENTE";
    func_Ani_Left(titulo);

    ler_cpf(clt->cpf);
    if (!cpf_existente(clt->cpf)) {            // Lê o CPF e verifica duplicidade antes de continuar                        
         free(clt);                                // Libera memória alocada para o cliente
         pausar();
         return;
    }
    ler_nome(clt->nome);  
    ler_email(clt->email);
    ler_telefone(clt->telefone);
    clt->status = true;

    if (!confirma_dados_cliente(clt)) {
        printf("\nCadastro cancelado pelo usuário.\n");
        free(clt);
        pausar();
        return;
    }
    gravar_cliente(clt);
    printf("\n Cliente cadastrado com sucesso!\n");
    free(clt);
    pausar();
}



void atualizar_cliente(){

    Cliente* clt;
    char cpf_lido1[15];
    FILE *arq_clientes;
    int encontrado = 0;
    clt = (Cliente*) malloc(sizeof(Cliente));
    if (clt == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return;
    }   

    char titulo[19] = "ATUALIZAR CLIENTE";
    func_Ani_Left(titulo);

    ler_cpf(cpf_lido1);
    printf("═══════════════════════════════════\n");

    arq_clientes = fopen("clientes.dat", "r+b");                          // Abre o arquivo em modo leitura e escrita
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
       
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1 && (!encontrado)) {        // Percorre o arquivo de clientes
        if (strcmp(clt->cpf, cpf_lido1) == 0) {                                         // Compara o CPF lido com o CPF do cliente atual
            
            encontrado = 1;
            printf("Insira os novos dados do cliente:\n");
            ler_nome(clt->nome);
            ler_email(clt->email);
            ler_telefone(clt->telefone);
            clt->status = true;
            if (!confirma_dados_cliente(clt)) {
                printf("\nAtualização cancelada pelo usuário.\n");
                fclose(arq_clientes);
                free(clt);
                pausar();
                return;
            }
            fseek(arq_clientes, -sizeof(Cliente), SEEK_CUR);
            fwrite(clt, sizeof(Cliente), 1, arq_clientes);
            printf("═════════════════════════════════\n");
            printf("Cliente com CPF '%s' atualizado com sucesso.\n", cpf_lido1);
            pausar();
        } 
    }

    fclose(arq_clientes);
    free(clt);
    if (!encontrado) {
        printf("Cliente com CPF '%s' não encontrado.\n", cpf_lido1);
        pausar();
        return;
    }
}



void pesquisar_cliente(){
    char cpf_lido[20];
    Cliente* clt;
    FILE *arq_clientes;
    clt = (Cliente*) malloc(sizeof(Cliente));
    if (clt == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return;
    }

    char titulo[19] = "PESQUISAR CLIENTE";
    func_Ani_Left(titulo);

    printf("\n \n");
    ler_cpf(cpf_lido);
    printf("═══════════════════════════════════\n");

    arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if ((strcmp(clt->cpf, cpf_lido) == 0) && (clt->status == true)) {
            limparTela();
            exibir_cliente(clt);
            fclose(arq_clientes);
            free(clt);
            pausar();
            return;
        }
    } 
    fclose(arq_clientes); 
    free(clt);
    printf("Cliente com CPF '%s' não encontrado.\n", cpf_lido);
    pausar();
}



void excluir_cliente() {
    Cliente* clt;
    int encontrado = 0;
    FILE *arq_clientes;
    char cpf_lido[15];
    char confirm;
    clt = (Cliente*) malloc(sizeof(Cliente));
    if (clt == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
        return;
    }

    char titulo[19] = "EXCLUIR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n \n");

    ler_cpf(cpf_lido);
    printf("═══════════════════════════════════\n");

    arq_clientes = fopen("clientes.dat", "r+b");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        free(clt);
        return;
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1 && (!encontrado)) {
        if ((strcmp(clt->cpf, cpf_lido) == 0) && (clt->status == true)) {
            limparTela();
            exibir_cliente(clt);
            printf("Tem certeza que deseja excluir este Cliente? (s/n): ");
            scanf(" %c", &confirm);                                             
            limparBuffer();
            if (confirm == 's' || confirm == 'S') {                               // Confirmação de exclusão
                encontrado = 1;
                clt->status = false;
                fseek(arq_clientes, -sizeof(Cliente), SEEK_CUR);                 // Move o ponteiro de arquivo de volta para o início do registro do cliente
                fwrite(clt, sizeof(Cliente), 1, arq_clientes);                   // Atualiza o registro do cliente no arquivo
                printf("Cliente com CPF '%s' encontrado e excluido.\n", cpf_lido);
            } else {                                                             // Cancelamento da exclusão
                printf("Operação de exclusão cancelada.\n");
                fclose(arq_clientes);
                free(clt);
                pausar();
                return;
            }
        }
    
    }
    fclose(arq_clientes);
    free(clt);

    if (!encontrado) {
        printf("Cliente com CPF '%s' não encontrado.\n", cpf_lido);
    }

    pausar();

}





void cliente(){
    int executar_C;

    do {
        menu_cliente();
        scanf("%d", &executar_C);
        limparBuffer();

        switch (executar_C) {
            case 1: 
                cadastrar_cliente(); 
                break;
            case 2:
                pesquisar_cliente();
                break;
            case 3:
                atualizar_cliente();
                break;
            case 4:
                excluir_cliente();
                break;
            case 0:
                break;
            
            default:
                printf("\n \n");
                printf("Valor inválido! Digite uma das opções acima.\n");
                pausar();
                break;
        }
    } while (executar_C != 0);        
}

Cliente* buscar_cliente_por_cpf(const char* cpf) {
    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        return NULL;
    }

    Cliente* clt = (Cliente*) malloc(sizeof(Cliente));
    while (fread(clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (strcmp(clt->cpf, cpf) == 0 && clt->status == true) {
            fclose(arq_clientes);
            return clt;
        }
    }

    fclose(arq_clientes);
    free(clt);
    return NULL;
}