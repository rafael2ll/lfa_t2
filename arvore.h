#ifndef ARV_BINARIA_H
#define ARV_BINARIA_H "ARV_BINARIA_H"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_ *Arvore;

Arvore criar_arvore();

int inserir_profundidade(Arvore *arv, char *alfabeto, char simbolo);

void print_arvore(Arvore arv);

int contains(char *alfabeto, char a);

char busca_profundidade(Arvore *arv);

#endif