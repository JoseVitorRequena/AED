#include <stdio.h>

#define EPS 1e-9

void verificarEquilibrio(double a, double b, double c, double d) {
    double pesos[4] = {a, b, c, d};
    
    for (int i = 0; i < 16; i++) {
        double esquerda = 0, direita = 0;
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) esquerda += pesos[j];
            else direita += pesos[j];
        }
        if (fabs(esquerda - direita) < EPS) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    verificarEquilibrio(a, b, c, d);
    return 0;
}
