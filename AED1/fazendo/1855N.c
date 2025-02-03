#include <stdio.h>

#define MAX 100

char mapa[MAX][MAX];
int visitado[MAX][MAX];
int largura, altura;

int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0};
char direcoes[] = {'>', '<', 'v', '^'};

int dentro_do_mapa(int x, int y) {
    return x >= 0 && x < altura && y >= 0 && y < largura;
}

int encontrar_bau(int x, int y) {
    while (1) {
        if (!dentro_do_mapa(x, y)) {
            return 0; 
        }

        if (visitado[x][y]) {
            return 0; 
        }

        if (mapa[x][y] == '*') {
            return 1; 
        }

        visitado[x][y] = 1;  

        int encontrou_direcao = 0;
        for (int i = 0; i < 4; i++) {
            if (mapa[x][y] == direcoes[i]) {
                x += dx[i];
                y += dy[i];
                encontrou_direcao = 1;
                break;
            }
        }

        if (!encontrou_direcao) {
            return 0; 
        }
    }
}

int main() {
    scanf("%d", &largura);
    scanf("%d", &altura);

    for (int i = 0; i < altura; i++) {
        scanf("%s", mapa[i]);
    }

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            visitado[i][j] = 0;
        }
    }

    if (mapa[0][0] == '*') {
        printf("*\n");
        return 0;
    }

    int resultado = encontrar_bau(0, 0);

    if (resultado) {
        printf("*\n");
    } else {
        printf("!\n");
    }

    return 0;
}
