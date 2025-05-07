#include <stdio.h>

void ex16() {
    float numero, tercaParte;

    printf("Digite um número real: ");
    scanf("%f", &numero);

    tercaParte = numero / 3.0;

    printf("A terça parte de %.2f é %.2f\n", numero, tercaParte);
}
