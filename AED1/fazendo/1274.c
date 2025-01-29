#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 21
#define MAX_CURSOS 1600  

typedef struct {
    int pos;
    bool calculado;
} CacheItem;

CacheItem cache[MAX_N][MAX_CURSOS];

int simular_rede_dp(const int* cursos, int num_cursos, int entrada, int n) {
    if (cache[entrada][num_cursos].calculado) {
        return cache[entrada][num_cursos].pos;
    }
    
    int pos = entrada - 1;
    for (int i = 0; i < num_cursos; i++) {
        if (cursos[i] == pos) pos++;
        else if (cursos[i] == pos - 1) pos--;
    }
    
    cache[entrada][num_cursos].pos = pos + 1;
    cache[entrada][num_cursos].calculado = true;
    return pos + 1;
}

bool verificar_sequencia(const int* cursos, int pos, int n) {
    if (pos > 0) {
        for (int i = 1; i < pos; i++) {
            if (abs(cursos[i] - cursos[i-1]) <= 1) {
                return false;
            }
        }
    }
    return true;
}

bool verificar_solucao(const int* cursos, int num_cursos, const int* transformacoes, int n) {
    memset(cache, 0, sizeof(cache));
    
    for (int i = 1; i <= n; i++) {
        if (simular_rede_dp(cursos, num_cursos, i, n) != transformacoes[i-1]) {
            return false;
        }
    }
    return true;
}

bool encontrar_solucao_rec(int* cursos, int pos, int tam, const int* transformacoes, int n) {
    if (pos == tam) {
        return verificar_solucao(cursos, tam, transformacoes, n);
    }
    
    int inicio = (pos > 0) ? cursos[pos-1] + 2 : 1;
    
    for (int i = inicio; i < n; i++) {
        cursos[pos] = i;
        if (!verificar_sequencia(cursos, pos + 1, n)) continue;
        if (encontrar_solucao_rec(cursos, pos + 1, tam, transformacoes, n)) {
            return true;
        }
    }
    return false;
}

void resolver_p_network(int n, const int* transformacoes) {
    if (n == 1) {
        printf("%d\n", (transformacoes[0] == 1) ? 0 : -1);
        return;
    }
    
    if (n == 2) {
        if (transformacoes[0] == 2 && transformacoes[1] == 1) {
            printf("1 1\n");
            return;
        }
        if (transformacoes[0] == 1 && transformacoes[1] == 2) {
            printf("0\n");
            return;
        }
        printf("No solution\n");
        return;
    }
    
    int* cursos = (int*)malloc(MAX_CURSOS * sizeof(int));
    bool encontrou = false;
    
    int tam_min = 0;
    for (int i = 0; i < n; i++) {
        tam_min += abs(transformacoes[i] - (i + 1));
    }
    tam_min = (tam_min + 1) / 2;
    
    for (int tam = tam_min; tam < 4 * n * n && !encontrou; tam++) {
        if (encontrar_solucao_rec(cursos, 0, tam, transformacoes, n)) {
            printf("%d", tam);
            for (int i = 0; i < tam; i++) {
                printf(" %d", cursos[i]);
            }
            printf("\n");
            encontrou = true;
        }
    }
    
    if (!encontrou) {
        printf("No solution\n");
    }
    
    free(cursos);
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        int* transformacoes = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &transformacoes[i]);
        }
        
        resolver_p_network(n, transformacoes);
        free(transformacoes);
    }
    return 0;
}