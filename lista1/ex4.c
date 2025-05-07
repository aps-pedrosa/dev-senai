#include <stdio.h>

void ex4() {
  float num[3];
  float sum = 0;
  float avg;

  for (int i = 0; i < 3; i++) {
    printf("Digite um numero: ");
    scanf("%f", &num[i]);
    sum += num[i];
  }
  avg = sum/3;
  printf("A media dos numeros e igual a %.2f\n", avg);
}
