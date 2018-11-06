#include "arvore.h"

struct no_ {
    struct no_ *dir;
    struct no_ *esq;
    char simbolo;
};

Arvore criar_arvore() {
    Arvore arv = malloc(sizeof(struct no_));
    arv->esq = NULL;
    arv->dir = NULL;

    return arv;
}

int inserir_profundidade(Arvore *arv, char *alfabeto, char simbolo) {
    if (*arv == NULL) {
        *arv = criar_arvore();
        (*arv)->simbolo = simbolo;
        return 1;
    } else if (contains(alfabeto, (*arv)->simbolo)) {
        return 0;
    } else {
        int i = inserir_profundidade(&((*arv)->esq), alfabeto, simbolo);
        if (i != 1)return inserir_profundidade(&((*arv)->dir), alfabeto, simbolo);
    }
}


void print_arvore(Arvore arv) {
    if (arv != NULL) {
        print_arvore(arv->esq);
        printf("%c", arv->simbolo);
        print_arvore(arv->dir);
    }
}

char busca_profundidade(Arvore *arv) {
    if (*arv == NULL) return '\0';
    if ((*arv)->esq == NULL && (*arv)->dir == NULL) {
        char temp = (*arv)->simbolo;
        *arv = NULL;
        return temp;
    }
    char a = busca_profundidade(&((*arv)->esq));
    if (a == '\0') a = busca_profundidade(&((*arv)->dir));
    return a;

}

int contains(char *alfabeto, char c) {
    int i;
    for (i = 0; i < strlen(alfabeto); i++)
        if (alfabeto[i] == c) return 1;
    return 0;
}