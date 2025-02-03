#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char string[51];
    int indice;
} Palavra;

void insertion_sort(Palavra *palavras, int n) {
    int i, j;
    Palavra chave;
    for (i = 1; i < n; i++) {
        chave = palavras[i];
        j = i - 1;
        while (j >= 0 && (strlen(palavras[j].string) > strlen(chave.string))) {
            palavras[j + 1] = palavras[j];
            j--;
        }
        palavras[j + 1] = chave;
    }
}

int main() {
    int quantidade, i;
    
    scanf("%d", &quantidade);
    getchar();
    
    while (quantidade--) {
        Palavra palavras[50];
        int contador = 0;
        
        char linha[255];
        fgets(linha, sizeof(linha), stdin);
        
        char *token = strtok(linha, " \n");
        while (token != NULL) {
            strcpy(palavras[contador].string, token);
            palavras[contador].indice = contador;
            contador++;
            token = strtok(NULL, " \n");
        }
        
        insertion_sort(palavras, contador);
        
        for (i = 0; i < contador; i++) {
            if (i > 0) printf(" ");
            printf("%s", palavras[i].string);
        }
        printf("\n");
    }
    
    return 0;
}
