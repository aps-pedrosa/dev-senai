#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void funcPow() {
  int n1;
  int n2;
  int po;

  printf("Digite um numero:\n");
  scanf("%d", &n1);
  if (n1 == 0) {
    printf("O numero nao pode ser 0\n");
    exit(0);
  }
  printf("Digite outro numero:\n");
  scanf("%d", &n2);
  if (n2 == 0) {
    printf("O numero nao pode ser 0\n");
    exit(0);
  }

  po = pow(n1, n2);

  printf("A potencia equivale a %d\n", po);
}
