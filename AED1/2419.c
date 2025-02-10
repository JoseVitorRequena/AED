#include <stdio.h>

#define MAX 1000

char mapa[MAX][MAX];
int M, N;

int ehCosta(int i, int j) {
    if (mapa[i][j] != '#') return 0;
    if (i == 0 || i == M - 1 || j == 0 || j == N - 1) return 1;
    if (mapa[i-1][j] == '.' || mapa[i+1][j] == '.' || mapa[i][j-1] == '.' || mapa[i][j+1] == '.')
        return 1;
    return 0;
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        scanf("%s", mapa[i]);
    }
    
    int costa = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (ehCosta(i, j)) costa++;
        }
    }
    
    printf("%d\n", costa);
    return 0;
}
