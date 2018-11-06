#ifndef LISTA_TRANSICAO
#define LISTA_TRANSICAO "LISTA_TRANSICAO"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct no_transicao *ListaT;

ListaT criar_listaT();

void inserir_transicao(ListaT lt, int t);

void print_transicoes(FILE *f, ListaT lt);

int sizeof_listaT();

#endif