# Listas Encadeadas

```
    Uma Lista Encadeada é uma sequência de elementos(registros) na memória de um computador. Sendo chamados de "célula". 
    Representam elementos consecutivos de sequência, mas não necessáriamente da memória.
```

### Exemplo:
Cada célula terá um valor e um ponteiro que aponta para o próximo da sequência

```c
typedef struct celula cel{
    int valor;
    struct celula *proximo;
}
```

```
assim:
    cel c;
    cel *p;
```
onde c seria uma célula e p seria o ponteiro para uma célula. Caso p seja o ponteiro para a última célula, o resultado do valor é null.

Uma lista pode também ser:
* Duplamente encadeada
* Com ou sem cabeça
    


    
