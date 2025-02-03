#include <stdio.h>
#include <string.h>

int main() {
    int qtd_caixas, x, y, num, i, j;
    int contagem[101] = {0};
    int estante[10000]; 
    
    while (scanf("%d", &qtd_caixas) != EOF) {
        memset(contagem, 0, sizeof(contagem)); 
        
        for (i = 0; i < qtd_caixas; i++) {
            scanf("%d %d", &x, &y);
            for (j = x; j <= y; j++) {
                contagem[j]++;
            }
        }
        
        int prateleira = 0;
        for (i = 1; i <= 100; i++) {
            while (contagem[i]--) {
                estante[prateleira++] = i;
            }
        }
        
        scanf("%d", &num);
        int encontrado = 0, inicio = -1, fim = -1;
        for (i = 0; i < prateleira; i++) {
            if (estante[i] == num) {
                if (!encontrado) {
                    inicio = i;
                    encontrado = 1;
                }
                fim = i;
            }
        }
        
        if (encontrado) {
            printf("%d found from %d to %d\n", num, inicio, fim);
        } else {
            printf("%d not found\n", num);
        }
    }
    
    return 0;
}
