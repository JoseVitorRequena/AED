#include <stdio.h>
#include <stdlib.h>

#define E 4 // Número de arestas
#define V 4 // Número de vértices

// Estrutura para representar uma aresta
struct Aresta {
    int origem;
    int destino;
    int peso; // Opcional, para grafos ponderados
};

// Função para criar um grafo representado por uma lista de arestas
void criarGrafo(struct Aresta grafo[]) {
    // Aresta 0 -> 1
    grafo[0].origem = 0;
    grafo[0].destino = 1;
    grafo[0].peso = 2; // Peso opcional

    // Aresta 0 -> 2
    grafo[1].origem = 0;
    grafo[1].destino = 2;
    grafo[1].peso = 3;

    // Aresta 1 -> 2
    grafo[2].origem = 1;
    grafo[2].destino = 2;
    grafo[2].peso = 1;

    // Aresta 2 -> 3
    grafo[3].origem = 2;
    grafo[3].destino = 3;
    grafo[3].peso = 5;
}

// Função para imprimir o grafo
void imprimirGrafo(struct Aresta grafo[]) {
    printf("Lista de Arestas:\n");
    for (int i = 0; i < E; i++) {
        printf("Aresta %d: %d -> %d (Peso: %d)\n", i, grafo[i].origem, grafo[i].destino, grafo[i].peso);
    }
}

int main() {
    struct Aresta grafo[E]; // Lista de arestas

    criarGrafo(grafo);
    imprimirGrafo(grafo);

    return 0;
}