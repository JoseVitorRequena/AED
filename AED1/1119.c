#include <stdio.h>

int main() {
    int n, k, m;
    int circulo[20];
    int posicao1, posicao2;
    int contador, removidos;
    
    while (1) {
        scanf("%d %d %d", &n, &k, &m);
        if (n == 0 && k == 0 && m == 0) break;
        
        for (int i = 0; i < n; i++) {
            circulo[i] = i + 1;
        }
        
        posicao1 = n - 1;
        posicao2 = 0;
        removidos = 0;
        
        while (removidos < n) {
            contador = 0;
            while (contador < k) {
                posicao1 = (posicao1 + 1) % n;
                if (circulo[posicao1] != 0) contador++;
            }
            
            contador = 0;
            while (contador < m) {
                posicao2 = (posicao2 - 1 + n) % n;
                if (circulo[posicao2] != 0) contador++;
            }
            
            if (removidos > 0) printf(",");
            
            if (posicao1 == posicao2) {
                printf("%3d", circulo[posicao1]);
                circulo[posicao1] = 0;
                removidos++;
            } else {
                printf("%3d%3d", circulo[posicao1], circulo[posicao2]);
                circulo[posicao1] = circulo[posicao2] = 0;
                removidos += 2;
            }
        }
        printf("\n");
    }
    return 0;
}