#include <stdio.h>
#include <limits.h>

#define V 6 // Número de vértices no grafo

// Função para encontrar o vértice com a menor distância que ainda não foi processado
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Função para imprimir o array de distâncias
void printSolution(int dist[]) {
    printf("Vértice \t Distância da Origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Função que implementa o algoritmo de Dijkstra para um grafo representado por uma matriz de adjacência
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Array para armazenar as distâncias mais curtas da origem para cada vértice
    int sptSet[V]; // Array para verificar se um vértice já foi processado

    // Inicializa todas as distâncias como infinito e sptSet[] como falso (0)
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    // A distância da origem para ela mesma é sempre 0
    dist[src] = 0;

    // Encontra o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Escolhe o vértice com a menor distância
        sptSet[u] = 1; // Marca o vértice como processado

        // Atualiza as distâncias dos vértices adjacentes ao vértice escolhido
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Imprime o array de distâncias
    printSolution(dist);
}

int main() {
    // Exemplo de grafo representado por uma matriz de adjacência
    int graph[V][V] = {
        {0, 2, 0, 0, 0, 0},
        {2, 0, 4, 1, 0, 0},
        {0, 4, 0, 0, 3, 0},
        {0, 1, 0, 0, 0, 2},
        {0, 0, 3, 0, 0, 0},
        {0, 0, 0, 2, 0, 0}
    };

    dijkstra(graph, 0); // Executa o algoritmo de Dijkstra a partir do vértice 0

    return 0;
}