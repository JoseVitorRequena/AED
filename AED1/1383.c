#include <stdio.h>

int matriz[9][9];

int verifica_linha(int linha) {
    int existe[10] = {0};
    for(int j = 0; j < 9; j++) {
        if(existe[matriz[linha][j]] == 1) return 0;
        existe[matriz[linha][j]] = 1;
    }
    return 1;
}

int verifica_coluna(int coluna) {
    int existe[10] = {0};
    for(int i = 0; i < 9; i++) {
        if(existe[matriz[i][coluna]] == 1) return 0;
        existe[matriz[i][coluna]] = 1;
    }
    return 1;
}

int verifica_quadrante(int linha, int coluna) {
    int existe[10] = {0};
    for(int i = linha; i < linha + 3; i++) {
        for(int j = coluna; j < coluna + 3; j++) {
            if(existe[matriz[i][j]] == 1) return 0;
            existe[matriz[i][j]] = 1;
        }
    }
    return 1;
}

int verifica_matriz() {
    for(int i = 0; i < 9; i++) {
        if(!verifica_linha(i)) return 0;
        if(!verifica_coluna(i)) return 0;
    }
    
    for(int i = 0; i < 9; i += 3) {
        for(int j = 0; j < 9; j += 3) {
            if(!verifica_quadrante(i, j)) return 0;
        }
    }
    
    return 1;
}

int main() {
    int n, instancia = 1;
    scanf("%d", &n);
    
    while(n--) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        
        printf("Instancia %d\n", instancia++);
        printf("%s\n\n", verifica_matriz() ? "SIM" : "NAO");
    }
    
    return 0;
}