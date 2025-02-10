#include <stdio.h>
#include <string.h>

void construirPosfixa(char *pre, char *in, int n) {
    if (n <= 0) return;
    
    char raiz = pre[0];
    int i;
    
    for (i = 0; i < n; i++) {
        if (in[i] == raiz) break;
    }
    
    construirPosfixa(pre + 1, in, i);
    construirPosfixa(pre + 1 + i, in + i + 1, n - i - 1);
    putchar(raiz);
}

int main() {
    int C;
    scanf("%d", &C);
    
    while (C--) {
        int N;
        char pre[53], in[53];
        
        scanf("%d %s %s", &N, pre, in);
        construirPosfixa(pre, in, N);
        putchar('\n');
    }
    
    return 0;
}