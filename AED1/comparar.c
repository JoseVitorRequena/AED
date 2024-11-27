#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copymatriz(int* v1, int* v2, int MAX){

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
    int *v1, *v2;
    int MAX = 400000;
    float t;

    while (MAX<=400000){
        v1 = (int*)calloc(MAX, sizeof(int));
        v2 = (int*)calloc(MAX, sizeof(int));

        srand(time(NULL));
        for(int i = 0; i < MAX; i++){
            v1[i] = rand();
        }
        for(int i = 0; i < MAX; i++){
            v2[i] = v1[i];
        }

        printf("Max: %d\n", MAX);
        t = clock();
        insertion(MAX, v1);
        t = (float)(clock() - t) / CLOCKS_PER_SEC;;
        printf("T insertion: %f\n", t);
        t = clock();
        mergesort(0, MAX, v2);
        t = (float)(clock() - t) / CLOCKS_PER_SEC;;
        printf("T merge: %f\n", t);

        free(v1);
        free(v2);

        MAX += 50000;
    }
    return 0;
}