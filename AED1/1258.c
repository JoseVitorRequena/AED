#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Camiseta {
    char nome[100];
    char cor[10];
    char tamanho;
};

int compara(const void *a, const void *b) {
    struct Camiseta *ca = (struct Camiseta *)a;
    struct Camiseta *cb = (struct Camiseta *)b;
    
    int comp_cor = strcmp(ca->cor, cb->cor);
    if (comp_cor != 0) return comp_cor;
    
    if (ca->tamanho != cb->tamanho)
        return cb->tamanho - ca->tamanho;
        
    return strcmp(ca->nome, cb->nome);
}

int main() {
    int n, comeco = 0;
    struct Camiseta camisetas[60];
    char nome[100];
    
    while (1) {
        scanf("%d", &n);
        getchar();
        
        if (n == 0) break;
        if (comeco != 0) printf("\n"); 
        for (int i = 0; i < n; i++) {
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0;
            strcpy(camisetas[i].nome, nome);
            
            scanf("%s %c", camisetas[i].cor, &camisetas[i].tamanho);
            getchar();
        }
        
        qsort(camisetas, n, sizeof(struct Camiseta), compara);
        
        for (int i = 0; i < n; i++) {
            printf("%s %c %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }
        comeco++;
    }
    
    return 0;
}