#include <stdio.h>
#include <stdlib.h>
//Calculo de fração
typedef struct eq{
    int ValueN;
    int ValueD;
    struct eq* prox;
} eq;

eq* pegalinha(eq* new){
    eq* temp = new;
    int N1, N2, D1, D2;
    char mod;
    scanf("%d / %d %c %d / %d", &N1, &D1, &mod, &N2, &D2);
    
    if(mod == '+'){
        temp->ValueN = (N1*D2) + (N2*D1);
        temp->ValueD = (D1*D2);
    } 
    else if(mod == '-'){
        temp->ValueN = (N1*D2) - (N2*D1);
        temp->ValueD = (D1*D2);
    }
    else if(mod == '*'){
        temp->ValueN = (N1*N2);
        temp->ValueD = (D1*D2);
    } else {
        temp->ValueN = (N1*D2);
        temp->ValueD = (N2*D1);
    }
    
    return temp;
}

eq* criar(){
    eq* temp = (eq*)malloc(sizeof(eq));
    temp->prox = NULL;
    pegalinha(temp);
    
    return temp;
}

void inserir(eq** head){
    eq* new = criar();
    if(*head == NULL){
        *head = new; 
        return;
    }

    eq* temp = *head;
    while(temp->prox!=NULL){
        temp = temp->prox;
    }
    temp->prox = new;
}

int mdc(int n, int m){
    int valor, result;
    while (n != 0){
        valor =  m % n;
        m = n;
        n = valor;
    }
    result = m;
    if (result<0){
        result = result*-1;
    }
    return result;
}

void printfila(eq* head){
    eq* temp = head;
    int result;
    while(temp != NULL){
        printf("%d/%d", temp->ValueN, temp->ValueD);
        result = mdc(temp->ValueN, temp->ValueD);
        if(result != 0){
            printf(" = %d/%d", temp->ValueN/result, temp->ValueD/result);
        }
        printf("\n");
        temp=temp->prox;
    }
}

int main(){
    int n, ValueN, ValueD;
    eq* head = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        inserir(&head);
    }
    
    printfila(head);
    free(head);
    return 0;
}
