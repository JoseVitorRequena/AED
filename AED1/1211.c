#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXC 205

char numeros[MAXN][MAXC];

int compare(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int prefixo_comum(char *str1, char *str2) {
    int i = 0;
    while (str1[i] && str2[i] && str1[i] == str2[i]) {
        i++;
    }
    return i;
}

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s", numeros[i]);
        }
        
        qsort(numeros, n, MAXC, compare);
        
        int economia = 0;
        for (int i = 1; i < n; i++) {
            economia += prefixo_comum(numeros[i], numeros[i-1]);
        }
        
        printf("%d\n", economia);
    }
    
    return 0;
}