#include <stdio.h>
#include <math.h>  // Para M_PI, pow()

void calcularCirculo() {
    float raio, perimetro, area;

    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);

    perimetro = 2 * M_PI * raio;
    area = M_PI * pow(raio, 2);

    printf("\na. Perímetro: %.2f\n", perimetro);
    printf("b. Área: %.2f\n", area);
}

