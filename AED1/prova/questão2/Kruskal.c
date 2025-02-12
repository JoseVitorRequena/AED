#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTICES 5 // Número de vértices no grafo
#define NUM_ARESTAS 7  // Número de arestas no grafo

// Estrutura para representar uma aresta
struct Edge {
    int src, dest, weight;
};

// Estrutura para representar um grafo
struct Graph {
    int V, E;           // V = número de vértices, E = número de arestas
    struct Edge* edge;   // Array de arestas
};

// Função para criar um grafo
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Estrutura para representar um subconjunto para Union-Find
struct subset {
    int parent;
    int rank;
};

// Função para encontrar o conjunto de um elemento (com path compression)
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    return subsets[i].parent;
}

// Função para unir dois conjuntos (com união por rank)
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // União por rank
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Função para comparar duas arestas com base no peso (usada para ordenação)
int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

// Função que implementa o algoritmo de Kruskal
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; // Array para armazenar a MST
    int e = 0; // Índice usado para result[]
    int i = 0; // Índice usado para arestas ordenadas

    // Passo 1: Ordena todas as arestas em ordem crescente de peso
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    // Aloca memória para criar V subconjuntos
    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));

    // Inicializa os subconjuntos
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Passo 2: Processa cada aresta ordenada
    while (e < V - 1 && i < graph->E) {
        // Passo 3: Escolhe a menor aresta
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // Se a aresta não forma um ciclo, inclui na MST
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Passo 4: Imprime a MST
    printf("Aresta \tPeso\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d \n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    // Exemplo de grafo
    int V = NUM_VERTICES; // Número de vértices
    int E = NUM_ARESTAS;  // Número de arestas
    struct Graph* graph = createGraph(V, E);

    // Adiciona as arestas ao grafo
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 2;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 3;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 8;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 5;

    graph->edge[5].src = 2;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 7;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 4;
    graph->edge[6].weight = 9;

    // Executa o algoritmo de Kruskal
    KruskalMST(graph);

    return 0;
}