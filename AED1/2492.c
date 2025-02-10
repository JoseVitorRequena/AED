#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char origem[31];
    char destino[31];
} Conexao;

int main() {
    int T;
    Conexao conexoes[MAX];
    char origens[MAX][31], destinos[MAX][31];
    
    while (scanf("%d", &T) && T != 0) {
        int mapOrigem[MAX] = {0}, mapDestino[MAX] = {0};
        int numOrigens = 0, numDestinos = 0;
        
        for (int i = 0; i < T; i++) {
            scanf(" %30s -> %30s", conexoes[i].origem, conexoes[i].destino);
            
            int foundOrigem = -1, foundDestino = -1;
            for (int j = 0; j < numOrigens; j++) {
                if (strcmp(origens[j], conexoes[i].origem) == 0) {
                    foundOrigem = j;
                    break;
                }
            }
            if (foundOrigem == -1) {
                strcpy(origens[numOrigens], conexoes[i].origem);
                foundOrigem = numOrigens++;
            }
            mapOrigem[foundOrigem]++;
            
            for (int j = 0; j < numDestinos; j++) {
                if (strcmp(destinos[j], conexoes[i].destino) == 0) {
                    foundDestino = j;
                    break;
                }
            }
            if (foundDestino == -1) {
                strcpy(destinos[numDestinos], conexoes[i].destino);
                foundDestino = numDestinos++;
            }
            mapDestino[foundDestino]++;
        }
        
        int isFunction = 1, isInvertible = 1;
        for (int i = 0; i < numOrigens; i++) {
            if (mapOrigem[i] > 1) {
                isFunction = 0;
                break;
            }
        }
        
        if (isFunction) {
            for (int i = 0; i < numDestinos; i++) {
                if (mapDestino[i] > 1) {
                    isInvertible = 0;
                    break;
                }
            }
        }
        
        if (!isFunction) {
            printf("Not a function.\n");
        } else if (isInvertible) {
            printf("Invertible.\n");
        } else {
            printf("Not invertible.\n");
        }
    }
    return 0;
}