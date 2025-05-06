#include <stdio.h>

void funcSoma100() {
    int soma = 0;

    for (int i = 1; i <= 100; i++) {
        printf("%d\n", i);
        soma += i;
    }

    printf("Soma total: %d\n", soma);

}
