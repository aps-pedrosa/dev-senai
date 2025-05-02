#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void funcPow() {
  float n1;
  float n2;

  printf("Digite um numero: ");
  scanf("%f", &n1);
  if (n1 == 0) {
    printf("O numero nao pode ser 0\n");
    // exit(0);
  }
  printf("Digite outro numero: ");
  scanf("%f", &n2);
  if (n2 == 0) {
    printf("O numero nao pode ser 0\n");
    // exit(0);
  }

  float power = pow(n1, n2);

  printf("A potencia equivale a %.2f\n", power);
}
