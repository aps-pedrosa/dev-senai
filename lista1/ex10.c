#include <stdio.h>

void ex10() {
  float weight;
  float more;
  float less;

  printf("Digite o peso atual: ");
  scanf("%f", &weight);

  more = weight * 1.15;
  less = weight * 0.8;

  printf("Variacao de peso:\nAumento de 15%: %.2f kg\nReducao de 20%: %.2f kg\n", more, less);
}
