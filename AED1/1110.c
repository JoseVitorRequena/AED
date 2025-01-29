#include <stdio.h>

int main() {
    int n;
    int fila[50];
    int inicio, fim, tamanho;
    int primeiro = 1;
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        
        inicio = 0;
        fim = n - 1;
        tamanho = n;
        
        for (int i = 0; i < n; i++) {
            fila[i] = i + 1;
        }
        
        printf("Discarded cards:");
        
        while (tamanho > 1) {
            if (tamanho == n) {
                printf(" %d", fila[inicio]);
            } else {
                printf(", %d", fila[inicio]);
            }
            
            inicio = (inicio + 1) % n;
            tamanho--;
            
            fim = (fim + 1) % n;
            fila[fim] = fila[inicio];
            inicio = (inicio + 1) % n;
        }
        
        printf("\nRemaining card: %d\n", fila[inicio]);
    }
    return 0;
}