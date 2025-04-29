#include <stdio.h>

void funcArea() {
  float b;
  float h;
  float area;

  printf("Digite a base do triangulo: ");
  scanf("%f", &b);
  printf("Digite altura do triangulo: ");
  scanf("%f", &h);

  area = b * h / 2;

  printf("A area do triangulo e %.2f\n", area);
}
