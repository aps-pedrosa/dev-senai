//
// Created by aluno_iot on 29/04/2025.
//

#include <stdio.h>
#include <stdbool.h>

int numero;

void verificarPar() {

    printf("Forneça o número: ");
    scanf("%d", &numero);
    if (numero % 2 == 0) {
        printf("o número %d é par\n", numero);
    }
    else  {
        printf("O número %d é impar\n", numero);
    }
}
