#include "lista_transicao.h"

struct no_transicao {
    int t;
    struct no_transicao *prox;
};

ListaT criar_listaT() {
    ListaT lt = malloc(sizeof(struct no_transicao));
    lt->prox = NULL;
    return lt;
}

void inserir_transicao(ListaT l, int t) {
    struct no_transicao *no = malloc(sizeof(struct no_transicao));
    no->t = t;
    no->prox = l->prox;
    l->prox = no;
}

void print_transicoes(ListaT lt) {
    ListaT aux = lt->prox;
    while (aux != NULL) {
        printf("%d, ", aux->t);
        aux = aux->prox;
    }
}


int sizeof_listaT() { return sizeof(struct no_transicao); }