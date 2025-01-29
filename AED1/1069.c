#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char valor[1000];
    int topo;
} no;

void inicia(no* head){
    head->topo = -1;
}

int vazia(no* head){
    return head->topo == -1;
}

void push(no* head, char valor){
    head->valor[++(head->topo)] = valor;
}

int pop(no* head){
    if (vazia(head)) return 0;
    head->topo--;
    return 1;
}

int contador(char* diamantes){
    no head;
    inicia(&head);

    int count = 0;

    for (int j = 0; diamantes[j] != '\0'; j++) {
        if (diamantes[j] == '<') {
            push(&head, diamantes[j]);
        } else if (diamantes[j] == '>') {
            if (pop(&head)) {
                count++;
            }
        }
    }

    return count;
}   

int main(){
    int n;
    scanf("%d", &n);
    getchar();

    int* resultados = calloc(n, sizeof(int));
    
    for(int i = 0; i < n; i++){
        char diamantes[1000];
        fgets(diamantes, 1000, stdin);
        diamantes[strcspn(diamantes, "\n")] = '\0';

        resultados[i] = contador(diamantes);
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", resultados[i]);
    }
    free(resultados);
    return 0;
}