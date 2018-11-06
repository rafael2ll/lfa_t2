#ifndef LISTA_ESTADO
#define LISTA_ESTADO "LISTA_ESTADO"

#include <stdlib.h>
#include "lista_transicao.h"

typedef struct no_estado *ListaE;

void criar_listaEstados(ListaE *le);

void inserir_estado(ListaE l, int estado, int alf_c);

int inserir_estado_nofinal(ListaE l, int est, int alf_c);

int tamanho_listaE(ListaE l);

void copiar_listaE(ListaE, ListaE);

int primeiro_listaE(ListaE);

int ultimo_listaE(ListaE);

int inserir_estado_transicao(ListaE l, int estado, int simbolo, int estado_para);

void exportar_estados(FILE *f, ListaE le);

void exportar_matriz_transicao(FILE *f, ListaE le, char *alfabeto);
void print(ListaE le, int alf_c);

#endif