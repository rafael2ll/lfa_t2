cmake_minimum_required(VERSION 3.9)
project(lfa_t2 C)

set(CMAKE_C_STANDARD 11)

add_executable(lfa_t2 automato.c pilha.c pilha.h automato_helper.c automato_helper.h arvore.c arvore.h lista_estado.c lista_estado.h lista_transicao.c lista_transicao.h)