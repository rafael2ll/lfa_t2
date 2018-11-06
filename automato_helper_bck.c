#include "automato_helper.h"
#include "pilha.h"
#include "arvore.h"

void gera_automato(Arvore arv) {
    Pilha pilha;
    char simbolo;
    ListaE matriz_transicao;
    criar_listaEstados(&matriz_transicao);

    while (arv != NULL) {
        simbolo = busca_profundidade(&arv);
        switch (simbolo) {
            case '+' :
                uniao(matriz_transicao, desempilha(&pilha), desempilha(&pilha));
            case '.' :
                concatenacao(matriz_transicao)
        }
        empilha(pilha,)
    }
}

ListaE simbolo(int simbolo, int *contador, int alf_c) {
    ListaE matriz_transicao;
    criar_listaEstados(&matriz_transicao);

    inserir_estado(matriz_transicao, *contador, alf_c);
    inserir_estado(matriz_transicao, *contador + 1, alf_c);
    inserir_estado_transicao(matriz_transicao, *contador, simbolo, *contador + 1);
    *contador += 2;

    return matriz_transicao;
}

void uniao(ListaE matriz_transicao, ListaE exp1, ListaE exp2, int *contador, int alf_c) {
    ListaE matriz_transicao;
    criar_listaEstados(&matriz_transicao);

    inserir_estado(matriz_transicao, *contador, alf_c);

    inserir_estado_transicao(matriz_transicao, *contador, alf_c, ultimo_listaE(exp1));
    inserir_estado_transicao(matriz_transicao, *contador, alf_c, ultimo_listaE(exp2));

    inserir_estado_transicao(exp1, primeiro_listaE(exp1), alf_c, *contador + 1);
    inserir_estado_transicao(exp2, primeiro_listaE(exp2), alf_c, *contador + 1);


    copiar_listaE(matriz_transicao, exp1);
    copiar_listaE(matriz_transicao, exp2);

    inserir_estado(matriz_transicao, *contador + 1, alf_c);

    *contador += 2;
}


void concatenacao(ListaE matriz_transicao, ListaE exp1, ListaE exp2, int alf_c) {
    copiar_listaE(matriz_transicao, exp1);

    inserir_estado_transicao(matriz_transicao, primeiro_listaE(exp1), alf_c, ultimo_listaE(exp2));

    copiar_listaE(matriz_transicao, exp2);
}


void fechamento(ListaE matriz_transicao, int *contador, int alf_c) {
    //Inserir transicao de repeticao(ultimo para o primeiro)
    inserir_estado_transicao(matriz_transicao, primeiro_listaE(matriz_transicao), alf_c,
                             ultimo_listaE(matriz_transicao));

    //Do penultimo pro ultimo
    inserir_estado_transicao(matriz_transicao, primeiro_listaE(matriz_transicao), alf_c, *contador + 1);

    int primeiro = ultimo_listaE(matriz_transicao);

    inserir_estado_nofinal(matriz_transicao, *contador, alf_c);
    //Do primeiro pro segundo 
    inserir_estado_transicao(matriz_transicao, *contador, alf_c, primeiro);

    //Inserindo estado final 
    inserir_estado(matriz_transicao, *contador + 1, alf_c);


    //Do ultimo pro primeiro
    inserir_estado_transicao(matriz_transicao, *contador, alf_c, *contador + 1);

    *contador += 2;


}