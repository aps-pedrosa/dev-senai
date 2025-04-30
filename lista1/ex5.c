#include <stdio.h>
#include <stdlib.h>

void aumentoSalario() {
  float salario;

  printf("Qual é o salário do funcionário em R$: ");
  scanf("%f", &salario);
  if (salario <= 0) {
    printf("Erro: O salário não pode ser menor ou igual a zero!\n");
    exit(0);
  };
  float novosalario = salario * 1.25;
  printf("O novo salário é de: R$ %.2f\n", novosalario);

}
