#include <stdio.h>

int contarTrocas(int *vagoes, int tamanho) {
    int trocas = 0;
    int temp;
    
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vagoes[j] > vagoes[j + 1]) {
                temp = vagoes[j];
                vagoes[j] = vagoes[j + 1];
                vagoes[j + 1] = temp;
                trocas++;
            }
        }
    }
    return trocas;
}

int main() {
    int qtdTestes;
    int tamanho;
    int vagoes[50];
    
    scanf("%d", &qtdTestes);
    
    for (int i = 0; i < qtdTestes; i++) {
        scanf("%d", &tamanho);
        
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &vagoes[j]);
        }
        
        int resultado = contarTrocas(vagoes, tamanho);
        printf("Optimal train swapping takes %d swaps.\n", resultado);
    }
    
    return 0;
}