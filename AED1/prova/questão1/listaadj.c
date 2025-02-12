#include <stdio.h>
#include <stdlib.h>

#define V 4 // Número de vértices

// Estrutura para um nó da lista de adjacência
struct Node {
    int dest;
    struct Node* next;
};

// Estrutura para o grafo
struct Graph {
    struct Node* head[V];
};

// Função para criar um novo nó
struct Node* criarNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função para inicializar o grafo
struct Graph* criarGrafo() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < V; i++) {
        graph->head[i] = NULL;
    }
    return graph;
}

// Função para adicionar uma aresta
void adicionarAresta(struct Graph* graph, int origem, int destino) {
    struct Node* newNode = criarNode(destino);
    newNode->next = graph->head[origem];
    graph->head[origem] = newNode;

    // Para grafos não direcionados, adicione a aresta no sentido contrário também
    newNode = criarNode(origem);
    newNode->next = graph->head[destino];
    graph->head[destino] = newNode;
}

// Função para imprimir o grafo
void imprimirGrafo(struct Graph* graph) {
    for (int i = 0; i < V; i++) {
        struct Node* temp = graph->head[i];
        printf("Lista de adjacência do vértice %d\n", i);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = criarGrafo();

    adicionarAresta(graph, 0, 1);
    adicionarAresta(graph, 0, 2);
    adicionarAresta(graph, 1, 2);
    adicionarAresta(graph, 2, 3);

    imprimirGrafo(graph);

    return 0;
}