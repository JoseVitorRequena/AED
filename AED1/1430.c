#include <stdio.h>
#include <string.h>


double nota_para_duracao(char nota) {
    switch(nota) {
        case 'W': return 1.0;      
        case 'H': return 0.5;      
        case 'Q': return 0.25;     
        case 'E': return 0.125;    
        case 'S': return 0.0625;   
        case 'T': return 0.03125;  
        case 'X': return 0.015625; 
        default: return 0.0;
    }
}

int validar_compasso(const char *compasso, int tamanho) {
    double duracao = 0.0;
    
    for (int i = 0; i < tamanho; i++) {
        duracao += nota_para_duracao(compasso[i]);
    }
    
    return (duracao > 0.9999 && duracao < 1.0001);
}

int contar_compassos_validos(const char *composicao) {
    int compassos_validos = 0;
    int tamanho = strlen(composicao);
    int inicio_compasso = 1; 
    int tam_compasso;
    
    for (int i = 1; i < tamanho; i++) {
        if (composicao[i] == '/') {
            tam_compasso = i - inicio_compasso;
            
            if (tam_compasso > 0) {
                if (validar_compasso(composicao + inicio_compasso, tam_compasso)) {
                    compassos_validos++;
                }
            }
            
            inicio_compasso = i + 1;
        }
    }
    
    return compassos_validos;
}

int main() {
    char linha[205];
    
    while (1) {
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;
        
        linha[strcspn(linha, "\n")] = 0;
        
        if (strcmp(linha, "*") == 0) break;
        
        printf("%d\n", contar_compassos_validos(linha));
    }
    
    return 0;
}