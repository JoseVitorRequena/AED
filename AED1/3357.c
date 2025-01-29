#include <stdio.h>
#include <string.h>

int main() {
    int N;
    float L, Q;
    char nomes[10][13];

    scanf("%d %f %f", &N, &L, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%s", nomes[i]);
    }

    int rico = 0;
    float ultima_cuia = 0.0;

    int i = 0;
    while (L > 0) {
        if (L >= Q) {
            L -= Q;
            ultima_cuia = Q;
        } else {
            ultima_cuia = L;
            L = 0;
        }
        rico = i;
        i = (i + 1) % N;
    }
    printf("%s %.1f\n", nomes[rico], ultima_cuia);
    return 0;
}
