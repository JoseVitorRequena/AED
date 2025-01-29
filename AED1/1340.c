#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct{
    int value[1000];
    int topo;
} Pilha;

typedef struct {
    int value[MAX];
    int frente, tras;
}   Fila;

typedef struct {
    int value[MAX];
    int topo;
} Prioridade;

void inicia_pilha(Pilha *pilha){
    pilha->topo = -1;
}

bool insere_pilha(Pilha *pilha, int x){
    if (pilha->topo >= MAX - 1) return false;
    pilha->value[++pilha->topo] = x;
    return true;
}

bool remove_pilha(Pilha *pilha, int *x){
    if (pilha->topo < 0) return false;
    *x = pilha->value[pilha->topo--];
    return true;
}

void inicia_fila(Fila *fila){
    fila->frente = 0;
    fila->tras = 0;
}

bool insere_fila(Fila *fila, int x){
    if (fila->tras >= MAX) return false;
    fila->value[fila->tras++] = x;
    return true;
}

bool remove_fila(Fila *fila, int *x){
    if (fila->frente == fila->tras) return false;  
    *x = fila->value[fila->frente++];
    return true;
}

void inicia_prioridade(Prioridade *prioridade){
    prioridade->topo = 0;
}

bool insere_prioridade(Prioridade *prioridade, int x){
    if (prioridade->topo == MAX) return false;
    prioridade->value[prioridade->topo++] = x;
    return true;
}

bool remove_prioridade(Prioridade *prioridade, int *x){
    if (prioridade->topo == 0) return false;
    int maximo = 0;
    for(int i = 0; i < prioridade->topo; i++){
        if (prioridade->value[i] > prioridade->value[maximo]){
            maximo = i;
        }
    }
    *x = prioridade->value[maximo];
    prioridade->value[maximo] = prioridade->value[--prioridade->topo];
    return true;
}

int main(){
    int n, j = 0;
    int *resultados = malloc(sizeof(int) * 10000);
    while (scanf("%d", &n) != EOF){

        Pilha pilha;
        Fila fila;
        Prioridade prioridade;

        inicia_pilha(&pilha);
        inicia_fila(&fila);
        inicia_prioridade(&prioridade);

        bool is_pilha = true, is_fila = true, is_prioridade = true;

        for(int i = 0; i < n; i++){
            int cmd , x;
            scanf("%d %d", &cmd, &x);
            
            if(cmd == 1){
                if (is_pilha) insere_pilha(&pilha, x);
                if (is_fila) insere_fila(&fila, x);
                if (is_prioridade) insere_prioridade(&prioridade, x);
            } else if (cmd == 2) {
                int val;
                if (is_pilha) {
                    if (!remove_pilha(&pilha, &val) || val != x) is_pilha = false;
                }
                if (is_fila){
                    if (!remove_fila(&fila, &val) || val != x) is_fila = false;
                }
                if (is_prioridade){
                    if (!remove_prioridade(&prioridade, &val) || val != x) is_prioridade = false;
                }
            }
        }
        
        if(is_pilha + is_fila + is_prioridade > 1){
            resultados[j] = 0;
        } else if (is_pilha){
            resultados[j] = 1;
        } else if (is_fila){
            resultados[j] = 2;
        } else if (is_prioridade){
            resultados[j] = 3;
        } else {
            resultados[j] = 4;
        }
        j++;
    }

    for (int i = 0; i < j; i++) {
    if (resultados[i] == 0)
        printf("not sure\n");
    else if (resultados[i] == 1)
        printf("stack\n");
    else if (resultados[i] == 2)
        printf("queue\n");
    else if (resultados[i] == 3)
        printf("priority queue\n");
    else
        printf("impossible\n");
    }

    return 0;