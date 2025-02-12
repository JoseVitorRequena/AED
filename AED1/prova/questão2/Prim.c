#include <stdio.h>
#include <limits.h>

#define V 5 // Número de vértices no grafo

// Função para encontrar o vértice com a chave de valor mínimo que ainda não está na MST
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Função para imprimir a MST
void printMST(int parent[], int graph[V][V]) {
    printf("Aresta \tPeso\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Função que implementa o algoritmo de Prim para encontrar a MST
void primMST(int graph[V][V]) {
    int parent[V];  // Array para armazenar a MST
    int key[V];     // Valores das chaves usados para escolher a aresta de menor peso
    int mstSet[V];  // Array para representar os vértices incluídos na MST

    // Inicializa todas as chaves como infinito e mstSet[] como falso (0)
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    // Inclui o primeiro vértice na MST
    key[0] = 0;     // A chave do primeiro vértice é 0 para que ele seja escolhido primeiro
    parent[0] = -1; // O primeiro vértice é a raiz da MST

    // A MST terá V vértices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Escolhe o vértice com a menor chave que ainda não está na MST
        mstSet[u] = 1; // Adiciona o vértice à MST

        // Atualiza as chaves e os pais dos vértices adjacentes ao vértice escolhido
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Imprime a MST
    printMST(parent, graph);
}

int main() {
    // Exemplo de grafo representado por uma matriz de adjacência
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph); // Executa o algoritmo de Prim

    return 0;
}