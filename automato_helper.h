#ifndef AUTOMATO_HELPER
#define AUTOMATO_HELPER "AUTOMATO_HELPER"

#include "lista_estado.h"
#include "pilha.h"
#include "arvore.h"

void gera_automato(Arvore arrv);

ListaE simbolo(int simbolo, int *contador, int alf_c);

ListaE uniao(ListaE exp1, ListaE exp2, int *contador, int alf_c);

ListaE concatenacao(ListaE exp1, ListaE exp2, int alf_c);

ListaE fechamento(ListaE matriz_transicao, int *contador, int alf_c);

int indexOf(char simbolo, char *alfabeto);

#endif