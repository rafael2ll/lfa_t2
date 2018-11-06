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

void print_transicoes(FILE *f, ListaT lt) {
    ListaT aux = lt->prox;
    if (aux != NULL) {
        fprintf(f, "{");
        while (aux->prox != NULL) {
            fprintf(f, "q%d,", aux->t);
            aux = aux->prox;
        }
        fprintf(f, "q%d} ", aux->t);
    } else {
        fprintf(f, "{} ");
    }
}


int sizeof_listaT() { return sizeof(struct no_transicao); }