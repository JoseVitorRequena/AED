#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *prox;
} no;

no* criar(int valor){
	no* novo = malloc(sizeof(no));
	novo->valor = valor;
	novo->prox = NULL;
	return novo;
}

void inserir(no *head[], int valor, int x){
	no* novo = criar(valor);
	if (head[x] == NULL){
		head[x] = novo;
		return;
	}
	no* temp = head[x];
	while(temp->prox != NULL){
		temp = temp->prox;
	}
	temp->prox = novo;
}

void printhash(no *hash[], int m, int ultimo_teste) {
    for (int i = 0; i < m; i++) {
        printf("%d -> ", i);
        no* temp = hash[i];
        while (temp != NULL) {
            printf("%d -> ", temp->valor);
            temp = temp->prox;
        }
        printf("\\\n");
    }
    if (!ultimo_teste) {
        printf("\n");
    }
}

int main(){
	int n, c, m, aux;
	no **hash;
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++){
		scanf("%d %d", &m, &c);
		hash = calloc(m, sizeof(no*));
		for(int j = 0; j<m; j++){
			hash[j] = NULL;
		}
		for(int j = 0; j<c; j++){
			scanf("%d", &aux);		

			inserir(hash, aux, aux%m);
		}
		
		printhash(hash, m, i == n - 1);
		
		free(hash);	
	}	
}
