#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            int entrada[n], topo = -1, valido = 1, vagao;
            int *pilha = malloc(n * sizeof(int));

            scanf("%d", &vagao);
            if (vagao == 0) {
                printf("\n");
                free(pilha);
                break;
            }

            entrada[0] = vagao;
            for (int i = 1; i < n; i++) {
                scanf("%d", &entrada[i]);
            }

            int esperado = 1;
            for (int i = 0; i < n; i++) {
                while (esperado <= entrada[i]) {
                    pilha[++topo] = esperado++;
                }
                if (pilha[topo] == entrada[i]) {
                    topo--;
                } else {
                    valido = 0;
                    break;
                }
            }

            printf(valido ? "Yes\n" : "No\n");
            free(pilha);
        }
    }

    return 0;
}
