#include "pilha.h"

struct no_simbolo {
    ListaE listaE;
    struct no_simbolo *bottom;
};

void empilha(Pilha *p, ListaE listaE) {
    struct no_simbolo *no = malloc(sizeof(struct no_simbolo));
    no->listaE = listaE;
    if (*p != NULL) {
        no->bottom = *p;
        *p = no;
    } else {
        no->bottom = NULL;
        *p = no;
    }
}

ListaE desempilha(Pilha *p) {
    if (*p == NULL) return '\0';
    ListaE aux = (*p)->listaE;
    *p = (*p)->bottom;
    return aux;
}
