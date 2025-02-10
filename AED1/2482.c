#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 50
#define MAX_TRADUCOES 100

typedef struct {
    char lingua[MAX_STR];
    char felizNatal[MAX_STR];
} Traducao;

typedef struct {
    char nome[MAX_STR];
    char lingua[MAX_STR];
} Crianca;

const char* buscar_traducao(Traducao traducoes[], int N, const char* lingua) {
    for (int i = 0; i < N; i++) {
        if (strcmp(traducoes[i].lingua, lingua) == 0) {
            return traducoes[i].felizNatal;
        }
    }
    return NULL;  
}

int main() {
    int N, M;
    Traducao traducoes[MAX_TRADUCOES];
    Crianca criancas[MAX_TRADUCOES];
    
    scanf("%d", &N);
    getchar();  
    
    for (int i = 0; i < N; i++) {
        fgets(traducoes[i].lingua, MAX_STR, stdin);
        traducoes[i].lingua[strcspn(traducoes[i].lingua, "\n")] = 0;  
        
        fgets(traducoes[i].felizNatal, MAX_STR, stdin);
        traducoes[i].felizNatal[strcspn(traducoes[i].felizNatal, "\n")] = 0;  
    }
    
    scanf("%d", &M);
    getchar();  
    
    for (int i = 0; i < M; i++) {
        fgets(criancas[i].nome, MAX_STR, stdin);
        criancas[i].nome[strcspn(criancas[i].nome, "\n")] = 0;  
        
        fgets(criancas[i].lingua, MAX_STR, stdin);
        criancas[i].lingua[strcspn(criancas[i].lingua, "\n")] = 0; 
    }
    
    for (int i = 0; i < M; i++) {
        const char* traducao = buscar_traducao(traducoes, N, criancas[i].lingua);
        printf("%s\n%s\n\n", criancas[i].nome, traducao);
    }
    
    return 0;
}