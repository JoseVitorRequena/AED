#include <stdio.h>
#include <string.h>

#define MAX_TAM 27  

int esta_ordenada(char seq[]) {
    int len = strlen(seq);
    for (int i = 0; i < len - 1; i++) {
        if (seq[i] > seq[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int pode_ordenar_com_uma_troca(char seq[]) {
    int len = strlen(seq);
    char temp_seq[MAX_TAM];
    int trocas_necessarias = 0;
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            strcpy(temp_seq, seq);
            
            char temp = temp_seq[i];
            temp_seq[i] = temp_seq[j];
            temp_seq[j] = temp;
            
            if (esta_ordenada(temp_seq)) {
                return 1;
            }
        }
    }
    
    return 0;
}

int main() {
    int N, M;
    char sequencia[MAX_TAM];
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &M, sequencia);
        
        if (esta_ordenada(sequencia)) {
            printf("There aren't the chance.\n");
            continue;
        }
        
        if (pode_ordenar_com_uma_troca(sequencia)) {
            printf("There are the chance.\n");
        } else {
            printf("There aren't the chance.\n");
        }
    }
    
    return 0;
}