#include <stdio.h>



void funcNumeroDivisivel() {

    int numero;

    printf("Forneça o valor: ");
    scanf("%f", &numero);

    if (numero % 3 == 0 && numero % 7 == 0) {

        printf("O seu numero é divisivel por 3 ou 7.");
    } else {
        printf("Seu numero não é divisivel por 3 ou 7.");
    }

}

// int main() {
   // funcNumeroDivisivel();
  //  return 0;
// }