#include <stdio.h>
#include <stdlib.h>

char verificar_divisao(int A1, int A2, int A3, int A4) {
    if (A1 * (long long)A4 == A2 * (long long)A3) return 'S';
    if (A1 * (long long)A2 == A3 * (long long)A4) return 'S';
    if (A1 * (long long)A3 == A2 * (long long)A4) return 'S';
    
    return 'N';
}

int main() {
    int A1, A2, A3, A4;
    
    scanf("%d %d %d %d", &A1, &A2, &A3, &A4);
    
    printf("%c\n", verificar_divisao(A1, A2, A3, A4));
    
    return 0;
}