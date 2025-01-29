#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n, k, i = 0, j = 0;
    char* nome;
    char* aux;
    char** nomes;

    scanf("%d %d", &n, &k);

    nomes = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        nome = (char*)calloc(50, sizeof(char));
        scanf("%s", nome);
        nome[strcspn(nome, "\n")] = '\0';
        nomes[i] = nome;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                aux = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = aux;
            }
        }
    }

    printf("%s\n", nomes[k-1]);
    
    for(int i = 0; i < n; i++){
        free(nomes[i]);
    }
    free(nomes);
    return 0;
}