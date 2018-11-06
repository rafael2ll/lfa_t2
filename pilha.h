#ifndef PILHA
#define PILHA "PILHA"

#include <stdlib.h>
#include "lista_estado.h"

typedef struct no_simbolo *Pilha;

void empilha(Pilha *p, ListaE s);

ListaE desempilha(Pilha *p);

#endif
