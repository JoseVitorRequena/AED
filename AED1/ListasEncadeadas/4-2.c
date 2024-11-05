#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct cel *proximo;
} cel;

int main(){
    //Lista com cabeça
    cel c, *lst1;
    c.proximo = NULL;
    lst1 = &c;
    //ou
    cel *lst2;
    lst2 = malloc(sizeof(cel));
    lst2->proximo = NULL;

    //lista sem cabeça
    cel *lst3;
    lst3 = NULL;
}