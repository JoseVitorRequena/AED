#include <stdio.h>
#include <stdlib.h>

#define V 4 // Número de vértices

void inicializarMatriz(int matriz[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            matriz[i][j] = 0;
        }
    }
}

void adicionarAresta(int matriz[V][V], int origem, int destino) {
    matriz[origem][destino] = 1;
    matriz[destino][origem] = 1; // Para grafos não direcionados
}

void imprimirMatriz(int matriz[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[V][V];
    inicializarMatriz(matriz);

    adicionarAresta(matriz, 0, 1);
    adicionarAresta(matriz, 0, 2);
    adicionarAresta(matriz, 1, 2);
    adicionarAresta(matriz, 2, 3);

    imprimirMatriz(matriz);

    return 0;
}