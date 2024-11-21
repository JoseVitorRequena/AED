#include <stdio.h>
#include <stdlib.h>

int VerificaMatriz(int **mat, int start, int n){
    for(int j = 0; j < start; j++){
        int *tempRow = (int*)calloc(9, sizeof(int));
        int *tempCol = (int*)calloc(9, sizeof(int));
        for(int k = 0; k < start; k++){
            tempRow[mat[j][k]-1]++;
            tempCol[mat[k][j]-1]++;
        }
        for(int l = 0; l < 9; l++){
            if(tempCol[l]!=1 || tempRow[l]!=1){
                printf("Instancia %d \n", n);
                printf("NAO\n\n");
                return 0;
            } else {
                printf("Instancia %d \n", n);
                printf("SIM\n\n");
                return 0;
            }
        }
        free(tempCol);
        free(tempRow);
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    int **mat = (int **)malloc((9 * n) * sizeof(int*));
    for (int i = 0; i < 9*n; ++i) mat[i] = (int *)malloc(9 * sizeof(int));
    for (int i = 0; i < 9*n; i++){
        for (int j = 0; j < 9; j++){
            scanf("%d", &mat[i][j]);
        }  
    }
    for(int i = 0; i < n; i++){
        VerificaMatriz(mat,9*n,n);
    }
    free(mat);
    return 0;
}
