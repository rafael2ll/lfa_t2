#include "lista_estado.h"

struct no_estado {
    int estado;
    ListaT *transicoes;
    struct no_estado *prox;
};


void criar_listaEstados(ListaE *le) {
    *le = malloc(sizeof(struct no_estado));
    (*le)->estado = -1;
    (*le)->prox = NULL;
}

void inserir_estado(ListaE l, int est, int alf_c) {
    int i;
    struct no_estado *estado = malloc(sizeof(struct no_estado));
    estado->prox = l->prox;
    estado->estado = est;
    estado->transicoes = malloc(sizeof_listaT() * (alf_c + 1));
    l->prox = estado;

    //Iniciando matriz de transicoes
    for (i = 0; i <= alf_c; i++) estado->transicoes[i] = criar_listaT();

    //Definindo caso base de E-fecho(est) = {estado}
    inserir_transicao(estado->transicoes[alf_c], est);
}

int inserir_estado_transicao(ListaE l, int estado, int simbolo, int estado_para) {
    ListaE aux = l->prox;

    while (aux != NULL) {
        if (aux->estado == estado) break;
        aux = aux->prox;
    }

    if (aux != NULL) {
        inserir_transicao(aux->transicoes[simbolo], estado_para);
        return 1;
    }
    return 0;
}

int ultimo_listaE(ListaE l) {
    ListaE aux = l->prox;

    while (aux->prox != NULL) aux = aux->prox;

    return aux->estado;
}


void copiar_listaE(ListaE orig, ListaE temp) {
    ListaE aux = temp->prox;
    while (temp->prox != NULL) temp = temp->prox;
    temp->prox = orig->prox;
    orig->prox = aux;
}

int primeiro_listaE(ListaE l) {
    ListaE aux = l->prox;

    return aux->estado;
}

int inserir_estado_nofinal(ListaE l, int est, int alf_c) {
    int i;
    ListaE aux = l;
    struct no_estado *estado = malloc(sizeof(struct no_estado));
    estado->prox = NULL;
    estado->estado = est;
    estado->transicoes = malloc(sizeof_listaT() * (alf_c + 1));

    while (aux->prox != NULL) aux = aux->prox;
    aux->prox = estado;

    //Iniciando matriz de transicoes
    for (i = 0; i <= alf_c; i++) estado->transicoes[i] = criar_listaT();

    //Definindo caso base de E-fecho(est) = {estado}
    inserir_transicao(estado->transicoes[alf_c], est);
}

int tamanho_listaE(ListaE l) {
    ListaE aux = l->prox;
    int c = 0;
    while (aux != NULL) {
        aux = aux->prox;
        c++;
    }
    return c;
}

void print(ListaE le, int alf_c) {
    ListaE aux = le->prox;
    int i;
    while (aux != NULL) {
        printf("----%d----\n", aux->estado);
        for (i = 0; i <= alf_c; i++) {
            printf("Lendo %d:{", i);
            print_transicoes(aux->transicoes[i]);
            printf("}\n");
        }
        aux = aux->prox;
        printf("\n");
    }
}