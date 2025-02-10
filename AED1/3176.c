#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOME 21  

typedef struct {
    char nome[MAX_NOME];
    int idade;
} Duende;

int comparar_duendes(const void* a, const void* b) {
    Duende* d1 = (Duende*)a;
    Duende* d2 = (Duende*)b;
    
    if (d1->idade != d2->idade) {
        return d2->idade - d1->idade;
    }
    
    return strcmp(d1->nome, d2->nome);
}

int main() {
    int N;
    scanf("%d", &N);
    
    Duende* duendes = (Duende*)malloc(N * sizeof(Duende));
    
    for (int i = 0; i < N; i++) {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }
    qsort(duendes, N, sizeof(Duende), comparar_duendes);
    
    int num_times = N / 3;
    
    for (int i = 0; i < num_times; i++) {
        int lider = i;                    
        int entregador = i + num_times;   
        int piloto = i + 2 * num_times;  
        
        printf("Time %d\n", i + 1);
        printf("%s %d\n", duendes[lider].nome, duendes[lider].idade);
        printf("%s %d\n", duendes[entregador].nome, duendes[entregador].idade);
        printf("%s %d\n", duendes[piloto].nome, duendes[piloto].idade);
        printf("\n");
    }
    
    free(duendes);
    return 0;
}