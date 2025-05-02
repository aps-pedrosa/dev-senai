#include <stdio.h>
#include <math.h> 

void exibirInformacoesNumero() {
    float numero, quadrado, raiz;

    printf("Digite um número: ");
    scanf("%f", &numero);

    quadrado = numero * numero;
    raiz = sqrt(numero);

    printf("\na. Número: %.2f\n", numero);
    printf("b. Quadrado: %.2f\n", quadrado);
    printf("c. Raiz quadrada: %.2f\n", raiz);
}

