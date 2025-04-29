#include <stdio.h>

void funcMult() {
  int n1;
  int n2;
  int mult;

  printf("Digite um numero: ");
  scanf("%d", &n1);
  printf("Digite outro numero: ");
  scanf("%d", &n2);

  mult = n1 * n2;

  printf("O resultado da multiplicacao e igual a %d\n", mult);
}
