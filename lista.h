#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#define TAMANHO_MAXIMO 100
typedef struct {
    int dados[TAMANHO_MAXIMO];
    int tamanho_atual;
} ListaSequencial;

void lista_criar(ListaSequencial* lista);

bool lista_esta_vazia(const ListaSequencial* lista);

bool lista_esta_cheia(const ListaSequencial* lista);

int lista_obter_tamanho(const ListaSequencial* lista);

bool lista_obter_elemento(const ListaSequencial* lista, int posicao, int* valor_retornado);

bool lista_modificar_elemento(ListaSequencial* lista, int posicao, int valor);

bool lista_inserir_elemento(ListaSequencial* lista, int posicao, int valor);

bool lista_retirar_elemento(ListaSequencial* lista, int posicao);

void lista_imprimir(const ListaSequencial* lista);

#endif