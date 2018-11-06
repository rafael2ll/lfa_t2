#include "arvore.h"
#include "automato_helper.h"

int main(int argc, char const *argv[]) {
    /* Arvore arv = criar_arvore();
     ListaE matriz_transicao;
     int counter = 0;
     char  alfabeto[] = {'0', '1'};
     char * expressao_regular = ".*+011+10";


     criar_listaEstados(&matriz_transicao);

     ListaE s1 = simbolo(0, &counter, strlen(alfabeto));
     ListaE s2 = simbolo(1, &counter, strlen(alfabeto));

     print(s1, strlen(alfabeto));
     printf("----------------------------------------------------\n");
     print(s2, strlen(alfabeto));
     printf("----------------------------------------------------\n");

     uniao(matriz_transicao, s1, s2, &counter, strlen(alfabeto));
     fechamento(matriz_transicao, &counter, strlen(alfabeto));
     print(matriz_transicao, strlen(alfabeto));

     int i = 0;

     for(i = 0; i< strlen(expressao_regular); i++){
         inserir_profundidade(&arv, alfabeto, expressao_regular[i]);
     }
     print_arvore(arv);
     printf("\n");*/
    gera_automato(NULL);
    return 0;
}
