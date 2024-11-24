#include <stdio.h>
#include <stdlib.h>
//Gasto por cidade
typedef struct cidade{
    int Qtd;
    int Gasto;
    struct cidade* prox;
    struct cidade* proxcasa;
} cidade;

cidade* criar(){
    cidade* new = (cidade*)malloc(sizeof(cidade));
    new->prox = NULL;
    new->proxcasa = NULL;
    
    return new;
}

void inserir(cidade* head){
    cidade* new = criar();
    if (head==NULL){
        head = new;
        return;
    }
    cidade* temp = (cidade*)malloc(sizeof(cidade));
    while(temp->prox!=NULL){
        temp=temp->prox;
    }
    // adicionar lógica
}

void pegarinput(cidade* head, int n){
    int pessoas, consumo;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &pessoas, &consumo);
        //
    }
}

void printar(){
    // cidade #n
    //printar pessoas organizadas
    //media por pessoas
    // Cidade# 1:
    // 2-5 3-7 3-13
    // Consumo medio: 9.00 m3.
}

int main(){
    int n;
    scanf("%d", &n);
    //inserir

    //pensar no fluxo principal
    //criar uma head ** para apontar para os próximos * que serão as cidades;

    //printar
    return 0;
}