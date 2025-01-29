#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_M 1000
#define MAX_PALAVRA 17

typedef struct {
    char palavra[MAX_PALAVRA];
    double valor;
} HayPoint;

int main() {
    int M, N, i, j;
    char palavra[MAX_PALAVRA];
    double valor;
    
    scanf("%d %d", &M, &N);
    HayPoint dicionario[MAX_M];
    
    for (i = 0; i < M; i++) {
        scanf("%s %lf", dicionario[i].palavra, &dicionario[i].valor);
    }
    
    char descricao[1001];
    double total;
    
    for (i = 0; i < N; i++) {
        total = 0.0;
        while (scanf("%s", palavra) && strcmp(palavra, ".") != 0) {
            for (j = 0; j < M; j++) {
                if (strcmp(dicionario[j].palavra, palavra) == 0) {
                    total += dicionario[j].valor;
                    break;
                }
            }
        }
        printf("%.0lf\n", total);
    }
    
    return 0;
}