#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void bfs(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    No* fila[500];
    int inicio = 0, fim = 0;

    fila[fim++] = raiz;

    while (inicio < fim) {
        No* atual = fila[inicio++];
        printf("%d", atual->valor);

        if (inicio < fim || atual->esq || atual->dir) {
            printf(" ");
        }

        if (atual->esq) {
            fila[fim++] = atual->esq;
        }
        if (atual->dir) {
            fila[fim++] = atual->dir;
        }
    }
    printf("\n");
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    int C, N, valor;
    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {
        scanf("%d", &N);
        No* raiz = NULL;

        for (int i = 0; i < N; i++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso);
        bfs(raiz);

        liberarArvore(raiz);

        if (caso < C) {
            printf("\n");
        }
    }

    return 0;
}