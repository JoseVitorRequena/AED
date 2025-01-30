#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 300

int contar_ligacoes(const char *sequencia) {
    int pilha_B = 0, pilha_C = 0; 
    int ligacoes = 0;
    
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (sequencia[i] == 'B') {
            pilha_B++;
        } else if (sequencia[i] == 'S') {
            if (pilha_B > 0) {
                pilha_B--;
                ligacoes++;
            }
        } else if (sequencia[i] == 'C') {
            pilha_C++;
        } else if (sequencia[i] == 'F') {
            if (pilha_C > 0) {
                pilha_C--;
                ligacoes++;
            }
        }
    }
    
    return ligacoes;
}

int main() {
    char sequencia[MAX_TAMANHO + 1]; 

    while (scanf("%s", sequencia) != EOF) {
        printf("%d\n", contar_ligacoes(sequencia));
    }

    return 0;
}
