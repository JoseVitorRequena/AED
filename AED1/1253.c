#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 51  

void decodificar_cesar(char texto[], int deslocamento) {
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            int posicao = texto[i] - 'A';
            
            int posicao_original = (posicao - deslocamento + 26) % 26;
            
            texto[i] = posicao_original + 'A';
        }
    }
}

int main() {
    int N;             
    char texto[MAX_LENGTH]; 
    int deslocamento;       

    scanf("%d", &N);
    
    getchar();
    
    while (N--) {
        fgets(texto, MAX_LENGTH, stdin);
        texto[strcspn(texto, "\n")] = 0;
        
        scanf("%d", &deslocamento);
        getchar(); 
        
        decodificar_cesar(texto, deslocamento);
        
        printf("%s\n", texto);
    }
    
    return 0;
}