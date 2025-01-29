#include <stdio.h>
#include <stdlib.h>

int comparar_pares(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int comparar_impares(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int quantidade, i, pares[100000], impares[100000], contador_pares = 0, contador_impares = 0;
    
    scanf("%d", &quantidade);
    
    for (i = 0; i < quantidade; i++) {
        int numero;
        scanf("%d", &numero);
        if (numero % 2 == 0) {
            pares[contador_pares++] = numero;
        } else {
            impares[contador_impares++] = numero;
        }
    }
    
    qsort(pares, contador_pares, sizeof(int), comparar_pares);
    qsort(impares, contador_impares, sizeof(int), comparar_impares);
    
    for (i = 0; i < contador_pares; i++) {
        printf("%d\n", pares[i]);
    }
    
    for (i = 0; i < contador_impares; i++) {
        printf("%d\n", impares[i]);
    }
    
    return 0;
}
