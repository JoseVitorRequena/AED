#include <stdio.h>
#include <string.h>

void encontrarPosicoes(const char *texto, const char *palavra) {
    int tamanhoTexto = strlen(texto);
    int tamanhoPalavra = strlen(palavra);
    int encontrou = 0; 
    int primeiro = 1;  

    for (int i = 0; i <= tamanhoTexto - tamanhoPalavra; i++) {
        if (strncmp(&texto[i], palavra, tamanhoPalavra) == 0) {
            if ((i == 0 || texto[i - 1] == ' ') && 
                (i + tamanhoPalavra == tamanhoTexto || texto[i + tamanhoPalavra] == ' ')) {
                if (!primeiro) {
                    printf(" "); 
                }
                printf("%d", i); 
                encontrou = 1;
                primeiro = 0; 
            }
        }
    }

    if (!encontrou) {
        printf("-1");
    }
    printf("\n");
}

int main() {
    int q;
    scanf("%d", &q); 

    char texto[129]; 
    char palavra[129]; 

    for (int i = 0; i < q; i++) {
        scanf(" %[^\n]", texto); 
        scanf(" %s", palavra);   

        encontrarPosicoes(texto, palavra);
    }

    return 0;
}