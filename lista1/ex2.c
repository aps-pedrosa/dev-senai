#include <stdio.h>

void funcDiv() {
  int n1;
  int n2;
  int div;

  printf("Digite um numero: ");
  scanf("%d", &n1);
  printf("Digite outro numero: ");
  scanf("%d", &n2);
  if (n2 != 0) {

  div = n1 / n2;

  printf("O resultado da divisao e igual a %d\n", div);
  } else {
    printf("Uma divisao por 0 nao e possivel.\nExemplo de divisao valida: \"5/2\" \n");
  }
}
