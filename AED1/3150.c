#include <stdio.h>
#include <string.h>

#define MAX_PONTOS 1000
#define MAX_CAMINHOS 10000

int grafo[MAX_PONTOS][MAX_PONTOS];
int grau[MAX_PONTOS];
int visitado[MAX_PONTOS];

void dfs(int ponto) {
    visitado[ponto] = 1;
    for (int i = 0; i < MAX_PONTOS; i++) {
        if (grafo[ponto][i] && !visitado[i]) {
            dfs(i);
        }
    }
}

int main() {
    int pontos, caminhos;
    scanf("%d %d", &pontos, &caminhos);
    memset(grafo, 0, sizeof(grafo));
    memset(grau, 0, sizeof(grau));
    memset(visitado, 0, sizeof(visitado));
    
    for (int i = 0; i < caminhos; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        grafo[a][b] = 1;
        grafo[b][a] = 1;
        grau[a]++;
        grau[b]++;
    }
    
    for (int i = 0; i < pontos; i++) {
        if (grau[i] % 2 != 0) {
            printf("Rambo esta perdido\n");
            return 0;
        }
    }
    
    dfs(0);
    for (int i = 0; i < pontos; i++) {
        if (grau[i] > 0 && !visitado[i]) {
            printf("Rambo esta perdido\n");
            return 0;
        }
    }
    printf("Rambo esta salvo\n");
    return 0;
}
