#include <stdio.h>
#include <stdlib.h>

typedef struct nó{
    int value;
    struct nó *prox;
} nó;

nó *criar(int value){
    nó *new = malloc(sizeof(nó));
    new->value = value;
    new->prox = NULL;
    return new;
}

void push(int value, nó **head, nó **topo, nó **headDec){
    nó *new = criar(value);
    
    if (*head == NULL && *headDec == NULL){
        *topo = new;
        *head = new;
        *headDec = new;
        return;
    }

    nó *temp = *head;
    while (temp->prox != NULL){
        temp = temp->prox;
    }

    temp->prox = new;
    *topo = temp->prox;
    ///////////////////////////
    new = criar(value);
    nó *aux2 = *headDec;
    nó *aux = NULL;
    if (aux2 == NULL || aux2->value <= value) {
        new->prox = *headDec;
        *headDec = new;
        return;
    }
    while (aux2 != NULL && aux2->value > value) {
        aux = aux2;
        aux2 = aux2->prox;
    }
    
    new->prox = aux2;
    aux->prox = new;
}

void pop(int value, nó **head, nó **topo, nó **headDec, int *ctop, int *chead, int *cDec){
    nó *lixo = *head;
    nó *temp = NULL;
    
    while(lixo->value != value && lixo != NULL){
        temp = lixo;
        lixo = lixo->prox;
    } 
    if(lixo != *topo && lixo != *head){
        temp->prox = lixo->prox;
        free(lixo);
        return;
    } else{
        if((*cDec) == 1){
            if(lixo == *headDec){
                nó *aux = *headDec;
                *headDec = (*headDec)->prox; 
                free(aux);
                (*cDec)--;
            }
        }
        if(*head == *topo && lixo->prox != NULL){
            (*chead)++;
            (*ctop)++;
            free(lixo);
            head == NULL;
            return;
        } else {
            if(*head == lixo && *head != *topo){
                *head = lixo->prox;
                (*chead)++;
                free(lixo);
                return;
            }

            if(*topo == lixo && *head != *topo){
                temp->prox = NULL;
                *topo = temp;
                (*ctop)++;
                free(lixo);
                return;
            }
        }
    }
}

int main(){
    int n, acao, value, chead = 0, ctop = 0, cDec = 1, poped = 0;
    nó *head = NULL;
    nó *Ptopo = NULL;
    nó *headDec = NULL;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &acao, &value);
        if (acao == 1){
            push(value, &head, &Ptopo, &headDec);
        } 
        if (acao == 2) {
            pop(value, &head, &Ptopo, &headDec, &ctop, &chead, &cDec);
            poped++;
        }
    }

    if(poped == 0){
        printf("impossible");
    } else {
        if((ctop==0 && cDec == 0) || (chead==0 && cDec == 0)) 
            printf("not sure");
        if(ctop == 0 && chead != 0)
            printf("queue");
        if(chead == 0 && ctop != 0)
            printf("stack");
        if(cDec == 0){
            printf("piority queue");
        }
    }
        
    printf("\n\n%d %d", ctop, chead);
    return 0;
}