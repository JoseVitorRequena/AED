#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int criticidade;
    char tipo;
} Problema;

int comparar(const void *a, const void *b) {
    Problema *p1 = (Problema *)a;
    Problema *p2 = (Problema *)b;

    if (p1->tipo != p2->tipo) {
        return (p1->tipo == 'V') ? -1 : 1;
    }

    return p1->criticidade - p2->criticidade;
}

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    Problema problemas[N * M];
    int total = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char entrada[3];
            scanf("%s", entrada);

            problemas[total].criticidade = entrada[0] - '0';
            problemas[total].tipo = entrada[1];
            total++;
        }
    }

    qsort(problemas, total, sizeof(Problema), comparar);

    for (int i = 0; i < total; i++) {
        printf("%d%c\n", problemas[i].criticidade, problemas[i].tipo);
    }

    return 0;
}
