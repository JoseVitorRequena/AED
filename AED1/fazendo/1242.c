#include <stdio.h>
#include <string.h>

char fita[305];
int dp[305][305];
int n;

int sao_pares(char a, char b) {
    return (a == 'B' && b == 'S') || (a == 'S' && b == 'B') || 
           (a == 'C' && b == 'F') || (a == 'F' && b == 'C');
}

int resolver(int inicio, int fim) {
    if (inicio >= fim) return 0;
    if (dp[inicio][fim] != -1) return dp[inicio][fim];
    
    int resposta = resolver(inicio + 1, fim);
    
    for (int k = inicio + 1; k <= fim; k++) {
        if (sao_pares(fita[inicio], fita[k])) {
            int ligacoes = 1;
            if (k == inicio + 1)
                ligacoes += resolver(k + 1, fim);
            else
                ligacoes += resolver(inicio + 1, k - 1) + resolver(k + 1, fim);
                
            if (ligacoes > resposta)
                resposta = ligacoes;
        }
    }
    
    dp[inicio][fim] = resposta;
    return resposta;
}

int main() {
    while (scanf("%s", fita) != EOF) {
        n = strlen(fita);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = -1;
                
        printf("%d\n", resolver(0, n - 1));
    }
    return 0;
}