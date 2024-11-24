#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//lista de compras
typedef struct cel {
    char palavra[21];
    struct cel *proximo;
} cel; 

cel* criarNo(char *palavra) {
    cel* nova = (cel*)malloc(sizeof(cel));
    strcpy(nova->palavra, palavra);
    nova->proximo = NULL;
    return nova;   
}

void inserir(cel** head, char* palavra){
    cel* atual = *head;
    cel* anterior = NULL;

    while (atual != NULL && strcmp(atual->palavra, palavra) < 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && strcmp(atual->palavra, palavra) == 0) {
        return;
    }

    cel* nova = criarNo(palavra);
    if (nova == NULL) return;

    if (anterior == NULL) {
        nova->proximo = *head;
        *head = nova;
    }
    
    else {
        nova->proximo = atual;
        anterior->proximo = nova;
    }
}

void imprimirLista(cel* head) {
    cel* temp = head;
    while (temp != NULL) {
        printf("%s", temp->palavra);
        temp = temp->proximo;
        if (temp != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

void limpar(cel* head) {
    cel* temp;
    while (head != NULL) {
        temp = head;
        head = head->proximo;
        free(temp);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    scanf("%*c");

    cel** listas = (cel**)malloc(n * sizeof(cel*));
    for(int i = 0; i < n; i++) {
        listas[i] = NULL;
    }

    for(int i = 0; i < n; i++){
        char* palavras = (char*)calloc(21001, sizeof(char));
        
        fgets(palavras, 21001, stdin);
        palavras[strcspn(palavras, "\n")] = '\0';
        
        char* palavra = strtok(palavras, " ");
        while (palavra != NULL) {
            inserir(&listas[i], palavra);
            palavra = strtok(NULL, " ");
        }

        free(palavras);
    }

    for(int i = 0; i < n; i++) {
        imprimirLista(listas[i]);
        limpar(listas[i]);
    }

    free(listas);
    return 0;
}