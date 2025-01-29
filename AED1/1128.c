#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2001

int grafo[MAX][MAX];
int grafo_reverso[MAX][MAX];
int visitado[MAX];
int resultados[MAX];
int resultadoCont = 0;

void reset_grafos(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grafo[i][j] = 0;
            grafo_reverso[i][j] = 0;
        }
    }
}

void reset_visitado(int n) {
    for (int i = 1; i <= n; i++) {
        visitado[i] = 0;
    }
}

void dfs(int node, int n, int grafo[MAX][MAX]) {
    visitado[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (grafo[node][i] && !visitado[i]) {
            dfs(i, n, grafo);
        }
    }
}

int fortemente_conectado(int n) {
    reset_visitado(n);
    dfs(1, n, grafo);
    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            return 0;
        }
    }

    reset_visitado(n);
    dfs(1, n, grafo_reverso);
    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n, m;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }

        reset_grafos(n);

        for (int i = 0; i < m; i++) {
            int v, w, p;
            scanf("%d %d %d", &v, &w, &p);
            grafo[v][w] = 1;
            grafo_reverso[w][v] = 1;
            if (p == 2) {
                grafo[w][v] = 1;
                grafo_reverso[v][w] = 1;
            }
        }

        resultados[resultadoCont++] = fortemente_conectado(n);
    }

    for (int i = 0; i < resultadoCont; i++) {
        printf("%d\n", resultados[i]);
    }

    return 0;
}
