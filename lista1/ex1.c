#include <stdio.h>

void funcMult() {
  float n1;
  float n2;
  float mult;

  printf("Digite um numero: ");
  scanf("%f", &n1);
  printf("Digite outro numero: ");
  scanf("%f", &n2);

  mult = n1 * n2;

  printf("O resultado da multiplicacao e igual a %.2f\n", mult);
}
