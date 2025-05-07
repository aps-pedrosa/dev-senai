#include <stdio.h>

void ex3() {
    float n1;
    float n2;
    float n3;
    float n4;

    printf("Digite o primeiro número: ");
    scanf("%f", &n1);

    printf("Digite o segundo número: ");
    scanf("%f", &n2);

    printf("Digite o terceiro número: ");
    scanf("%f", &n3);

    printf("Digite o quarto número: ");
    scanf("%f", &n4);

    float soma = n1 + n2 + n3 + n4;

    printf("A soma final dos 4 números é de: %.2f\n", soma);
}
