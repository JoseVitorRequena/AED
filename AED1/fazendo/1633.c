#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int t, c;
} Processo;

typedef struct {
    Processo *dados;
    int tamanho;
} MinHeap;

void swap(Processo *a, Processo *b) {
    Processo temp = *a;
    *a = *b;
    *b = temp;
}

void inserirHeap(MinHeap *heap, Processo p) {
    int i = heap->tamanho++;
    heap->dados[i] = p;
    while (i > 0 && heap->dados[(i - 1) / 2].c > heap->dados[i].c) {
        swap(&heap->dados[(i - 1) / 2], &heap->dados[i]);
        i = (i - 1) / 2;
    }
}

Processo removerHeap(MinHeap *heap) {
    Processo raiz = heap->dados[0];
    heap->dados[0] = heap->dados[--heap->tamanho];
    int i = 0;
    while (2 * i + 1 < heap->tamanho) {
        int menor = 2 * i + 1;
        if (menor + 1 < heap->tamanho && heap->dados[menor + 1].c < heap->dados[menor].c)
            menor++;
        if (heap->dados[i].c <= heap->dados[menor].c) break;
        swap(&heap->dados[i], &heap->dados[menor]);
        i = menor;
    }
    return raiz;
}

int comparar(const void *a, const void *b) {
    return ((Processo *)a)->t - ((Processo *)b)->t;
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        Processo processos[N];
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &processos[i].t, &processos[i].c);
        }

        qsort(processos, N, sizeof(Processo), comparar);
        MinHeap heap = {malloc(N * sizeof(Processo)), 0};
        
        long long tempo_atual = 0, espera_total = 0;
        int indice = 0;

        while (indice < N || heap.tamanho > 0) {
            if (heap.tamanho == 0) {
                tempo_atual = processos[indice].t;
            }
            while (indice < N && processos[indice].t <= tempo_atual) {
                inserirHeap(&heap, processos[indice++]);
            }
            Processo p = removerHeap(&heap);
            espera_total += tempo_atual - p.t;
            tempo_atual += p.c;
        }

        printf("%lld\n", espera_total);
        free(heap.dados);
    }
    return 0;
}
