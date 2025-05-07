#include <stdio.h>

void ex27() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero % 10 == 0) {
        printf("O número é divisível por 10.\n");
    } else if (numero % 5 == 0) {
        printf("O número é divisível por 5.\n");
    } else if (numero % 2 == 0) {
        printf("O número é divisível por 2.\n");
    } else {
        printf("O número não é divisível por 10, 5 ou 2.\n");
    }
}
