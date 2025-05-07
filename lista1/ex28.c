#include <stdio.h>
#include <math.h>

void ex28() {
    float numero;
    
    printf("Digite um número: ");
    scanf("%f", &numero);
    
    printf("\nResultados:\n");
    printf("a. Número: %.2f\n", numero);
    printf("b. Quadrado: %.2f\n", numero * numero);
    printf("c. Raiz quadrada: %.2f\n", sqrt(numero));
}
