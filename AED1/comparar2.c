#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int *v, int inicio, int fim) {
    int pivo = v[fim];  
    int i = inicio - 1; 

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i + 1], &v[fim]); 
    return i + 1;
}

void quicksort(int *v, int inicio, int fim) {
    if (inicio < fim) {
        int p = particiona(v, inicio, fim); 
        quicksort(v, inicio, p - 1);      
        quicksort(v, p + 1, fim);          
    }
}


void insertion(int n, int v[]){
    int i, j, x;
    for(j = 1; j < n; j++){
        x = v[j];
        for(i = j-1; i >= 0 && v[i] > x; i--){
            v[i+1] = v[i];
        }
        v[i+1] = x;
    }
}

void intercala(int p, int q, int r, int v[]){
    int i, j, k, *w;
    w = malloc((r-p) * sizeof(int));
    i = p; j = q; k = 0;
    while (i < q && j < r){
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++) v[i] = w[i-p];
    free(w);
}
void mergesort(int p, int r, int v[]){
    if (p < r - 1){
        int q = (p + r)/2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

int main(){
    int *v1, *v2, *v3;
    int MAX = 20000;
    float t;

    while (MAX<=400000){
        v1 = (int*)calloc(MAX, sizeof(int));
        v2 = (int*)calloc(MAX, sizeof(int));
        v3 = (int*)calloc(MAX, sizeof(int));

        srand(time(NULL));
        for(int i = 0; i < MAX; i++){
            v1[i] = rand();
            v2[i] = v1[i];
            v3[i] = v1[i];
        }

        printf("Max: %d\n", MAX);
        t = clock();
        insertion(MAX, v1);
        t = (float)(clock() - t) / CLOCKS_PER_SEC;;
        printf("%f\n", t);
        
        t = clock();
        mergesort(0, MAX, v2);
        t = (float)(clock() - t) / CLOCKS_PER_SEC;;
        printf("%f\n", t);

        t = clock();
         quicksort(v3, 0, MAX - 1);
        t = (float)(clock() - t) / CLOCKS_PER_SEC;;
        printf("%f\n", t);

        free(v1);
        free(v2);
        free(v3); 
        
        MAX += 20000;
    }
    return 0;
}