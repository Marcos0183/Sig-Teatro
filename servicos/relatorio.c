#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"
#include "anima.h"
#include "utils.h"
#include "tecnicos.h"
#include "leitura.h"
#include "shows.h"
#include "ingresso.h"
#include "pesquisa.h"
#define true 1
#define false 0

int tempo_relatorio = 100;

void menu_relatorio(){
    limparTela();
        printf("╔══════════════════════════════════════════════════╗\n");
        func_Ani(tempo_relatorio);
        printf("║               MODULO RELATÓRIO                   ║\n");
        func_Ani(tempo_relatorio);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_relatorio);
        printf("║                                                  ║\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 1. Relatorio Clientes                          ║\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 2. Relatorio Técnicos                          ║\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 3. Relatorio Shows/Espetaculos                 ║\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 4. Relatorio Ingressos                         ║\n");
        func_Ani(tempo_relatorio);
        printf("╠══════════════════════════════════════════════════╣\n");
        func_Ani(tempo_relatorio);
        printf("║ ► 0. Voltar ao Menu principal                    ║\n");
        func_Ani(tempo_relatorio);
        printf("╚══════════════════════════════════════════════════╝\n");
        func_Ani(tempo_relatorio);
        printf("--> Digite a opção desejada: ");
}

void listar_clientes_ativos() {
    limparTela();
    char titulo[28] = "LISTANDO CLIENTES ATIVOS";
    func_Ani_Left(titulo);
    printf("\n\n");
    Cliente clt;
    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(&clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (clt.status == true) {
            exibir_cliente(&clt);
        }
    }
    fclose(arq_clientes);
    pausar();
}

void listar_clientes_inativos() {
    limparTela();
    char titulo[30] = "LISTANDO CLIENTES INATIVOS";
    func_Ani_Left(titulo);
    printf("\n\n");
    Cliente clt;
    FILE *arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        limparBuffer();
        return;
    }
    while (fread(&clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (clt.status == false) {
            exibir_cliente(&clt);
        }
    }
    fclose(arq_clientes);
    pausar();
}


NoCliente* carregar_clientes_ordenados() {
    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        return NULL;
    }

    NoCliente* lista = NULL;
    Cliente clt;

    while (fread(&clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (clt.status == true) {
            NoCliente* novo = (NoCliente*) malloc(sizeof(NoCliente));
            novo->cliente = clt;

            // Inserção ordenada
            if (lista == NULL || strcmp(novo->cliente.nome, lista->cliente.nome) < 0) {
                novo->prox = lista;
                lista = novo;
            } else {
                NoCliente* atual = lista;
                while (atual->prox != NULL && strcmp(novo->cliente.nome, atual->prox->cliente.nome) > 0) {
                    atual = atual->prox;
                }
                novo->prox = atual->prox;
                atual->prox = novo;
            }
        }
    }
    fclose(arq_clientes);
    return lista;
}

void listar_clientes_ordenados_alfabeticamente() {
    limparTela();
    char titulo[40] = "CLIENTES ORDENADOS POR NOME";
    func_Ani_Left(titulo);
    printf("\n\n");

    NoCliente* lista = carregar_clientes_ordenados();
    NoCliente* p = lista;
    while (p != NULL) {
        exibir_cliente(&p->cliente);
        NoCliente* temp = p;
        p = p->prox;
        free(temp); // Libera a memória do nó após exibi-lo
    }

    pausar();
}

void relatorio_cliente(){ 
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE CLIENTES              ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 1. Listar Clientes ativos                      ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 2. Listar Clientes inativos                    ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 3. Listar Clientes ordem alfabética            ║\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 0. Voltar ao Menu Relatórios                   ║\n");
    func_Ani(tempo_relatorio);
    printf("╚══════════════════════════════════════════════════╝\n");
    func_Ani(tempo_relatorio);
    printf("--> Digite a opção desejada: ");
}

void listar_tecnicos_ativos() {
    limparTela();
    char titulo[28] = "LISTANDO TÉCNICOS ATIVOS";
    func_Ani_Left(titulo);
    printf("\n\n");
    Tecnico tec;
    FILE* arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de técnicos.\n");
        limparBuffer();
        return;
    }
    while (fread(&tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) {
        if (tec.status == true) {
            exibir_tecnico(&tec);
        }
    }
    fclose(arq_tecnicos);
    pausar();
}

void listar_tecnicos_inativos() {
    limparTela();
    char titulo[30] = "LISTANDO TÉCNICOS INATIVOS";
    func_Ani_Left(titulo);
    printf("\n\n");
    Tecnico tec;
    FILE *arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        printf("Erro ao abrir o arquivo de técnicos.\n");
        limparBuffer();
        return;
    }
    while (fread(&tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) {
        if (tec.status == false) {
            exibir_tecnico(&tec);
        }
    }
    fclose(arq_tecnicos);
    pausar();
}


NoTecnico* carregar_tecnicos_ordenados() {
    FILE* arq_tecnicos = fopen("tecnicos.dat", "rb");
    if (arq_tecnicos == NULL) {
        return NULL;
    }

    NoTecnico* lista = NULL;
    Tecnico tec;

    while (fread(&tec, sizeof(Tecnico), 1, arq_tecnicos) == 1) {
        if (tec.status == true) {
            NoTecnico* novo = (NoTecnico*) malloc(sizeof(NoTecnico));
            novo->tecnico = tec;

            // Inserção ordenada
            if (lista == NULL || strcmp(novo->tecnico.nome, lista->tecnico.nome) < 0) {
                novo->prox = lista;
                lista = novo;
            } else {
                NoTecnico* atual = lista;
                while (atual->prox != NULL && strcmp(novo->tecnico.nome, atual->prox->tecnico.nome) > 0) {
                    atual = atual->prox;
                }
                novo->prox = atual->prox;
                atual->prox = novo;
            }
        }
    }
    fclose(arq_tecnicos);
    return lista;
}

void listar_tecnicos_ordenados_alfabeticamente() {
    limparTela();
    char titulo[40] = "TÉCNICOS ORDENADOS POR NOME";
    func_Ani_Left(titulo);
    printf("\n\n");

    NoTecnico* lista = carregar_tecnicos_ordenados();
    NoTecnico* p = lista;
    while (p != NULL) {
        exibir_tecnico(&p->tecnico);
        NoTecnico* temp = p;
        p = p->prox;
        free(temp); // Libera a memória do nó após exibi-lo
    }

    pausar();
}

void relatorio_tecnico(){ 
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE TÉCNICOS              ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 1. Listar Técnicos ativos                      ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 2. Listar Técnicos inativos                    ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 3. Listar Técnicos por ordem alfabética        ║\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 0. Voltar ao Menu Relatórios                   ║\n");
    func_Ani(tempo_relatorio);
    printf("╚══════════════════════════════════════════════════╝\n");
    func_Ani(tempo_relatorio);
    printf("--> Digite a opção desejada: ");
}

//###########################################  FUNÇÕES DO MODO RELATÓRIO SHOWS  ###########################################################

int contar_ingressos_por_show(int id_show) {
    FILE* arq_ingresso = fopen("arq_ingresso.dat", "rb");
    if (arq_ingresso == NULL) {
        return 0;
    }

    Dados_I ingresso;
    int contador = 0;
    while (fread(&ingresso, sizeof(Dados_I), 1, arq_ingresso) == 1) {
        if (ingresso.id_show == id_show && ingresso.status == true) {
            contador++;
        }
    }
    fclose(arq_ingresso);
    return contador;
}

void listar_shows_ativos(){
    ListaID *lista;
    char titulo[16] = "SHOWS AGENDADOS";
    func_Ani_Left(titulo);
   
    lista = listaI_id_show();
    printf("\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("|ID   |NOME                                        |DHD - DATA - HORA - DURACAO              |\n");
    printf("----------------------------------------------------------------------------------------------\n");
    exibir_rel_show(lista);
    
    ListaID *temp = lista;
    while(lista !=NULL){
        lista = lista ->prox;
        free(temp);
        temp = lista;
    }
    pausar();
}

void relatorio_ocupacao_shows() {
    limparTela();
    char titulo[] = "RELATÓRIO DE OCUPAÇÃO POR SHOW";
    func_Ani_Left(titulo);
    printf("\n\n");

    FILE* arq_shows = fopen("arq_shows.dat", "rb");
    if (arq_shows == NULL) {
        printf("Nenhum show cadastrado.\n");
        pausar();
        return;
    }

    printf("╔═════════╤══════════════════════════════════╤═════════════╤═══════════╗\n");
    printf("║ %-7s │ %-32s │ %-11s │ %-9s ║\n", "ID SHOW", "NOME DO SHOW", "VENDIDOS", "OCUPAÇÃO");
    printf("╠═════════╪══════════════════════════════════╪═════════════╪═══════════╣\n");

    Dados_S show;
    int shows_encontrados = 0;
    while (fread(&show, sizeof(Dados_S), 1, arq_shows) == 1) {
        if (show.status == true) {
            int vendidos = contar_ingressos_por_show(show.id);
            float ocupacao = (vendidos / 100.0) * 100.0;
            printf("║ %-7d │ %-32s │ %-11d │ %-8.1f%% ║\n", show.id, show.nome, vendidos, ocupacao);
            shows_encontrados++;
        }
        fseek(arq_shows, show.tam_DHD + show.tam_personagem, SEEK_CUR);
    }

    if (shows_encontrados == 0) {
        printf("║ %-74s ║\n", "Nenhum show ativo encontrado.");
    }

    printf("╚═════════╧══════════════════════════════════╧═════════════╧═══════════╝\n");
    fclose(arq_shows);
    pausar();
}

void listar_shows_inativos(){
    ListaID *lista;
    char titulo[16] = "SHOWS AGENDADOS";
    func_Ani_Left(titulo);
   
    lista = listaD_id_show();
    printf("\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("|ID   |NOME                                        |DHD - DATA DURACAO E HORA                |\n");
    printf("----------------------------------------------------------------------------------------------\n");
    exibir_rel_show(lista);
    ListaID *temp = lista;
    while(lista !=NULL){
        lista = lista ->prox;
        free(temp);
        temp = lista;
    }
    pausar();
    
}

void relatorio_shows(){ 
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE SHOWS                 ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 1. Listar Shows Agendados                      ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 2. Relatório de Ocupação                       ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 3. Listar Shows Apresentados                   ║\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 0. Voltar ao Menu Relatórios                   ║\n");
    func_Ani(tempo_relatorio);
    printf("╚══════════════════════════════════════════════════╝\n");
    func_Ani(tempo_relatorio);
    printf("--> Digite a opção desejada: ");
}

//########################################  FUNÇÕES DO MODO RELATÓRIO INGRESSO  ###########################################################

int contar_ingressos_por_cpf(const char* cpf) {
    FILE* arq_ingresso = fopen("arq_ingresso.dat", "rb");
    if (arq_ingresso == NULL) {
        return 0;
    }

    Dados_I ingresso;
    int contador = 0;
    while (fread(&ingresso, sizeof(Dados_I), 1, arq_ingresso) == 1) {
        if (strcmp(ingresso.cpf, cpf) == 0 && ingresso.status == true) {
            contador++;
        }
    }
    fclose(arq_ingresso);
    return contador;
}

void exibir_ingresso_com_nome_cliente(Dados_I* ingresso) {
    Cliente* clt = buscar_cliente_por_cpf(ingresso->cpf);
    char nome_cliente[51] = "Cliente não encontrado";

    if (clt != NULL) {
        strncpy(nome_cliente, clt->nome, 50);
        nome_cliente[50] = '\0'; // Garante terminação nula
        free(clt);
    }

    printf("\n╔═════════════════════════════════════════════════════════════╗\n");
    printf("║ ID do Ingresso: %-45d ║\n", ingresso->id);
    printf("╠═════════════════════════════════════════════════════════════╣\n");
    printf("║ Cliente  : %-50s ║\n", nome_cliente);
    printf("║ ID do Show : %-50d ║\n", ingresso->id_show);
    printf("║ Cadeira    : %-50s ║\n", ingresso->cadeira);
    printf("╚═════════════════════════════════════════════════════════════╝\n");
}

void listar_ingressos_ativos(){
    int achado;
    Dados_I *dados;
    dados = (Dados_I *) malloc(sizeof(Dados_I));
    char titulo[22] = "INGRESSOS COMPRADOS";
    func_Ani_Left(titulo);
    printf("\n");

    FILE *arq_ingresso;
    arq_ingresso = fopen("arq_ingresso.dat","rb");
    achado = True;

    printf("\n\n");
    printf("╔════════════════╤════════════════════════════════════════════════╤════════════════════════════════════════════╤═════════╤════╗\n");
    printf("║CPF             │CLIENTE                                         │ID - SHOW                                   │CADEIRA  │ID  ║\n");
    printf("╠════════════════╪════════════════════════════════════════════════╪════════════════════════════════════════════╪═════════╪════╣\n");
    while(fread(dados,sizeof(Dados_I),1,arq_ingresso) == 1){
        if(dados ->status == True){
            exibir_rel_ingresso(dados);
            achado = False;
        }
    }
    if(achado)printf("SEM INGRESSOS COMPRADOS\n");
    printf("╚════════════════╧════════════════════════════════════════════════╧════════════════════════════════════════════╧═════════╧════╝\n");
    fclose(arq_ingresso);
    pausar();
    free(dados);
}

void relatorio_resumo_compras_cliente() {
    limparTela();
    char titulo[] = "RESUMO DE COMPRAS POR CLIENTE";
    func_Ani_Left(titulo);
    printf("\n\n");

    FILE* arq_clientes = fopen("clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        pausar();
        return;
    }

    printf("╔══════════════════════════════════════════════════════╤════════════════════════╗\n");
    printf("║ %-50s │ %-20s ║\n", "NOME DO CLIENTE", "INGRESSOS COMPRADOS");
    printf("╠══════════════════════════════════════════════════════╪════════════════════════╣\n");

    Cliente clt;
    while (fread(&clt, sizeof(Cliente), 1, arq_clientes) == 1) {
        if (clt.status == true) {
            int num_ingressos = contar_ingressos_por_cpf(clt.cpf);
            printf("║ %-50s │ %-20d ║\n", clt.nome, num_ingressos);
        }
    }

    printf("╚══════════════════════════════════════════════════════╧════════════════════════╝\n");
    fclose(arq_clientes);
    pausar();
}

void listar_ingressos_inativos(){
    int achado;
    Dados_I *dados;
    dados = (Dados_I *) malloc(sizeof(Dados_I));
    char titulo[22] = "INGRESSOS RASGADOS";
    func_Ani_Left(titulo);
    printf("\n");

    FILE *arq_ingresso;
    arq_ingresso = fopen("arq_ingresso.dat","rb");
    achado = True;

    printf("\n\n");
    printf("╔════════════════╤════════════════════════════════════════════════╤════════════════════════════════════════════╤═════════╤════╗\n");
    printf("║CPF             │CLIENTE                                         │ID - SHOW                                   │CADEIRA  │ID  ║\n");
    printf("╠════════════════╪════════════════════════════════════════════════╪════════════════════════════════════════════╪═════════╪════╣\n");
    while(fread(dados,sizeof(Dados_I),1,arq_ingresso) == 1){
        if(dados ->status == False){
            exibir_rel_ingresso(dados);
            achado = False;
        }
    }
    if(achado)printf("SEM INGRESSOS COMPRADOS\n");
    printf("╚════════════════╧════════════════════════════════════════════════╧════════════════════════════════════════════╧═════════╧════╝\n");
    fclose(arq_ingresso);
    free(dados);
    pausar();
}

void relatorio_ingressos(){
    limparTela();
    printf("╔══════════════════════════════════════════════════╗\n");
    func_Ani(tempo_relatorio);
    printf("║               RELATÓRIO DE INGRESSOS             ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 1. Listar Igressos Comprados                   ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 2. Resumo de Compras por Cliente               ║\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 3. Listar Ingressos Rasgados                   ║\n");
    func_Ani(tempo_relatorio);
    printf("║                                                  ║\n");
    func_Ani(tempo_relatorio);
    printf("╠══════════════════════════════════════════════════╣\n");
    func_Ani(tempo_relatorio);
    printf("║ ► 0. Voltar ao Menu Relatórios                   ║\n");
    func_Ani(tempo_relatorio);
    printf("╚══════════════════════════════════════════════════╝\n");
    func_Ani(tempo_relatorio);
    printf("--> Digite a opção desejada: ");
}


//ESCOLHA DOS MODULOS
void relatorio() {
    int executar_R;
    int opcao_tecnico;
    int opcao_cliente;
    int opcao_show;
    int opcao_ingresso;

    do {
        menu_relatorio();
        scanf("%d", &executar_R);
        limparBuffer();

        switch (executar_R) {
            case 1:
                do {
                    relatorio_cliente();
                    scanf("%d", &opcao_cliente);
                    limparBuffer();
                    switch (opcao_cliente) {
                        case 1:
                            listar_clientes_ativos();
                            break;
                        case 2:
                            listar_clientes_inativos();
                            break;
                        case 3:
                            listar_clientes_ordenados_alfabeticamente();
                            break;
                        case 0:
                            break;
                    }
                } while (opcao_cliente != 0);
                break;

            case 2:
                do {
                    relatorio_tecnico();
                    scanf("%d", &opcao_tecnico);
                    limparBuffer();
                    switch (opcao_tecnico) {
                        case 1:
                            listar_tecnicos_ativos();
                            break;
                        case 2:
                            listar_tecnicos_inativos();
                            break;
                        case 3:
                            listar_tecnicos_ordenados_alfabeticamente();
                            break;
                        case 0:
                            break; 
                    }
                } while (opcao_tecnico != 0);
                break;
            
            case 3:
                do{
                    relatorio_shows();
                    scanf("%d", &opcao_show);
                    limparBuffer();
                    switch (opcao_show) {
                        case 1:
                            listar_shows_ativos();
                            break;
                        case 2:
                            relatorio_ocupacao_shows();
                            break;
                        case 3:
                            listar_shows_inativos();
                            break;
                        case 0:
                            break; 
                    }
                }while(opcao_show != 0);
                break;
            
            case 4:
                do{
                    relatorio_ingressos();
                    scanf("%d", &opcao_ingresso);
                    limparBuffer();
                    switch (opcao_ingresso) {
                        case 1:
                            listar_ingressos_ativos();
                            break;
                        case 2:
                            relatorio_resumo_compras_cliente();
                            break;
                        case 3:
                            listar_ingressos_inativos();
                            break;
                        case 0:
                            break;
                    }
                }while(opcao_ingresso != 0);
                break;
                
            case 0:
                break;

            default:
                printf("\n \n");
                printf("!VALOR INVALIDO, POR FAVOR INSERIR APENAS UM DOS VALORES ACIMA!\n");
                pausar();
                break;
        }
    } while (executar_R != 0);
}