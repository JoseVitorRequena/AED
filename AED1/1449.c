#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 85
#define MAX_DICT 1000005

typedef struct {
    char japones[MAX_LEN];
    char portugues[MAX_LEN];
} Traducao;

Traducao dict[MAX_DICT];

int comp(const void *a, const void *b) {
    return strcmp(((Traducao *)a)->japones, ((Traducao *)b)->japones);
}

Traducao *buscar(char *palavra, int M) {
    Traducao chave;
    strcpy(chave.japones, palavra);
    return bsearch(&chave, dict, M, sizeof(Traducao), comp);
}

void processar_linha(char *linha, int M) {
    char *palavra = strtok(linha, " \n");
    int primeiro = 1;
    
    while (palavra != NULL) {
        if (!primeiro) printf(" ");
        primeiro = 0;
        
        Traducao *trad = buscar(palavra, M);
        if (trad) printf("%s", trad->portugues);
        else printf("%s", palavra);
        
        palavra = strtok(NULL, " \n");
    }
    printf("\n");
}

int main() {
    int T, M, N;
    char linha[MAX_LEN];
    
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &M, &N);
        getchar();
        
        for (int i = 0; i < M; i++) {
            fgets(linha, MAX_LEN, stdin);
            linha[strcspn(linha, "\n")] = 0;
            strcpy(dict[i].japones, linha);
            
            fgets(linha, MAX_LEN, stdin);
            linha[strcspn(linha, "\n")] = 0;
            strcpy(dict[i].portugues, linha);
        }
        
        qsort(dict, M, sizeof(Traducao), comp);
        
        for (int i = 0; i < N; i++) {
            if (fgets(linha, MAX_LEN, stdin) != NULL) {
                linha[strcspn(linha, "\n")] = 0;
                if (strlen(linha) > 0) {
                    processar_linha(linha, M);
                } else {
                    printf("\n");
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}