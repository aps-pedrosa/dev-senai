#include <stdio.h>

void funcMaior() {
  float tmp;
  float maior = 0;

  for (int i=0; i < 3; i++) {
    printf("Digite um numero: ");
    scanf("%f", &tmp);
    if (maior < tmp) {
      maior = tmp;
    }
  }
  
  printf("O maior numero e: %.2f\n", maior);
}
