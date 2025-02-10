#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int x, y;
} posicao;

typedef struct {
    char simbolo;
    int visitado;
} Cell;

Cell mapa[MAX_SIZE][MAX_SIZE];
int largura, altura;

posicao proxpos(posicao atual, char direction) {
    posicao prox = atual;
    switch (direction) {
        case '>': prox.y++; break;
        case '<': prox.y--; break;
        case 'v': prox.x++; break;
        case '^': prox.x--; break;
        case '.': break;
        default: break;
    }
    return prox;
}

int isValid(posicao pos) {
    return pos.x >= 0 && pos.x < altura && pos.y >= 0 && pos.y < largura;
}

char olharmapa() {
    posicao atual = {0, 0};
    char atualDire = '>';
    
    while (1) {
        if (!isValid(atual)) {
            return '!';
        }
        
        Cell *CelAtual = &mapa[atual.x][atual.y];
        
        if (CelAtual->visitado) {
            return '!';
        }
        
        if (CelAtual->simbolo == '*') {
            return '*';
        }
        
        CelAtual->visitado = 1;
        
        if (CelAtual->simbolo == '>' || CelAtual->simbolo == '<' || 
            CelAtual->simbolo == 'v' || CelAtual->simbolo == '^') {
            atualDire = CelAtual->simbolo;
        }
        
        atual = proxpos(atual, atualDire);
    }
}

int main() {
    scanf("%d", &largura);
    scanf("%d", &altura);
    
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            scanf(" %c", &mapa[i][j].simbolo);
            mapa[i][j].visitado = 0;
        }
    }
    
    char result = olharmapa();
    printf("%c\n", result);
    
    return 0;
}