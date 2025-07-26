#include <stdio.h>
#include "lista.h"

void lista_criar(ListaSequencial* lista) {
    if (lista != NULL) {
        lista->tamanho_atual = 0;
    }
}

bool lista_esta_vazia(const ListaSequencial* lista) {
    return lista->tamanho_atual == 0;
}

bool lista_esta_cheia(const ListaSequencial* lista) {
    return lista->tamanho_atual == TAMANHO_MAXIMO;
}

int lista_obter_tamanho(const ListaSequencial* lista) {
    return lista->tamanho_atual;
}

bool lista_obter_elemento(const ListaSequencial* lista, int posicao, int* valor_retornado) {
    if (posicao < 1 || posicao > lista->tamanho_atual) {
        fprintf(stderr, "Erro [obter]: Posição %d é inválida.\n", posicao);
        return false;
    }
    *valor_retornado = lista->dados[posicao - 1];
    return true;
}

bool lista_modificar_elemento(ListaSequencial* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho_atual) {
        fprintf(stderr, "Erro [modificar]: Posição %d é inválida.\n", posicao);
        return false;
    }
    lista->dados[posicao - 1] = valor;
    return true;
}

bool lista_inserir_elemento(ListaSequencial* lista, int posicao, int valor) {
    if (lista_esta_cheia(lista)) {
        fprintf(stderr, "Erro [inserir]: A lista está cheia.\n");
        return false;
    }
    if (posicao < 1 || posicao > lista->tamanho_atual + 1) {
        fprintf(stderr, "Erro [inserir]: Posição %d é inválida.\n", posicao);
        return false;
    }

    for (int i = lista->tamanho_atual; i >= posicao; --i) {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[posicao - 1] = valor;
    lista->tamanho_atual++;
    return true;
}

bool lista_retirar_elemento(ListaSequencial* lista, int posicao) {
    if (lista_esta_vazia(lista)) {
        fprintf(stderr, "Erro [retirar]: A lista está vazia.\n");
        return false;
    }
    if (posicao < 1 || posicao > lista->tamanho_atual) {
        fprintf(stderr, "Erro [retirar]: Posição %d é inválida.\n", posicao);
        return false;
    }

    for (int i = posicao - 1; i < lista->tamanho_atual - 1; ++i) {
        lista->dados[i] = lista->dados[i + 1];
    }
    
    lista->tamanho_atual--;
    return true;
}

void lista_imprimir(const ListaSequencial* lista) {
    if (lista_esta_vazia(lista)) {
        printf("Lista: []\n");
        return;
    }
    printf("Lista: [");
    for (int i = 0; i < lista->tamanho_atual; ++i) {
        printf("%d%s", lista->dados[i], (i == lista->tamanho_atual - 1 ? "" : ", "));
    }
    printf("]\n");
}