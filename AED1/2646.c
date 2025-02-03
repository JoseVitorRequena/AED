#include <stdio.h>
#include <string.h>

#define TAM_ALFABETO 26
#define MAX_PALAVRA 50

int matriz[TAM_ALFABETO][TAM_ALFABETO];

void floyd_warshall() {
    for (int k = 0; k < TAM_ALFABETO; k++) {
        for (int i = 0; i < TAM_ALFABETO; i++) {
            for (int j = 0; j < TAM_ALFABETO; j++) {
                if (matriz[i][k] && matriz[k][j]) {
                    matriz[i][j] = 1;
                }
            }
        }
    }
}

int palavras_iguais(char *p1, char *p2) {
    int tam1 = strlen(p1), tam2 = strlen(p2);
    if (tam1 != tam2) return 0;
    for (int i = 0; i < tam1; i++) {
        if (p1[i] != p2[i] && !matriz[p1[i] - 'a'][p2[i] - 'a']) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    memset(matriz, 0, sizeof(matriz));
    for (int i = 0; i < TAM_ALFABETO; i++) {
        matriz[i][i] = 1;
    }
    for (int i = 0; i < m; i++) {
        char origem, destino;
        scanf(" %c %c", &origem, &destino);
        matriz[origem - 'a'][destino - 'a'] = 1;
    }
    floyd_warshall();
    for (int i = 0; i < n; i++) {
        char palavra1[MAX_PALAVRA + 1], palavra2[MAX_PALAVRA + 1];
        scanf("%s %s", palavra1, palavra2);
        printf("%s\n", palavras_iguais(palavra1, palavra2) ? "yes" : "no");
    }
    return 0;
}
