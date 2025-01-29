#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int pessoas;
    int consumo;
} Imovel;

typedef struct {
    Imovel* imoveis;
    int total_imoveis;
    int total_pessoas;
    int total_consumo;
} Cidade;

int comparador(const void* a, const void* b) {
    Imovel* imovelA = (Imovel*)a;
    Imovel* imovelB = (Imovel*)b;

    if (imovelA->consumo != imovelB->consumo)
        return imovelA->consumo - imovelB->consumo;
    return imovelA->pessoas - imovelB->pessoas;
}

void processar_cidade(Cidade* cidade, int numero_cidade) {
    qsort(cidade->imoveis, cidade->total_imoveis, sizeof(Imovel), comparador);

    printf("Cidade# %d:\n", numero_cidade);

    int pessoas_agrupadas = cidade->imoveis[0].pessoas;
    int consumo_atual = cidade->imoveis[0].consumo;

    for (int i = 1; i < cidade->total_imoveis; i++) {
        if (cidade->imoveis[i].consumo == consumo_atual) {
            pessoas_agrupadas += cidade->imoveis[i].pessoas;
        } else {
            printf("%d-%d ", pessoas_agrupadas, consumo_atual);
            pessoas_agrupadas = cidade->imoveis[i].pessoas;
            consumo_atual = cidade->imoveis[i].consumo;
        }
    }
    printf("%d-%d\n", pessoas_agrupadas, consumo_atual);

    double consumo_medio = (double)cidade->total_consumo / cidade->total_pessoas;
    printf("Consumo medio: %.2lf m3.\n", floor(consumo_medio * 100) / 100);
}

int main() {
    int n, numero_cidade = 1;
    Cidade cidades[100];
    int total_cidades = 0;

    while (scanf("%d", &n) && n != 0) {
        Cidade cidade;
        cidade.imoveis = (Imovel*)malloc(n * sizeof(Imovel));
        cidade.total_imoveis = n;
        cidade.total_pessoas = 0;
        cidade.total_consumo = 0;

        for (int i = 0; i < n; i++) {
            int pessoas, consumo;
            scanf("%d %d", &pessoas, &consumo);

            cidade.imoveis[i].pessoas = pessoas;
            cidade.imoveis[i].consumo = consumo / pessoas;

            cidade.total_pessoas += pessoas;
            cidade.total_consumo += consumo;
        }

        cidades[total_cidades++] = cidade;
    }

    for (int i = 0; i < total_cidades; i++) {
        if (i > 0) {
            printf("\n"); 
        }
        processar_cidade(&cidades[i], i + 1);
        free(cidades[i].imoveis);
    }

    return 0;
}
