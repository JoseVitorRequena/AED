#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct No {
    int altura;
    int nivel;
    struct No *esquerda;
    struct No *direita;
} No;

typedef struct {
    int nivel;
    int menor_altura;
} MenorPorNivel;

No* criar_no(int altura, int nivel) {
    No* novo = (No*)malloc(sizeof(No));
    novo->altura = altura;
    novo->nivel = nivel;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int altura, int nivel) {
    if (raiz == NULL) {
        return criar_no(altura, nivel);
    }
    
    if (altura < raiz->altura) {
        raiz->esquerda = inserir(raiz->esquerda, altura, nivel + 1);
    } else {
        raiz->direita = inserir(raiz->direita, altura, nivel + 1);
    }
    
    return raiz;
}

int profundidade_maxima(No* raiz) {
    if (raiz == NULL) return -1;
    
    int esq = profundidade_maxima(raiz->esquerda);
    int dir = profundidade_maxima(raiz->direita);
    
    return (esq > dir ? esq : dir) + 1;
}

void atualizar_menores(No* raiz, MenorPorNivel* menores) {
    if (raiz == NULL) return;
    
    if (raiz->altura < menores[raiz->nivel].menor_altura) {
        menores[raiz->nivel].menor_altura = raiz->altura;
        menores[raiz->nivel].nivel = raiz->nivel;
    }
    
    atualizar_menores(raiz->esquerda, menores);
    atualizar_menores(raiz->direita, menores);
}

int comparar(const void* a, const void* b) {
    return ((MenorPorNivel*)a)->nivel - ((MenorPorNivel*)b)->nivel;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int altura;
    scanf("%d", &altura);
    No* raiz = criar_no(altura, 0);
    
    for (int i = 1; i < N; i++) {
        scanf("%d", &altura);
        inserir(raiz, altura, 0);
    }
    
    int max_prof = profundidade_maxima(raiz);
    
    MenorPorNivel* menores = (MenorPorNivel*)malloc((max_prof + 1) * sizeof(MenorPorNivel));
    for (int i = 0; i <= max_prof; i++) {
        menores[i].nivel = i;
        menores[i].menor_altura = INT_MAX;
    }
    
    atualizar_menores(raiz, menores);
    
    qsort(menores, max_prof + 1, sizeof(MenorPorNivel), comparar);
    
    for (int i = 0; i <= max_prof; i++) {
        if (menores[i].menor_altura != INT_MAX) {
            printf("%d %d\n", menores[i].nivel, menores[i].menor_altura);
        }
    }
    
    return 0;
}