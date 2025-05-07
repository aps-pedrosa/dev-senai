#include <stdio.h>

void ex12() {
  float gas;
  float distance;

  printf("Digite a distancia percorrida: ");
  scanf("%f", &distance);
  printf("Digite a quatidade de combustivel percorrida: ");
  scanf("%f", &gas);

  float avg = distance/gas;

  printf("O consumo medio de combustivel por distancia equivale a: %.2fL/Km\n", avg);
}
