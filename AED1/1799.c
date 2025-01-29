#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_PONTOS 4001
#define MAX_CONEXOES 5001
#define MAX_NOME 51

typedef struct No {
    int destino;
    struct No* proximo;
} No;

typedef struct {
    int num_vertices;
    No* lista_adj[MAX_PONTOS];
    char nomes[MAX_PONTOS][MAX_NOME];
} Grafo;

typedef struct {
    int vertice;
    int distancia;
} ElementoHeap;

void trocar(ElementoHeap *a, ElementoHeap *b) {
    ElementoHeap temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(ElementoHeap *heap, int tamanho, int idx) {
    int menor = idx;
    int esq = 2 * idx + 1;
    int dir = 2 * idx + 2;

    if (esq < tamanho && heap[esq].distancia < heap[menor].distancia)
        menor = esq;

    if (dir < tamanho && heap[dir].distancia < heap[menor].distancia)
        menor = dir;

    if (menor != idx) {
        trocar(&heap[idx], &heap[menor]);
        min_heapify(heap, tamanho, menor);
    }
}

void inicializar_grafo(Grafo* grafo) {
    grafo->num_vertices = 0;
    for (int i = 0; i < MAX_PONTOS; i++) {
        grafo->lista_adj[i] = NULL;
    }
}

void adicionar_aresta(Grafo* grafo, int origem, int destino) {
    No* novo_no = malloc(sizeof(No));
    novo_no->destino = destino;
    novo_no->proximo = grafo->lista_adj[origem];
    grafo->lista_adj[origem] = novo_no;

    novo_no = malloc(sizeof(No));
    novo_no->destino = origem;
    novo_no->proximo = grafo->lista_adj[destino];
    grafo->lista_adj[destino] = novo_no;
}

int bfs_distancia(Grafo* grafo, int inicio, int fim) {
    int distancia[MAX_PONTOS];
    int visitado[MAX_PONTOS] = {0};
    int fila[MAX_PONTOS], frente = 0, tras = 0;

    for (int i = 0; i < grafo->num_vertices; i++) {
        distancia[i] = INT_MAX;
    }
    
    distancia[inicio] = 0;
    visitado[inicio] = 1;
    fila[tras++] = inicio;

    while (frente < tras) {
        int atual = fila[frente++];
        
        if (atual == fim) {
            return distancia[atual];
        }

        for (No* v = grafo->lista_adj[atual]; v != NULL; v = v->proximo) {
            if (!visitado[v->destino]) {
                visitado[v->destino] = 1;
                distancia[v->destino] = distancia[atual] + 1;
                fila[tras++] = v->destino;
            }
        }
    }

    return -1;
}

int main() {
    int num_pontos, num_conexoes;
    Grafo grafo;
    
    scanf("%d %d", &num_pontos, &num_conexoes);
    inicializar_grafo(&grafo);

    int indice_entrada = -1, indice_queijo = -1, indice_saida = -1;

    for (int i = 0; i < num_conexoes; i++) {
        char origem[MAX_NOME], destino[MAX_NOME];
        scanf("%s %s", origem, destino);

        int idx_origem = -1, idx_destino = -1;
        
        for (int j = 0; j < grafo.num_vertices; j++) {
            if (strcmp(grafo.nomes[j], origem) == 0) {
                idx_origem = j;
                break;
            }
        }
        if (idx_origem == -1) {
            idx_origem = grafo.num_vertices;
            strcpy(grafo.nomes[grafo.num_vertices], origem);
            grafo.num_vertices++;
        }

        for (int j = 0; j < grafo.num_vertices; j++) {
            if (strcmp(grafo.nomes[j], destino) == 0) {
                idx_destino = j;
                break;
            }
        }
        if (idx_destino == -1) {
            idx_destino = grafo.num_vertices;
            strcpy(grafo.nomes[grafo.num_vertices], destino);
            grafo.num_vertices++;
        }

        adicionar_aresta(&grafo, idx_origem, idx_destino);

        if (strcmp(origem, "Entrada") == 0) indice_entrada = idx_origem;
        if (strcmp(destino, "Entrada") == 0) indice_entrada = idx_destino;
        if (strcmp(origem, "*") == 0) indice_queijo = idx_origem;
        if (strcmp(destino, "*") == 0) indice_queijo = idx_destino;
        if (strcmp(origem, "Saida") == 0) indice_saida = idx_origem;
        if (strcmp(destino, "Saida") == 0) indice_saida = idx_destino;
    }

    int caminho1 = bfs_distancia(&grafo, indice_entrada, indice_queijo);
    int caminho2 = bfs_distancia(&grafo, indice_queijo, indice_saida);

    printf("%d\n", caminho1 + caminho2);

    return 0;
}