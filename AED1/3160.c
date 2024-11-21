#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char palavra[15];
    struct cel *proximo;
} cel; 

cel* criarNo(char *palavra) {
    cel* nova = (cel*)malloc(sizeof(cel));
    strcpy(nova->palavra, palavra);
    nova->proximo = NULL;
    return nova;   
}

void inserir(cel** head, char* palavra, char *condicao) {
    cel* nova = criarNo(palavra);
    
    if (*head == NULL) {
        *head = nova;
        return;
    }

    cel* ultima = *head;
    cel* temp = NULL;

    if (condicao == NULL || strcmp(condicao, "nao") == 0 || strlen(condicao) == 0) {
        while (ultima->proximo != NULL) {
            ultima = ultima->proximo;
        }
        ultima->proximo = nova;
    } else {
        while (ultima != NULL && strcmp(ultima->palavra, condicao) != 0) {
            temp = ultima;
            ultima = ultima->proximo;
        }
        
        if (ultima == NULL) {
            temp->proximo = nova;
        } else if (temp == NULL) { 
            nova->proximo = *head;
            *head = nova;
        } else {  
            nova->proximo = ultima;
            temp->proximo = nova;
        }
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

int main() {
    char *nomes;
    char* token;
    char *condicao = NULL;
    cel *Head = NULL;

    for (int i = 0; i < 2; i++) {
        nomes = (char*)calloc(100, sizeof(char));
        fgets(nomes, 100, stdin);

        if (i == 1) {
            condicao = (char*)calloc(15, sizeof(char));
            fgets(condicao, 15, stdin);
            condicao[strcspn(condicao, "\n")] = '\0';
        }
        
        token = strtok(nomes, " \n");
        while (token != NULL) {
            inserir(&Head, token, condicao);
            token = strtok(NULL, " \n");
        }

        free(nomes);
    }

    free(condicao);
    imprimirLista(Head);
    limpar(Head);

    return 0;
}
