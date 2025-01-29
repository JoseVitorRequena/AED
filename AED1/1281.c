#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    double preco;
} Produto;

int main() {
    int N, M, P, i, j;
    char produto_nome[51];
    int quantidade;
    
    scanf("%d", &N);
    
    while (N--) {
        scanf("%d", &M);
        Produto produtos[M];
        
        for (i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }
        
        scanf("%d", &P);
        double total = 0.0;
        
        for (i = 0; i < P; i++) {
            scanf("%s %d", produto_nome, &quantidade);
            
            for (j = 0; j < M; j++) {
                if (strcmp(produtos[j].nome, produto_nome) == 0) {
                    total += produtos[j].preco * quantidade;
                    break;
                }
            }
        }
        
        printf("R$ %.2lf\n", total);
    }
    
    return 0;
}