#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000

typedef struct {
    int chegada;
    int saida;
} Carro;

Carro estacionamento[MAX_N];
int topo = -1;

void push(Carro c, int K) {
    if (topo < K - 1) {
        estacionamento[++topo] = c;
    }
}

void pop() {
    if (topo >= 0) {
        topo--;
    }
}

int main() {
    int N, K;

    while (1) {
        scanf("%d %d", &N, &K);
        if (N == 0 && K == 0) break;

        topo = -1; 

        int possivel = 1; 

        for (int i = 0; i < N; i++) {
            Carro c;
            scanf("%d %d", &c.chegada, &c.saida);

            while (topo >= 0 && estacionamento[topo].saida <= c.chegada) {
                pop();
            }

            push(c, K);

            if (topo >= K) {
                possivel = 0;
            }
        }

        printf("%s\n", possivel ? "Sim" : "Nao");
    }

    return 0;
}
