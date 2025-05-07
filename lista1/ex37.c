#include <stdio.h> 
#include <math.h>


void ex37() {
    float num[5];

    printf("Digite um número: ");
    scanf("%f", &num[0]);
    printf("O quadrado de %.2f é %.2f\n", num[0], pow(num[0], 2));
    for (int i = 1; i < 5; i++) {
        printf("Digite outro número: ");
        scanf("%f", &num[i]);
        printf("O quadrado de %.2f é %.2f\n", num[i], pow(num[i], 2));
    }

}
