#include <stdio.h>
#include <math.h>

void funcCalcularLogaritmo() {
    double numero;
    int base;

    printf("Digite um numero: ");
    scanf("%lf", &numero);

    printf("Digite a base: ");
    scanf("%d", &base);

    if (numero <= 0 || base <= 1) {
        printf("Erro: número deve ser > 0 e base deve ser > 1.\n");
        return;
    }

    double resultado = log(numero) / log(base);

    printf("\nResultado: log base %d de %.2f = %.4f\n", base, numero, resultado);
}

// int main() {
//     funcCalcularLogaritmo();
//     return 0;
// }
