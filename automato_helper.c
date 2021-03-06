#include "automato_helper.h"


void gera_automato(char *expressao_regular) {
    Arvore arv = criar_arvore();
    int contador = 0;
    char *alfabeto = gerar_alfabeto(expressao_regular);
    int i = 0, alf_c = strlen(alfabeto);
    for (i = 0; i < strlen(expressao_regular); i++) {
        inserir_profundidade(&arv, alfabeto, expressao_regular[i]);
    }

    print_arvore(arv);
    printf("\n");

    Pilha pilha;
    ListaE matriz_transicao;
    criar_listaEstados(&matriz_transicao);
    char simb;

    while (arv != NULL) {
        simb = busca_profundidade(&arv);
        printf("%c ", simb);
        if (simb != '\0')
            switch (simb) {
                case '+' :
                    empilha(&pilha, uniao(desempilha(&pilha), desempilha(&pilha), &contador, alf_c));
                    break;
                case '.' :
                    empilha(&pilha, concatenacao(desempilha(&pilha), desempilha(&pilha), alf_c));
                    break;
                case '*' :
                    empilha(&pilha, fechamento(desempilha(&pilha), &contador, alf_c));
                    break;
                default:
                    empilha(&pilha, simbolo(indexOf(simb, alfabeto), &contador, alf_c));
            }
    }
    matriz_transicao = desempilha(&pilha);
    print(matriz_transicao, alf_c);

    gerar_arquivo(matriz_transicao, alfabeto);
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

ListaE uniao(ListaE exp1, ListaE exp2, int *contador, int alf_c) {

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
    return matriz_transicao;
}


ListaE concatenacao(ListaE exp1, ListaE exp2, int alf_c) {
    ListaE matriz_transicao;
    criar_listaEstados(&matriz_transicao);

    copiar_listaE(matriz_transicao, exp1);

    inserir_estado_transicao(matriz_transicao, primeiro_listaE(exp1), alf_c, ultimo_listaE(exp2));

    copiar_listaE(matriz_transicao, exp2);

    return matriz_transicao;
}


ListaE fechamento(ListaE matriz_transicao, int *contador, int alf_c) {

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
    return matriz_transicao;
}


void gerar_arquivo(ListaE le, char *alfabeto) {
    FILE *automato = fopen("automato", "w");
    exportar_estados(automato, le);
    fprintf(automato, "\n");
    exportar_alfabeto(automato, alfabeto);
    fprintf(automato, "\n");
    fprintf(automato, "{q%d}\n", ultimo_listaE(le));
    fprintf(automato, "{q%d}\n", primeiro_listaE(le));

    exportar_matriz_transicao(automato, le, alfabeto);
}

void exportar_alfabeto(FILE *f, char *alfabeto) {
    int i;
    fprintf(f, "{");
    for (i = 0; i < strlen(alfabeto) - 1; i++) fprintf(f, "%c,", alfabeto[i]);
    fprintf(f, "%c}", alfabeto[i]);
}

char *gerar_alfabeto(char *exp) {
    int i, alf_c = 0;
    char *aux = malloc(strlen(exp));
    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] != '+' && exp[i] != '*' && exp[i] != '.' && indexOf(exp[i], aux) == -1) {
            aux[alf_c++] = exp[i];
        }
    }

    char *alfabeto = malloc(alf_c);
    printf("Alfabeto: ");
    for (i = 0; i < alf_c; i++) {
        printf("%c ", aux[i]);
        alfabeto[i] = aux[i];
    }
    printf("\n");
    free(aux);
    return alfabeto;
}

int indexOf(char simbolo, char *alfabeto) {
    int i = 0;
    for (i = 0; i < strlen(alfabeto); i++) if (alfabeto[i] == simbolo) break;
    return i < strlen(alfabeto) ? i : -1;
}