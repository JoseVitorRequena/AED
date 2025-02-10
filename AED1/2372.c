#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int dist[MAX][MAX];
int N, M;

void floydWarshall() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int melhorCidade() {
    int menorMaxDist = INF;
    for (int i = 0; i < N; i++) {
        int maxDist = 0;
        for (int j = 0; j < N; j++) {
            if (i != j && dist[i][j] > maxDist)
                maxDist = dist[i][j];
        }
        if (maxDist < menorMaxDist)
            menorMaxDist = maxDist;
    }
    return menorMaxDist;
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    for (int i = 0; i < M; i++) {
        int U, V, W;
        scanf("%d %d %d", &U, &V, &W);
        if (dist[U][V] > W) {
            dist[U][V] = W;
            dist[V][U] = W;
        }
    }
    
    floydWarshall();
    printf("%d\n", melhorCidade());
    
    return 0;
}
