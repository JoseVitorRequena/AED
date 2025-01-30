#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000

int contarTrocas(int arr[], int N) {
    int visitado[MAX_N + 1] = {0};
    int trocas = 0;

    for (int i = 0; i < N; i++) {
        if (visitado[i] || arr[i] == i + 1) {
            continue;
        }

        int tamanhoCiclo = 0;
        int j = i;

        while (!visitado[j]) {
            visitado[j] = 1;
            j = arr[j] - 1;
            tamanhoCiclo++;
        }

        if (tamanhoCiclo > 1) {
            trocas += (tamanhoCiclo - 1);
        }
    }

    return trocas;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        int arr[MAX_N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        printf("%d\n", contarTrocas(arr, N));
    }

    return 0;
}
