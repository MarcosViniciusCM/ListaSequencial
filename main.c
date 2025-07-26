// main.c

#include <stdio.h>
#include "lista.h"

int main() {
    printf("--- Inciando Testes da Lista Sequencial (versão C) ---\n");

    ListaSequencial minha_lista;
    lista_criar(&minha_lista);
    printf("Lista criada.\n");

    printf("A lista está vazia? %s\n", lista_esta_vazia(&minha_lista) ? "Sim" : "Não");
    lista_imprimir(&minha_lista);
    printf("Tamanho atual: %d\n", lista_obter_tamanho(&minha_lista));
    printf("-----------------------------------------\n");

    printf("Inserindo elementos...\n");
    lista_inserir_elemento(&minha_lista, 1, 10);
    lista_inserir_elemento(&minha_lista, 2, 30);
    lista_inserir_elemento(&minha_lista, 2, 20);
    lista_imprimir(&minha_lista);
    printf("Tamanho atual: %d\n", lista_obter_tamanho(&minha_lista));
    printf("A lista está vazia? %s\n", lista_esta_vazia(&minha_lista) ? "Sim" : "Não");
    printf("-----------------------------------------\n");

    int valor;
    if (lista_obter_elemento(&minha_lista, 2, &valor)) {
        printf("Elemento na posição 2: %d\n", valor);
    }
    printf("Modificando elemento na posição 3 para 99...\n");
    lista_modificar_elemento(&minha_lista, 3, 99);
    lista_imprimir(&minha_lista);
    printf("-----------------------------------------\n");

    printf("Retirando elemento da posição 1...\n");
    lista_retirar_elemento(&minha_lista, 1);
    lista_imprimir(&minha_lista);
    printf("Tamanho atual: %d\n", lista_obter_tamanho(&minha_lista));
    printf("-----------------------------------------\n");
    
    printf("Tentando inserir na posição 5 (inválida)...\n");
    lista_inserir_elemento(&minha_lista, 5, 500);
    printf("Tentando obter elemento da posição 0 (inválida)...\n");
    lista_obter_elemento(&minha_lista, 0, &valor);
    printf("Tentando retirar da posição 3 (inválida)...\n");
    lista_retirar_elemento(&minha_lista, 3);
    lista_imprimir(&minha_lista);

    printf("\n--- Testes Finalizados ---\n");

    return 0;
}