#include <stdio.h>

void ex32() {
  int age;

  printf("Digite a idade do nadador: ");
  scanf("%d", &age);

  if ((age>=5)&&(age<=7)) {
    printf("O nadador esta na categoria Infantil A\n");

  } else if ((age>=8)&&(age<=10)) {
    printf("O nadador esta na categoria Infantil B\n");

  } else if ((age>=11)&&(age<=13)) {
    printf("O nadador esta na categoria Juvenil A\n");

  } else if ((age>=14)&&(age<=17)) {
    printf("O nadador esta na categoria Juvenil B\n");

  } else if (age>=18) {
    printf("O nadador esta na categoria Senior\n");
  } else {
    printf("Esta idade nao e permitida pela confederacao brasileira de natacao.\n");
  }
}
